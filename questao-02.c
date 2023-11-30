#include <stdio.h>
#include <math.h>

int main() {
    int meses;
    double aporte, taxaJuros, M;
    
    scanf("%d", &meses);
    scanf("%lf", &aporte);
    scanf("%lf", &taxaJuros);

    double fator = 1.0 + taxaJuros;

    for (int tempo = 1; tempo <= meses; tempo++) {
        double termo_potencia = pow(fator, tempo);

        M = aporte * fator * ((termo_potencia - 1) / taxaJuros);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", tempo, M);
    }

    return 0;
}