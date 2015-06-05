#include<iostream>
using namespace std;

const int SIZE = 1010;
int root[SIZE];
int RANK[SIZE];

/**
 * compact path strategy
 * */
int find(int x) {
    int y = x;
    while (root[y] != y) {
        y = root[y];
    }
    int k = x;
    int j;
    //compact path
    while (k != y) {
        j = root[k];
        root[k] = y;
        k = j;
    }
    return y;
}

/**
 * union by rank strategy
 * */
void unite(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);

    //unite the lower rank to higher rank
    //rank is the height of the tree
    if (RANK[f1] <= RANK[f2]) {
        root[f1] = f2;
        if (RANK[f1] == RANK[f2]) {
            ++RANK[f2];
        }
    } else {
        root[f2] = f1;
    }
}

int main() {
    int N, M, s, e, count;

    while (scanf("%d", &N) != EOF) {
        if (N==0) break;
        scanf("%d", &M);
        for (int i = 1; i <= N; i++) {
            root[i] = i;
            RANK[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            scanf("%d%d", &s, &e);
            unite(s, e);
        }

        int count = -1;
        for (int i= 1; i <= N; i++) {
            if (root[i] == i) {
                ++count;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}
