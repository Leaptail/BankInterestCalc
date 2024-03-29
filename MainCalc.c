#include <stdio.h>
//program to write to a txt file about my current bank, particularly, liquid, Investments,growth,salary.

//function to get first 2 digits
int First2digit(int Num)
{
    Num /= 1000000;
    return Num;
}

//function to return the month 
int Monthdigit(int Num)
{
    Num %= 1000000;
    Num /= 10000;
    return Num;
}

//function to return the year
int Yeareturn(int Num)
{
	Num %= 10000;
	return Num;
}

//difference between dates in days
int FDaydiff(int date1,int date2)
{
	int Months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int days=0,daysbefore=0,daysafter=0;

	//days in year before first date
	for(int h=0;h<=Monthdigit(date1)-1;h++) daysbefore+=Months[h];
	daysbefore+=First2digit(date1); 
	
	//days in year after second date
	for(int h=Monthdigit(date2);h<=11;h++) daysafter+=Months[h];//WHY TF DOES <= WORK AND NOT ==????????????????????
	daysafter-=First2digit(date2);

	days=(365*(Yeareturn(date2)-Yeareturn(date1)+1))-daysbefore-daysafter;
	return days;
}

int checkdate(int date)
{
	int Months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(date<1010001)
	{
		return 0;
	}
	else if(Monthdigit(date)<13)
	{
		if(First2digit(date)<=Months[Monthdigit(date)-1])
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int main(int argc, char *argv[])
{
	int liquid=0,inve=0,salary=0,date1;
    int liquid2=0,inve2=0,salary2=0,date2=0;
	int daydiff;
	double growth=0;

	//read numbers in file and compare the interest rate
	FILE * in = fopen("Bnk.txt","r+");
	if (in==NULL) printf("ERROR Unable to open");

	//go back one line
	int y = -32;
	fseek(in,y,SEEK_END);

	//scan last line of data
	fscanf(in,"%d %d %d %d",&liquid,&inve,&salary,&date1);
	fclose(in);
	
	label_input:
	//ask for new numbers
	do{
		printf("Enter The numbers liquid/invest/salary/date (ddyymmmm): \n");
		scanf("%d %d %d %d", &liquid2, &inve2, &salary2, &date2);
	} while(checkdate(date2)==0);
	
	//while(liquid2==0||inve2==0||salary2==0||date2==0);
	//check date validity
	//if(checkdate(date2)==0) goto label_input; 

	//print change
    printf("Change in liq/inv/sal: \n             %d %d %d",liquid2-liquid,inve2-inve,salary2-salary);

	//Calculating Date change
	daydiff=FDaydiff(date1,date2);
	printf("\nDifference in days: %4d", daydiff);

	//daily growth
	growth=(liquid2-liquid+inve2-inve)/((double)liquid+(double)inve);
	growth=100*growth/daydiff;
	printf("\ngrowth daily = %2.3f",growth);

	FILE * out = fopen("Bnk.txt","a+");
	//write numbers to file in previous row
	fprintf(out,"\n%7d %7d %7d %8d",liquid2,inve2,salary2,date2);
	fclose(out);
}