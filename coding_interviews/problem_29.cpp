

int MoreThanHalfNum(int * numbers,int length)
{
	//check the array
	

	int result=numbers[0];
	int c=1;

	for(int i=1;i<length;i++)
	{
	   if(numbers[i]==result)
	   {
	   
	   c++
	   
	   }

	   if(numbers[i]!=result)
	   {
	   
	   
	   c--;
	   
	   }


	   if(c==0)
	   {
	     result=numbers[i];
	     c=1;
	   
	   }	
	
	}

	//check result


}
