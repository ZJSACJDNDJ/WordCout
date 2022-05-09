#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//统计文件字符数 
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

//统计文件单词数 
int getWord(FILE *fp)
{
	int num=0;
	int a=0,b=0;
	int flag=0;  //作为一个标志位，用来判断该字符的前一个字符是否是逗号还是空格
	char word;   //取出对应位置的字符，用Word去得到它的值

    word = fgetc(fp);   //当读取一个字符后，下次读取前会自动后移到一个字节开始读

	if(word == ' ' || word == ',')//用来判断首字符是否是空格还是逗号
	{
		     flag=1;
			 num--;
			 b--;
	}
	while(feof(fp)==0)
    {
        if(flag == 0 && (word == ' ' || word == ','))//判断该字符是否为逗号或空格，若是则它之前的所有字符归为一个单词，单词数加一
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
		word = fgetc(fp);   //当读取一个字符后，下次读取前会自动后移到一个字节开始读
    }
	
	if(flag==1)//用来判断末尾字符是否为逗号还是空格
	{
	    num=a;
	}
    rewind(fp);
	if(a==b)//用来判断中间是否有被重复计算了的单词数目
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
    	
		fp = fopen(argv[2],"r");        //读取文件的内容
		 
		if(fp == NULL)
		{
			printf("错误：无法打开%s\n",argv[2]);
			exit(1);
		}     //打开失败
		

            //对参数进行匹配，若为"c"则统计字符数目，若为"w"则统计单词数目，若都不是则报错
	       if(!strcmp(argv[1],"-c"))	
			{
		        num = getChar(fp);
		     	printf("字符数为：%d\n",num);
		    }
		
		   else if(!strcmp(argv[1],"-w"))
			{
			    num = getWord(fp);
			    printf("单词数为：%d\n",num); 
			}
           else 
			{
                printf("参数错误 ！");
            }
	}
	else 
	{
		printf("错误：参数输入错误，请重新输入\n");
	}
} 
