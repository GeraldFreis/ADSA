
#include <iostream>

int *minmax(int *, int);
int *countingSort(int *, int);
int *radixSort(int *, int);

int main(){
	int arr[5] = {0,1,3,1,2};
	int *returned = countingSort(arr, 5);
	for(int i= 0; i < 5; i++){
		std::cout << returned[i] << " ";
	}
	std::cout <<"\n";
}

/* takes in formal parameters int* array, int n
returns int* array = {min,max} */   
int *minmax(int *array, int n){
	// assuming n = array.size()

	int min=array[0], max=array[0];
	for(int i = 0; i < n; i++){
		if(min > array[i]) min=array[i];
		else if(max < array[i]) max=array[i];

		if(min > max){int temp=max; max=min; min=temp;}
	}

	int *dos=new int[2];
	dos[0]=min; dos[1]=max;
	return dos;
}


/* uses counting sort on array */
int *countingSort(int *array, int n){
	int *returnedminmax=minmax(array, n);
	int range=(returnedminmax[1]-returnedminmax[0]), min=returnedminmax[0], max=returnedminmax[1];

	int counted_vals[range]; for(int i = 0; i < range; i++) counted_vals[i]=0;

	for(int i = 0; i < n; i++){
		counted_vals[array[i]] += 1;
	}


	// turning counted_vals into an array
	int *returned_array = new int[n];

	int x=0;
	for(int i = min; i <= max; i++){
		std::cout << counted_vals[i] << "\n";
		if(counted_vals[i]==0){continue;}
		else{
			for(int j = 0; j < counted_vals[i]; j++){
				// std::cout << i << "\n";
				returned_array[x] = i;
				x++;
			}
		}
	}
	return returned_array;
}

// quicksort will be the sort of choice for the radix algorithm
int *quickSort(int *array, int n)
{

}


int *radixSort(int *array, int n) 
{

}