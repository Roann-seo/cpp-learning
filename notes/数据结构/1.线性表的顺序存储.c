#include<stdio.h>
//顺序表的定义
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
    Elemtype data[MAXSIZE];
    int length;
}Seqlist;
//顺序表的初始化
void initList(Seqlist *L){
    L->length=0;
}
//在尾部添加元素
int appendElem(Seqlist *L,Elemtype e){
    if(L->length>=MAXSIZE){
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;
}
//遍历顺序表
void listElem(Seqlist *L){
    for(int i=0;i<L->length;i++){
        printf("%d",L->data[i]);
    }
    printf("\n");
}
int main(){
    Seqlist list;
    initList(&list);
    printf("初始化成功,目前长度占用%d\n",list.length);
    printf("目前占用字节%zu\n",sizeof(list.data));
    appendElem(&list,88);
    listElem(&list);
    getchar();  // 防止窗口一闪而过
    return 0;
}