// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.

long long int  merge(long long arr[],long long temp[],long long left,long long mid,long long right){
    
    int i,j,k;
    long long int inversions = 0;
    
    i = left;
    j = mid;
    k = left;
    
    while(i<=mid-1 && j<=right){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
            temp[k] = arr[j];
            j++;
            k++;
            
            inversions+=(mid - i);
        }
    }
    
    while(i<=mid-1){
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while(j<=right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for(int s = left;s<=right;s++){
        arr[s] = temp[s];
    }
    
    return inversions;
}

long long int mergesort(long long arr[],long long temp[],long long left,long long right){
    
    long long int inversions = 0;
    
    if(right > left){
        
        long long  mid  = (right + left)/2;
        
        inversions+=mergesort(arr,temp,left,mid);
        inversions+=mergesort(arr,temp,mid+1,right);
        inversions+=merge(arr,temp,left,mid+1,right);
    }
    
    return inversions;
}


long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
   return mergesort(arr,temp,0,N-1);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends