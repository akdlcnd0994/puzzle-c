#include <stdio.h>

#include <time.h>

int main() {
    int i, j, p, o, k = 0, size, temp, count;
    int ** arr;
    srand((unsigned int) time(NULL));

    printf("ex) 3,4,5\n");
    scanf("%d", & size);
    arr = (int ** ) malloc(sizeof(int * ) * size);
    for (i = 0; i < size; i++) {
        arr[i] = (int * ) malloc(sizeof(int) * size);
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size;) {
            count = 0;
            k = rand() % (size * size);
            for (p = 0; p <= i; p++) {
                for (o = 0; o < size; o++) {
                    if (arr[p][o] == k) {
                        count++;
                        break;
                    }
                }
                if (count != 0) {
                    break;
                }
            }
            if (count != 0) {
                continue;
            }
            arr[i][j] = k;
            j++;
        }
    }

    while (1) {
        system("cls");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (arr[i][j] == 0) {
                    printf("   ");
                    continue;
                }
                printf("%3d", arr[i][j]);
            }
            printf("\n");
        }
        k = 0, count = 0;;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (arr[i][j] == ++k) {
                    count++;
                }
            }
        }
        if (count == size * size - 1) {
            printf("클리어하셨습니다!");
            break;
        }

        i = 0, count = 0;
        while (i < size) {
            j = 0;
            while (j < size) {
                if (arr[i][j] == 0) {
                    count++;
                    break;
                }
                j++;
            }
            if (count != 0) {
                break;
            }
            i++;
        }

        scanf("%d", & p);

        if (i > 0) {
            if (arr[i - 1][j] == p) {
                arr[i - 1][j] = arr[i][j];
                arr[i][j] = p;
            }
        }
        if (i < size - 1) {
            if (arr[i + 1][j] == p) {
                arr[i + 1][j] = arr[i][j];
                arr[i][j] = p;
            }
        }
        if (j > 0) {
            if (arr[i][j - 1] == p) {
                arr[i][j - 1] = arr[i][j];
                arr[i][j] = p;
            }
        }
        if (j < size - 1) {
            if (arr[i][j + 1] == p) {
                arr[i][j + 1] = arr[i][j];
                arr[i][j] = p;
            }
        }




    }
    return 0;
}
