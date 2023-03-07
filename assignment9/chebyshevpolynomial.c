#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void WritePoly(const int NumPts, const double x[], double y[]);
void WritePoly(const int NumPts, const double x[], double y[])
{
    FILE* fp;
    fp = fopen("poly.data", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < NumPts; i++)
    {
        fprintf(fp, "%lf %lf\n", x[i], y[i]);
    }
    fclose(fp);
}

void SamplePoly(const int N,
                    const int Numpts,
                    const double b[],
                    const double x[],
                    double y[])
    {
        for (int i = 0; i < Numpts; i++)
        {
            const double a=x[i]; double phi; y[i]=b[0];
            for(int k=1; k<=N; k++ )
            {
                switch(k)
                {
                    case 1: phi=a;
                    break;
                    case 2: phi=2*pow(a,2)-1;
                    break;
                    case 3: phi =4*pow(a,3)-(3*a);
                    break;
                    case 4:phi =8*pow(a,4)-8*pow(a,2)+1;
                    break;
                    case 5: phi=16*pow(a,5)-20*pow(a,3)+5*a;
                    break;
                }
                y[i] +=b[k]*phi; 
            }
        }
        
    }

int main()
{
    const int Nmax=5;
    int N;
    printf("\n INput polynomial degree (0-%i): ",Nmax);
    scanf("%i",&N);

    if(N<0 || N>Nmax)
    {
        printf("Invalid value of N =%i\n\n",N);
        printf("N must satisfy: 0<=N<= %i\n\n",Nmax);
        exit(1);
    }
    printf("\n");
    // read-in coefficients
    double b[Nmax+1];
    for (int i = 0; i <=N; i++)
    {
        printf("set b[%i]: ",i);
        scanf("%lf",&b[i]);
    }
    printf("\n");
    // set x-coordinates
    const int Numpts=21;
    double x[Numpts];
    for(int i=0;i<=Numpts;i++)
    {
        x[i]= -1.0+i*(2.0/(1.0*(Numpts-1)));
    }
    // calculate polynomial at X coordinates
    double y[Numpts];
    void SamplePoly(const int N,
                    const int Numpts,
                    const double b[],
                    const double x[],
                    double y[]);
    SamplePoly(N,Numpts,b,x,y);

    // write into file
    
    WritePoly(Numpts,x,y);
    // calling the python file which contains the plot
    system("python PlotPoly.py");
    // execv("/usr/bin/python")
    return 0;
    
}
