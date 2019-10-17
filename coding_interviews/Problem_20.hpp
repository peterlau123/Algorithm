//顺时针打印矩阵

void PrintMatrixClockwisely(int**numbers,int columns,int rows)
{
	
	if(columns==0||rows==0) return;

	int loopmax=min(columns,rows);
	//=========
	int colH=columns;int colL=0;
	int rowH=rows;int rowL=0;

	for(int loop=0;loop*loop<loopmax;loop++)
	{
		int j=loop;
		int i=loop;
		
		//考虑只有一列或只有一行，或者只有一个元素的情况
		if(rowL=rowH-1)
		{
			for(;j<colH;j++)
			{
			printf("%d ",numbers[i][j]);

			}

			break;
		}

		if(colL=colH-1)
		{
			for(;i<rowH;i++)
			{
			printf("%d ",numbers[i][j]);
			}

			break;
		}

		//一圈至少包含两行两列
		for(;j<colH;j++)
		{
			printf("%d ",numbers[i][j]);

		}
		j--;i++;//adjust index,prevent 重复打印


		for(;i<rowH;i++)
		{
			printf("%d ",numbers[i][j]);

		}
		i--;j--;


		for(;j>=colL;j--)
		{
			printf("%d ",numbers[i][j]);

		}
		j++;i--;


		for(;i>rowL;i--)
		{
			printf("%d ",numbers[i][j]);

		}

		//adjust boundaries
		colH-=1;colL+=1;
		rowH-=1;rowL+=1;

	}

}