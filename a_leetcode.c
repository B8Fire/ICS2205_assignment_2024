#include <stdio.h>
#include <stdlib.h>

int findJudge(int N, int** trust, int trustSize, int* trustColSize);

int main() {
    int n = 4;
    int trust_arr[][2] = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    int** trust = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        trust[i] = (int*)malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++) {
            trust[i][j] = trust_arr[i][j];
        }
    }

    int result = findJudge(n, trust, 5, 2);
    printf("Label of the town judge: %d\n", result);  // Output: 3

    // Free memory
    for (int i = 0; i < 5; i++) {
        free(trust[i]);
    }
    free(trust);

    return 0;
}
int findJudge(int N, int** trust, int trustSize, int* trustColSize) {
    int* trusts = (int*)calloc(N + 1, sizeof(int));
    int* trustedBy = (int*)calloc(N + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        trusts[trust[i][0]]++;
        trustedBy[trust[i][1]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (trusts[i] == 0 && trustedBy[i] == N - 1) {
            free(trusts);
            free(trustedBy);
            return i;
        }
    }

    free(trusts);
    free(trustedBy);
    return -1;
}
