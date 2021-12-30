class Solution {
public:
long double factorial(int n)
{
long double fact=1;
for(int i=n;i>n/2;i--)
{
fact*=i;
}
return fact;
}
long double factorial1(int n)
{
long double fact=1;
for(int i=2;i<=n;i++)
{
fact*=i;
}
return fact;
}
int numTrees(int n) {
int ans;
long double num;
num=factorial(2*n);
ans=num/factorial1(n+1);
return ans;
}
};