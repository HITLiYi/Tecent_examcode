/*
本内容为腾讯在线笔试的五道测试题
*/
#include <iostream>
#include <string>
using namespace std;

/*
判断正整数是否是对称数，如3，123,121,12321。不能把整数转为字符串来判断。
//返回 1：对称，0：不对称
*/
int ismirror( int value )
{
	int reversenum,inputdata;
	reversenum=0;
	inputdata=value;
	while(value!=0)
	{
		reversenum=reversenum*10+value%10;
		value/=10;
	}
	if (reversenum==inputdata)
		return 1;
	else
		return 0;
}

/*
给定一个递增循环整数数组，从里面找出最小的元素，使用的算法越快越好。
特别地，最小的元素可能出现在数组中间。比如：50, 52, 63, 90, 3, 8, 15, 44
findmin1采用遍历法，findmin2采用二分法
*/
int findmin1( int array[], int count )
{
	int value,i;
	for(i=0;i<count-1;i++)
	{
		if (array[i]<array[i+1])
		{
			value=array[i];
		    array[i+1]=value;
		}
		else
		{
			value=array[i+1];
		    break;
		}
	}
	return value;	
}
int findmin2( int array[], int count )
{
	int *phead,*ptail,*pmid,value;
	phead=&array[0];
	ptail=&array[count-1];
    while((ptail-phead)/2)
	{
		pmid=phead+(ptail-phead)/2;
		if (*pmid<*ptail)
			ptail=pmid;
		if (*pmid>*ptail)
			phead=pmid;
	}
	return *phead>*ptail?*ptail:*phead;	
}
/*
给定一个单向链表，请给出从最后节点倒数第n个节点
*/
struct Node 
{
    int iValue;
    struct Node* pNext;
};
struct Node* New()
{
	Node* head=(Node *)malloc(sizeof(Node));
	head->pNext=NULL;
	return head;
}
struct Node* Process( struct Node* pHead, int n )
{
	Node *p, *np;  
    if(n<1)
        return NULL;   
    np=pHead;  
    while(--n)
	{  
        if(!np->pNext)  
            return NULL;   
        np=np->pNext;  
    }  
    p = pHead;  
    while(np->pNext)
	{  
        p=p->pNext;  
        np=np->pNext;  
	}  
	return p;   
}

/*
在二叉排序树上面找出第3大的节点。
注意：不能把二叉树全量存储到另外的存储空间，比如存储到数组中，然后取出数组的第三个元素
*/
struct TreeNode 
{
    int value; 
    struct TreeNode * left, * right; 
}; 
struct TreeNode * find( struct TreeNode * root )
{
	TreeNode *number,*croot;
	if (root->right!=NULL)
	{
		croot=root->right;
	    if (croot->right!=NULL)
			number=croot->right;
		else if(croot->left!=NULL)
			number=croot->left;
		else
			return root;
	}
	else if(root->left!=NULL)
	{
		croot=root->left;
		if (croot->right!=NULL)
			number=croot->right;
		else if(croot->left!=NULL)
			return croot->left;
		else
			return root;
	}

	find(croot);
}
struct TreeNode *CreateTree()
{
	cout<<"请输入数据，先输入根节点，输入以0结束"<<endl;
	TreeNode *head,*p,*q;
	head=new TreeNode;
	int value;
	cin>>value;
	head->value=value;
	head->left=NULL;
	head->right=NULL;
	while(cin>>value&&value!=0)
	{
		p=new TreeNode;
		p->value=value;
		p->left=NULL;
		p->right=NULL;
		q=head;
		while(1)
		{
			if(p->value<q->value)
			{
				if (q->left==NULL)
				{
					q->left=p;
					break;
				}
				else
					q=q->left;
			}
			else
			{
				if(q->right==NULL)
				{
					q->right=p;
					break;
				}
				else
					q=q->right;
			}
		}
	}
	return head;
}
	

/*
给定两个字符串 s1 和 s2 ，从 s1 中删除在 s2 中出现过的字符
*/
char* Delete(char *s1,const char *s2)
{
	char *s=s1;
	int index=0;
	int hash_table[256] = { 0 };
    for( int i = 0; i < strlen(s2); i++ )
	{
      hash_table[ (int)s2[i] ] = 1;
	}
	while(*s!='\0')
	{
		if( 0 == hash_table[(int)*s] )
		{
			s1[index++] = *s;
		}
		s++;
	}
	s1[index]='\0';
    return s1;

}

void main()
{
	
	//1
	int mirrornum,judge;
	cout<<"输入需要判断的数"<<endl;
	cin>>mirrornum;
	judge=ismirror(mirrornum);
	cout<<judge<<endl;
	//2
	int arraylist[]={50, 52, 63, 70, 90,0, 3, 8, 15, 44, 45};
	int value;
	value=findmin1(arraylist,(sizeof(arraylist)/sizeof(arraylist[0])));
	cout<<"遍历最小值是"<<value<<endl;
	value=findmin2(arraylist,(sizeof(arraylist)/sizeof(arraylist[0])));
	cout<<"二分最小值是"<<value<<endl;
	
	//3	
	cout<<"输入单向链表，以0结束"<<endl;
	int ch,n=3;
	Node *p,*head,*valuenum;
	head=New();
	p=head;
	while(cin>>ch&&ch!=0)
	{
		p->iValue=ch;
		p->pNext=(Node *)malloc(sizeof(Node));
		p=p->pNext;
	}
	p->pNext=NULL;
	valuenum=Process( head,n);
	cout<<"倒数第"<<n<<"个值是："<<valuenum->iValue<<endl;
	
	//4
	TreeNode *minnum;
	TreeNode *Treehead=CreateTree();
	minnum=find(Treehead);
	cout<<"最大的数字是"<<minnum->value<<endl;
	//5
	char *squeue,s1[50],s2[50];
	cout<<"输入原始数据和想用删除的字符，用回车换行"<<endl;
	cin>>s1>>s2;
	squeue=Delete(s1,s2);
	cout<<"删除后的变量为"<<squeue<<endl;
	system("pause");
}