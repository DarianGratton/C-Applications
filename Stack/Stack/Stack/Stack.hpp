// Header file for the Stack solution

constexpr int max = 10;

class Stack {
private:
	int stack[max];
	int curr_top; // Stores the index of the current top of the stack
public:
	Stack() : curr_top(-1), stack() { }
	void push(int);
	void pop();
	const int top();
	const bool empty();
	const bool full();
	const void print();
	int getCurrtop();
};