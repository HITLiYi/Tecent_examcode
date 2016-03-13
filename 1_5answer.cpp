/*
������Ϊ��Ѷ���߱��Ե����������
*/
#include <iostream>
#include <string>
using namespace std;

/*
�ж��������Ƿ��ǶԳ�������3��123,121,12321�����ܰ�����תΪ�ַ������жϡ�
//���� 1���Գƣ�0�����Գ�
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
����һ������ѭ���������飬�������ҳ���С��Ԫ�أ�ʹ�õ��㷨Խ��Խ�á�
�ر�أ���С��Ԫ�ؿ��ܳ����������м䡣���磺50, 52, 63, 90, 3, 8, 15, 44
findmin1���ñ�������findmin2���ö��ַ�
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
����һ��������������������ڵ㵹����n���ڵ�
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
�ڶ��������������ҳ���3��Ľڵ㡣
ע�⣺���ܰѶ�����ȫ���洢������Ĵ洢�ռ䣬����洢�������У�Ȼ��ȡ������ĵ�����Ԫ��
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
	cout<<"���������ݣ���������ڵ㣬������0����"<<endl;
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
���������ַ��� s1 �� s2 ���� s1 ��ɾ���� s2 �г��ֹ����ַ�
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
	cout<<"������Ҫ�жϵ���"<<endl;
	cin>>mirrornum;
	judge=ismirror(mirrornum);
	cout<<judge<<endl;
	//2
	int arraylist[]={50, 52, 63, 70, 90,0, 3, 8, 15, 44, 45};
	int value;
	value=findmin1(arraylist,(sizeof(arraylist)/sizeof(arraylist[0])));
	cout<<"������Сֵ��"<<value<<endl;
	value=findmin2(arraylist,(sizeof(arraylist)/sizeof(arraylist[0])));
	cout<<"������Сֵ��"<<value<<endl;
	
	//3	
	cout<<"���뵥��������0����"<<endl;
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
	cout<<"������"<<n<<"��ֵ�ǣ�"<<valuenum->iValue<<endl;
	
	//4
	TreeNode *minnum;
	TreeNode *Treehead=CreateTree();
	minnum=find(Treehead);
	cout<<"����������"<<minnum->value<<endl;
	//5
	char *squeue,s1[50],s2[50];
	cout<<"����ԭʼ���ݺ�����ɾ�����ַ����ûس�����"<<endl;
	cin>>s1>>s2;
	squeue=Delete(s1,s2);
	cout<<"ɾ����ı���Ϊ"<<squeue<<endl;
	system("pause");
}