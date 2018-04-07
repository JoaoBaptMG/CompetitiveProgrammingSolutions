#include<bits/stdc++.h>
 
using namespace std;
 
long long crivo[1000000]= {0};
 
int main(){
long long m,x;
int ok=0;
for (long long i =2; i<=1000000; i++){
    if ( crivo[i]==0){
        for (long long j=2*i; j<=1000000; j+=i){
            crivo[j]=1;
            }
        }
    }
scanf("%lld", &x);
for(int i=0; i<x; i++){
    scanf("%lld", &m);
    int a=sqrt(m);
    if(a*a==m && crivo[a]==0) {printf("YES\n"); ok=1;}
    if(ok==0) printf("NO\n");
    ok=0;
}
return 0;
}
