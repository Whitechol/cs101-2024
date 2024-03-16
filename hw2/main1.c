#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int n;
    FILE* fp = fopen("lotto.txt", "w+");

    scanf("%d", &n);
    int content[n][7];
    
    srand(1);
    int x = 0, y = 0, tmp;
    int generated[69] = {0};
    while (x < n) {
        tmp = rand() % 69 + 1;
        if (!generated[tmp]) {
            content[x][y] = tmp;
            generated[tmp] = 1;
            y++;
        }
        if (y == 7) {
            x++;
            y = 0;
            for (int i = 0; i < 69; i++) {
                generated[i] = 0;
            }
        }
    }

    fprintf(fp, "========= lotto649 =========\n");
    fclose(fp);
    fp = fopen("lotto.txt", "a+");

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        if (i < n) {
            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", content[i][j]);
            }
        }
        else {
            for (int j = 0; j < 7; j++) {
                fprintf(fp, "__ ");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "========= csie@CGU =========\n");

    fclose(fp);

    return 0;
}