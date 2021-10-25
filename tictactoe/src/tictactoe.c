#include <stdio.h>

struct Field
{
    int sqare[3][3];
    int player;
    int gameOver;
    int freePlaces;
};


void resetField(struct Field *field)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            field->sqare[i][j] = 0;
        }
    }
    field->player = 1;
    field->gameOver = 0;
    field->freePlaces = 9;
}

void printField(struct Field *field)
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (field->sqare[i][j])
            {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("X");
                break;
            case 2:
                printf("O");
                break;
            default:
                break;
            };
            if(j < 2 )
                printf(" | ");
        }
        if(i < 2)
            printf("\n---------\n");
    }
    printf("\n\n");
}


void getInput(struct Field* field)
{
    int input;
    printf("\nPlease enter your move: ");
    scanf("%d", &input);
    input--;
    int x = input % 3;
    int y = input / 3;
    field->sqare[y][x] = field->player;
    if (field->player == 1)
        field->player = 2;
    else
        field->player = 1;
    field->freePlaces--;
}

void isGameOver(struct Field* field)
{
    if(field->freePlaces == 0)
    {
        field->gameOver = 1;
        printf("\nTie... No winner\n");
    }
    for(int i = 0; i < 3; i++)
        if((field->sqare[i][0] == field->sqare[i][1]) && (field->sqare[i][0] == field->sqare[i][2]) && (field->sqare[i][0] != 0))
        {
            field->gameOver = 1;
            printf("\nPlayer %d wins!!!", field->sqare[i][0]);
        }
    for(int i = 0; i < 3; i++)
        if((field->sqare[0][i] == field->sqare[1][i]) && (field->sqare[0][i] == field->sqare[2][i]) && (field->sqare[0][i] != 0))
        {
            field->gameOver = 1;
            printf("\nPlayer %d wins!!!", field->sqare[0][i]);
        }
    if(field->sqare[0][0] == field->sqare[1][1] && field->sqare[0][0] == field->sqare[2][2] && field->sqare[0][0] != 0)
    {
        field->gameOver = 1;
        printf("\nPlayer %d wins!!!", field->sqare[0][0]);
    }
    if(field->sqare[0][2] == field->sqare[1][1] && field->sqare[0][0] == field->sqare[2][0] && field->sqare[0][2] != 0)
    {
        field->gameOver = 1;
        printf("\nPlayer %d wins!!!", field->sqare[0][2]);
    }
}




int main()
{
    struct Field field;
    resetField(&field);
    printField(&field);
    while (!field.gameOver)
    {
        getInput(&field);
        printField(&field);
        isGameOver(&field);
    }
    
    return 0;
}
