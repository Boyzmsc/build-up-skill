#include <stdio.h>


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