#include<stdio.h>
#include<termio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct Table{
    int pch, ppo, pom, pbe, pso, ppeo, total, total2, be, so
}table;
typedef struct Date{
    int day, income;
    struct Table ta
}date;
table t[SIZE];
date d[SIZE];
void check(int, int);
void TS(int);
void people(int);
void tanum(void);
void order(int, int);
void list(int);
void _list(int);
void pay(int);
void sales(int);
void total(int);
int Memo(void);
const char chi[10] = "Chicken";
const char por[10] = "Pork";
const char oml[10] = "Omlet";
const char bee[10] = "Beer";
const char soj[10] = "Soju";
const char price[5] = {20000, 18000, 13000, 3500, 4000};
void main(void){
    int i=0;
    int select;

    printf("===POS===\n\n");
    do{
        printf("DATE: ");
        scanf("%d", &d[i].day);
        if(d[i].day == 0)
            break;
        do{
            printf("\n1.People \n2.Order \n3.Order List \n4.Pay \n5.Today Income \n6.Quit: ");
            scanf("%d", &select);
            check(select, i);
            if(select == 6)
                Memo();
        }while(select!=6);
    }while(1)
}
void tanum(void){
    if(t[1].ppeo != 0)
        printf("No.1 Table Full\n");
    if(t[2].ppeo != 0)
        printf("No.2 Table Full\n");
    if(t[3].ppeo != 0)
        printf("No.3 Table Full\n");
    if(t[4].ppeo != 0)
        printf("No.4 Table Full\n");
    if(t[5].ppeo != 0)
        printf("No.5 Table Full\n");
void TS(int a){
    do{
        printf("Select Table: ");
        scanf("%d", &a);
        if(a>5||a<0)
            printf("Our Bar Have 1~5 Table!!!\n");
    }while(a>5||a<0);
}
void check(int _select, int _i){
    int ts;
    do{
    switch(ts)
    {
        case 1:
            tanum();
            TS(ts);
            people(ts);
            break;
        case 2:
            tanum();
            TS(ts);
            order(ts, _i);
            break;
        case 3:
            tanum();
            TS(ts);
            list(ts);
            break;
        case 4:
            tanum();
            TS(ts);
            pay(ts);
            break;
        case 5:
            tnum()
            TS(ts);
            sales(_i);
            break;
        case 6:
            break;
        default:
            printf("Wrong Input\n");
    }
    }while(_select !=6);
}
void people(int i){
    do{
        printf("How Many People Come Together: ");
        scanf("%d", &t[i].ppeo);
        if(t[i].ppeo<=0)
            printf("Under 0 People Cannot Come\n");
    }while(t[i].ppeo<=0);
}
void order(int i, int a){
    int num;
    int sum=0;
    printf("====ORDER====\n\n");
    do{
        printf("If You Want To Remove Press '-' With Number\n");
        printf("1.%s: %d won\n2.%s: %d won\n3.%s: %d won\n4.%s: %dwon\n5.%s: %d won\n6. Quit: ",chi,price[0], por,prince[1], oml,price[2], bee,price[3], soj,price[4]);
        scanf("%d", &num);
        switch(num)
        {
            case 1:
                sum+=price[0];
                t[i].pch++;
                break;
            case -1:
                if(t[i].pch>0){
                    sum-=price[0]
                    t[i].pch--;}
                    break;
            case 2:
                sum+=price[1];
                t[i].ppo++;
                break;
            case -2:
                if(t[i].ppo>0){
                    sum-=price[1];
                    t[i].ppo--};
                    break;
            case 3:
                sum+=price[2];
                t[i].pom++;
                break;
            case -3:
                if(t[i].pom>0){
                    sum-=price[2];
                    t[i].pom--;}
                    break;
            case 4:
                sum+=price[3];
                t[i].pbe++;
                t[i].be++;
                break;
            case -4:
                if(t[i].pbe>0){
                    sum-=price[3];
                    t[i].pbe--;
                    t[i].be--;}
                    break;
            case 5:
                sum+=price[4];
                t[i].pso++;
                t[i].so++;
                break;
            case -5:
                if(t[i].pso>0){
                    sum-=price[4];
                    t[i].pso--;
                    t[i].so--;}
                    break;
            case 6:
                break;
            default:
                printf("Wrond Input\n");
        }
        _list(i);
    }while(num!=6);
}
void list(int i){
    int num;
    _list(i);
    do{
        printf("Quit >> 0: ");
        scanf("%d", &num);
    }while(num!=0);
}
void _list(i){
    if(t[i].pch!=0)
        printf("%s(%d): %d won\n", chi, t[i].pch, price[0]*t[i].pch);
    if(t[i].ppo!=0)
        printf("%s(%d): %d won\n", por, t[i].ppo, price[1]*t[i].ppo);
    if(t[i].pom!=0)
        printf("%s(%d): %d won\n", oml, t[i].pom, price[2]*t[i].pom);
    if(t[i].pbe!=0)
        printf("%s(%d): %d won\n", bee, t[i].pbe, price[3]*t[i].pbe);
    if(t[i].pso!=0)
        printf("%s(%d): %d won\n", soj, t[i].pbe, price[4]*t[i].pso);
}
void pay(int i){
    int j, k;
    int result = t[i].total;
    int getm;

    printf("====PAY====\n\n");
    do{
        printf("1. pay\n2. Quit: ");
        scanf("%d", &j);
        switch(j)
        {
            case 1:
                    printf("If you want to dutch pay press 1, If you don't press any number: ");
                    scanf("%d", &k);
                    switch(k)
                    {
                        case 1:
                            printf("1 per person pay: %d won\n", t[i].total/t[i].ppeo);
                            printf("Receive Money: ");
                            scanf("%d"m &getm);
                            result-=getm*t[i].ppeo;
                            if(result<=0)
                            {
                                printf("Change: %d", (-1)*result);
                                break;}
                        default:
                                printf("1 per person pay: %d won\n", t[i].total/t[i].ppeo);
                                printf("Receive Money: ");
                                scanf("%d"m &getm);
                                result-=getm;
                                if(result<=0)
                                {
                                printf("Change: %d", (-1)*result);
                                break;}
                    }
                    t[i].total2 = t[i].total;
                    if(result<=0){
                        t[i].pch =0;
                        t[i].ppo =0;
                        t[i].pom=0;
                        t[i].pbe=0;
                        t[i].pso=0;}

        case 2:
            break;
        deafault :
            printf("Worong Input\n");
        }
    }while(j==2 && result<=0);
}
int total(int i){
    t[i].total = (t[i].pch*price[0])+(t[i].ppo*price[1])+(t[i].pom*price[2])+(t[i].pbe*price[3])+(t[i].pso*price[4]);
    return t[i].total;
}
void sales(int a){
    int i;
    for(i=1; i<6; i++){
        d[a].income+=t[i].total2
        d[a].ta.be += t[i].pbe;
        d[a].ta.so += t[i].pso;
    }

    printf("Daily Sales: %d", d[a].income);
}

int Memo(){
    FILE *fp;
    int i=0;

    fopen("a,txt", "a+")
    if(fp == NULL){
        printf("Cannot Make File\n");
        return 1;
    }
    else
    {
        do{
            printf("==============\n");
            printf("Date %d", d[i].day);
            printf("Income: %d", d[i].income);
            printf("Beer Bottles: %d", d[i].ts.be);
            printf("Soju Bottles: %d", d[i].ts.so);
            i++
        }while(d[i].day != 0);
