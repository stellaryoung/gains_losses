#include <iostream>
#include <string>
#include <stack>
using namespace std;
class MyStack {
public:
	stack<int> s1;
	stack<int> s2;
	void push(int v) {
		s1.push(v);
		if (s2.empty() == true) {
			s2.push(v);
		}
		else {
			if (s2.top() > v) {
				s2.push(v);
			}
			else {
				s2.push(s2.top());
			}
		}
	}
	void pop() {
		int v = s1.top();
		s1.pop();
		s2.pop();
	}

	int top() {
		return s2.top();
	}
};

int main() {
//	freopen("E:\\patin.txt", "r", stdin);
	int N, v;
	string temp;
	string s1("push");
	string s2("pop");
	string s3("getMin");
	cin >> N;

	MyStack myStack;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		if (temp == s1) {
			cin >> v;
			myStack.push(v);
		}
		else if (temp == s2) {
			myStack.pop();
		}
		else {
			cout << myStack.top() << endl;
		}
	}
	return 0;
}
