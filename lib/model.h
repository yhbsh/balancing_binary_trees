#define INF 1000007 // 1e6 + 7


typedef struct Node {
    struct Node* left, *right;
    int data;
    bool color;
} Node;