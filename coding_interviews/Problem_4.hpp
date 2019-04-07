//替换空格
//length是字符数组的总容量
//by liuxin on 17.4.20
void ReplaceBlank(char string[],int length)
{
	if(string==NULL||length<=0)return;

	//
	int originallength=0; 
	int numOfBlank=0;
	int i=0;

	//先统计空格数目及原来的数组有效长度，不适合用strlen
	while(string[i]!='/0')
	{
		originallength++;
		if(string[i]==' ')numOfBlank++;

		i++;
	}

	int offset=numOfBlank<<1;
	int newLength=originallength+offset;

	if(newLength>length)return;

	int k=newLength-1;
	for(int i=originallength-1;i>=0;i--)
	{
		if(string[i]==' ')
		{
			string[k]='0';
			string[--k]='2';
			string[--k]='%';
			

		}else{

			string[k]=string[i];


		}
		--k;
	//============	
	}


}