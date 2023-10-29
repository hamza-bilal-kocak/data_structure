#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öğrenci yapısı
struct Student {
    char name[50];
    int studentID;
    struct Student* next;
};

// Bağlı liste üzerinde öğrenci arama işlevi
struct Student* searchStudentByName(struct Student* head, const char* nameToFind) {
    struct Student* current = head;

    while (current != NULL) {
        if (strcmp(current->name, nameToFind) == 0) {
            return current; // İstenen öğrenciyi bulduk, geri dön
        }
        current = current->next;
    }

    return NULL; // Öğrenci bulunamadı
}

int main() {
    // Örnek bağlı liste oluştur
    struct Student* head = NULL;
    struct Student* student1 = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student1->name, "Alice");
    student1->studentID = 1001;
    student1->next = NULL;
    head = student1;

    struct Student* student2 = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student2->name, "Bob");
    student2->studentID = 1002;
    student2->next = NULL;
    student1->next = student2;

    struct Student* student3 = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student3->name, "Charlie");
    student3->studentID = 1003;
    student3->next = NULL;
    student2->next = student3;

    // Öğrenci adına göre arama
    const char* searchName = "Bob";
    struct Student* foundStudent = searchStudentByName(head, searchName);

    if (foundStudent != NULL) {
        printf("Öğrenci bulundu: Adı: %s, Öğrenci ID: %d\n", foundStudent->name, foundStudent->studentID);
    } else {
        printf("Öğrenci bulunamadı: %s\n", searchName);
    }

    // Belleği temizle
    struct Student* current = head;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
