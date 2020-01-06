#include <iostream>
#include <string>
#include <stack>

/*
使用2个栈模拟队列的代码
测试结果：运行时间约为1s 
*/ 
using namespace std;
int main() {
//	freopen("E:\\patin.txt", "r", stdin);
	stack<int> stack1;
	stack<int> stack2;
	int N, v;
	string temp;
	string s1("add");
	string s2("poll");
	string s3("peek");
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> temp;
		if (temp == s1) {
			cin >> v;
			stack1.push(v);
		}
		else if (temp == s2) {
			if(stack2.empty()){            //栈2为空，将栈1中的元素一次性全部出栈并入栈2 
				while(!stack1.empty()){
					stack2.push(stack1.top());
					stack1.pop();
				}
			}	
			stack2.pop();
		}
		else{
			if(stack2.empty()){
				while(!stack1.empty()){    
					stack2.push(stack1.top());
					stack1.pop();
				}	
			} 
			cout << stack2.top() << endl;
		}
	}
	return 0;
}
