#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define length_mas 255

void GotoXY(int X, int Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleTextAttribute(hStdOut,4);
    SetConsoleCursorPosition(hStdOut, coord);
}

void colour(int i)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,i);
}

void ConsoleCursorVisible(int show, short size)//the visibility of the cursor
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void frame(int x1, int y1, int x2, int y2)  //=
{
     int i;
    GotoXY(x1, y1);
    printf("%c", '\311');
    for (i = (x1 + 1); i <= (x2 - 1); i++)
        printf("%c", '\315');
    printf("%c", '\273');
    for (i = (y1 + 1); i <= (y2 - 1); i++)
    {
        GotoXY(x1, i);
        printf("%c", '\272');
        GotoXY(x2, i);
        printf("%c", '\272');
    }
    GotoXY(x1, y2);
    printf("%c", '\310');
    for (i = (x1 + 1); i <= (x2 - 1); i++)
        printf("%c", '\315');
    printf("%c", '\274');
}

void frame1(int x1, int y1, int x2, int y2)  //*
{
    colour(6);
    int i;
    GotoXY(x1, y1);
    for (i = x1; i <= x2; i++)
        printf("%c", '*');
    for (i = y1; i <= y2; i++)
    {
        GotoXY(x1, i);
        printf("%c", '*');
        GotoXY(x2, i);
        printf("%c", '*');
    }
    GotoXY(x1, y2);
    for (i = x1; i <= x2; i++)
        printf("%c", '*');
}

void zastavka()
{
    system("cls");//clear screen
    frame1(9, 5, 86, 23);
    frame(10, 6, 85, 22);
    colour(10);
    GotoXY(32, 6);
    printf("Laboratory work 6\n");
    GotoXY(34, 7);
    printf("programming\n");
    GotoXY(35, 8);
    printf("Variant 24\n");
    GotoXY(16, 10);
    printf("TASK:\n");
    GotoXY(16, 11);
    printf("A non-empty text with a length of up to 255 characters is specified.\n");
    GotoXY(16, 12);
    printf("This text contains words,\n");
    GotoXY(16, 13);
    printf( "each of which has from 1 to 5 lowercase Latin letters;\n");
    GotoXY(16, 14);
    printf( "between adjacent words - a comma,\n");
    GotoXY(16, 15);
    printf( "after the last word - a period.\n");
    GotoXY(16, 16);
    printf( "Print:\n");
    GotoXY(16, 17);
    printf("(a) the same sequence of words,\n");
    GotoXY(16, 18);
    printf("but remove repeated occurrences of words from it;\n");
    GotoXY(16, 19);
    printf("b) all words that occur in a sequence only once.\n");
    GotoXY(65, 21);
    printf("Fialkovska Olya\n");
    GotoXY(10, 24);
    printf("Please press any key to continue\n");
}

void in(char *mas1)
{
    printf("\nText input condition:\n");
    printf("1. the text contains words, which contains small Latin letters,\n");
    printf("2. between adjacent words - a comma,\n");
    printf("3. after the last word - a period.\n");
    int f=-1,k=1;
    while(k)
    {
        printf("\nInput:\n");
        scanf("%s",&*mas1);
        int i=0;
        for(int i=0; i<strlen(mas1)-1; i++)
            if(mas1[i]=='.' && mas1[i+1]!=' ')
                f=0;
        while(i<length_mas && mas1[i]!='.')
        {
            if(mas1[i]!=',')
            {
                if(mas1[i]<'a' || mas1[i]>'z')
                    f=0;
            }
            else i++;
            i++;
        }
        if( f==-1)
        {
            k=0;
            break;
        }
        else
        {
            printf("The entered text is not conditional. Press any key to exit\n");
            fflush (stdin); // fflush == clean cache-
            _getch();
            menu();
        }

    }
}
void delete_repeat(char *mas1,int ind_ff,int ll,int i)
{
    int k,r,f=-1;
    int j=i;
    k=ind_ff;

    while( j<=strlen(mas1)-1 )
    {

        if(mas1[j]!=',')
        {
            while(k<ind_ff+ll && mas1[j]==mas1[k])
            {
                k++;

                if(k==ind_ff+ll && (mas1[j+1]==','||mas1[j+1]=='.'))
                {
                    for(int p=j-ll; p<=strlen(mas1)-ll; p++)
                    {
                        mas1[p]=mas1[p+ll+1];
                        f=0;
                    }

                    k=ind_ff;
                }
                else
                    break;

            }

        }
        else k=ind_ff;
        j++;
    }

    if(j-1==strlen(mas1)-1 && f==-1)
    {
        for(int u = i-ll; u<=i; u++)
            printf("%c",mas1[u]);
    }

}


void out(char *mas1)
{
    for(int i = 0; i<strlen(mas1); i++)
        printf("%c",mas1[i]);
    printf("\n");
}

void data()
{
    char mas[length_mas];
    in(&mas);

    int i = 0,l,ind_f=i;

    printf("SINGLE WORDS:\n");
    while (i<=strlen(mas)-1)
    {
        l=0;

        while(mas[i]!=',' && mas[i]!='.' && i<strlen(mas)-1)
        {
            i++;
            l++;
        }

        delete_repeat(&mas,ind_f,l,i);

        i++;
        ind_f = i;

    }

    printf("\nFINISH SUCH A HARD WORKS FOR WORDS:\n");
    out(&mas);

    printf("\nPlease press any key to continue\n");
}

void menu()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    ConsoleCursorVisible(0, 100);
    //меню
    const char* menuOptions[] = {"Main","Program","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        GotoXY(38, 8);
        printf("To switch to another mode,\n");
        GotoXY(30, 9);
        printf("switch using the left and right arrows on keyboard.\n");
        int x = 20, y = 12;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x+=15, y);
            if (i == active_menu)
            {
                colour(8);
                printf("[ %s ] ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 75://Left
            if (active_menu > 0)
                active_menu--;
            break;
        case 77://Right
            if (active_menu < numOptions - 1)
                active_menu++;
            break;

        case 13://enter
            switch (active_menu)
            {
            case 0:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                system("CLS");
                GotoXY(x, y);
                zastavka();//main
                _getch();
                system("CLS");
                break;
            case 1:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                system("CLS");
                data();
                _getch();
                system("CLS");
                break;
            case 2:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                exit(0);
                break;
            }
            break;

        }
    }

}

int main()
{
    menu();
    return 0;
}

