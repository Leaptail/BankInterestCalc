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

int main(int argc, char *argv[])
{
	int liquid=0,inve=0,salary=0, date;
    int liquid2=0,inve2=0,salary2=0,date2;
	double growth=0;
	FILE * out = fopen("Bnk.txt","w");
	FILE * in = fopen("Bnk.txt","r");
	if (in==NULL||out==NULL) printf("ERROR Unable to open");
	printf("Enter The numbers liquid/invest/salary/date: \n");
	scanf("%d %d %d %d", &liquid, &inve, &salary, &date);
	
        //read numbers in file and compare the interest rate
	fscanf(in,"%d %d %d %d",&liquid2,&inve2,&salary2,&date2);
    printf("Change in liq/inv/sal: \n             %d %d %d",liquid2-liquid,inve2-inve,salary2-salary);
    //now we need to take the first 2 numbers of the date (ddmmyyyy)


	//write numbers to file in the next row
	
	//other cool calculations i might want
}