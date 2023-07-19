#include<stdio.h>
void display (char player[20],float average, int odi_rank);
struct cricket_player
{
    char player[20];
    char team[20];
    float average;
    int highest_score;
    int centuries;
    int odi_rank;
};
main()
{
    struct cricket_player c1;
    char player[20];
    float average;
    int odi_rank;
    scanf("%s",c1.player);
    scanf("%s",c1.team);
    scanf("%f",&c1.average);
    scanf("%d",&c1.highest_score);
    scanf("%d",&c1.centuries);
    scanf("%d",&c1.odi_rank);
   display(c1.player,c1.average,c1.odi_rank);
}
void display (char player[20], float average, int odi_rank)
{
    printf("%s\n %f\n %d\n",player,average,odi_rank);
}
