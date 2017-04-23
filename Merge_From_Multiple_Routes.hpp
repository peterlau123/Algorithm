//problem statement
//有20个有序数组，每个数组有500个unsigned int元素，若从这10000个元素中选出最大的500个

//method 1:

//method 2:

//method 3:
struct ElemType{

unsigned int value;//值

int source;//来源哪一个数组

}



const int branchsLength=20;//共有20路数据

int len=500;//每一路数组大小

int branches[branchsLength][len]={};

int tree[branchsLength];//败者树的非叶子节点，记录数据索引，根据此索引找到对应的数据

int nodes[branchsLength];//败者树的叶子节点，每个节点记录每一路数据的当前数据

int nodes_iterator[branchsLength]={0};//nodes_iterator[i]记录当前第i路数组已经取到第几个元素


//设置第i个叶子节点的下一个数据
void put(int index)
{
	nodes[index]=branches[index][nodes_iterator[index]++];

}



//取出第i个节点的当前数据
int get(int index)
{
	return nodes[index];

}



//调整第index个叶子节点
void  adjust(int index)
{
	int size=branchesLength;
	int t=(size+index)/2;//父亲结点序号

	while(t>0)
	{
		if(get(tree[t])>get(index))
		{
			int temp=tree[t];
			tree[t]=index;
			index=temp;

		}

		t/=2;
	}

	tree[0]=index;
}

//归并并输出
vector<int> merge(int Num)
{
	vector<int>list1;
	int top;
	int i=0;
	
	while(i<Num)//输出归并后Num个数
	{
		top=tree[0];
		list1.push_back(top);
		i++;
		put(tree[0]);
		adust(tree[0]);
	}



return list1;
}

void init()
{
	int size=branchesLength;
	for(int i=0;i<size;i++)
	{
		put(i);
	}

	//找出出现在哪一个叶子节点的值最大
	int winner=0;
	for(int i=1;i<size;i++)
	{
		if(get(i)>get(winner)){
			winner=i;
		}

	}

	for(int i=0;i<branchesLength;i++)//非叶子节点初始化为冠军节点
		tree[i]=winner;

	for(int i=size-1;i>=0;i--)//从下往上依次调整非叶子节点
		adjust(i);

}
