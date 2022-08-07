#include <stdio.h>

char game[3][3], player1[20], player2[20];

void FillHeadquarters()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            game[i][j] = ' ';
        }
    }
}

void Print()
{
    int i, j;
    printf("\n  0    1    2\n\n");
    for(i=0; i<3; i++)
    {

        for(j=0; j<3; j++)
        {

            printf("  %c ", game[i][j]);
            if(j<2)
                printf("|");
        }
        printf("  %d", i);
        if(i<2)
            printf("\n--------------\n");
    }
    printf("\n\n\n");
}

int PositionValidate(int line, int column)
{
    if(line >=0 && line <=2)
        if(column >= 0 && column <=2)
            return 1;
    return 0;
}

int PlayValidate(int line, int column)
{
    if(game[line][column] == ' ')
        return 1;
    return 0;
}

int WinLine()
{
    int i, j, conf = 0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(!PlayValidate(i,j) && game[i][j] == game[i][j+1])
                conf++;
        }
        if(conf == 2)
            return 1;
        conf = 0;
    }
    return 0;
}

int WinColumn()
{
    int i, j, conf = 0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(!PlayValidate(j,i) && game[j][i] == game[j+1][i])
                conf++;
        }
        if(conf == 2)
            return 1;
        conf = 0;
    }
    return 0;
}

int WinD1()
{
    int i, conf = 0;
    for(i=0; i<2; i++)
    {
        if(!PlayValidate(i,i) && game[i][i] == game[i+1][i+1])
            conf++;
    }
    if(conf == 2)
        return 1;
    return 0;
}

int WinD2()
{
    int i, j, conf = 0;
    for(i=0, j=2; i<2, j>0; i++, j--)
    {
        if(!PlayValidate(i,j) && game[i][j] == game[i+1][j-1])
            conf++;
    }
    if(conf==2)
        return 1;
    return 0;
}
void Play()
{
    int line, column, conf = 0, order = 0, win = 0;
    do
    {
        do
        {
            Print();
            printf("\nChose a line: ");
            scanf("%d", &line);
            printf("\nChose a column: ");
            scanf("%d", &column);
            conf = PositionValidate(line, column);
            printf("%d", conf);
            conf += PlayValidate(line, column);
            system("cls");
        }
        while(conf!=2);
        if(order%2 == 0)
            game[line][column] = 'X';
        else
            game[line][column] = '0';
        order++;

        win += WinLine();
        win += WinColumn();
        win += WinD1();
        win += WinD2();

    }
    while(order < 9 && win == 0);
    Print();
    if(order%2 == 1)
        printf("Congratulations, %s, you win!", player1);
    else
        printf("Congratulations, %s, you win!", player2);

}

int main()
{

    FillHeadquarters();
    printf("\nHello players!Let's go!\n");
    printf("\nEnter name, player 1: ");
    scanf("%s", player1);
    printf("\nEnter name, player 2: ");
    scanf("%s", player2);

    Play();
    getche();
}
