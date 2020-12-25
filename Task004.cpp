//Silalak Kaewjanpet sec 001
//610510670
#include <iostream>
#include <string.h> 

using namespace std;

int main(){ 

	string text1, text2;

	cin >> text1;
	cin >> text2;

	int n1 = text1.length();
	int n2 = text2.length();

	int array[n1+1][n2+1];
	int i;

	for(i = 0; i <= n1; i++){ 
		array[i][0] = 0;
	}

	for(i = 0; i <= n2; i++){ 
		array[0][i] = 0;
	}
	
	for(i = 1; i <= n1; i++)
    {
		for(int j = 1; j <= n2; j++)
        {
			if(text1[i-1] == text2[j-1])
            { 
				array[i][j] = 1 + array[i-1][j-1];
			}
            else
            {
				array[i][j] = max(array[i-1][j], array[i][j-1]);

			}
		}
	}

	cout << array[n1][n2];
}
