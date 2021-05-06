#include<bits/stdc++.h>
using namespace std;

void* memcpy(void* dst,void* src,size_t size){
	char* pdst;
	char* psrc;
	if(dst==nullptr||src==nullptr){
		return NULL;
	}
	
	if(src<dst && (char*)src+size>(char*)dst){  //如果dst和src内存发生重叠时 
		psrc=(char*)src+size-1;
		pdst=(char*)dst+size-1;
		while(size--){
			*pdst--=*psrc--;
		}
	}
	else{
		psrc=(char*)src;
		pdst=(char*)dst;
		while(size--){
			*pdst++=*psrc++;
		}
	}
	return dst;
}

int main(){
	char buf[100]="abcdefghijmkl";
	memcpy(buf+2,buf,5);
	printf("%s\n",buf+2);
	return 0;
}
