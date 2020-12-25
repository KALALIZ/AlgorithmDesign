//Silalak Kaewjanpet sec 001
//610510670

// C/C++ program to solve fractional Knapsack Problem 
#include <bits/stdc++.h> 
#include <iostream>
#include <array>
using namespace std; 

// Structure for an item which stores weight and corresponding 
// value of Item 
struct Item 
{ 
	int value, weight; 

	// Constructor 
	Item(int value, int weight) : value(value), weight(weight) 
	{} 
}; 

// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 

// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
	// sorting Item on basis of ratio 
	sort(arr, arr + n, cmp); 

	// Uncomment to see new order of Items with their ratio 
	/* 
	for (int i = 0; i < n; i++) 
	{ 
		cout << arr[i].value << " " << arr[i].weight << " : " 
			<< ((double)arr[i].value / arr[i].weight) << endl; 
	} 
	*/

	int curWeight = 0; // Current weight in knapsack 
	double finalvalue = 0.0; // Result (value in Knapsack) 

	// Looping through all Items 
	for (int i = 0; i < n; i++) 
	{ 
		// If adding Item won't overflow, add it completely 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 

		// If we can't add current Item, add fractional part of it 
		else
		{ 
			int remain = W - curWeight; 
			finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
			break; 
		} 
	} 

	// Returning final value 
	return finalvalue; 
} 

// driver program to test above function 
int main() 
{ 
    int N, W;
    cin >> N >> W;
    
    int valwt[][];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> valwt[i][0] >> valwt[0][j];
        }
        
    }

	//int W = 50; // Weight of knapsack 
	Item arr = valwt; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << fractionalKnapsack(W, arr, n); 
	return 0; 
} 
