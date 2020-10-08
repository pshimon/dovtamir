#include <stdio.h>
int f2c()
{
        double f,c;
        int ret,run=1;
        while(run) {
                printf("input temperature (°F): ");
                fflush(stdout);
                ret=scanf("%lf",& f);
                if (ret!=1) {
                        fflush(stdin);
                        run=0;
                }
                c=5.0*(f-32)/9.0;
                printf("temperature: %f °F = %f °C\n",f,c);
        }
        return 0;
}

int c2f()
{
        double f,c;
        int ret=1;
        while(ret==1) {
                printf("input temperature (°C): ");
                fflush(stdout);
                ret=scanf("%lf",& c);
                f=9.0*c/5.0+32;
                printf("temperature: %f °C = %f °F\n",c,f);
        }
        fflush(stdin);
        return 0;
}

int main()
{
        int ret,run=1;
        char c_or_f;

        while(run){
                printf("C: traslate from Celsius to Fahrenheit\n");
                printf("F: traslate from Fahrenheit to Celsius\n");
                printf("Q: quit\n");

                ret=scanf("%c",& c_or_f);
                if(ret!=1) {
                        fprintf(stderr,"scanf failed\n");
                        return 1;
                }
                switch(c_or_f){
                        case 'C': c2f();break;
                        case 'F': f2c();break;
                        case 'Q':
                                  printf("exiting \n");
                                  run=0;

                
                default:
                        fflush(stdin);
                }
        }
        return 0;
}
