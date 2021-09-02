/*program to guess the number.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int number, number1, n, i = 0, j = 1, k, count = 0, nums = 1, num[10], iv = 0, invalid_input[20], check;
    int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char first_player[10], second_player[10];
    //for generate random number
    srand(time(0));
    number = rand() % 10;
    // check user want to play with computer or friends.
    printf("Do you want to play with computer or friend?\n");
loop1:
    printf("Enter 0 for computer and 1 for friend:");
    scanf("%d", &check);
    // if user select 0 for playing with computer
    if (check == 0)
    {
        srand(time(0));
        number1 = rand() % 20 + 1;
        printf("Let's play with computer.\n");
        printf("\n");
        printf("------>Rules of Game are:------>\n");
        printf("You have four(4) chances to play this game:\n");
        printf("You must guess number between 0 to 20.\n");
        printf("The number more than 20 or less than 0 is not count.\n");
        printf("\n");
        printf("Game starting..........\n");
        for (i = 0; i < 4; i++)
        {
            count++;
        loopx:
            iv++; // real value of iv is (iv -4) because it runs extra 4 time for valid input
            printf("Guess number:");
            scanf("%d", &n);
            num[i] = n;
            if (n == number1) //if user enter right input
            {
                printf("\n");
                printf("....CONGRATULATIONS.....\n");
                printf("Match the number.\n");
                printf("You win the game.\n");
                printf("Numbers you entered:\n");
                for (i = 0; i < count; i++)
                {
                    printf("%d\t", num[i]);
                }
                printf("\n");
                printf("The correct number is %d.\n", number1);
                printf("\n");
                if (iv > 4)
                {
                    printf("Invalid input you entered:\n");
                    for (i = 1; i <= iv - 4; i++) //dispaly invalid input(iv/2 beacuse this loop run two times)
                    {
                        printf("%d\t", invalid_input[i]);
                    }
                }
                exit(0);
            }
            else if (n > 20 || n < 0)
            {
                invalid_input[iv] = n;
                printf("\n");
                printf("Invalid input.\n");
                printf("Guess number must be between 0 and 20.\n");
                goto loopx;
            }

            else
            { // give the clue for the program
                if (n > number1)
                {
                    printf("\n");
                    printf("Your number is greater.\n");
                }
                else
                {
                    printf("\n");
                    printf("Your number is smaller.\n");
                }
            }
        }
        // if use enter wrong number three times after that
        printf("\n");
        printf("......SORRY......\n");
        printf("You lose the game.\n");
        printf("Numbers you entered:\n");
        for (i = 0; i < count; i++)
        {
            printf("%d\t", num[i]);
        }
        printf("\n");
        printf("The correct number is %d.\n", number1);
        printf("Don't lose hope.\n");
        printf("Play again.\n");
        printf("\n");
        if (iv > 4)
        {
            printf("Invalid input you entered:\n");
            for (i = 1; i <= iv - 4; i++) //dispaly invalid input
            {
                printf("%d\t", invalid_input[i]);
            }
        }
    }
    // if user select 1 for playing with friends
    else if (check == 1)
    {
        printf("The correct number is %d.\n", number);
        printf("\n");
        printf("lets play with friends.\n");
        printf("\n");
        printf("------>Rules of Game are:------>\n");
        printf("You must guess number between 0 to 9.\n");
        printf("Win or lose of game define by your input.\n");
        printf("The number more than 9 or less than 0 is not count.\n");
        printf("\n");
        // get the name of two player
        printf("Enter the name of first player:\n");
        scanf("%s", first_player);
        printf("Enter the name of second player:\n");
        scanf("%s", second_player);
        printf("\n");
        printf("Game starting..........\n");
        do
        {

            if (nums % 2 == 0) //if even that means second player
            {
            loopy:
                printf("\n");
                printf("%s\n", second_player);
                printf("Guess number:");
                scanf("%d", &n);
                if (n >= 0 && n < 10) //check input valid or not
                {
                    num[j] = n; // store the entered number in array num
                }
                else
                {
                    printf("Invalid Input:\n");
                    goto loopy;
                }
            }
            else // that means first player
            {
            loopz:
                printf("\n");
                printf("%s\n", first_player);
                printf("Guess number:");
                scanf("%d", &n);
                if (n >= 0 && n < 10) //check input valid or not
                {
                    num[j] = n; // store the entered number in array num
                }
                else
                {
                    printf("Invalid Input:\n");
                    goto loopz;
                }
            }
            j++; // for making aaray
            if (n == number)
            {
                if (nums % 2 == 0) /*if number is match and position of enter number is even 
                than the winner is second player*/
                {
                    printf("\n");
                    printf("Congurats,%s..\n", second_player);
                    printf("You win the game.\n");
                    printf("\n");
                    printf("Numbers you entered:\n");
                    for (j = 1; j <= nums; j++)
                    {
                        if (j % 2 == 0) // display the input of only second player
                        {
                            printf("%d\t", num[j]);
                        }
                    }
                    printf("\n");
                    printf("The correct number is %d.\n", number);
                    printf("\n");
                    printf("Numbers entered by %s:\n", first_player); //display the result oppenent player
                    for (j = 1; j <= nums; j++)
                    {
                        if (j % 2 != 0)
                        {
                            printf("%d\t", num[j]);
                        }
                    }
                    exit(0);
                }
                else
                {
                    printf("\n");
                    printf("\n");
                    printf("Congurats,%s..\n", first_player);
                    printf("You win the game.\n");
                    printf("\n");
                    printf("Numbers you entered:\n");
                    for (j = 1; j <= nums; j++)
                    {
                        if (j % 2 != 0) // display the input of only first player
                        {
                            printf("%d\t", num[j]);
                        }
                    }
                    printf("\n");
                    printf("The correct number is %d.\n", number);
                    printf("\n");
                    printf("Numbers entered by %s:\n", second_player); //display the result oppenent player
                    for (j = 1; j < nums; j++)
                    {
                        if (j % 2 == 0)
                        {
                            printf("%d\t", num[j]);
                        }
                    }
                    printf("\n");
                    if (nums == 1)
                    {

                        printf("Not entered any number.\n");
                    }
                    exit(0);
                }
            }
            else
            {
                nums++;
            }
        } while (n != number);
    }
    else //if user input isnot 0 or 1.
    {
        printf("invalid input.\n");
        goto loop1;
    }

    return 0;
}