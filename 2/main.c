#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 100;
    int numbers[n];
    int i, j, temp;

    // Rastgele sayıları diziye ekle
    for (i = 0; i < n; i++) {
        numbers[i] = rand() % 101;
    }

    // Diziyi büyükten küçüğe sırala
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (numbers[i] < numbers[j]) {
                // Swap işlemi
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Sıralanmış sayıları ekrana yazdır
    printf("Sıralanmış Sayılar:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
