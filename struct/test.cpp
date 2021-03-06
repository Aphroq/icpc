#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size;
    int length;
    int *data;
} Vector;

void init(Vector *vector,int size) {
    vector->size=size;
    vector->data=(int*)malloc(size*sizeof(int));
    vector->length=0;
}

void clear(int *vector) {
    free(vector);
}

void expand(Vector* vector) {
    int *old_data=vector->data;
    
    vector->data=(int *)malloc(2*vector->size*sizeof(int));
    // 可用calloc扩展 , 不用重新分配
    for(int i=1;i<=vector->length;i++)
    {
        vector->data[i]=old_data[i];
    }
    
    clear(old_data);
    
    printf("expand\n");
    
}

int insert(Vector* vector,int loc,int val) {
    
    if(loc<0||loc>vector->length)return ERROR;
    if(vector->length>=vector->size)expand(vector);
    
    for(int i=vector->length;i>loc;i--)
    {
        vector->data[i]=vector->data[i-1];
    }
    
    vector->data[loc]=val;
    vector->length++;
    
    return OK;
}

void print(Vector* vector )
{
        for(int i=0 ; i< vector->length ;i++)
            printf("loc: %d  val: %d\n",i,vector->data[i]);
        printf("outend\n\n\n");
        return ;
}


int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
    
    int n;
    
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
        int p,q;
        
        scanf("%d%d",&p,&q);
        
        if(insert(a,p,q))printf("success\n");
        else printf("failed\n");
        print(a);
    
    }
    return 0;
}