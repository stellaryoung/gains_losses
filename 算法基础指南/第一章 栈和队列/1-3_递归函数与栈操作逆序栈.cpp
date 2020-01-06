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
	for(int i = 0;i < n;++i){        //ţ��������������ʽҪ��Ƚ���֣������ÿ�к�Ҫ��һ���ո񣬷���������ʽ���� 
		tmp = myStack.top();
		myStack.pop();
		printf("%d ",tmp);
	}
	printf("\n"); 
	return 0;	
} 
