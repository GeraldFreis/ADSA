#include 	<iostream>
#include 	<cstring>
#include 	<string>
#include 	<vector>


static int col_counter;
void column_counter(std::string given_line);
int **existing_road_matrix_maker(std::string line);
int **building_road_matrix_maker(std::string line);
int **destroy_road_matrix_maker(std::string line);
void printarray(int **arr);

int alltraversals(int **existing_array, int **building_array, int **destroy_array);

/*
Constraints for the assignment:
We need, after reconstruction, exactly one path between each city pairs
-> can not have multiple paths between cities (can we just create a ring route?)
--> Ring route will not be an optimal solution
We need to find the minimal cost for reconstruction (minimal cost to ensure that there is exactly one path between city pairs)
*/

int main()
{
	col_counter = 0;
	std::string line;
	std::getline(std::cin, line); // saving all information into line which we can then separate

	column_counter(line); // finding out how big our matrices need to be
	int **existing_road_matrix = existing_road_matrix_maker(line);
	int **building_road_matrix = building_road_matrix_maker(line);
	int **destroy_road_matrix = destroy_road_matrix_maker(line);

	// reading in works woo
	printarray(existing_road_matrix);
	std::cout <<'\n';
	printarray(building_road_matrix);
	std::cout <<'\n';
	printarray(destroy_road_matrix);
	std::cout <<'\n';
	// std::cout << '3';

}
// function to count how many columns we are going to need (and then also the row amount because it is a n*n matrix)
void column_counter(std::string given_line)
{
	int counter = 0;
	for(int i = 0; i < given_line.size(); i++)
	{
		if(given_line.at(i) == ' ') // breaking the loop if we hit a space (this signifies the end of the cols)
		{
			counter++;
			break;
		} 
		else if(given_line.at(i) == ',')
		{
			counter++;
		}
	}
	col_counter = counter; // setting the col_counter to be the amount of columns we need
	return;
}



// for this assignment we need an existing road  matrix maker, a builder matrix maker and a destroyer matrix maker

// the function that creates the existing road matrix
int **existing_road_matrix_maker(std::string line)
{
	// we take the first col_counter partitions
	// allocating the matrix
	int n = col_counter;
	int **existing_road_matrix = new int*[col_counter]; // n * n matrix
	for(int i = 0; i < col_counter; i++) 
	{
		existing_road_matrix[i] = new int[col_counter];
	}

	// transferring the stuffs into the matrix
	int row_index = 0; int col_index = 0;
	for(int i = 0; i < line.size() && i < (n*n + n); i++){ // iterating over the string until we hit n*n + n
		// std::cout << line.at(i) << " ";
		if(line.at(i)==','){col_index++;}
		else if(line.at(i) == ' '){row_index++;}
		else {existing_road_matrix[row_index][col_index] = line.at(i)-48;}
	}

	return existing_road_matrix;
}

// function that creates the matrix for building cost
int **building_road_matrix_maker(std::string line)
{
	int n = col_counter;
	int **building_road_matrix = new int*[col_counter]; // n * n matrix
	for(int i = 0; i < col_counter; i++) 
	{
		building_road_matrix[i] = new int[col_counter];
	}

	// transferring the stuffs into the matrix
	int row_index = 0; int col_index = 0;
	for(int i = (n*n+n); i < line.size() && i < 2*(n*n + n); i++){ // iterating over the string until we hit 2(n*n + n)+1
		
		if(line.at(i) == ','){row_index++; col_index = 0;}
		else {
			if(line.at(i) >= 'a' && line.at(i) <= 'z'){
				building_road_matrix[row_index][col_index] = line.at(i)-'a' + 26; col_index++;
			} else {
				building_road_matrix[row_index][col_index] = line.at(i)-'A'; col_index++;
			}
		}
	}

	return building_road_matrix;
}

int **destroy_road_matrix_maker(std::string line)
{
	int n = col_counter;
	int **destroy_road_matrix = new int*[col_counter]; // n * n matrix
	for(int i = 0; i < col_counter; i++) 
	{
		destroy_road_matrix[i] = new int[col_counter];
	}

	// transferring the stuffs into the matrix
	int row_index = 0; int col_index = 0;
	for(int i = 2*(n*n+n); i < line.size(); i++){ // iterating over the string until we hit the end (starting from 2*(n*n+n)+1)
		if(line.at(i) == ','){row_index++; col_index = 0;}
		else {
			if(line.at(i) >= 'a' && line.at(i) <= 'z'){
				destroy_road_matrix[row_index][col_index] = line.at(i)-'a' + 26; col_index++;
			} else {
				destroy_road_matrix[row_index][col_index] = line.at(i)-'A'; col_index++;
			}
		}
	}

	return destroy_road_matrix;
}

void printarray(int **arr){
	for(int i = 0; i < col_counter; i++){
		for(int j = 0; j < col_counter; j++){
			std::cout << arr[i][j] << " ";
		} std::cout << std::endl;
	}
}


int alltraversals(int **existing_array, int **building_array, int **destroy_array)
{
	int n = col_counter;

}

