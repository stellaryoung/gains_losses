#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getAndRemoveLastElement(stack<int> &myStack){
	int v = myStack.top();
	myStack.pop();
	if(myStack.empty() == true){
		return v;	
	}else{
		int res = getAndRemoveLastElement(myStack);
		myStack.push(v);
		return res;	
	}
}

void reverse(stack<int> myStack){
	if(myStack.empty() == true){
		return;
	}else{
		int v = getAndRemoveLastElement(myStack); 
		reverse(myStack);
		myStack.push(v);	
	}
}

int main()
{
//	freopen("E:\\patin.txt", "r", stdin);
	stack<int> myStack;
	int n;
	scanf("%d",&n);
	int tmp;
	for(int i = 0;i < n;++i){
		scanf("%d",&tmp);
		myStack.push(tmp);
	}
		
	reverse(myStack);
	for(int i = 0;i < n;++i){        //牛客网程序的输出格式要求比较奇怪，输出的每行后要有一个空格，否则会出报格式错误 
		tmp = myStack.top();
		myStack.pop();
		printf("%d ",tmp);
	}
	printf("\n"); 
	return 0;	
} 
