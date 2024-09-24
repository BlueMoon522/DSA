#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class SortingAlgorithm
{
public:
	// DOESNOT WORKS
	std::vector<int> StupidSort(std::vector<int> &height)
	{
		int current_smallest;
		std::vector<int> sorted = {1};
		int vec_size = height.size();
		int smallest = 10000; // brute
		for (int i = 0; i < vec_size; i++)
		{

			for (int j = 0; j < vec_size; j++)
			{

				if (height[i] < height[j])
				{
					current_smallest = height[i];
				}
				else if (height[j] < height[i])
				{
					current_smallest = height[j];
				}

				if (current_smallest < smallest)
				{
					smallest = current_smallest;
				}
			}
			sorted.push_back(smallest);
		}

		return sorted;
	}
};

int main()
{
	std::vector<int> height = {3, 5, 2, 1, 7};
	SortingAlgorithm obj = SortingAlgorithm();
	std::vector<int> result = obj.StupidSort(height);
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
	return 0;
}
