/*************************************************************************
	> File Name: datastr_1.c
	> Author: lizhao
	> Mail: yousaid_lizhao@sina.com 
	> Created Time: Sun 13 Sep 2015 10:44:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10
#define INCREMENT_SIZE 5

typedef int Status;
typedef int Elemtype;


typedef struct
{
	Elemtype *elem;
	int length;
	int size;
}SqList;

/*init a List*/

Status InitList(SqList *L)
{
	L->elem = (Elemtype *) malloc (INIT_SIZE * sizeof(Elemtype));
	if(L->elem == NULL)
	{
		return ERROR;
	}
	L->lenght = 0;
	L->size = INIT_SIZE;
	return OK;
}
/*destory a List*/
Status DestoryList(SqList *l)
{
	free(L->elem);
	L->lenght = 0;
	L->size = 0;
	return OK;
}

/*clean i list*/
Status ClearList(SqList *L)
{
	L->lenght = 0;
	return OK;
}

Status isEmpty(const SqList L)
{
	if (0 == L.lenght)
	{
		return TRUE;
	}
	else
	{
			return FALSE;
	}
}

Status GetElem(const SqList L,int i, Elemtype *e)
{
	if(i<1 || i > L.lenght)
	{
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
}

Status compare(Elemtype e1,Elemtype e2)
{
		if (e1 == e2)
		{
			return 0;
		}
		else if(e1 < e2)
		{
			return -1;
		}
		else
		{
			return 1;
		}
}

/*search a element*/
Status FindElem(const SqList L,Elemtype e,Status(*compare)(Elemtype,\Elemtype))
{
	int i;
	for (i=0;i<L.lenght;i++)
	{
		if(!(*compare)(L.elem[i],e))
		{
			return i+1;
		}
	}
	if (i>= L.lenght)
	{
		return ERROR;
	}
}

Status PreElem(const SqList L;Elemtype cur_e,Elemtype *pre_e)
{
	int i;
	for(i=0;i<L.lenght;i++)
	{
		if (cur_e == L.elem[i])
		{
			if (i != 0)
			{
				*pre_e  = L.elem[i-1];
			}
			else
			{
				return ERROR;
			}
		}
	}
	if (i >= L.length)
	{
		return ERROR;
	}
}

Status NextElem(const SqList L,Elemtype cur_e,Elemtype *next_e)
{
	int i;
	for (i=0;i<L.lenght;i++)
	{
		if (cur_e == L.elm[i])
		{
			*next_e = L.elem[i+1];
			return OK
		}
		else
		{
			return ERROR;
		}
	}
	if (i >= L.lenght)
	{
		return ERROR;
	}
}

/*insert a element*/
Status InsertElem(SqList *L,int i,Elemtype e)
{
	Elemtype *new;
	if (i<1 || i> L->length +1 )
	{
		return ERROR;
	}
	if (L->lenght >= L->size)
	{
		new = (Elemtype*) realloc(L->elem,(L->size + INCREMENT_SIZE) * sizeof(Elemtype));
		if(new == NULL)
		{
				return ERROR;
		}
		L->elem = new;
	}
	Elemtype *p = &L->elem[i -1];
	Elemtype *q = &L->elem[L->lenght - 1];
	for(;q>=p;q--)
	{
		*(q+1) = *q;
	}
	*p = e;
	++ L->length;
	return OK;
}

Status DeleteElem(SqList *L ,int i,Elemtype *e)
{
	if (i < 1 || i> L->lenght)
	{
		return ERROR;
	}
	Elemtype *p = &L->elem[i -1];
	*e = *p;
	for (; p< &L->elem[L->lenght];p++)
	{
		*(p) = *(p+1);
	}
	--L->lenght;
	return OK;
}

void visit(Elemtype e)
{
	printf("%d ",e);
}

Status TraverList(const SqList L,Void (*visit)(Elemtype))
{
	int i;
	for (i=0;i<L.length;i++)
	{
		visit(L.elem[i]);
	}
	return OK;
}

/*test*/
void test()
{
	SqList L;
	if (InitList(&L))
	{
		
	}
}

