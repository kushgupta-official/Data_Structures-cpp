# include <bits/stdc++.h>

using namespace std;
# define ll long long int

map<char,int> precedence;


int main(){
	precedence['*']=1;
	precedence['/']=1;
	precedence['+']=2;
	precedence['-']=2;
	precedence['^']=0;
	int test_cases=0;
	cout<<"Enter number of test_cases : ";
	cin>>test_cases;
	while(test_cases--){
		string s="";
		cout<<"Enter Infix expression : ";
		cin>>s;
		s='('+s+')';
		string result="";
		stack <char>st;
		for (int i=0;i!=s.size();i++){
			switch(s[i]){
				case '(':	st.push('(');
							break;
				case ')':	while(st.top()!='('){
								char ch=st.top();
								result=result+ch;
								st.pop();
							}
							st.pop();
							break;
				case '+':	while (st.top()!='(' && precedence[st.top()]<=precedence['+']){
								result=result+st.top();
								st.pop();
							}
							st.push('+');
							break;
				case '-':	while (st.top()!='(' && precedence[st.top()]<=precedence['-']){
								result=result+st.top();
								st.pop();
							}
							st.push('-');
							break;
				case '*':	while (st.top()!='(' && precedence[st.top()]<=precedence['*']){
								result=result+st.top();
								st.pop();
							}
							st.push('*');
							break;
				case '/':	while (st.top()!='(' && precedence[st.top()]<=precedence['/']){
								result=result+st.top();
								st.pop();
							}
							st.push('/');
							break;
				case '^':	while (st.top()!='(' && precedence[st.top()]<=precedence['^']){
								result=result+st.top();
								st.pop();
							}
							st.push('^');
							break;
				default:	result=result+s[i];
			}
			if (!st.empty()){
				stack <char>temp=st;
				string t="";
				while(!temp.empty()){
					t=temp.top()+t;
					temp.pop();
				}
				cout<<s[i]<<"\t"<<t<<"\t"<<result<<endl;
			}
		}
		cout<<"Postfix : "<<result<<endl;
	}
	return 0;
}