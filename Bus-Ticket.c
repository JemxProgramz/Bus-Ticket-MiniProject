
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_PASS 10

/* ================= COLOR ================= */
void color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/* ================= HEADER ================= */
void header(char title[]){
    system("cls");
    color(11);
    printf("\n=============================================================\n");
    printf("                     %s\n",title);
    printf("=============================================================\n");
    color(7);
}

/* ================= WELCOME ================= */
void welcomeScreen(){
    system("cls");
    color(14);
    char msg[]="WELCOME TO SMART BUS RESERVATION SYSTEM";
    printf("\n\n\t\t");
    for(int i=0;msg[i]!='\0';i++){
        printf("%c",msg[i]);
        Sleep(40);
    }
    printf("\n\n\t\tLoading");
    for(int i=0;i<5;i++){
        printf(".");
        Sleep(400);
    }
    Sleep(800);
}

/* ================= STRUCTURES ================= */
struct Bus{
    int busNo;
    char source[50];
    char destination[50];
    int totalSeats;
    float fare;
};

struct Ticket{
    int ticketID;
    int busNo;
    int seatNo;
    char name[50];
    int age;
    char category[10];
    char phone[20];
    char username[50];
    char travelDate[20];
    char travelTime[10];
    float fare;
};

struct User{
    char username[50];
    char password[50];
};

char currentUser[50];

/* ================= PASSWORD MASK ================= */
void inputPassword(char *pass){
    int i=0; char ch;
    while(1){
        ch=getch();
        if(ch==13){ pass[i]='\0'; break; }
        else if(ch==8 && i>0){ i--; printf("\b \b"); }
        else{ pass[i++]=ch; printf("*"); }
    }
}

/* ================= REGISTER ================= */
void registerUser(){
    struct User u;
    FILE *fp=fopen("users.dat","ab");
    header("USER REGISTRATION");

    printf("Username : ");
    scanf("%s",u.username);

    printf("Password : ");
    inputPassword(u.password);

    fwrite(&u,sizeof(u),1,fp);
    fclose(fp);

    color(10); printf("\nRegistration Successful!\n"); color(7);
    system("pause");
}

/* ================= USER LOGIN ================= */
int userLogin(){
    struct User u;
    char username[50],password[50];
    int found=0;

    FILE *fp=fopen("users.dat","rb");
    if(fp==NULL){ printf("No users registered!\n"); system("pause"); return 0; }

    header("USER LOGIN");

    printf("Username : ");
    scanf("%s",username);

    printf("Password : ");
    inputPassword(password);

    while(fread(&u,sizeof(u),1,fp)){
        if(strcmp(u.username,username)==0 &&
           strcmp(u.password,password)==0){
            found=1;
            strcpy(currentUser,username);
            break;
        }
    }
    fclose(fp);

    if(found){
        color(10); printf("\nLogin Successful!\n"); color(7);
        Sleep(800);
        return 1;
    }

    color(12); printf("\nInvalid Credentials!\n"); color(7);
    Sleep(800);
    return 0;
}

/* ================= ADMIN LOGIN ================= */
int adminLogin(){
    char u[20],p[20];
    header("ADMIN LOGIN");

    printf("Username : ");
    scanf("%s",u);

    printf("Password : ");
    inputPassword(p);

    if(strcmp(u,"admin")==0 && strcmp(p,"1234")==0){
        color(10); printf("\nAdmin Login Successful!\n"); color(7);
        Sleep(800);
        return 1;
    }

    color(12); printf("\nInvalid Admin Credentials!\n"); color(7);
    Sleep(800);
    return 0;
}

/* ================= ADD BUS ================= */
void addBus(){
    struct Bus b;
    FILE *fp=fopen("buses.dat","ab");

    header("ADD BUS");

    printf("Bus No        : "); scanf("%d",&b.busNo);
    printf("Source        : "); scanf("%s",b.source);
    printf("Destination   : "); scanf("%s",b.destination);
    printf("Total Seats   : "); scanf("%d",&b.totalSeats);
    printf("Adult Fare    : "); scanf("%f",&b.fare);

    fwrite(&b,sizeof(b),1,fp);
    fclose(fp);

    color(10); printf("\nBus Added Successfully!\n"); color(7);
    system("pause");
}

/* ================= VIEW BUSES ================= */
void viewBuses(){
    struct Bus b;
    FILE *fp=fopen("buses.dat","rb");
    header("AVAILABLE BUSES");

    if(fp==NULL){ printf("No buses available!\n"); system("pause"); return; }

    while(fread(&b,sizeof(b),1,fp)){
        printf("Bus:%d | %s -> %s | Seats:%d | Fare: %.2f\n",
               b.busNo,b.source,b.destination,b.totalSeats,b.fare);
    }
    fclose(fp);
    system("pause");
}

/* ================= SEARCH BUS ================= */
void searchBus(){
    struct Bus b;
    char src[50],dest[50];
    int found=0;

    header("SEARCH BUS");

    printf("Enter Source      : "); scanf("%s",src);
    printf("Enter Destination : "); scanf("%s",dest);

    FILE *fp=fopen("buses.dat","rb");
    if(fp==NULL){ printf("No buses!\n"); system("pause"); return; }

    while(fread(&b,sizeof(b),1,fp)){
        if(strcmp(b.source,src)==0 && strcmp(b.destination,dest)==0){
            printf("Bus:%d | Seats:%d | Fare: %.2f\n",
                   b.busNo,b.totalSeats,b.fare);
            found=1;
        }
    }
    fclose(fp);

    if(!found) printf("No matching buses found!\n");

    system("pause");
}

/* ================= VIEW ALL BOOKINGS ================= */
void viewAllBookings(){
    struct Ticket t;
    FILE *fp=fopen("tickets.dat","rb");
    header("ALL BOOKINGS");

    if(fp==NULL){ printf("No bookings yet!\n"); system("pause"); return; }

    while(fread(&t,sizeof(t),1,fp)){
        printf("TicketID:%d | Bus:%d | Seat:%d | %s | %s | %s\n",
               t.ticketID,t.busNo,t.seatNo,
               t.name,t.username,t.travelDate);
    }
    fclose(fp);
    system("pause");
}

/* ================= CHECK BOOKING EXISTS ================= */
int hasBooking(int busNo){
    struct Ticket t;
    FILE *fp=fopen("tickets.dat","rb");
    if(fp==NULL) return 0;

    while(fread(&t,sizeof(t),1,fp)){
        if(t.busNo==busNo){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

/* ================= SEAT MAP ================= */
// fills booked array (1..totalSeats) with 1 if booked for same bus and date
void getBookedSeats(int busNo, const char *date, int totalSeats, int *booked){
    for(int i=0;i<=totalSeats;i++) booked[i]=0;
    struct Ticket t;
    FILE *fp=fopen("tickets.dat","rb");
    if(fp==NULL) return;
    while(fread(&t,sizeof(t),1,fp)){
        if(t.busNo==busNo && strcmp(t.travelDate,date)==0){
            if(t.seatNo>=1 && t.seatNo<=totalSeats) booked[t.seatNo]=1;
        }
    }
    fclose(fp);
}

void showSeatLayout(int busNo, int totalSeats, const char *date, int *booked){
    header("SEAT LAYOUT");
    printf("Bus: %d | Date: %s\n\n", busNo, date);

    int cols = 4; // seats per row
    for(int s=1;s<=totalSeats;s++){
        if((s-1) % cols == 0 && s!=1) printf("\n");

        if(booked[s]){
            color(12); // red for booked
            printf("[x]");
            color(7);
        } else {
            color(10); // green for available
            printf("[%d]", s);
            color(7);
        }

        if(s % cols) printf(" ");
    }
    printf("\n\n");
}

/* ================= DELETE BUS ================= */
void deleteBus(){
    int busNo,found=0;
    struct Bus b;

    header("DELETE BUS");

    printf("Enter Bus No to Delete : ");
    scanf("%d",&busNo);

    if(hasBooking(busNo)){
        color(12);
        printf("Cannot delete! Tickets exist for this bus.\n");
        color(7);
        system("pause");
        return;
    }

    FILE *fp=fopen("buses.dat","rb");
    FILE *temp=fopen("temp.dat","wb");

    while(fread(&b,sizeof(b),1,fp)){
        if(b.busNo!=busNo)
            fwrite(&b,sizeof(b),1,temp);
        else
            found=1;
    }

    fclose(fp);
    fclose(temp);

    remove("buses.dat");
    rename("temp.dat","buses.dat");

    if(found){
        color(10); printf("Bus Deleted Successfully!\n");
    }else{
        color(12); printf("Bus Not Found!\n");
    }
    color(7);
    system("pause");
}

/* ================= PAYMENT ================= */
int processPayment(float amount){
    int ch;
    printf("\nTotal Amount: %.2f\n",amount);
    printf("1. Card\n2. UPI\n3. Cash\n");
    printf("Enter Choice : ");
    scanf("%d",&ch);

    Sleep(1000);

    if(ch>=1 && ch<=3){
        color(10); printf("Payment Successful!\n"); color(7);
        return 1;
    }
    color(12); printf("Payment Failed!\n"); color(7);
    return 0;
}

/* ================= BOOK TICKET ================= */
void bookTicket(){
    struct Bus b;
    int busNo,found=0,passengers;
    float total=0;

    header("BOOK TICKET");

    printf("Enter Bus No : ");
    scanf("%d",&busNo);

    FILE *fp=fopen("buses.dat","rb");
    if(fp==NULL){ printf("No buses!\n"); system("pause"); return; }

    while(fread(&b,sizeof(b),1,fp)){
        if(b.busNo==busNo){ found=1; break; }
    }
    fclose(fp);

    if(!found){ printf("Bus Not Found!\n"); system("pause"); return; }

    char date[20],timeStr[10];
    printf("Travel Date (DD/MM/YYYY) : "); scanf("%s",date);
    printf("Travel Time (HH:MM)      : "); scanf("%s",timeStr);

    printf("Number of Passengers (Max 10) : ");
    scanf("%d",&passengers);

    if(passengers<1 || passengers>MAX_PASS){
        printf("Invalid number!\n");
        system("pause");
        return;
    }

    struct Ticket tickets[MAX_PASS];

    int *booked = (int*)calloc(b.totalSeats+1, sizeof(int));
    if(!booked){ printf("Memory error\n"); system("pause"); return; }

    getBookedSeats(busNo, date, b.totalSeats, booked);

    for(int i=0;i<passengers;i++){
        // show seat map and prompt until an available seat chosen
        int chosen=0;
        while(!chosen){
            header("BOOK TICKET - Passenger Input");
            showSeatLayout(busNo, b.totalSeats, date, booked);
            printf("Passenger %d of %d\n", i+1, passengers);
            printf("Seat No : "); scanf("%d",&tickets[i].seatNo);
            if(tickets[i].seatNo < 1 || tickets[i].seatNo > b.totalSeats){
                printf("Invalid seat number!\n"); Sleep(800); continue;
            }
            if(booked[tickets[i].seatNo]){
                color(12); printf("Seat %d already booked!\n", tickets[i].seatNo); color(7);
                Sleep(800); continue;
            }
            // also ensure same user doesn't pick same seat twice in this booking
            booked[tickets[i].seatNo]=1; // reserve locally
            chosen=1;
        }

        printf("Name    : "); scanf("%s",tickets[i].name);
        printf("Age     : "); scanf("%d",&tickets[i].age);
        printf("Phone   : "); scanf("%s",tickets[i].phone);

        if(tickets[i].age < 3){
            strcpy(tickets[i].category,"Infant");
            tickets[i].fare = 0.0f; // infants travel free
        } else if(tickets[i].age>=3 && tickets[i].age<=12){
            strcpy(tickets[i].category,"Child");
            tickets[i].fare = b.fare * 0.5f;
        } else {
            strcpy(tickets[i].category,"Adult");
            tickets[i].fare = b.fare;
        }

        tickets[i].busNo=busNo;
        tickets[i].ticketID=rand()%90000+10000;
        strcpy(tickets[i].username,currentUser);
        strcpy(tickets[i].travelDate,date);
        strcpy(tickets[i].travelTime,timeStr);

        total+=tickets[i].fare;

        header("BOOK TICKET");
        color(14); // highlight collected info
        printf("Collected %d/%d passenger(s)\n", i+1, passengers);
        color(11);
        printf("Name: %s | Seat: %d | Fare: %.2f\n", tickets[i].name, tickets[i].seatNo, tickets[i].fare);
        color(7);
        Sleep(700);
    }

    header("PAYMENT");
    printf("Processing payment of: %.2f\n", total);
    Sleep(800);

    if(processPayment(total)){
        FILE *ft=fopen("tickets.dat","ab");
        for(int i=0;i<passengers;i++){
            header("BOOKING PROGRESS");
            color(10);
            printf("Processing passenger %d/%d\n", i+1, passengers);
            printf("TicketID:%d | Name:%s | Seat:%d | Fare:%.2f\n",
                   tickets[i].ticketID, tickets[i].name, tickets[i].seatNo, tickets[i].fare);
            color(7);
            fwrite(&tickets[i],sizeof(struct Ticket),1,ft);
            Sleep(700);
        }
        fclose(ft);

        header("BOOK TICKET");
        color(10); printf("Booking Confirmed!\n"); color(7);
    }

    free(booked);

    system("pause");
}

/* ================= VIEW MY TICKETS ================= */
void viewMyTickets(){
    struct Ticket t;
    FILE *fp=fopen("tickets.dat","rb");

    header("MY TICKETS");

    if(fp==NULL){ printf("No bookings found!\n"); system("pause"); return; }

    int found=0;
    while(fread(&t,sizeof(t),1,fp)){
        if(strcmp(t.username,currentUser)==0){
            found=1;
            printf("TicketID:%d | Bus:%d | Seat:%d | %s | %.2f\n",
                   t.ticketID,t.busNo,t.seatNo,
                   t.travelDate,t.fare);
        }
    }

    if(!found) printf("No bookings found!\n");

    fclose(fp);
    system("pause");
}

/* ================= CANCEL TICKET ================= */
void cancelTicket(){
    int id,found=0;
    struct Ticket t;

    header("CANCEL TICKET");
    printf("Enter Ticket ID : ");
    scanf("%d",&id);

    FILE *fp=fopen("tickets.dat","rb");
    FILE *temp=fopen("temp.dat","wb");

    while(fread(&t,sizeof(t),1,fp)){
        if(t.ticketID==id && strcmp(t.username,currentUser)==0){
            found=1;
            printf("Refund Amount (75%%) : %.2f\n",t.fare*0.75);
        }else{
            fwrite(&t,sizeof(t),1,temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("tickets.dat");
    rename("temp.dat","tickets.dat");

    if(found) printf("Ticket Cancelled Successfully!\n");
    else printf("Ticket Not Found!\n");

    system("pause");
}

/* ================= ADMIN PANEL ================= */
void adminPanel(){
    int ch;
    while(1){
        header("ADMIN PANEL");
        printf("1. Add Bus\n");
        printf("2. View All Buses\n");
        printf("3. Delete Bus\n");
        printf("4. View All Bookings\n");
        printf("5. Logout\n");
        printf("\nEnter Choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1: addBus(); break;
            case 2: viewBuses(); break;
            case 3: deleteBus(); break;
            case 4: viewAllBookings(); break;
            case 5: return;
            default: printf("Invalid Choice!\n"); system("pause");
        }
    }
}

/* ================= USER PANEL ================= */
void userPanel(){
    int ch;
    while(1){
        header("USER PANEL");
        printf("1. View Buses\n");
        printf("2. Search Bus\n");
        printf("3. Book Ticket\n");
        printf("4. View My Tickets\n");
        printf("5. Cancel Ticket\n");
        printf("6. Logout\n");
        printf("\nEnter Choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1: viewBuses(); break;
            case 2: searchBus(); break;
            case 3: bookTicket(); break;
            case 4: viewMyTickets(); break;
            case 5: cancelTicket(); break;
            case 6: return;
            default: printf("Invalid Choice!\n"); system("pause");
        }
    }
}

/* ================= MAIN ================= */
int main(){
    srand(time(0));
    welcomeScreen();

    int choice;
    while(1){
        header("SMART BUS RESERVATION SYSTEM");

        printf("1. Admin Login\n");
        printf("2. Register User\n");
        printf("3. User Login\n");
        printf("4. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: if(adminLogin()) adminPanel(); break;
            case 2: registerUser(); break;
            case 3: if(userLogin()) userPanel(); break;
            case 4: exit(0);
            default: printf("Invalid Choice!\n"); system("pause");
        }
    }
}

