
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

/*******************************************GLOBAL VARIABLES**********************************************************/

typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
	char seat_class[40];
	int seat_classno;
	int Age;
}pd;




/*******************************************FUNCTION PROTOTYPE**********************************************************/

void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);                               //cancel ticket
void printticket(char name[],int,int,float,int,int);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int,int);							//charge automatically w.r.t number of seats and train
void login();                                        //login function
void loadingBar();                                  //loading bar


int main()
{
	system("cls");
	loadingBar();
	system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RES. SYSTEM            |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|              |      GROUP 8   |               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

//The function is yet not completed, need more details to be added!
//timings of the trains are still missing

void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\t\t   Charges-Seat Class\t\t\tTime\n");
	printf("-----------------------------------------------------------------------------------------------------------------------");
	printf("\n1001\tNAVJEEVAN Express     \tChennai to Ahmedabad   \tRs.1200-AC1  Rs.800-AC2   Rs.500-AC3\t\t9am");
	printf("\n1002\tDURANTO Express       \tNagpur To Mumbai       \tRs.1300-AC1  Rs.1000-AC2  Rs.600-AC3\t\t12pm");
	printf("\n1003\tRAJDHANI Express      \tDelhi To Mumbai        \tRs.900-AC1   Rs.600-AC2   Rs.450-AC3\t\t8am");
	printf("\n1004\tAzad Hind Express     \tKolkatta To Pune       \tRs.950-AC1   Rs.650-AC2   Rs.450-AC3\t\t11am");
	printf("\n1005\tHUTAATMA Express      \tPune To Bhusawal       \tRs.1100-AC1  Rs.700-AC2   Rs.400-AC3\t\t7am");
	printf("\n1006\tCSTM GORK Express     \tCSTM To Gorakhpur      \tRs.1100-AC1  Rs.800-AC2   Rs.450-AC3\t\t9.30am");
    printf("\n1007\tMAHARASHTRA Express   \tGondia To Kolhapur     \tRs.1000-AC1  Rs.600-AC2   Rs.350-AC3\t\t1pm");
    printf("\n1008\tGARIBRATH Express     \tMumbai To Jabalpur     \tRs.900-AC1   Rs.700-AC2   Rs.350-AC3\t\t4pm");
    printf("\n1009\tSAINAGAR KALKA Express\tShirdi To Kalka        \tRs.1600-AC1  Rs.1200-AC2  Rs.700-AC3\t\t3.35pm");
    printf("\n1010\tAHMEDABAD PURI Express\tAhmedabad To Puri      \tRs.1500-AC1  Rs.900-AC2   Rs.600-AC3\t\t4.15pm");

}

/*********************************************RESERVATION()*************************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name: ");
	fflush(stdin);
	gets(passdetails.name);

	printf("\nEnter Your Age: ");
	fflush(stdin);
	scanf("%d",&passdetails.Age);
	//error here have to take input of the name
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	
	start3:
	printf("\nEnter the type of seat from AC1 AC2 and AC3 tier seat  ");
    fflush(stdin);
	gets(passdetails.seat_class);
	if(strcmp(passdetails.seat_class,"AC1")==0)
    passdetails.seat_classno=1;
	else if(strcmp(passdetails.seat_class,"AC2")==0)
    passdetails.seat_classno=2;
	else if(strcmp(passdetails.seat_class,"AC3")==0)
    passdetails.seat_classno=3;
	else 
	{
	printf("\nType of seat entered is not available.");
	goto start3;
	}

	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats,passdetails.seat_classno);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges,passdetails.seat_classno,passdetails.Age);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats,int seat_typeno)
{
		if (train_num==1001)
	{
		if(seat_typeno==1)
		return (1200.0*num_of_seats);
		if(seat_typeno==2)
		return(800.0*num_of_seats);
		if(seat_typeno==3)
		return(500.0*num_of_seats);
	}
	if (train_num==1002)
	{
		if(seat_typeno==1)
		return (1300.0*num_of_seats);
		if(seat_typeno==2)
		return(1000.0*num_of_seats);
		if(seat_typeno==3)
		return(600.0*num_of_seats);
	}
	if (train_num==1003)
	{
		if(seat_typeno==1)
		return (900.0*num_of_seats);
		if(seat_typeno==2)
		return(600.0*num_of_seats);
		if(seat_typeno==3)
		return(450.0*num_of_seats);
	}
	if (train_num==1004)
	{
		if(seat_typeno==1)
		return (950.0*num_of_seats);
		if(seat_typeno==2)
		return(650.0*num_of_seats);
		if(seat_typeno==3)
		return(450.0*num_of_seats);
	}
	if (train_num==1005)
	{
		if(seat_typeno==1)
		return (1100.0*num_of_seats);
		if(seat_typeno==2)
		return(700.0*num_of_seats);
		if(seat_typeno==3)
		return(400.0*num_of_seats);
	}
	if (train_num==1006)
	{
		if(seat_typeno==1)
		return (1150.0*num_of_seats);
		if(seat_typeno==2)
		return(800.0*num_of_seats);
		if(seat_typeno==3)
		return(450.0*num_of_seats);
	}
	if (train_num==1007)
	{
		if(seat_typeno==1)
		return (1000.0*num_of_seats);
		if(seat_typeno==2)
		return(600.0*num_of_seats);
		if(seat_typeno==3)
		return(350.0*num_of_seats);
	}
	if (train_num==1008)
	{
		if(seat_typeno==1)
		return (900.0*num_of_seats);
		if(seat_typeno==2)
		return(700.0*num_of_seats);
		if(seat_typeno==3)
		return(350.0*num_of_seats);
	}
	if (train_num==1009)
	{
		if(seat_typeno==1)
		return (1600.0*num_of_seats);
		if(seat_typeno==2)
		return(1200.0*num_of_seats);
		if(seat_typeno==3)
		return(700.0*num_of_seats);
	}
	if (train_num==1010)
	{
		if(seat_typeno==1)
		return (1500.0*num_of_seats);
		if(seat_typeno==2)
		return(900.0*num_of_seats);
		if(seat_typeno==3)
		return(600.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges,int seat_classtype,int age)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nAge:\t\t\t%d",age);
    if(seat_classtype==1)
	printf("\nSeat type:\t\tAC First tier Seat");
	if(seat_classtype==2)
	printf("\nSeat type:\t\tAC two tier Seat");
	if(seat_classtype==3)
	printf("\nSeat type:\t\tAC three tier Seat");
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{

	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tNAVJEEVAN Express");
		printf("\nDestination:\t\tChennai to Ahmedabad");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tDURANTO Express");
		printf("\nDestination:\t\tNagpur to Mumbai");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tRAJDHANI Express");
		printf("\nDestination:\t\tDelhi to Mumbai");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tAzad Hind Express");
		printf("\nDestination:\t\tKolkatta to Pune");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tHUTAATMA Express");
		printf("\nDestination:\t\tPune to Bhusawal");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tCSTM GORAKHPUR Express");
		printf("\nDestination:\t\tCSTM to Gorakhpur");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tGONDIA MAHARASHTA Express");
		printf("\nDestination:\t\tGondia to Kolhapur");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tGARIBRATH Express");
		printf("\n Destination:\t\tMumbai to Jabalpur");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tSAINAGAR KALKA Express");
		printf("\nDestination:\t\tShirdi to Kalka");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tAHMEDABAD PURI Express");
		printf("\nDestination:\t\tAhmedabad to Puri");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"admin")==0 && strcmp(pword,"password")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

void cancel(void)  
{

	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");

		scanf("%i",&trainnum);
		printf("\n\nCancelled");
		getch();
}
void loadingBar()
{
	// A - Green text
	system("color A");


	char a = 177, b = 219;

	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\t"
		"Loading...\n\n");
	printf("\t\t\t\t\t");

	for (int i = 0; i < 20; i++)
		printf("%c", a);

	// Set the cursor again starting
	printf("\r");
	printf("\t\t\t\t\t");

	for (int i = 0; i < 20; i++) {
		printf("%c", b);

		
		Sleep(250);
	}
}
