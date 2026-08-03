#include<stdio.h>
//顺序表的定义
#define MAXSIZE 100
typedef int Elemtype;
// typedef struct{
//     Elemtype data[MAXSIZE];
//     int length;
// }Seqlist;
// //顺序表的初始化
// void initList(Seqlist *L){
//     L->length=0;
// }
//动态内存分配初地址始化
typedef struct{
    Elemtype *data;
    int length;
}Seqlist;
Seqlist* initList(){
    Seqlist *L=(Seqlist*)malloc(sizeof(Seqlist));
    L->data=(Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
    L->length=0;
    return L;
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
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
//插入数据
//注意这里的插入数据就是要i--,所有数都往后挪
int insertElem(Seqlist *L,int pos,Elemtype e){
    if(L->length>MAXSIZE){
        printf("顺序表错误\n");
        return 0;
    }
    if(pos<1||pos>L->length+1){
        printf("位置插入错误\n");
        return 0;
    }
    for(int i=L->length-1;i>=pos-1;i--){
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->length++;
    return 1;
}

//删除数据
//注意这里的插入数据就是要i++,所有数都往前挪
int deleteElem(Seqlist *L,int pos,Elemtype *e){
    if(L->length==0){
        printf("空表\n");
        return 0;
    }
    if(pos<1||pos>L->length){
        printf("插入位置有误\n");
        return 0;
    }
    *e=L->data[pos-1];
    for(int i=pos;i<L->length;i++){
        L->data[i-1]=L->data[i];
    }
    L->length--;
    return 1;
}
//查找
int findElem(Seqlist *L,Elemtype e){
    if(L->length==0){
        printf("空列表\n");
        return 0;
    }
    for(int i=0;i<L->length;i++){
        if(L->data[i]==e){
            return i+1;
        }
    }
    return 0;
}
int main(){
    // Seqlist list;
    // initList(&list);
    //这个是结构体的变量
    Seqlist *list=initList();
    //现在这个是结构体的指针
    printf("初始化成功,目前长度占用%d\n",list->length);
    printf("目前占用字节%zu\n",sizeof(list->data));
    appendElem(list,88);
    appendElem(list,67);
    appendElem(list,40);
    appendElem(list,8);
    appendElem(list,23);
    listElem(list);
    insertElem(list,2,18);
    listElem(list);
    Elemtype delData;
    deleteElem(list,2,&delData);
    printf("被删除的数据是:%d\n",delData);
    listElem(list);
    printf("位置:%d\n",findElem(list,40));
    getchar();  // 防止窗口一闪而过
    return 0;
}