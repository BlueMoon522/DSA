#include <iostream>

#define MAX_SIZE 100

class Stack
{
public:
	int pointer = -1;
	int stack[MAX_SIZE];

public:
	void push(int item)
	{
		if (pointer < MAX_SIZE)
		{
			pointer++;
			stack[pointer] = item;
		}
		else{
		std::cout << "ARRAY LIMIT EXCEEDED \n";
		}
	}

	void pop()
	{
		if (pointer == -1)
		{
			std::cout << "NO ITEMS TO POP";
		}
		else{
		pointer--;
		}
	}

	void display()
	{
		if (pointer == -1)
		{
			std::cout << "NO ITEMS TO DISPLAY";
		}
		for (int i = 0; i < pointer + 1; i++)
		{
			std::cout << "ITEM: " << stack[i] << std::endl;
		}
	}
};

int main()
{
	Stack stack_obj = Stack();
	stack_obj.push(5);
	stack_obj.push(6);
	stack_obj.push(7);
	stack_obj.display();
	stack_obj.pop();
	stack_obj.display();
	return 0;
}