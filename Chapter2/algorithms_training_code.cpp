// 2.2 재귀적 알고리즘
// 2.2.1 부분집합 생성하기
/*
#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
typedef vector<int> vi;

vi subset;
set<vi> unique_subset;
int n = 3;

void printSubset(vi const& input) {
    printf("subset print { ");
    for (auto const& i : input) {
        printf("%d ", i);
    }
    printf("}\n");
}

void search(int k) {
    printf("#search(%d) start\n", k);
    if (k == n + 1) {
        unique_subset.insert(subset);
        printf("k equals %d, exit.\n", n + 1);
    } else {
        printSubset(subset);
        printf("subset push search(%d)\n", k);
        subset.push_back(k);
        printSubset(subset);
        search(k + 1);

        printSubset(subset);
        printf("subset pop search(%d)\n", k);
        subset.pop_back();
        printSubset(subset);
        search(k + 1);
    }
    printf("#search(%d) end\n", k);
}

int main(void) {
    search(1);
    for (auto const& subset : unique_subset) {
        printf("{ ");
        for (auto const& i : subset) {
            printf("%d ", i);
        }
        printf("} ");
    }
}
*/

// 2.2.2 순열 생성하기
/*
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int n{3};
vi permutation;
set<vi> unique_permutation;
bool chosen[n + 1];

void printPermutation(vi const& input) {
    printf("permutation print { ");
    for (auto const& i : input) {
        printf("%d ", i);
    }
    printf("}\n");
}

void search() {
    printf("#search() start\n");
    if (permutation.size() == n) {
        unique_permutation.insert(permutation);
        printf("permutation.size equals %d, exit.\n", n);
    } else {
        for (int i = 1; i <= n; i++) {
            printPermutation(permutation);
            printf("chosen[%d] is %s\n", i, chosen[i] ? "true" : "false");
            if (chosen[i]) continue;
            printf("chosen[%d] is continue\n", i);
            chosen[i] = true;
            printf("chosen[%d] is %s\n", i, chosen[i] ? "true" : "false");
            printf("permutation push search()\n");
            permutation.push_back(i);
            printPermutation(permutation);
            search();

            chosen[i] = false;
            printf("chosen[%d] is %s\n", i, chosen[i] ? "true" : "false");
            printf("permutation pop search()\n");
            permutation.pop_back();
            printPermutation(permutation);

        }
    }
    printf("#search() end\n");
}

int main(void) {
    search();
    printf("permutation print { ");
    for (auto const& permutation : unique_permutation) {
        printf("{ ");
        for (auto const& i : permutation) {
            printf("%d ", i);
        }
        printf("} ");
    }
}
*/

// 2.2.3 퇴각 검색 (Backtracking)
/*
#include <bits/stdc++.h>
using namespace std;

const int n{4};
int count = 0;

void search(int y) {
    if (y == n) {
        count++;
        return;
    } else {
        for (int x = 0; x < n; x++) {
            if (col[x] || diag[x + y] || diag2[x - y + n - 1]) continue;
            col[x] = diag[x + y] = diag2[x - y + n - 1] = 1;
            search(y + 1);
        }
        col[x] = diag[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main(void) { search(0); }
*/
