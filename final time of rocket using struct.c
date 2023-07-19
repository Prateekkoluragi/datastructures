#include<stdio.h>

struct time
{
    int hr;
    int min;
};
void travel(struct time t1,struct time t2);
int main()
{
    struct time t1;
    struct time t2;
    struct time t3;
    printf("enter the initial time\n");
    scanf("%d %d",&t1.hr,&t1.min);
    printf("enter the travel time\n");
    scanf("%d %d",&t2.hr,&t2.min);
    travel(t1,t2);
}
void travel(struct time t1,struct time t2)
{
    struct time t3;
    t3.hr=t1.hr+t2.hr;
    t3.min=t1.min+t2.min;
    if(t3.min>59)
    {
        t3.hr++;
        t3.min-60;
    }
    if(t3.hr>23)
    {
        t3.hr=t3.hr-24;
    }
    printf("final time is%d:%d",t3.hr,t3.min);
}

