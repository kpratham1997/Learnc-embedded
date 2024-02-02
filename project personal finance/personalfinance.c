#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50
#define MAX_TRANSACTIONS 100

void displayValues();
void inputTransaction();

int numTransactions = 0;
float transactions[MAX_TRANSACTIONS];
char types[MAX_TRANSACTIONS];

int main(){

  
    char choice;
    
    
   
    while (choice != '3'){
        /* code */
    
    
    printf("1. Input Transaction \n");
    printf("2. Display Summary \n");
    printf("3. Exit \n");
    printf("Enter your choice :- ");
    
    
    choice=getchar();
    
    while(getchar()!='\n'){
        
    }



        switch(choice){
            case '1':
                inputTransaction();
                break;
            case '2':
                displayValues();
                break;
            case '3':
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid choice, try again ! \n");

        }

    }
     
    

}

void inputTransaction(){
    char type;
    int i=0;
    char amountstr[MAX_LENGTH];

      if (numTransactions == MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
     }


    printf("Enter transaction(I for Income, E for expenses)");
    type=getchar();
    while(getchar()!='\n'){

    }

    printf("Enter transaction amount : ");
        while(i< MAX_LENGTH-1){
            amountstr[i]=getchar();
            if(amountstr[i]=='\n'){
                amountstr[i]='\0';
                break;
            }
            i++;
        }


    transactions[numTransactions] = atof(amountstr); // Convert string to float
    types[numTransactions] = type;
    numTransactions++;

}

void displayValues(){

    float totalIncome,totalExpenses=0;

    for(int i=0; i<numTransactions;i++){
        if(types[i]=='I'){

            totalIncome = totalIncome + transactions[i];

        }else{
            totalExpenses=totalExpenses+transactions[i];


        }


    }

    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Budget Remaining: %.2f\n", totalIncome - totalExpenses);




}