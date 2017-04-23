//
int a[n];
int b[k+1];
BuildHeap(b,k);
for(int i=k;i<n;i++)
{
	if(a[i]>b[1])continue;
	b[1]=a[i];
	AdjustDown(b,1,k);
}