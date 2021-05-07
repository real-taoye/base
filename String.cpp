#include<bits/stdc++.h>
using namespace std;

char* strcpy(char* dst,const char* src){
	assert(dst!=nullptr&&src!=nullptr);
	char* addr=dst;
	if(dst==src){                           //ָ�����򲻿��ظ� 
		return addr;
	}
	while(*src!='\0'){
		*dst++=*src++;
	}
	*dst++='\0';
	return addr;
}

class String{
public:
	String(const char* p=nullptr){
		if(p!=nullptr){
			_pstr=new char[strlen(p)+1];
			strcpy(_pstr,p);
		}
		else{
			_pstr=new char[1];
			*_pstr='\0';
		}
	}
	~String(){
		delete[] _pstr;
		_pstr=nullptr;
	}
	String(const String& str)
	{
		_pstr=new char[strlen(str._pstr)+1];
		strcpy(_pstr,str._pstr);
	}
	String& operator=(const String& str)    //���ص���һ�����ã� thisָ����ǵ�ǰ����ĵ�ַ 
	{
		if(this==&str){
			return *this;      
		}
		delete[] _pstr;
		_pstr=new char[strlen(str._pstr)+1];
		strcpy(_pstr,str._pstr);
		return *this;
	}
	const char* c_str()const{
		return _pstr;
	}
	int length()const{
		return strlen(_pstr);
	}
	char& operator[](int index){                //֧��char ch=str[6]   Ҳ֧��str[6]='7'; 
		return _pstr[index];
	}
	const char& operator[](int index)const{    // ֧��char ch=str[6]   ��֧��str[6]='7'����֧���޸� 
		return _pstr[index];
	}
	bool operator>(const String& str)
	{
		return strcmp(_pstr,str._pstr)>0;
	}
	bool operator<(const String& str)
	{
		return strcmp(_pstr,str._pstr)<0;
	}
	bool operator==(const String& str)
	{
		return strcmp(_pstr,str._pstr)==0;
	}
	//������ָ�����һ��λ�� 
	class iterator{
	public:
		iterator(char* p=nullptr):_p(p){
			
		}
		bool operator!=(const iterator& it){
			return _p!=it._p;
		}
		void operator++()           //ǰ��++ 
		{
			++_p;
		}
		char& operator*()
		{
			return *_p;
		}
	private:
		char *_p;
	};
	
	iterator begin()                         //begin���ص��������ײ���Ԫ�صĵ������ı�ʾ 
	{
		return iterator(_pstr);
	}
	iterator end()                           //end���ص��������ײ�ĩβԪ�غ��λ�õĵ������ı�ʾ 
	{
		return iterator(_pstr+length());
	}
private:
	char *_pstr;
	friend String operator+(const String&str1,const String&str2);
	friend ostream& operator<<(ostream& out,const String& str);
	friend istream& operator>>(istream& in,String& str); 
};
String operator+(const String& str1,const String& str2)
{
	//char *tmp=new char[strlen(str1._pstr)+strlen(str2._pstr)+1];
	String tmp;
	tmp._pstr=new char[strlen(str1._pstr)+strlen(str2._pstr)+1];
	strcpy(tmp._pstr,str1._pstr);
	strcat(tmp._pstr,str2._pstr);
	return tmp;
}
ostream& operator<<(ostream& out,const String &str)
{
	out<<str._pstr;
	return out;
}
istream& operator>>(istream& in,String& str)
{
	in>>str._pstr;
	return in;
}

int main(){
	String str="aabbcc";
	String str2="ffgg";
	String str3=str+str2;
	cout<<str3<<endl;
	cout<<str3[2]<<endl;
//	String str4;
//	cin>>str4;
//	cout<<str4<<endl;
	String::iterator it=str.begin();
	for(;it!=str.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
