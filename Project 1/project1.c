#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
void creatematrix(int arr[4][4])
{
    int n=15;
    int num[n];
    int i,j;
    for(i=0;i<15;i++)
    {
        num[i]=i+1;  //storing 1-15 numbers in array
    }
    srand(time(NULL));    //for random number generation
    int lastindex=n-1,index;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(lastindex>=0)
            {
                index=rand()%(lastindex+1);
                arr[i][j]=num[index];
                num[index]=num[lastindex--];
            }
        }
        arr[i-1][j-1]!=0;
    }
}
void showmatrix(int arr[4][4])  //to show matrix in prescribed pattern
{
    int i,j;
    printf("--------------------\n");
    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
            {
                printf("%-2d | ",arr[i][j]);
            }
            else
            {
                printf("   | ");
            }
        }
        printf("\n");
    }
    printf("--------------------\n");
}
int readEnteredKey()  //to read entered key
{
        char c;
            c=_getch();
            if(c==-32)
            c=_getch();

    return c;
}
void GameRule(int arr[][4])
{
        printf("           -: RULES OF THIS GAME :-\n\n");
    printf("1. You can move only 1 step at a time with the arrow key.\n");
    printf("  Move Up   : by Up Arrow key.\n  Move Down : by Down Arrow Key.\n  Move Right: by Right Arrow Key.\n  Move Left : by Left Arrow Key.\n");
    printf("\n2. You can move numbers at an empty position only.\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n");
    printf("\n4. Winning Situation :\n");
    printf("\nNumber in a 4*4 matrix should be in order from 1 to 15.\n");
    printf("        ---------------------");
    printf("\n        | 1  | 2  | 3  | 4  |\n        | 5  | 6  | 7  | 8  |\n");
    printf("        | 9  | 10 | 11 | 12 |\n        | 13 | 14 | 15 |    |\n");
    printf("        ---------------------");
    printf("\n5. You can exit the game any time by pressing 'E' or 'e'\n");
    printf("\n  So, try to win in minimum number of move.\n\n\n         Happy Game,Good luck.\n");
    printf("\nEnter any key to start......\n\n");
    int x=readEnteredKey();
}
int winner(int arr[4][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++,k++)
        {
            if(arr[i][j] != k && k !=16)
            {
                break;
            }
        }
    }
    if(j<4)
        return 0;
    return 1;
}
void swap(int *x,int *y) //swapping of values
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf("");
}

int shiftUp(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==3)                 // shifting not possible
        return 0;
        swap(&arr[i][j],&arr[i+1][j]);
        return 1;               // shift up success
}

int shiftDown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==0)                 // shifting not possible
        return 0;
         swap(&arr[i][j],&arr[i-1][j]);    // swap numbers

        return 1;               // shift up success
}

int shiftRight(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==0)                 // shifting not possible
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;               // shift up success
}

int shiftLeft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)                 // shifting not possible
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;               // shift up success
}
int main()
{
    int arr[4][4];
    char n[20];
    int Maxtry=220;
    printf("\n\n\n\nPLAYER NAME:");
    scanf("%s",&n);
    system("cls");
    while(1)
    {
        creatematrix(arr);  // calling function to create matrix

        GameRule(arr);  //calling function for game rule

        while(!winner(arr))    //checking for winning situation
        {
            system("cls");
            if(!Maxtry)    //for remaining zero move
                break;

                printf("\n\n  Player Name:  %s , Move Remaining: %d\n\n",n,Maxtry);

                showmatrix(arr);  // show matrix

                int key=readEnteredKey(); //this will return ascii code of user entered key

                switch(key)  //mapping
                {
                case 101: // ascii of E

                case 69:  //ascii of e
                    printf("\a\a\a\a\a\a\n        Thanks for Playing !\n\a");
                    printf("\nHit 'Enter' to exit the game \n");
                    key=readEnteredKey();
                    return 0;

                case 72:  // arrow up
                    if(shiftUp(arr))
                        Maxtry--;
                    break;
                case 80: // arrow down
                    if(shiftDown(arr))
                        Maxtry--;
                    break;
                case 77: // arrow right
                    if(shiftRight(arr))
                        Maxtry--;
                    break;
                case 75:  //arrow left
                    if(shiftLeft(arr))
                        Maxtry--;
                    break;

                default:
                    printf("\n\n    \a\a Not Allowed \a");
                }
        }
        if(!Maxtry)
            printf("\n\a       YOU LOSE !       \a\a\n");
        else
            printf("\n\a!!!!!!!!!!!!Congratulation %s for winning this game !!!!!!!!!!\a\a",n);

        fflush(stdin);    //Will clear buffer
        char check;
        printf("\n Want to play again ?\n\n");
        printf("Enter 'y' to play again: ");
        scanf("%c",&check);

        //Leave the game here itself !

        if((check != 'y')&& (check != 'Y'))
            break;

        Maxtry=220;
    }
    return 0;
}
