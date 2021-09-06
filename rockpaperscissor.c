#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Name(char *name)
{
    gets(name);
}

int main(int argc, char const *argv[])
{
    char *name;
    int n = 15;
    int opt, i, option,playerscore = 0, compscore = 0, count = 1;
    char choice;

    name = (char *)malloc(n * sizeof(char));

    printf("\nWELCOME TO ROCK PAPER SCISSCORS GAME\n");
    printf(" ENTER to continue\n");
    getchar();

    printf("Enter your name: ");
    Name(name);

BEGIN:
    printf("\nWelcome %s\n", name);

    srand(time(NULL));

    for (i = 0; i < 3; i++)
    {
        opt = rand() % 3;
        printf("\nRound %d\n", count);
        printf("\nChoose : \n");
        printf("1.Rock\n");
        printf("2.Paper\n");
        printf("3.Scissors\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("You chose ROCK!\n");
            break;
        case 2:
            printf("You chose PAPER!\n");
            break;
        case 3:
            printf("You chose SCISSORS!\n");
            break;
        }

        switch (opt)
        {
        case 0:
            printf("\nComputer chose ROCK!\n");
            break;
        case 1:
            printf("\nComputer chose PAPER!\n");
            break;
        case 2:
            printf("\nComputer chose SCISSOR!\n");
            break;
        }

        if ((opt== 0 && option == 3) || (opt == 1 && option == 1) || (opt == 2 && option == 2))
        {
            compscore++;
        }

        else if ((option == 1 && opt == 2) || (option == 2 && opt== 0) || (option == 3 && opt== 1))
        {
            playerscore++;
        }

        else if ((option - 1) == opt)
        {
            printf("tie\n");
            playerscore += 0;
            compscore += 0;
        }

        count++;
    }

    printf("\n%s's Score:  %d \nComputer's Score: %d\n", name, playerscore, compscore);
    free(name);
    if (playerscore > compscore)
    {
        printf("You Win");
    }

    else if (playerscore < compscore)
    {
        printf("You Lose. Better luck next time");
    }

    else
    {
        printf("It's a tie");
    }

    return 0;
}