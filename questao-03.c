#include <stdio.h>
#include <string.h>

void verificarDia(char p[], char d[]) {
    int u = p[strlen(p) - 1];

    if (d[0] != '\0') {
        char dias[6][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA"};

        for (int i = 0; i < 5; i++) {
            if (strcmp(d, dias[i]) == 0) {
                if ((u == '0' + i * 2) || (u == '1' + i * 2)) {
                    printf("%s nao pode circular %s\n", p, d);
                } else {
                    printf("%s pode circular %s\n", p, d);
                }
                return;
            }
        }

        if (strcmp(d, "SABADO") == 0 || strcmp(d, "DOMINGO") == 0) {
            printf("Nao ha proibicao no fim de semana\n");
        } else {
            printf("Dia da semana invalido\n");
        }
    } else {
        printf("Dia da semana nao especificado\n");
    }
}

int main() {
    char p[9], d[15];
    scanf("%s %s", p, d);

    if ((strlen(p) == 8 && p[3] == '-') || (strlen(p) == 7 && p[2] != '-')) {
        verificarDia(p, d);
    } else {
        printf("Placa invalida\n");
    }

    return 0;
}