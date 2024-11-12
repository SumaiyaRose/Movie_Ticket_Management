#include<stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 10

int seats[MAX_ROWS][MAX_COLS]; //0 for unbooked, 1 for booked
int show_id = 101; //Assuming a single show for simplicity

void view_show_list()
{
    printf("\tMovie Name: Kung Fu Panda 1 Show Id: %d Time: 13/11/2024 3:00PM\n",show_id);
}

void book_seats()
{
   int row, col;
   printf("Enter the row number (0 to 4): ");
   scanf("%d",&row);
   printf("Enter the column number (0 to 9): ");
   scanf("%d",&col);

   if(row<0 || row>=MAX_ROWS || col<0 || col>=MAX_COLS)
   {
       printf("\tInvalid seat position!\n");
       return;
   }

   if(seats[row][col] == 1)
   {
       printf("\tSeat at (%d, %d) is already booked.\n",row,col);
   }
   else
   {
       seats[row][col] = 1;
       printf("\tSeat at (%d, %d) successfully booked.\n",row,col);
   }

}

void view_available_seats()
{
    printf("\nAvailable seats:\n");
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLS; j++)
        {
            printf("%d ",seats[i][j]); //0 means available, 1 means booked
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    //Initialize all seats to 0 (unbooked)
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLS; j++)
        {
            seats[i][j] = 0;
        }
    }
    while(1)
    {
        printf("\nOptions:\n");
        printf("1 : View all show today\n");
        printf("2 : View available seats\n");
        printf("3 : Book Ticket\n");
        printf("4 : Exit\n");
        printf("Enter Option: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            view_show_list();
            break;
        case 2:
            view_available_seats();
            break;
        case 3:
            book_seats();
            break;
        case 4:
            printf("\n\tExiting the system. Have a nice day!\n");
            return 0;
        default:
            printf("\n\tInvalid Option. Please try again.\n");
        }
    }
    return 0;
}
