#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define doctors 3

#define queueSize 10

#define stackSize 10



struct appoinmentNode;

struct Doctor{
    char name[30];

    char depertment[50];

    struct appoinmentNode *appoinmentHead;

};

struct Doctor list[doctors];


struct appoinmentNode{
    char patientName[30];
    char time[10];
    struct appoinmentNode *next;


};


char patientQueue[queueSize][30];
int front =-1;
int rear= -1;





char historyStack[stackSize][100];
int top = -1;



void initializeDoctors();
void add_walk_in_patient();
void see_next_patient();
void view_waiting_list();
void book_scheduled_appoinment();
void view_doctor_schedule();
void complete_consultation();
void view_recent_history();


int main(){
    int choice;

    int option = 1;

    initializeDoctors();

    while(option){
        printf("\n**********************************\n");

        printf("    CLINIC MANAGEMENT SYSTEM USING DATA STRUCTURE\n");
        printf("************************************\n");
        printf("      1 -> Add Walk-in Patient \n");
        printf("      2 -> See Next Walk-in Patient \n");
        printf("      3 -> Book Scheduled Appointment \n");
        printf("      4 -> View Doctor's Schedule \n");
        printf("      5 -> Complete a Consultation \n");
        printf("      6 -> View Recent History \n");
        printf("      7 -> EXIT\n");
        printf("------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1: add_walk_in_patient();
            break;
            case 2: see_next_patient();
            break;
            case 3: book_scheduled_appoinment();
            break;
            case 4: view_doctor_schedule();
            break;
            case 5: complete_consultation();
            break;
            case 6: view_recent_history();
            break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }

        printf("\nDo you want to perform another action (1 for yes, 0 for no)?");
        scanf("%d", &option);


    }




return 0;







}



void initializeDoctors(){
    strcpy(list[0].name, "Ashis Rahman");
    strcpy(list[0].depertment, "General");


    list[0].appoinmentHead = NULL;


    strcpy(list[1].name, "Redwan Ahmed");
    strcpy(list[1].depertment, "Dentist");
    list[1].appoinmentHead = NULL;


    strcpy(list[2].name, "Sajib Kundu");
    strcpy(list[2].depertment, "Neuroligist");
    list[2].appoinmentHead = NULL;



}




void add_walk_in_patient(){

    char name[30];
    if(rear == queueSize-1){
        printf("Waiting list is full...\n");
    }
    else if(front== -1){
        front =0;

        printf("Enter patient name of waiting list:");
        scanf("%s",name);
        rear= rear+1;

        strcpy(patientQueue[rear],name);
        printf("%s added to the waiting list\n",name);

    }

    else{printf("Enter patient name of waiting list:");
        scanf("%s",name);
        rear= rear+1;

        strcpy(patientQueue[rear],name);
        printf("%s added to the waiting list\n",name);}




}


void see_next_patient(){

    if(front == -1 || front > rear){
        printf("Waiting list is empty...\n");

    }
    else{
        printf("Next patient to see is: %s\n", patientQueue[front]);
        front = front +1;
    }

}


void book_scheduled_appoinment(){

    int choice;

    struct appoinmentNode *newNode = malloc(sizeof(struct appoinmentNode));
    scanf("%d", &choice);

    if(choice< 0 || choice >= doctors){
        printf("Invalid Doctor selection...\n");
        free(newNode);
        return;
    }


    printf("Enter patient name: ");
    scanf("%s", newNode->patientName);

    printf("Enter the time (Example: 10:30PM");
    scanf("%s", newNode->time);
    newNode->next = NULL;



    printf("Appointment booked for %s with %s at %s.\n", newNode->patientName, list[choice].name, newNode->time);




}



void view_doctor_schedule(){

    int choice;

    printf("Select a Doctor(0:Ashis Rahman, 1:Redwan Ahmed, 2:Sajib Kundu):");

    scanf("%d",&choice);


    if(choice< 0 || choice>= doctors){
        printf("Invalid doctor selection.\n");

        return ;
    }


    struct appoinmentNode *p = list[choice].appoinmentHead;

    printf("\n*****Schedule for %s*****\n",list[choice].name);

    if (p == NULL){
        printf("No appointments scheduled.\n");
    }
    else{
        while ( p != NULL){
            printf("Time: %s, Patient: %s\n",p->time, p->patientName);
            p = p->next;
        }
    }


}



void complete_consultation(){
    char patientName[30],name[30], history[100];

    if(top== (stackSize-1)){
        printf("History is Full\n");

    }else{
        printf("Enter patient name who completed consultation: ");
        scanf("%s", patientName);
        printf("Enter doctor's name: ");
        scanf("%s", name);


        sprintf(history, "Patient: %s, Seen by: %s", patientName, name);

        top = top + 1;
        strcpy(historyStack[top], history);
        printf("Added to consultation history...\n");


    }



}



void view_recent_history(){
    int i;
    if (top == -1){
        printf("History is empty\n");
    }
    else{

        printf("\n*****Recent Consultation History******\n");
    for(i = top; i>=0; i--){
        printf("%s\n", historyStack[i]);
    }

    }

}



