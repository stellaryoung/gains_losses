#include <iostream>
#include <string>
#include <stack>

/*
ʹ��2��ջģ����еĴ���
���Խ��������ʱ��ԼΪ1s 
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
			if(stack2.empty()){            //ջ2Ϊ�գ���ջ1�е�Ԫ��һ����ȫ����ջ����ջ2 
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
