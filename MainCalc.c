#include <stdio.h>
//program to write to a txt file about my current bank, particularly, liquid, Investments,growth,salary.

//function to get first 2 digits
int First2digit(int Num)
{
    while(Num >= 100) Num/=10;
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
	int days;
	for(int h=Monthdigit(date1);h<=Monthdigit(date2);h++) days+=Months[h-1];
	return days;
}

int main(int argc, char *argv[])
{
	int liquid=0,inve=0,salary=0,date;
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
	fscanf(in,"%d %d %d %d",&liquid,&inve,&salary,&date);
    printf("Change in liq/inv/sal: \n             %d %d %d",liquid2-liquid,inve2-inve,salary2-salary);
    
	//Calculating Date change
	daydiff=FDaydiff(date,date2);
	printf("\nDifference in days: %4d", daydiff);

	//make days since update!

	//write numbers to file in the next row
	
	//other cool calculations i might want
	fclose(in);
}