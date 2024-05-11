#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool kazanan(int (*Y)[3]) {
    // Satır kontrolü
    for (int i = 0; i < 3; i++) {
        if (Y[i][0] == Y[i][1] && Y[i][1] == Y[i][2] && Y[i][0] != 0) {
            printf("Player %c wins! (Row %d)\n", (Y[i][0] == 3) ? ('X') : ('O'), i + 1);
            return true;
        }
    }
    // Sütun kontrolü
    for (int j = 0; j < 3; j++) {
        if (Y[0][j] == Y[1][j] && Y[1][j] == Y[2][j] && Y[0][j] != 0) {
            printf("Player %c wins! (Column %d)\n", (Y[0][j] == 3) ? ('X') : ('O'), j + 1);
            return true;
        }
    }
    // Çapraz kontrol
    if ((Y[0][0] == Y[1][1] && Y[1][1] == Y[2][2] && Y[0][0] != 0) ||
        (Y[0][2] == Y[1][1] && Y[1][1] == Y[2][0] && Y[0][2] != 0)) {
        printf("Player %c wins! (Diagonal)\n", (Y[1][1] == 3) ? ('X') : ('O'));
        return true;
    }
    return false;
}
void tahta(int (*Y)[3]) {
    int p, k;
    printf("\n   ");
    for (int i = 0; i < 3; i++) {
        printf("%3d ", i + 1);
    }
    printf("\n   ");
    for (int i = 0; i < 3; i++) {
        printf("___ ");
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (p = 0; p < 3; p++) {
            if (p == 1)
                printf("%2d|", i + 1);
            else
                printf("  |");
            for (k = 0; k < 3; k++) {
                if (p != 2) {
                    if (p == 0) {
                        printf("   |");
                    } else if (p == 1) {
                        if (Y[i][k] == 3) {
                            printf(" x |");
                        } else if (Y[i][k] == 2) {
                            printf(" o |");
                        } else {
                            printf("   |");
                        }
                    }
                } else {
                    printf("___|");
                }
            }
            printf("\n");
        }
    }
    bool result=false;
    result=kazanan(Y);
    if(result)
        exit(0);
}

int main() {
    char op = 'x';
    int number_of_move = 0, win = 1, Y[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Y[i][j] = 0;
        }
    }
    tahta(Y);
    printf("MOVE TURN IS X\n");
    while (number_of_move < 9 && win) {
        op = (number_of_move % 2) ? ('o') : ('x');
        int column, row;
        printf("Enter the coordinate ,please. (1-3)");
        scanf("%d %d", &row, &column);
        row--;
        column--;
        if (row < 0 || row > 2 || column < 0 || column > 2) {
            printf("Coordinates out of bounds. Please enter valid coordinates.\n");
            continue;
        }
        if (Y[row][column] != 0) {
            printf("This cell is already occupied. Please choose another cell.\n");
            continue;
        }
        if (op == 'x')
            Y[row][column] = 3;
        else if (op == 'o')
            Y[row][column] = 2;
        tahta(Y);
        number_of_move++;
        if (number_of_move % 2)
            printf("MOVE TURN IS O\n");
        else
            printf("MOVE TURN IS X\n");
    }
    return 0;
}
