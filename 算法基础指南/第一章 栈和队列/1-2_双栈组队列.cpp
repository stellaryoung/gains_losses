#include <iostream>
#include <string>
#include <stack>

/*
ʹ��2��ջģ����еĴ���
*/ 
using namespace std;
class TwoStackQueue{
public:
	stack<int> s1;
	stack<int> s2;
	void push(int v) {
		s1.push(v);
	}
	void poll() {
		if(s2.empty()){            //ջ2Ϊ�գ���ջ1�е�Ԫ��һ����ȫ����ջ����ջ2 
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}	
		s2.pop();
	}

	int peek(){
		if(s2.empty()){
			while(!s1.empty()){    
				s2.push(s1.top());
				s1.pop();
			}	
		} 
		return s2.top();
	}
};

int main() {
//	freopen("E:\\patin.txt", "r", stdin);
	int N, v;
	string temp;
	string s1("add");
	string s2("poll");
	string s3("peek");
	cin >> N;

	TwoStackQueue twoStackQueue;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		if (temp == s1) {
			cin >> v;
			twoStackQueue.push(v);
		}
		else if (temp == s2) {
			twoStackQueue.poll();
		}
		else {
			cout << twoStackQueue.peek() << endl;
		}
	}
	return 0;
}
