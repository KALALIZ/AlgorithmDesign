//Silalak Kaewjanpet sec 001
//610510670

#include <stdio.h>
//#include <conio.h>


void PutInBag() 
{
    int N, W, c = 0;            //N = จำนวนสิ่งของ W = น้ำหนักที่รับได้
    int weight; 
    float val = 0;
    scanf("%d,%d", &N, &W); 
    int object[N*2];
    int i;
    for(i=0; i<N*2; i++)
    {
        scanf("%d",&object[i]); 
    }

    for(i=0; i<N*2; i=i+2)
    {
        if(object[i+1] < W)
        {
            val += object[i];
            W = W - object[i+1];         
        }
        else
        {
            val += ((object[i]*W)/object[i+1]);
        }
        
    }
    printf("%.2f",&val);

    
}




int main()
{
    PutInBag();
    
}