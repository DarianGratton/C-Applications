// Driver program for the Stack solution 
#include "Stack.cpp"

// Main driver function
int main()
{
	Stack stack_obj;

	cout << "Push function test:" << endl;

	cout << "Before filling stack: " << endl;
	stack_obj.print();
	for (int i = 2; i <= 11; ++i) {
		stack_obj.push(i);
	}
	
	cout << "After filling stack: " << endl;
	stack_obj.print();
	
	cout << "Top function test: ";
	cout << stack_obj.top() << endl;

	stack_obj.pop();
	cout << "Pop function test: ";
	cout << stack_obj.top() << endl;

	cout << "Full function test: ";
	if (stack_obj.full()) {
		cout << "Stack is full" << endl;
	}
	else {
		cout << "Stack is not full" << endl;
	}

	cout << "Empty function test: ";
	if (stack_obj.empty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}

	system("pause"); 
	return 0;
}