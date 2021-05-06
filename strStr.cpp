#include<bits/stdc++.h>
using namespace std;

void getNext(string str,vector<int>& next){
	int j=0;
	next[0]=0;
	for(int i=1;i<str.size();i++){
		while(j>0&&str[j]!=str[i]){
			j=next[j-1];
		}
		if(str[j]==str[i]){
			j++;
		}
		next[i]=j;
	}
}

//����ƥ�����match���׸��ַ���sour�е�λ�� 
int strStr(string sour,string match){
	if(match.size()==0){
		return 0;
	}
	vector<int> next(match.size(),0);
	getNext(match,next);
	
	int j=0;   //j��ָ��ģʽ����ǰ����λ��
	for(int i=0;i<sour.size();i++){   //i��ָ���ı�����ǰ����λ�� 
		while(j>0&&sour[i]!=match[j]){
			j=next[j-1];
		}
		if(sour[i]==match[j]){
			j++;
		}
		if(j==match.size()){
			return (i-match.size()+1);
		}
	} 
	return -1;
}


int main(){
	string s1="aabaabaaf";
	string s2="aabaaf";
	int loc=strStr(s1,s2);
	cout<<loc<<endl;
	return 0;
}
