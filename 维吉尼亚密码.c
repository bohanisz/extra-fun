#include <stdio.h>
#include <string.h>
//���� 
void enc(char* plain,char* key,char* cipher)
{
	int l;
	l=strlen(key);   //�õ��ؼ��ֵĳ��� 
	for(int i=0;plain[i]!='\0';i++)
	{
		cipher[i] = ( ((plain[i]-'a') + ( key[i % l]) -'a' ) % 26 )+'a' - 32;   //�׹�ʽ 
	} 
}

//����
void dec(char* plain,char* key,char* cipher) 
{
	int l;
	l=strlen(key);   //�õ��ؼ��ֵĳ��� 
	for(int i=0;cipher[i]!='\0';i++)
	{
		plain[i] = ( ((cipher[i]-'a'+32) - (( key[i % l]) - 'a')+26 ) % 26 )+'a';   //�׹�ʽ 
	} 
}

int main()
{
	//int a=0;
	//char b=(char)(a+'a'-32);
	//printf("%c",b);
	char plain[100] = "";
	char key[100]  = "";
	char cipher[100] = "";
	int t;
	printf("����1 ����2 ��ҵ�����ʽ3 ������1��2��3\n");
	scanf("%d",&t);
	if(t==1) 
	{
		scanf("%s",plain);
		scanf("%s",key);
		enc(plain,key,cipher);
		printf("%s",cipher);
	}else if(t==2)
	{
		scanf("%s",cipher);
		scanf("%s",key);
		dec(plain,key,cipher);
		printf("%s",plain);
	}else if(t==3)
	{
		scanf("%s",plain);
		scanf("%s",key);
		int l=strlen(key);
		for(int i=0;plain[i]!='\0';i++)
		{
			printf("%c",key[i%l]);
		}
		printf("\n");
		enc(plain,key,cipher);
		dec(plain,key,cipher);
		printf("%s\n",cipher);
		printf("%s\n",plain);
		
	}

 	
}
