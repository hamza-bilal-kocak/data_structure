#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Düğüm yapısı
struct Node {
    char name[50];
    int length;
    struct Node* next;
};

// Yeni bir düğüm oluşturan yardımcı fonksiyon
struct Node* createNode(char name[], int length) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Hafıza yetersiz!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->length = length;
    newNode->next = NULL;
    return newNode;
}

// En uzun isimli kişiyi bulan fonksiyon
char* findLongestName(struct Node* head) {
    if (head == NULL) {
        printf("Bağlı liste boş.\n");
        return NULL;
    }

    char* longestName = head->name;
    int maxLength = head->length;

    struct Node* current = head->next;
    while (current != NULL) {
        if (current->length > maxLength) {
            maxLength = current->length;
            longestName = current->name;
        }
        current = current->next;
    }

    return longestName;
}

int main() {
    struct Node* head = createNode("Alice", 5);
    head->next = createNode("Bob", 3);
    head->next->next = createNode("Charlie", 7);
    head->next->next->next = createNode("David", 5);

    char* longestName = findLongestName(head);

    if (longestName != NULL) {
        printf("En uzun isimli kişi: %s\n", longestName);
    }

    // Belleği temizle
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
