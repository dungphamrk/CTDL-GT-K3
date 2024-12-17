#include <stdio.h>
#define MAX 100;
#include <string.h>
void createGraph(int n)
{
}
int main()
{
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    int matrix[n][n];
    memset(matrix, 0, (sizeof(int) * n * n));
    int edges[4][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    int a, b;

    for (int i = 0; i < n; i++)
    {
        a = edges[i][0];
        b = edges[i][1];
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}