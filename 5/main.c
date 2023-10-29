#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öğrenci düğümünü temsil eden yapı
struct Student {
    char name[50];
    struct Student* next;
};

// LinkedList'i temsil eden yapı
struct LinkedList {
    struct Student* head;
};

// LinkedList'e yeni bir öğrenci düğümü ekler
void insert(struct LinkedList* list, const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->next = list->head;
    list->head = newStudent;
}

// LinkedList'te belirli bir öğrenci adını arar ve bulduğunda bir sonraki düğümü siler
void deleteNext(struct LinkedList* list, const char* name) {
    struct Student* current = list->head;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Hedef öğrenciyi bulduk, bir sonraki düğümü sileceğiz
            struct Student* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// LinkedList'i yazdıran yardımcı fonksiyon
void printLinkedList(struct LinkedList* list) {
    struct Student* current = list->head;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList studentList;
    studentList.head = NULL;

    // Öğrencileri ekleyelim
    insert(&studentList, "A");
    insert(&studentList, "B");
    insert(&studentList, "C");
    insert(&studentList, "D");

    printf("Öğrenci Listesi:\n");
    printLinkedList(&studentList);

    const char* targetName = "Bob";
    printf("Öğrenci '%s' aranıyor...\n", targetName);
    deleteNext(&studentList, targetName);

    printf("Öğrenci Listesi ('%s' sonrası silindi):\n", targetName);
    printLinkedList(&studentList);

    return 0;
}
