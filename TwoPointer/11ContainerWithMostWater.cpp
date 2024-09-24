#include<vector>
#include<iostream>

int ContainerArea(std::vector<int> &height){
int p1 = 0;
int p2 = height.size() - 1;
int area;
int max_area = 0;
while(p1<p2){
	if(height[p1] < height[p2]){
		area = (p2-p1) * height[p1];
		p1++;

	}
	else{
		area = (p2-p1) * height[p2];
		p2--;

	}

if(area > max_area) max_area = area;
}
return max_area;

}
int main(){
	std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int result = ContainerArea(height);
	std::cout<<"MAX AREA IS: "<<result;
	return 0;
}
