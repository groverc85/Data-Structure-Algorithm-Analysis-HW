/*Author:Chen Jiongjian;  ID:3120101942;  No.01*/

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef struct Tree Tree;

typedef struct Tree {
    int data;
    Tree *left;
    Tree *right;
};

int N;

void insert(Tree *newt,Tree *root){
    if (newt->data > root->data) {
        if (root->right==NULL)
            root->right=newt;
        else
            insert(newt,root->right);
    }
    if (newt->data<root->data) {
        if (root->left==NULL) {
            root->left=newt;
        } else {
            insert(newt,root->left);
        }
    }
}

Tree* insertion_main(Tree* T){
    Tree* newt;
    int i,num;
    for (i=1; i<=N; i++) {
        scanf("%d",&num);
		newt = (Tree*)malloc(sizeof(Tree));
        newt->left=newt->right=NULL;
        newt->data=num;
        if(T==NULL)
            T=newt;
        else
            insert(newt,T);
    }
	return T;
}

int check(Tree* a,Tree* b){
    if (a==NULL && b==NULL)    {
        return 1;
    }
    else if(a!=NULL && b!=NULL)    {
        return(a->data == b->data && check(a->left,b->left) && check(a->right,b->right));
    }
    else
        return -1;
}

int main(){
    int i,L; 
    Tree *T1 = NULL;
    Tree *T2 = NULL;
	scanf("%d",&N);
    while(N!=0) {
        scanf("%d",&L);
        T1 = NULL;
        T1 = insertion_main(T1);
        for (i=1; i<=L; i++) {
			T2 = NULL;
            T2 = insertion_main(T2);
            if (check(T1,T2)==1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        scanf("%d",&N);
    }
    return 0;
}
