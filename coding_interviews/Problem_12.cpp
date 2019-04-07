//method1:使用递归实现全排列
void PrintNum(char *num)
{
	if(num==NULL)return;
	bool beginFlag=true;
	int i=0;
	int len=strlen(num);
	while(i<len)
	{
		if(beginFlag&&num[i]!='0')
			beginFlag=false
		if(!beginFlag)
		{

			printf('%c',num[i]);	
		}
		i++;
	}

}
void PrintToMaxOfNDigitsRecursively(char*p,int index,int length)
{
	if(index==length-1)
	{
			PrintNum(p);
			return;
	}

	index+=1;
	for(int j=0;j<10;j++)
	{
		
		p[index]=p[index]-'0'+j;
		PrintToMaxOfNDigitsRecursively(p,index,length)
	}

}

void PrintToMaxOfNDigits(int n)
{
	if(n<=0)return ;

	char *p=new char[n+1];
	memset(p,'0',n);
	p[n]='\0';
	int len=strlen(p);
	for(int i=0;i<len;i++)
	{
		p[0]=p[0]-'0'+i;

		PrintToMaxOfNDigitsRecursively(p,0,len);
	}
delete []p;
}

//method 2,先对字符串表示的数加一，接着在输出
bool Increment(char *num)
{
	if(num==NULL)return true;
	int len=strlen(num);
	bool flag=false;
	int upvalue=0;
	int tmp=num[len-1]-'0'+1+upvalue;
	if(len==1&&tmp==10)return true;


	int i=len-2;
	while(0<=i&&tmp==10)
	{
		num[i+1]='0';
		upvalue=1;

		num[i]=num[i]-'0'+upvalue;

		tmp=num[i];
		if(i==0&&tmp==10)
		{
			flag=true;
			return flag;
		}

	i--;

	}


return flag;

}



void PrintToMaxOfNDigits(int n)
{

	if(n<=0)return ;

	char *p=new char[n+1];
	memset(p,'0',n);
	p[n]='\0';

	while(!Increment(p))
	{

		PrintNum(p);
	}


return ;

}