#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(char *choice)
{
    printf("Menu:\na)Play new game with PC\nb)Play new game for two players\nc)Player's statistics\nd)End program\n");
    do
    {
        printf("Give choice: ");
        scanf("%c",choice);
        fflush(stdin);
        if((*choice!='a')&&(*choice!='b')&&(*choice!='c')&&(*choice!='d'))
            printf("Wrong choice\nChoice must be a,b,c or d\n");
    }
    while((*choice!='a')&&(*choice!='b')&&(*choice!='c')&&(*choice!='d'));//checks the answer
    system("cls");
}

void init(char *P)//initializes the table to empty
{
    int i;
    for(i=0;i<9;i++)
        *(P+i)=' ';
}

void table(char P[9])//tic tac toe appearance
{
    int i,j,k=0;
    for(i=0;i<=18;i++)//width of 19 characters
    {
        if((i==0)||(i==6)||(i==12)||(i==18))//places for line dividers
            for(j=0;j<=18;j++)//adds line dividers (length of 19 characters)
                printf("-");
        else
        {
            for(j=0;j<=18;j++)
            {
                if((j==0)||(j==6)||(j==12)||(j==18))//places for column dividers
                    printf("|");//column divider
                else
                {
                    if((j%3==0)&&((i==3)||(i==9)||(i==15)))//center of the boxes (6, 12 and 18 are checked by the external if)
                    {
                        printf("%c",P[k]);//prints the content of the box from the corresponding table
                        k++;//counts the place of the table that the repetition proceeds to
                    }
                    else
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int box(char P[9])//choice
{
    char b;
    do
    {
        printf("Give a box to fill (1-9): ");
        b=getchar();
        fflush(stdin);
        printf("\n");
        if(((b-'0')<1)||((b-'0')>9))
        {
            system("cls");
            table(P);
            printf("Choice must be 1-9\n");
        }
        else if(P[(b-'0')-1]!=' ')
        {
            system("cls");
            table(P);
            printf("Box already filled\n");
        }
    }
    while(((b-'0')<1)||((b-'0')>9)||(P[(b-'0')-1]!=' '));
    return (b-'0')-1;
}

void PCturn(char *P)//PC way of thinking
{
    int i=0,stop=0;
    //fills the middle box in case it's empty
    if(*(P+4)==' ')
    {
        *(P+4)='O';
        stop=1;
    }
    //creates a winning pattern
    i=0;
    while(!(stop)&&(i<=6))//horizontal
    {
        if(*(P+i)==*(P+i+1)&&*(P+i)=='O'&&*(P+i+2)==' ')
        {
            *(P+i+2)='O';
            stop=1;
        }
        else if(*(P+i+1)==*(P+i+2)&&*(P+i+1)=='O'&&*(P+i)==' ')
        {
            *(P+i)='O';
            stop=1;
        }
        else if(*(P+i)==*(P+i+2)&&*(P+i)=='O'&&*(P+i+1)==' ')
        {
            *(P+i+1)='O';
            stop=1;
        }
        i+=3;
    }
    if(!(stop))//checks whether it has played or not
    {
        i=0;
        while(!(stop)&&(i<3))//vertical
        {
            if(*(P+i)==*(P+i+3)&&*(P+i)=='O'&&*(P+i+6)==' ')
            {
                *(P+i+6)='O';
                stop=1;
            }
            else if(*(P+i+3)==*(P+i+6)&&*(P+i+3)=='O'&&*(P+i)==' ')
            {
                *(P+i)='O';
                stop=1;
            }
            else if(*(P+i)==*(P+i+6)&&*(P+i)=='O'&&*(P+i+3)==' ')
            {
                *(P+i+3)='O';
                stop=1;
            }
            i++;
        }
    }
    if(!(stop))//main diagonal
    {
        if(*P==*(P+4)&&*P=='O'&&*(P+8)==' ')
        {
            *(P+8)='O';
            stop=1;
        }
        else if(*P==*(P+8)&&*P=='O'&&*(P+4)==' ')
        {
            *(P+4)='O';
            stop=1;
        }
        else if(*(P+4)==*(P+8)&&*(P+4)=='O'&&*P==' ')
        {
            *P='O';
            stop=1;
        }
    }
    if(!(stop))//secondary diagonal
    {
        if(*(P+2)==*(P+4)&&*(P+2)=='O'&&*(P+6)==' ')
        {
            *(P+6)='O';
            stop=1;
        }
        else if(*(P+2)==*(P+6)&&*(P+2)=='O'&&*(P+4)==' ')
        {
            *(P+4)='O';
            stop=1;
        }
        else if(*(P+4)==*(P+6)&&*(P+4)=='O'&&*(P+2)==' ')
        {
            *(P+2)='O';
            stop=1;
        }
    }
    //interrupts users' win
    if(!(stop))
    {
        i=0;
        while(!(stop)&&(i<=6))//horizontally
        {
            if(*(P+i)==*(P+i+1)&&*(P+i)=='X'&&*(P+i+2)==' ')
            {
                *(P+i+2)='O';
                stop=1;
            }
            else if(*(P+i+1)==*(P+i+2)&&*(P+i+1)=='X'&&*(P+i)==' ')
            {
                *(P+i)='O';
                stop=1;
            }
            else if(*(P+i)==*(P+i+2)&&*(P+i)=='X'&&*(P+i+1)==' ')
            {
                *(P+i+1)='O';
                stop=1;
            }
            i+=3;
        }
    }
    if(!(stop))
    {
        i=0;
        while(!(stop)&&(i<3))//vertically
        {
            if(*(P+i)==*(P+i+3)&&*(P+i)=='X'&&*(P+i+6)==' ')
            {
                *(P+i+6)='O';
                stop=1;
            }
            else if(*(P+i+3)==*(P+i+6)&&*(P+i+3)=='X'&&*(P+i)==' ')
            {
                *(P+i)='O';
                stop=1;
            }
            else if(*(P+i)==*(P+i+6)&&*(P+i)=='X'&&*(P+i+3)==' ')
            {
                *(P+i+3)='O';
                stop=1;
            }
            i++;
        }
    }
    if(!(stop))//diagonally (main)
    {
        if(*P==*(P+4)&&*P=='X'&&*(P+8)==' ')
        {
            *(P+8)='O';
            stop=1;
        }
        else if(*P==*(P+8)&&*P=='X'&&*(P+4)==' ')
        {
            *(P+4)='O';
            stop=1;
        }
        else if(*(P+4)==*(P+8)&&*(P+4)=='X'&&*P==' ')
        {
            *P='O';
            stop=1;
        }
    }
    if(!(stop))//diagonally (secondary)
    {
        if(*(P+2)==*(P+4)&&*(P+2)=='×'&&*(P+6)==' ')
        {
            *(P+6)='O';
            stop=1;
        }
        else if(*(P+2)==*(P+6)&&*(P+2)=='×'&&*(P+4)==' ')
        {
            *(P+4)='O';
            stop=1;
        }
        else if(*(P+4)==*(P+6)&&*(P+4)=='×'&&*(P+2)==' ')
        {
            *(P+2)='O';
            stop=1;
        }
    }
    //case of two diagonal to each other boxes filled by the user
    if(!(stop)&&(*(P+4)=='O'))
    {
        if(((*P=='X')&&(*(P+8)=='X'))||((*(P+2)=='X')&&(*(P+6)=='X')))
        {
            //creates possible tic tac toe at the middle line
            if(*(P+5)==' '&&*(P+3)==' ')
            {
                *(P+5)='O';
                stop=1;
            }
            if(!(stop))//checks whether it's played or not
            {
                //creates possible tic tac toe at the middle column
                if(*(P+7)==' '&&*(P+1)==' ')
                {
                    *(P+1)='O';
                    stop=1;
                }
            }
        }
    }
    //in the case that it hasn't make a move, it fills a corner box
    if(!(stop))
    {
        if(*P==' ')
        {
            *P='O';
            stop=1;
        }
        else if(*(P+2)==' ')
        {
            *(P+2)='O';
            stop=1;
        }
        else if(*(P+6)==' ')
        {
            *(P+6)='O';
            stop=1;
        }
        else if(*(P+8)==' ')
        {
            *(P+8)='O';
            stop=1;
        }

    }
}

int endgame(char P[9])//checks if the game is over
{
    int i=0,end=0,tr=0,j=0;
    while(!(end)&&(i<=6))//checks for horizontal win
    {
        if(P[i]==P[i+1]&&P[i]==P[i+2]&&P[i]!=' ')
        {
            if(P[i]=='X')
                end=1;
            else
                end=2;
        }
        i+=3;
    }
    if(!(end))
    {
        i=0;
        while(!(end)&&(i<3))//checks for vertical win
        {
            if(P[i]==P[i+3]&&P[i]==P[i+6]&&P[i]!=' ')
            {
                if(P[i]=='X')
                    end=1;
                else
                    end=2;
            }
            i++;
        }
    }
    if(!(end))//checks for diagonal win (main)
    {
        if(P[0]==P[4]&&P[0]==P[8]&&P[0]!=' ')
        {
            if(P[0]=='X')
                end=1;
            else
                end=2;
        }
    }
    if(!(end))//checks for diagonal win (secondary)
    {
        if(P[2]==P[4]&&P[2]==P[6]&&P[2]!=' ')
        {
            if(P[2]=='X')
                end=1;
            else
                end=2;
        }
    }
    i=0;
    while(i<9&&!(tr))//checks if all the boxes are filled
    {
        if(P[i]==' ')
            tr=1;
        else
            j++;
        i++;
    }
    if(j==9)
        end=3;
    return end;
}

char *readname()//dynamic storage of users' names
{
    char *name=NULL;
    name=(char *)calloc(300,sizeof(char));
    printf("Give name: ");
    gets(name);
    fflush(stdin);
    name=(char *)realloc(name,strlen(name)+1);
    return name;
}






int main()
{
    FILE *stats;
    int i,j,end=0,*w=NULL,*l=NULL,*t=NULL,stop=0,line=0;
    char choice,P[9],*name=NULL,*player=NULL,*forlines=NULL;
    menu(&choice);
    system("cls");
    while(choice!='d')
    {
        if(choice=='a')
        {
            init(P);
            printf("You are playing against PC\nYour character is X\n");
            end=0;
            while(!end)
            {
                table(P);
                P[box(P)]='X';
                system("cls");
                table(P);
                end=endgame(P);
                switch(end)
                {
                    case 0:
                        PCturn(P);
                        system("cls");
                        table(P);
                        end=endgame(P);
                        switch(end)
                        {
                            case 1:
                                printf("You won!\n");
                                break;
                            case 2:
                                printf("You lost...\n");
                                break;
                            case 3:
                                printf("Tie\n");
                        }
                        break;
                    case 1:
                        printf("You won!\n");
                        break;
                    case 2:
                        printf("You lost...\n");
                        break;
                    case 3:
                        printf("Tie\n");
                }
                if(end)//statistics' storage
                {
                    name=readname();
                    //SEARCH
                    if((stats=fopen("statistics.txt","r"))!=NULL)//checks for case that the player has played before
                    {
                        line=0;//line with the statistics of the players we are searching for
                        stop=0;//ends the recursion if the name is found
                        while((!(stop))&&(!(feof(stats))))
                        {
                            player=(char *)calloc(300,sizeof(char));
                            fgets(player,300,stats);
                            fflush(stdin);
                            *(player+(strlen(player))-1)='\0';//replaces the character of \n that is read by fgets with \0
                            player=(char *)realloc(player,(strlen(player)+1)*sizeof(char));
                            w=(int *)malloc(sizeof(int));
                            l=(int *)malloc(sizeof(int));
                            t=(int *)malloc(sizeof(int));
                            fscanf(stats,"%d %d %d ",w,l,t);
                            line+=2;
                            if(!(strcmp(player,name)))
                                stop=1;
                            if((feof(stats))&&(!(stop)))//if the end of the file is reached and the name is not found
                                free(player);
                        }
                        fclose(stats);
                    }//if the file doesn't exist, it's okay because it will be created later
                    //information transfer
                    if(!(stop))//case: new name
                    {
                        if((stats=fopen("statistics.txt","a"))!=NULL)
                        {
                            if(end==1)//case of win
                            {
                                *w=1;
                                *l=0;
                                *t=0;
                            }
                            else if(end!=3)//case of defeat
                            {
                                *w=0;
                                *l=1;
                                *t=0;
                            }
                            else//case of draw
                            {
                                *w=0;
                                *l=0;
                                *t=1;
                            }
                            fputs(name,stats);
                            fprintf(stats,"\n%d\t%d\t%d\n",*w,*l,*t);
                            free(w);
                            free(l);
                            free(t);
                            free(player);
                            fclose(stats);
                        }
                        else
                            printf("Error opening file\n");
                    }
                    if(stop==1)//case: name exists
                    {
                        //transfer of changed line
                        if((stats=fopen("statistics.txt","r+"))!=NULL)
                        {
                            forlines=(char *)malloc(300*sizeof(char));
                            fseek(stats,0,SEEK_SET);//tranfers pointer at the begging of the file
                            for(j=1;j<=line-1;j++)//tranfers pointer at the begging of line with the statistics of the specific user
                            {
                                fgets(forlines,300,stats);
                            }
                            if(end==1)//case of win
                                (*w)++;
                            else if(end==2)//case of defeat
                                (*l)++;
                            else//case of draw
                                (*t)++;
                            fseek(stats,0,SEEK_CUR);
                            fprintf(stats,"%d\t%d\t%d\n",*w,*l,*t);//returns the information
                            free(w);
                            free(l);
                            free(t);
                            free(player);
                            free(forlines);
                            fclose(stats);
                        }
                        else
                            printf("Error opening file\n");
                    }
                    free(name);
                }
                else
                    system("cls");//clears screen
            }
        }



        else if(choice=='b')
        {
            init(P);
            printf("You are playing against other player\n");
            while(!(end))
            {
                table(P);
                printf("Player 1 (X)\n");
                P[box(P)]='X';
                system("cls");
                table(P);
                end=endgame(P);
                switch(end)
                {
                    case 0:
                        printf("Player 2 (O)\n");
                        P[box(P)]='O';
                        system("cls");
                        table(P);
                        end=endgame(P);
                        switch(end)
                        {
                            case 1:
                                printf("You won!\n");
                                break;
                            case 2:
                                printf("You lost...\n");
                                break;
                            case 3:
                                printf("Tie\n");
                        }
                        break;
                    case 1:
                        printf("Player 1 won!\n");
                        break;
                    case 2:
                        printf("Player 2 won!\n");
                        break;
                    case 3:
                        printf("Tie\n");
                }
                if(end)//storing the statistics
                {
                    for(i=1;i<3;i++)
                    {
                        printf("Player %d\n",i);
                        name=readname();
                        //SEARCH
                        if((stats=fopen("statistics.txt","r"))!=NULL)//searches for existing stats for the specific user
                        {
                            line=0;//line with the player's stats
                            stop=0;//ends the recursion if the name is found
                            while((!(stop))&&(!(feof(stats))))
                            {
                                player=(char *)calloc(300,sizeof(char));
                                fgets(player,300,stats);
                                fflush(stdin);
                                *(player+(strlen(player))-1)='\0';//replaces the character \n that is read by fgets with \0
                                player=(char *)realloc(player,(strlen(player)+1)*sizeof(char));
                                w=(int *)malloc(sizeof(int));
                                l=(int *)malloc(sizeof(int));
                                t=(int *)malloc(sizeof(int));
                                fscanf(stats,"%d %d %d ",w,l,t);
                                line+=2;
                                if(!(strcmp(player,name)))
                                    stop=1;
                                if((feof(stats))&&(!(stop)))//if the end of the file is reached and the name is not found
                                    free(player);
                            }
                            fclose(stats);
                        }//the case of a non existent file doesn't bother us since in that case it will be created later on
                        if(!(stop))//case: new name
                        {
                            if((stats=fopen("statistics.txt","a"))!=NULL)
                            {
                                if(end==i)//case of win
                                {
                                    *w=1;
                                    *l=0;
                                    *t=0;
                                }
                                else if(end!=3)//case of defeat
                                {
                                    *w=0;
                                    *l=1;
                                    *t=0;
                                }
                                else//case of draw
                                {
                                    *w=0;
                                    *l=0;
                                    *t=1;
                                }
                                fputs(name,stats);
                                fprintf(stats,"\n%d\t%d\t%d\n",*w,*l,*t);
                                free(w);
                                free(l);
                                free(t);
                                free(player);
                                fclose(stats);
                            }
                            else
                                printf("Error opening file\n");
                        }
                        if(stop==1)//case: existing name
                        {
                            //transfer of changed line
                            if((stats=fopen("statistics.txt","r+"))!=NULL)//changed information
                            {
                                forlines=(char *)malloc(300*sizeof(char));
                                fseek(stats,0,SEEK_SET);//tranfers pointer at the begging of the file
                                for(j=1;j<=line-1;j++)//tranfers pointer at the begging of line with the statistics of the specific user
                                {
                                    fgets(forlines,300,stats);
                                }
                                if(end==i)//case: win
                                    (*w)++;
                                else if(end!=3)//case: defeat
                                    (*l)++;
                                else//case: draw
                                    (*t)++;
                                fseek(stats,0,SEEK_CUR);
                                fprintf(stats,"%d\t%d\t%d\n",*w,*l,*t);//returns the information
                                free(w);
                                free(l);
                                free(t);
                                free(player);
                                free(forlines);
                                fclose(stats);
                            }
                            else
                                printf("Error opening file\n");
                        }
                        free(name);
                    }
                }
                else
                    system("cls");
            }
        }



        else if(choice=='c')
        {
            printf("You chose Player's Statistics\n");
            system("PAUSE");
            system("cls");
            name=readname();
            //SEARCH
            if((stats=fopen("statistics.txt","r"))!=NULL)
            {
                stop=0;
                if(feof(stats))
                    printf("Player not found\n");
                while((!(stop))&&(!(feof(stats))))
                {
                    player=(char *)calloc(300,sizeof(char));
                    fgets(player,300,stats);
                    fflush(stdin);
                    *(player+(strlen(player))-1)='\0';//replaces the character \n that is read by fgets with \0
                    player=(char *)realloc(player,(strlen(player)+1)*sizeof(char));
                    w=(int *)malloc(sizeof(int));
                    l=(int *)malloc(sizeof(int));
                    t=(int *)malloc(sizeof(int));
                    fscanf(stats,"%d %d %d ",w,l,t);
                    if(!(strcmp(player,name)))
                    {
                        printf("name:%s\twins=%d\tloses=%d\tties=%d\n",player,*w,*l,*t);
                        stop=1;
                    }
                    if((feof(stats))&&(!(stop)))
                        printf("Player not found\n");
                }
                fclose(stats);
                free(w);
                free(l);
                free(t);
                free(name);
                free(player);
                system("PAUSE");
            }
            else
                printf("Error opening file\n");
        }
        system("cls");
        menu(&choice);
    }
    printf("Closing program");
    return 0;
}
