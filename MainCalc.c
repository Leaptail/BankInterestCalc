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
	for(int h=Monthdigit(date2)-1;h<=11;h++) daysafter+=Months[h];//WHY TF DOES <= WORK AND NOT ==????????????????????
	daysafter-=Months[Monthdigit(date2)]+First2digit(date2);

	days=(365*(Yeareturn(date2)-Yeareturn(date1)+1))-daysbefore-daysafter;
	return days;
}

int main(int argc, char *argv[])
{
	int liquid=0,inve=0,salary=0,date1;
    int liquid2=0,inve2=0,salary2=0,date2;
	int daydiff;
	double growth=0;
	//FILE * out = fopen("Bnk.txt","w");
	FILE * in = fopen("Bnk.txt","r");

	//check file exist ||out==NULL
	if (in==NULL) printf("ERROR Unable to open");

	//ask for new numbers
	printf("Enter The numbers liquid/invest/salary/date: \n");
	scanf("%d %d %d %d", &liquid2, &inve2, &salary2, &date2);
	
    //read numbers in file and compare the interest rate
	fscanf(in,"%d %d %d %d",&liquid,&inve,&salary,&date1);
    printf("Change in liq/inv/sal: \n             %d %d %d",liquid2-liquid,inve2-inve,salary2-salary);
	
	//Calculating Date change
	daydiff=FDaydiff(date1,date2);
	printf("\nDifference in days: %4d", daydiff);

	//write numbers to file in the next row
	
	//other cool calculations i might want

	//close all files
	fclose(in);
	//fclose(out);
}