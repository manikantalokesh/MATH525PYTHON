int main()
 {
 // function declaration
 int binomial(int n,int k);

 // Pascal’s triangle
 printf("\n Pascal’s Triangle:\n\n");
 for (int n=0; n<=10; n++)
 for (int k=0; k<=n; k++)
 {
 int ans = binomial(n,k);
 printf("%5i",ans);
 if (k==n)
 { printf("\n"); }
 }
 printf("\n");
 return 0;
}


int binomial(int n,int k)
 {
 // function declaration
 int factorial(int n);

 // return n choose k
 return factorial(n) / (factorial(k) * factorial(n -k));
 }


 // recursive factorial function
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





