#include<stdio.h>
#include<stdlib.h>
#define F 0
#define T 1
#define MAX 100000
struct node
{
	int size;
    int info;
    int balance;
    struct node *lchild;
    struct node *rchild;
	struct node *parent;
};
struct node *rotateLeft(struct node *);
struct node *rotateRight(struct node *);
struct node *insert(struct node *,int);
struct node *insert_left_check(struct node *,int *);
struct node *insert_right_check(struct node *,int *);
struct node *insert_leftBalance(struct node *);
struct node *insert_rightBalance(struct node *);
struct node *del(struct node *,int);
struct node *del_left_check(struct node *,int *);
struct node *del_right_check(struct node *,int *);
struct node *del_leftBalance(struct node *,int *);
struct node *del_rightBalance(struct node *,int *);
void display(struct node *);
void insert_queue(struct node *);
struct node *del_queue();
int queue_empty();
struct node *queue[MAX];
int f=-1,r=-1;
int fun_size(struct node *node)
{
        if(node==NULL)
        return 0;
        if(node->lchild==NULL&&node->rchild==NULL)
        return (node->size=1);
        else
        {
                int sleft=fun_size(node->lchild);
                int sright=fun_size(node->rchild);
                return (node->size=sleft+sright+1);
        }
}
int i_num(struct node *node,int i)
{
	int g,k;
        if(node==NULL)
	return 0;
	if(node->lchild!=NULL)
        g=node->lchild->size+1;
	else
	g=1;
        if(g==i)
        return node->info;
        if(i>g)
        {
		k=i_num(node->rchild,i-g);
		return k;
	}
        if(i<g)
	{
		k=i_num(node->lchild,i);
	        return k;
	}
}
int num_i(struct node *node,int num,int rank)
{
	if(node==NULL)
	return 0;
	if(num==node->info){
	if(node->lchild==NULL)
	return rank+node->size;
	else
	return (rank+(node->lchild->size)+1);}
	if(num<node->info)
	return num_i(node->lchild,num,rank);
	if(num>node->info)
	return num_i(node->rchild,num,rank+node->lchild->size+1);
}
int main()
{

    int ch=0,i,n,ikey,dkey;
    struct node *root=NULL;
    printf("Enter the size of the tree.\n");
    scanf("%d",&n);
    printf("Enter the elements.\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ikey);
        root=insert(root,ikey);
    }
    int k;
    fun_size(root);
    while(ch!=-1)
    {
        printf("Enter your choice-:\n1:i to num\n2:num to i\n3:display\n-1:Quit\n");
        scanf("%d",&ch);
	int v;
        switch(ch)
        {
            case 1: printf("enter the value of i\n");
	    	    scanf("%d",&k);
	    	    printf("%d\n",i_num(root,k));
                    break;
            case 2: printf("Enter the number.\n");
                    scanf("%d",&dkey);
                    printf("%d\n",num_i(root,dkey,0));
                    break;
            case 3: display(root);
                    break;
            case -1:break;
            default:printf("Invalid choice.\n");
        }
    }
}
struct node *rotateLeft(struct node *pptr)
{
    struct node *aptr=pptr->rchild;
    pptr->rchild=aptr->lchild;
    aptr->lchild=pptr;
    return aptr;
}
struct node *rotateRight(struct node *pptr)
{
    struct node *aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    aptr->rchild=pptr;
    return aptr;
}
struct node *insert(struct node *pptr,int ikey)
{
    static int taller;
    if(pptr==NULL)
    {
        pptr=(struct node *)malloc(sizeof(struct node));
        pptr->info=ikey;
        pptr->balance=0;
        pptr->lchild=NULL;
        pptr->rchild=NULL;
        taller=T;
    }
    else if(ikey < pptr->info)
    {
        pptr->lchild=insert(pptr->lchild,ikey);
        if(taller==T)
        pptr=insert_left_check(pptr,&taller);
    }
    else if(ikey > pptr->info)
    {
        pptr->rchild=insert(pptr->rchild,ikey);
        if(taller==T)
        pptr=insert_right_check(pptr,&taller);
    }
    else
    {
        printf("Duplicate key");
        taller=F;
    }
    return pptr;
}
struct node *insert_left_check(struct node *pptr,int *t)

{

    switch(pptr->balance)

    {

        case 0: pptr->balance=1;

                break;

        case -1:pptr->balance=0;

                *t=F;

                break;

        case 1: pptr=insert_leftBalance(pptr);

                *t=F;

                break;

    }

    return pptr;

}

struct node *insert_leftBalance(struct node *pptr)

{

    struct node *aptr=pptr->lchild;

    if(aptr->balance==1)

    {

        aptr->balance=0;

        pptr->balance=0;

        pptr=rotateRight(pptr);

    }

    else

    {

        struct node *bptr=aptr->rchild;

        switch(bptr->balance)

        {

            case 0: aptr->balance=0;

                    pptr->balance=0;

                    break;

            case 1: aptr->balance=0;

                    pptr->balance=-1;

                    break;

            case -1:aptr->balance=1;

                    pptr->balance=0;

                    break;

        }

        bptr->balance=0;

        pptr->lchild=rotateLeft(aptr);

        pptr=rotateRight(pptr);

    }

    return pptr;

}

struct node *insert_right_check(struct node *pptr,int *t)

{

    switch(pptr->balance)

    {

        case 0: pptr->balance=-1;

                break;

        case 1: pptr->balance=0;

                *t=F;

                break;

        case -1: pptr=insert_rightBalance(pptr);

                *t=F;

                break;

    }

    return pptr;

}

struct node *insert_rightBalance(struct node *pptr)

{

    struct node *aptr=pptr->rchild;

    if(aptr->balance==-1)

    {

        aptr->balance=0;

        pptr->balance=0;

        pptr=rotateLeft(pptr);

    }

    else

    {

        struct node *bptr=aptr->lchild;

        switch(bptr->balance)

        {

            case 0: aptr->balance=0;

                    pptr->balance=0;

                    break;

            case 1: aptr->balance=-1;

                    pptr->balance=0;

                    break;

            case -1:aptr->balance=0;

                    pptr->balance=1;

                    break;

        }

        bptr->balance=0;

        pptr->rchild=rotateRight(aptr);

        pptr=rotateLeft(pptr);

    }

    return pptr;

}

struct node *del(struct node *pptr,int dkey)

{

    static int shorter;

    struct node *succ;

    if(pptr==NULL)

    {

        printf("Key is not present.\n");

        shorter=F;

    }

    else if(dkey < pptr->info)

    {

        pptr->lchild=del(pptr->lchild,dkey);

        if(shorter==T)

            pptr=del_left_check(pptr,&shorter);

    }

    else if(dkey > pptr->info)

    {

        pptr->rchild=del(pptr->rchild,dkey);

        if(shorter==T)

            pptr=del_right_check(pptr,&shorter);

    }

    else

    {

        if(pptr->lchild!=NULL&&pptr->rchild!=NULL)

        {

            succ=pptr->rchild;

            while(succ->lchild!=NULL)

                succ=succ->lchild;

            pptr->info=succ->info;

            pptr->rchild=del(pptr->rchild,succ->info);

            if(shorter==T)

                pptr=del_right_check(pptr,&shorter);

        }

        else

        {

            if(pptr->lchild!=NULL)

                pptr=pptr->lchild;

            else if(pptr->rchild!=NULL)

                pptr=pptr->rchild;

            else

                pptr=NULL;

            shorter=T;

        }

    }

    return pptr;

}

struct node *del_left_check(struct node *pptr,int *s)

{

    switch(pptr->balance)

    {

        case 0: pptr->balance=-1;

                *s=F;

                break;

        case 1: pptr->balance=0;

                break;

        case -1:pptr=del_rightBalance(pptr,s);

                break;

    }

    return pptr;

}

struct node *del_rightBalance(struct node *pptr,int *s)

{

    struct node *aptr,*bptr;

    aptr=pptr->rchild;

    if(aptr->balance==0)

    {

        pptr->balance=-1;

        aptr->balance=1;

        pptr=rotateLeft(pptr);

        *s=F;

    }

    else if(aptr->balance==-1)

    {

        pptr->balance=0;

        aptr->balance=0;

        pptr=rotateLeft(pptr);

    }

    else

    {

        bptr=aptr->lchild;

        switch(bptr->balance)

        {

            case 0: pptr->balance=0;

                    aptr->balance=0;

                    break;

            case -1:pptr->balance=1;

                    aptr->balance=0;

                    break;

            case 1: pptr->balance=0;

                    aptr->balance=-1;

                    break;

        }

        bptr->balance=0;

        pptr->rchild=rotateRight(aptr);

        pptr=rotateLeft(pptr);

    }

    return pptr;

}

struct node *del_right_check(struct node *pptr,int *s)

{

    switch(pptr->balance)

    {

        case 0: pptr->balance=1;

                *s=F;

                break;

        case -1:pptr->balance=0;

                break;

        case 1: pptr=del_leftBalance(pptr,s);

                break;

    }

    return pptr;

}

struct node *del_leftBalance(struct node *pptr,int *s)

{

    struct node *aptr,*bptr;

    aptr=pptr->lchild;

    if(aptr->balance==0)

    {

        pptr->balance=1;

        aptr->balance=-1;

        pptr=rotateRight(pptr);

        *s=F;

    }

    else if(aptr->balance==1)

    {

        pptr->balance=0;

        aptr->balance=0;

        pptr=rotateRight(pptr);

    }

    else

    {

        bptr=aptr->rchild;

        switch(bptr->balance)

        {

            case 0: pptr->balance=0;

                    aptr->balance=0;

                    break;

            case -1:pptr->balance=0;

                    aptr->balance=1;

                    break;

            case 1: pptr->balance=-1;

                    aptr->balance=0;

                    break;

        }

        bptr->balance=0;

        pptr->lchild=rotateLeft(aptr);

        pptr=rotateRight(pptr);

    }

    return pptr;

}

void display(struct node *root)

{

    struct node *ptr=root;

    if(ptr==NULL)

        printf("Tree is empty.\n");



    else

    {

        insert_queue(ptr);

        while(queue_empty()!=1)

        {

            ptr=del_queue();

            printf("%d %d\n",ptr->info,ptr->size);

            if(ptr->lchild!=NULL)

                insert_queue(ptr->lchild);

            if(ptr->rchild!=NULL)

                insert_queue(ptr->rchild);

        }

        printf("\n");

    }

}

void insert_queue(struct node *ptr)

{

    if(r!=MAX-1) //not full

    {

        if(f==-1)

            f=0;

        r++;

        queue[r]=ptr;

    }

}

struct node *del_queue(struct node *ptr)

{

    if(queue_empty()==1)

        return NULL;

    struct node *d=queue[f];

    f++;

    return d;

}

int queue_empty()

{

    if(f==-1||f==r+1)

        return 1;

    else

        return 0;

}

