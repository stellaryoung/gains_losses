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
		helpStack.push(cur);            //cur指向辅助栈的栈顶元素，元素依旧在栈内 
		
		while(!orderStack.empty()){
		
			int next = orderStack.top();   //next是当前排序栈出栈元素，也是下一个要入栈的元素 
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
					
					if(!helpStack.empty())     //这里卡bug卡了一段时间，为避免犯错，对栈进行top或者pop操作前一定要检查栈是否为空 ，虽然语句上啰嗦点，但逻辑上设计总是容易出现缺陷 
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
