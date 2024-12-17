#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc đồ thị
typedef struct {
    int adjMatrix[MAX][MAX]; // Ma trận kề
    int numVertices;         // Số lượng đỉnh
    int isDirected;          // Đồ thị có hướng (1) hoặc không hướng (0)
} Graph;

// Khởi tạo đồ thị
void initGraph(Graph *graph, int vertices, int isDirected) {
    graph->numVertices = vertices;
    graph->isDirected = isDirected;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Ban đầu, không có cạnh nào
        }
    }
}

// Thêm cạnh vào đồ thị
void addEdge(Graph *graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Dinh khong hop le!\n");
        return;
    }
    graph->adjMatrix[src][dest] = 1; // Thêm cạnh từ src đến dest
    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1; // Nếu đồ thị không hướng, thêm cạnh ngược lại
    }
}

// Hiển thị ma trận kề của đồ thị
void displayGraph(Graph *graph) {
    printf("\nMa tran ke cua do thi:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// DFS - Duyệt đồ thị theo chiều sâu (Đệ quy)
void DFS(Graph *graph, int vertex, int visited[]) {
    printf("%d ", vertex); // In đỉnh hiện tại
    visited[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// BFS - Duyệt đồ thị theo chiều rộng (Sử dụng hàng đợi)
void BFS(Graph *graph, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    printf("Duyet BFS bat dau tu dinh %d: ", startVertex);
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Menu chương trình
int main() {
    Graph graph;
    int vertices, choice, isDirected, src, dest, startVertex;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);

    printf("Do thi co huong (1) hay khong huong (0): ");
    scanf("%d", &isDirected);

    initGraph(&graph, vertices, isDirected);

    int visited[MAX] = {0}; // Mảng đánh dấu các đỉnh đã thăm

    do {
        printf("\n=== MENU ===\n");
        printf("1. Them canh\n");
        printf("2. Hien thi do thi\n");
        printf("3. Duyet DFS\n");
        printf("4. Duyet BFS\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh nguon va dinh dich: ");
                scanf("%d %d", &src, &dest);
                addEdge(&graph, src, dest);
                break;
            case 2:
                displayGraph(&graph);
                break;
            case 3:
                printf("Nhap dinh bat dau DFS: ");
                scanf("%d", &startVertex);
                for (int i = 0; i < vertices; i++) visited[i] = 0; // Reset mảng visited
                printf("Duyet DFS bat dau tu dinh %d: ", startVertex);
                DFS(&graph, startVertex, visited);
                printf("\n");
                break;
            case 4:
                printf("Nhap dinh bat dau BFS: ");
                scanf("%d", &startVertex);
                BFS(&graph, startVertex);
                break;
            case 5:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);

    return 0;
}
