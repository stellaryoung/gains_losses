#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
//	freopen("E:\\patin.txt", "r", stdin);
    int num;
    scanf("%d",&num);
    stack<int> orderStack;
    stack<int> helpStack;
    int tmp;
    for(int i = 0;i < num;++i){
        scanf("%d",&tmp);
        orderStack.push(tmp);
    }
    if(!orderStack.empty()){
        int cur = orderStack.top(); 
		orderStack.pop();
		helpStack.push(cur);            //curָ����ջ��ջ��Ԫ�أ�Ԫ��������ջ�� 
		
		while(!orderStack.empty()){
		
			int next = orderStack.top();   //next�ǵ�ǰ����ջ��ջԪ�أ�Ҳ����һ��Ҫ��ջ��Ԫ�� 
			orderStack.pop();
			if(next <= cur){
				helpStack.push(next);
				cur = next;
			}else{      
				int p = cur;     
				while(p < next){
					if(helpStack.empty())
						break;
					else
						helpStack.pop();
					orderStack.push(p);
					
					if(!helpStack.empty())     //���￨bug����һ��ʱ�䣬Ϊ���ⷸ����ջ����top����pop����ǰһ��Ҫ���ջ�Ƿ�Ϊ�� ����Ȼ����φ��µ㣬���߼�������������׳���ȱ�� 
						p = helpStack.top();
					else
						break;
				}      
				helpStack.push(next);
				cur = next;         
			}	
		}  
    }

    while(!helpStack.empty()){
    	int tmp = helpStack.top();
    	helpStack.pop();
    	orderStack.push(tmp);
	}
	
	while(!orderStack.empty()){
		int tmp = orderStack.top();
		orderStack.pop();
		printf("%d ",tmp);	
	} 
    
    return 0;   
}
