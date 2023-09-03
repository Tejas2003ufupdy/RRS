
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[50];
    char gen[1];
    int age;
    int adhr[12];
    
	int train_num;
	int num_of_seats;
}pd;

void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);								
void printticket(char name[],int,int,float);	//print ticket 
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();

/*__________________________________MAIN MENU_________________________________*/
int main()

{
		system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                 BROUGHT YOU BY                |\n");
	printf("\t\t|           |  Poorna, Tejas, Suraj  |          |\n");
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
			reservation();		
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


/*___________________________________________TRAIN DETAILS______________________________________________*/
void viewdetails(void)
{
	system("cls");
	printf("\t\t.......................AVAILABLE TRAINS.......................\n");
	printf("-------------------------------------------------------------------------------------------------");	
	printf("\nTr.No\tName                                   Destinations                    Charges    Time\n");
	printf("-------------------------------------------------------------------------------------------------");
	printf("\n1001\tAhmedabad-Howrah Superfast Express      Howrah to Ahmedabad             Rs.600     4:15pm");
	printf("\n1002\tAllahabad-Jaipur Express                Prayagraj to Jaipur             Rs.450     7:20pm");
	printf("\n1003\tBangalore Rajdhani Express              KSR Jn to Hazrat Nizamuddin     Rs.350     9:00am");
	printf("\n1004\tBhopal-Lucknow Express                  Mysuru to Chennai               Rs.450     8:00am");
	printf("\n1005\tChennai-Salem Express                   Chennai to Salem                Rs.400    11:00am");
	printf("\n1006\tDeccan Express                          Mumbai to Pune                  Rs.250     7:00am");
	printf("\n1007\tEast Bengal Express                     Sealdah to Goalundo ghat        Rs.350     9:30am");
    printf("\n1008\tFaizabad Delhi Express                  Faizabad to Old Delhi           Rs.300     1:00pm");	
    printf("\n1009\tGoa Express                             Vasco-da-gama to Hazrat Jn      Rs.250     4:00pm");
    printf("\n1010\tHampi Express                           Mysuru to Hubballi Jn           Rs.150     3:35pm");                  //10
	printf("\n1011\tKarnataka Express                       New Delhi to Bangalore city     Rs.400     2:50pm");
    printf("\n1012\tMangalore-Yeshwanthpur Express          YPR Jn to Mangalore             Rs.200    12:10am");
	printf("\n1013\tMysore Express                          Mysuru to Chennai               Rs.300     4:15am");
	printf("\n1014\tPuri-Yeshwanthpur GaribRath Express     Puri to Yeshwanthour Jn         Rs.100    12:00pm");
	printf("\n1015\tSheshadri Express                       Bangalore to Tirupati           Rs.150     2:00pm");
	printf("\n1016\tSharavati Express                       Mumbai to Mysore                Rs.200     4:20pm");
	printf("\n1017\tTirupati mysore Jn Passenger            Tirupati to Chamarajanagar      Rs.150     3:45pm");
	printf("\n1018\tTiruvananthapuram Central Express       Guwahati to Trivandrum          Rs.450    12:00pm");
	printf("\n1019\tWodeyar Express                         Mysore to Bangalore             Rs.800     1:30pm");
	printf("\n1020\tYeshwanthpur-Howrah Superfast Express   Yeshwanthpur to Howrah          Rs.450     2:50am");
	
    
}

/*_______________________________________________________RESERVATION_______________________________________________________*/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1020)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
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

/*_______________________________CHARGES_______________________________*/

float charge(int train_num,int num_of_seats)
{
	if (train_num==1001)  //1
	{
		return(600.0*num_of_seats);
	}
	if (train_num==1002)  //2
	{
		return(450.0*num_of_seats);
	}
	if (train_num==1003)  //3
	{
		return(350.0*num_of_seats);
	}
	if (train_num==1004)  //4
	{
		return(450.0*num_of_seats);
	}
	if (train_num==1005)  //5
	{
		return(400.0*num_of_seats);
	}
	if (train_num==1006)  //6
	{
		return(250.0*num_of_seats);
	}
	if (train_num==1007)  //7
	{
		return(350.0*num_of_seats);
	}
	if (train_num==1008)  //8
	{
		return(300.0*num_of_seats);
	}
	if (train_num==1009)  //9
	{
		return(250.0*num_of_seats);
	}
	if (train_num==1010)  //10
	{
		return(150.0*num_of_seats);
	}
	if (train_num==1011)  //11
	{
		return(400.0*num_of_seats);
	}
	if (train_num==1012)  //12
	{
		return(200.0*num_of_seats);
	}                                           //here

	if (train_num==1013)  //13
	{
		return(300.0*num_of_seats);
	}
	if (train_num==1014)  //14
	{
		return(100.0*num_of_seats);
	}
	if (train_num==1015)  //15
	{
		return(150.0*num_of_seats);
	}
	if (train_num==1016)  //16
	{
		return(200.0*num_of_seats);
	}
	if (train_num==1017)  //17
	{
		return(150.0*num_of_seats);
	}
	if (train_num==1018)  //18
	{
		return(450.0*num_of_seats);
	}
	if (train_num==1019)  //19
	{
		return(800.0*num_of_seats);
	}
	if (train_num==1020)  //20
	{
		return(450.0*num_of_seats);
	}
}

/*_______________________PRINT TICKET_______________________*/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*____________________________SPECIFIC TRAIN____________________________*/

void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tAhmedabad-Howrah Superfast Express");
		printf("\nDestination:\t\tHowrah to Ahmedabad");
		printf("\nDeparture:\t\t4:15pm");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tAllahabad-Jaipur Express ");
		printf("\nDestination:\t\tPrayagraj to Jaipur");
		printf("\nDeparture:\t\t7:20pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tBangalore Rajdhani Express ");
		printf("\nDestination:\t\tKSR Jn to Hazrat Nizamuddin ");
		printf("\nDeparture:\t\t9:00am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tBhopal-Lucknow Express");
		printf("\nDestination:\t\tMysuru to Chennai");
		printf("\nDeparture:\t\t8:00am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tChennai-Salem Express ");
		printf("\nDestination:\t\tChennai to Salem");
		printf("\nDeparture:\t\t11:00am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tDeccan Express");
		printf("\nDestination:\t\tMumbai to Pune");
		printf("\nDeparture:\t\t7:00am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tEast Bengal Express");
		printf("\nDestination:\t\tSealdah to Goalundo ghat");
		printf("\nDeparture:\t\t9:30am ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tFaizabad Delhi Express");
		printf("\nDestination:\t\tFaizabad to Old Delhi");
		printf("\nDeparture:\t\t1:00pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tGoa Express");
		printf("\nDestination:\t\tVasco-da-gama to Hazrat Jn");
		printf("\nDeparture:\t\t4:00pm");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tHampi Express");
		printf("\nDestination:\t\tMysuru to Hubballi Jn");
		printf("\nDeparture:\t\t3:35pm ");                        //10
	}
		if (train_num==1011)
	{
		printf("\ntrain:\t\t\tKarnataka Express ");
		printf("\nDestination:\t\tNew Delhi to Bangalore city");
		printf("\nDeparture:\t\t2:50pm ");
	}
		if (train_num==1012)
	{
		printf("\ntrain:\t\t\tMangalore-Yeshwanthpur Express ");
		printf("\nDestination:\t\tYPR Jn to Mangalore");
		printf("\nDeparture:\t\t12:10am ");
	}
		if (train_num==1013)
	{
		printf("\ntrain:\t\t\tMysore Express");
		printf("\nDestination:\t\tMysuru to Chennai");
		printf("\nDeparture:\t\t4:15am ");
	}
		if (train_num==1014)
	{
		printf("\ntrain:\t\t\tPuri-Yeshwanthpur GaribRath Express ");
		printf("\nDestination:\t\tPuri to Yeshwanthour J");
		printf("\nDeparture:\t\t12:00pm ");
	}
		if (train_num==1015)
	{
		printf("\ntrain:\t\t\tSheshadri Express");
		printf("\nDestination:\t\tBangalore to Tirupati");
		printf("\nDeparture:\t\t2:00pm ");
	}
		if (train_num==1016)
	{
		printf("\ntrain:\t\t\tSharavati Express");
		printf("\nDestination:\t\tMumbai to Mysore");
		printf("\nDeparture:\t\t4:20pm ");
	}
		if (train_num==1017)
	{
		printf("\ntrain:\t\t\tTirupati mysore Jn Passenger");
		printf("\nDestination:\t\tTirupati to Chamarajanagar");
		printf("\nDeparture:\t\t3:45pm ");
	}
		if (train_num==1018)
	{
		printf("\ntrain:\t\t\tTiruvananthapuram Central Express");
		printf("\nDestination:\t\tGuwahati to Trivandrum");
		printf("\nDeparture:\t\t12:00pm ");
	}
		if (train_num==1019)
	{
		printf("\ntrain:\t\t\tWodeyar Express");
		printf("\nDestination:\t\tMysore to Bangalore");
		printf("\nDeparture:\t\t1:30pm ");
	}
		if (train_num==1020)
	{
		printf("\ntrain:\t\t\tYeshwanthpur-Howrah Superfast Express");
		printf("\nDestination:\t\tYeshwanthpur to Howrah");
		printf("\nDeparture:\t\t2:50am ");
	}
}

/*__________________LOGIN PAGE____________________*/

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
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
		a++;
		
		getch();//holds the screen
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

/*___________________________CANCLE TICKET___________________________*/

void cancel(void)  
{
	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nCancelled");  
		getch();

}