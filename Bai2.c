//
// Created by Lenovo on 31/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Folder
{
    char name[MAX];
} Folder;
typedef struct Node
{
    Folder data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(Folder folder)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = folder;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}





void menu()
{
    printf("\n===== FOLDER MANAGER =====\n");
    printf("1. Tao thu muc goc \n");
    printf("2. Them thu muc con\n");
    printf("3. In cau truc thu muc\n");
    printf("4. Tim kiem thu muc theo ten\n");
    printf("5. Tinh chieu cao he thong thu muc\n");
    printf("6. In duong dan tu thu muc goc den thu muc con\n");
    printf("7. Thoat chuong trinh\n");
}

int main()
{
    Node* root = NULL;
    int choice;

    do
    {
        menu();
        printf("Vui long nhap lua chon \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Thoat chuong trinh \n");
                break;
            default:
                printf("Lua chon khong hop le!");
                break;
        }

    }while (choice != 7);

    return 0;
}