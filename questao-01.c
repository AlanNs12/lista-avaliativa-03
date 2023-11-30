#include <stdio.h>
#include <string.h>

int valorDecimal(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}

int romanoParaDecimal(char *romano) {
    int resultado = 0;
    int tamanho = strlen(romano);
    
    for (int i = 0; i < tamanho; i++) {
        int valor1 = valorDecimal(romano[i]);

        if (i + 1 < tamanho) {
            int valor2 = valorDecimal(romano[i + 1]);

            if (valor1 >= valor2) {
                resultado += valor1;
            } else {
                resultado += valor2 - valor1;
                i++;
            }
        } else {
            resultado += valor1;
            i++;
        }
    }

    return resultado;
}

void decimalParaBinario(int decimal) {
    int binario[32];
    int indice = 0;

    while (decimal > 0) {
        binario[indice++] = decimal % 2;
        decimal /= 2;
    }

    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
}

int main() {
    char romano[13];

    scanf("%s", romano);

    int decimal = romanoParaDecimal(romano);

    printf("%s na base 2: ", romano);
    decimalParaBinario(decimal);
    printf("\n%s na base 10: %d\n", romano, decimal);
    printf("%s na base 16: %x\n", romano, decimal);

    return 0;
}