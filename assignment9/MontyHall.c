#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL));
    int prize=rand()%3;
    int notprize1=(prize+1)%3;
    int notprize2=(prize+2)%3;


    printf("\n");
    printf("=============================\n");
    printf(" **Monty hall Simulator** \n");
    printf("=============================\n");
    printf("\n");

    int pick=-1;
    while(pick<0 || pick>2)
    {
        printf(" pick a door (0, 1 or 2): ");
        scanf("%d",&pick);
    }
    printf("\n youo have entered : %d\n ",pick);
    int other;
    int other_other;
    printf("\n INtresting Choice\n");
    if(pick==prize)
    {
        int ss=rand()%2;
        if(ss==0)
        {
            other=notprize1;
            other_other=notprize2;
        }
        else
        {
            other=notprize2;
            other_other=notprize1;
        }
    }
    else
    {
        other_other=prize;
        if(pick==notprize1)
        {
            other=notprize2;
        }
        else
        {
            other=notprize1;
        }
    }

    printf("\n Are you sure you want this door i don't see any prize behind the door: %i\n",other);
    int change=-1;
    while(change!=0 && change!=1)
    {
        printf("\n stay with Door %i (press 0) or you can swith with the door %i (press 1): ", pick, other_other);
        scanf("%d",&change);
    }
    int final_pick;
    if (change==0)
    {
        final_pick=pick;
        printf("\n you stayed with door %i\n",final_pick);
    }
    else
    {
        final_pick=other_other;
        printf("\n you switched to door %i \n",final_pick);
    }
    if(final_pick==prize)
    {
        printf("\n *** WINNER *** \n\n");
    }    
    else
    {
        printf("\n ---loser---\n\n");
    }
    printf("The prize was behind Door %i\n\n",prize);
    return 0;
}



