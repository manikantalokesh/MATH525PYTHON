// ** Professor some symbols I have used in comments are to edit the style of the comments 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//! factorial of a number
//! function will be called from myexp function
int factorial(int n)
{
    if (n<=1)
    {
        // base case
        return 1;
    }
    else
    {
    // return n*(n-1)!
    return n*factorial(n - 1);
    }
}

// ** exponential of a function using taylor's series
double myexp(double y)
{ 
    int kmax=100;
    double e=2.718281828459;
    double x0=round(y);
    double z=y-x0;
    double exp0=pow(e,x0);
    double s=0;
    for(int i=0;i<kmax;i++){
        double sold=s;
        s=s+(pow(z,i)/factorial(i));
        if (fabs(sold-s)<(10e-14))
        {
            break;
        }
    }
    //** printing the output to check the values in the function it self
    printf("exp0*s:   %lf\n",(exp0*s));
    return exp0*s; 
}



void main(){
    int n;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    double myexparray[n]; 
    double x[n];
    // double exparray[100];
    printf("Enter the values of the array :\n");
    for(int i=0;i<n;i++){
        scanf("%lf",&x[i]);
        // printf("\n");
        myexparray[i]= myexp(x[i]); 
    }
    printf("\n\narray elements are:  \n");
    for(int i=0;i<n;i++)
    {
        printf("%lf \n",myexparray[i]);
    }

    // TODO: Opening a file and storing the data into the file and made sure to close the file
    FILE* output =fopen("result.data","w");
    for (int i = 0; i < n; i++)
    {
        fprintf(output,"%lf\n",myexparray[i]);
    }
    fclose(output);

}