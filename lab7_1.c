#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.14159265359

int main(int argc, char *argv[]){
    double val;
    int rad_deg, status;

    if (argc<2){
        printf("Usage: filename 0/1\n");
        return 0;
    }
    else if(argc>2){
        printf("Usage: filename 0/1\n");
        return 0;
    }
    rad_deg = atoi(argv[1]);
    printf("%d\n", rad_deg);
    if((rad_deg) != 1 && rad_deg!=0){
        printf("Please enter 1 for radians or 0 for degrees.\n");
        return 0;
    }
    typedef struct
    {
        double r;
        double theta;
        double x;
        double y;
        
    }coordinate;

    coordinate p;
    printf("Please enter r: ");
    status = scanf("%lf", &val);
    while(status!= 1){
        while(getchar()!='\n'){}
        printf("Wrong input. Please enter r: ");
        status = scanf("%lf", &val);
    }
    p.r = val;

    printf("Please enter theta: ");
    status = scanf("%lf", &val);
    while(status!= 1){
        while(getchar()!='\n'){}
        printf("Wrong input. Please enter theta: ");
        status = scanf("%lf", &val);
    }
    p.theta = val;
    
    if(rad_deg == 1){
        p.x = p.r*cos(p.theta*PI/180);
        p.y = p.r*sin(p.theta*PI/180);
        printf("In polar coordinates r = %.2lf and theta = %.2lf is x = %.4lf and y = %.4lf\n", p.r, p.theta, p.x, p.y);
    }
    else{
        p.x = p.r*cos(p.theta);
        p.y = p.r*sin(p.theta);
        printf("In polar coordinates r = %.2lf and theta = %.2lf is x = %.4lf and y = %.4lf\n", p.r, p.theta, p.x, p.y);
    }
    
return 1;
}