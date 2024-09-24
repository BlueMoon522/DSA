#include<iostream>
#include<cmath>

//COMPLEXITY: 0LOG(N); RUNTIME: 7MS; BEATS:71.78%
//NOT VERY MEMORY EFFICIENT.
bool isPalindrome(int x){
	if (x<0){
		return false;
	}
	else if(x > 9){
		long long store_x = x; //int is max 4 bytes, there are the test cases will very large numbers.
		long long new_number = 0;
		int scale = std::log10(x); //can't use x  = 0 in log will get indefinite
	    int mod;
		while(x > 0)
		{
		 mod = x % 10;
		 new_number += mod*(std::pow(10, scale));
		 scale--;
		 x = x / 10;
		}
		return (store_x == new_number);
	}
	return true;

}
int main(){
	int number = 9;
	bool result = isPalindrome(number);
	std::cout<<"RESULT IS: "<<result;
	return 0;
}


