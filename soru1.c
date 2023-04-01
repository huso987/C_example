#include<stdio.h>
#include <limits.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int maxProfit(int *price, int priceSize,int *buyDays, int *sellDays)
{   
   int first_buy = INT_MIN;
   int first_sell = 0;
   int second_buy = INT_MIN;
   int second_sell = 0;
   for(int i=0;i<priceSize;i++) { 
     first_buy = max(first_buy,-price[i]);
     first_sell = max(first_sell,first_buy+price[i]);
     second_buy = max(second_buy,first_sell-price[i]);
     second_sell = max(second_sell,second_buy+price[i]);
   }
   
   return second_sell;
}

int main()
{ 
   int n;
   printf("pricesize gir:");
   scanf("%d", &n);

   int price[n];
   for(int i=0; i<n; i++) 
   {
    printf("%d ci price gir:",i+1);
    scanf("%d", &price[i]);
   }
   printf("Maximum Profit = %d", maxProfit(&price, n));
   return 0;
}