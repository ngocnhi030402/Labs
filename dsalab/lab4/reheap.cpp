#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index < 0 || index >= numberOfElements || numberOfElements == 0){
        return;
    }
    else{
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = 0;
        if(left <= numberOfElements && right <= numberOfElements){
        if(right <= numberOfElements && maxHeap[right] > maxHeap[left]) largest = right;
        else largest = left;
            
        if(maxHeap[largest] > maxHeap[index]){
            swap(maxHeap[largest], maxHeap[index]);
            reheapDown(maxHeap, numberOfElements, largest);
        }
        }
        
        
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index < 0 || index >= numberOfElements || numberOfElements == 0){
        return;
    }
    else{
        int max = (index - 1)/2;
        if(maxHeap[max] < maxHeap[index]){
            swap(maxHeap[max], maxHeap[index]);
            reheapUp(maxHeap, numberOfElements, max);
        }
    }
    
}
int main(){
    
}