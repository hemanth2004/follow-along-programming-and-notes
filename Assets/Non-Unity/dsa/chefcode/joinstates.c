#include <stdio.h>

#define MAX 100

void Delete(int index, int count, int* array)
{
    for(int i = index; i < count; i++)
    {
        *array = *(array+1);
    }
}

int main() {
	// your code goes here
	int testcases = 1;
	scanf("%d", &testcases);
	
	while(testcases--)
	{
	    int N;
	    int M;
	    scanf("%d", &N);
	    scanf("%d", &M);
	    
	    int A[MAX];
	    
	    for(int i = 0; i<N; i++)
	        scanf("%d", &A[i]);
	        
	    for(int i = 0; i < N; i++)
	    {
	        if(A[i] < M)
	        {
	            if(A[i+1] < M)
	            {
	                A[i] += A[i+1];
	                Delete(i, N, A);
	                N--;
	                i--;
	            }
	        }
	    }
	    
	    
	    
	    int no_literate_states;
	    for(int i = 0; i< N; i++)
	    {
	        if(A[i] >= M)
	         no_literate_states++;
	    }
	    
	    return no_literate_states;
	    
	}

}
