#include <stdio.h>
#include <stdlib.h>

int Digital(int row,int col)
{
    int sum = 0;
    while(row)
    {
        sum += row % 10;
        row /= 10;
    }
    while(col)
    {
        sum += col % 10;
        col /= 10;
    }
    return sum;
}

int _CanStay(int* arr,int ROW,int COL,int K,int row,int col)
{
    //参数合法性判断
    if(arr == NULL || K < 0)
    {
        return 0;
    }
    //坐标合法性判断
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
    {
        return 0;
    }
    //当满足这个点横纵坐标每一位的和的值小于等于K 并且 这个点没有走过
    //就把这个点标记为走过，并且递归的探测他周围的四个点 
    if(Digital(row,col) < K && arr[row*COL + col] == 0)
    {
        arr[row*COL + col] = 1;
        return 1 + _CanStay(arr,ROW,COL,K,row-1,col)
                 + _CanStay(arr,ROW,COL,K,row,col-1)
                 + _CanStay(arr,ROW,COL,K,row+1,col)
                 + _CanStay(arr,ROW,COL,K,row,col+1);
    }
    return 0;
}

int CanStay(int ROW,int COL,int K,int row,int col)
{
    //申请一个 ROW*COL 大小的空间
    //空间初始化为0，表示机器人还没有走过
    int* arr = (int*)malloc(sizeof(int)*ROW*COL);
    int i = 0;
    for(; i < ROW*COL; ++i)
    {
        arr[i] = 0;
    }
    free(arr);
    return _CanStay(arr,ROW,COL,K,row,col);

}
void Test()
{
    //这里row col表示机器人可以走过的最大的矩阵大小

//测试用例1
//    int row = 5;
//    int col = 5;
//    int K = 16;

//测试用例2
//    int row = 5;
//    int col = 5;
//    int K = -1;

//测试用例3
//    int row = 1;
//    int col = 5;
//    int K = 4;

//测试用例4
    int row = 1;
    int col = 5;
    int K = 0;

    //这里的 (0,0)是机器人的起始点位置
    int count = CanStay(row,col,K,0,0);
    printf("count = %d\n",count);
}

int main()
{
    Test();
    return 0;
}
