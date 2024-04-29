#include<stdio.h>

#include<string.h>

#include<math.h>


void karp(char T[],char P[],int q){

int d=10;

int n=strlen(T);

int m=strlen(P);

int p=0,t=0;

int j;

int h=(int)(pow(d,m-1))%q;

    

for(int i=0;i<m;i++){

     p=(d*p+P[i])%q;

     t=(d*t+T[i])%q;

}

    

for(int i=0;i<=n-m;i++){

     if(p==t){

         for(j=0;j<m;j++){

             if(T[i+j]!=P[j]){

                 break;

             }

         }

         if(j==m){

             printf("Pattern found at index %d\n",i);

         }

     }

     

     if(i<m-n){

         t=(d*(t-h*T[i])+T[i+m])%q;

     }

}

}


void main(){

char T[]="AABAACAADAABAAABAA";

char P[]="AABA";

int q=101;

karp(T,P,q);

}

