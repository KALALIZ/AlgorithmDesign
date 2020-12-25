//Silalak Kaewjanpet sec 001
//610510670

#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int RopeKnapsack(int rope, int val[], int buy, int weigh[])
{
	int array[buy+1];
    memset(array, 0, sizeof array);

    for(int i=0; i<=buy; i++)
    {
        for(int j=0; j<rope; j++)
        {
            if(weigh[j] <= i)
            {
                array[i] = max(array[i], array[i-weigh[j]] + val[j]);
            }
        }
    }
    return array[buy];
}


int main()
{
	int rope;
    cin >> rope;
    int val[rope];
    for(int i=0; i<rope; i++)
    {
        cin >> val[i];
    }
    int weigh[rope];
    for(int i=0; i<rope; i++)
    {
        weigh[i] = i+1;
    }
    int buy; 
    cin >> buy;

    cout << RopeKnapsack(rope, val, buy, weigh);
    return 0;
}
