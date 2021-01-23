#include <stdio.h>

// sort_num_3.cpp를 하면서 느낀점!
// cin,cout보다 scanf,printf가 출력이 더 빠른 것 같음
// 해당 정렬은 메모리와 시간 제한을 걸어두었기 때문에
// 최대한 간단하게 구현하고자 main()문 안에 모두 구현
// Counting Sort를 활용한 케이스

int arr[10001];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int num;
        scanf("%d",&num);
        arr[num]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}