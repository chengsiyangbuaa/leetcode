#include <stdio.h>
#include <stdlib.h>

void getnumlist(int numlist[], int M);
void Islegallist(int numlist[], int M, int N);

void Islegallist(int numlist[], int M, int N)
{
    int left = numlist[0];
    int right = numlist[0]; //左右浮标初始化为首个数字
    int tag = 1;            //标记是否合法
    for (int i = 0; i < N; i++)
    {
        if (numlist[i] > M + i) //排除栈满的情况
        {
            tag = 0;
            break;
        }
        if (i != 0)
        {
            if (numlist[i] == left - 1)
                left--;
            else if (numlist[i] == right + 1)
                right++;
            else
            {
                tag = 0;
                break;
            }
        }
    }

    if (tag == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
void getnumlist(int numlist[], int N)
{
    for (int i = 0; i <N; i++)
    {
        scanf("%d", &numlist[i]);
    }
}
int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++)
    {
        int numlist[N];
        getnumlist(numlist, N);
        Islegallist(numlist, M, N);
        if (i != K - 1)
            printf("\n");
    }
    return 0;
}