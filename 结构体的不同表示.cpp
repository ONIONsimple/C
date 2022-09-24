#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//结构体的不同输出方法

struct student {
    int num;
    char name[20];
    int score;
}stu[5] = { {1001,"liuxin",99},
         {1002,"wangwu",66},
         {1003,"wangpin",94},
         {1004,"laoliu",88},
         {1005,"lihua",78}
};

int main() {
    int i;
    struct student* p;
    printf("Num\tName\t\tScore\n");

    /*指针输出*/
    for (p = stu; p < stu + 5; p++) {
        printf("%d\t%s\t\t%d\n", p->num, p->name, p->score);
    }

    printf("\n");

    /*数组下标输出*/
    for (i = 0; i < 5; i++) {
        printf("%d\t%s\t\t%d\n", stu[i].num, stu[i].name, stu[i].score);
    }
}
