#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//ͳ���ļ��ַ��� 
int getChar(FILE *fp)
{
	char ch;
	int num=0;
	while((ch=fgetc(fp))!=EOF)
	{
		num++;
	}
	rewind(fp);
	return num;
}

//ͳ���ļ������� 
int getWord(FILE *fp)
{
	int num=0;
	int a=0,b=0;
	int flag=0;  //��Ϊһ����־λ�������жϸ��ַ���ǰһ���ַ��Ƿ��Ƕ��Ż��ǿո�
	char word;   //ȡ����Ӧλ�õ��ַ�����Wordȥ�õ�����ֵ

    word = fgetc(fp);   //����ȡһ���ַ����´ζ�ȡǰ���Զ����Ƶ�һ���ֽڿ�ʼ��

	if(word == ' ' || word == ',')//�����ж����ַ��Ƿ��ǿո��Ƕ���
	{
		     flag=1;
			 num--;
			 b--;
	}
	while(feof(fp)==0)
    {
        if(flag == 0 && (word == ' ' || word == ','))//�жϸ��ַ��Ƿ�Ϊ���Ż�ո���������֮ǰ�������ַ���Ϊһ�����ʣ���������һ
		{
			 num++;
             flag = 1;
             a++;
        }
        else if( (word != 32 && word != 44) && flag==1) 
        {
            num++;
            flag = 0;
			b++;
        }
		else
		{
		    num=num;
		}
		word = fgetc(fp);   //����ȡһ���ַ����´ζ�ȡǰ���Զ����Ƶ�һ���ֽڿ�ʼ��
    }
	
	if(flag==1)//�����ж�ĩβ�ַ��Ƿ�Ϊ���Ż��ǿո�
	{
	    num=a;
	}
    rewind(fp);
	if(a==b)//�����ж��м��Ƿ��б��ظ������˵ĵ�����Ŀ
	{
	num=num/2+1;
	}
    return num;
}


int main(int argc,char*argv[])
{
	FILE *fp;
	int num;
	char string;

    if(argc==3)
	{
    	
		fp = fopen(argv[2],"r");        //��ȡ�ļ�������
		 
		if(fp == NULL)
		{
			printf("�����޷���%s\n",argv[2]);
			exit(1);
		}     //��ʧ��
		

            //�Բ�������ƥ�䣬��Ϊ"c"��ͳ���ַ���Ŀ����Ϊ"w"��ͳ�Ƶ�����Ŀ�����������򱨴�
	       if(!strcmp(argv[1],"-c"))	
			{
		        num = getChar(fp);
		     	printf("�ַ���Ϊ��%d\n",num);
		    }
		
		   else if(!strcmp(argv[1],"-w"))
			{
			    num = getWord(fp);
			    printf("������Ϊ��%d\n",num); 
			}
           else 
			{
                printf("�������� ��");
            }
	}
	else 
	{
		printf("���󣺲��������������������\n");
	}
} 
