//
// Created by Lenovo on 31/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Employee
{
    int id;
    char name[MAX];
    int age;
    char hometown[MAX];
    int division;
    char phone[MAX];
} Employee;


typedef struct NodeSingly
{
    Employee data;
    struct NodeSingly *next;
} NodeSingly;

typedef struct NodeDouble
{
    Employee data;
    struct NodeDouble *next;
    struct NodeDouble *prev;
} NodeDouble;


NodeSingly *createNodeSingly(Employee e)
{
    NodeSingly *temp = (NodeSingly *)malloc(sizeof(NodeSingly));
    if (temp == NULL)
    {
        printf("Loi khong the cap phat bo nho");
        exit(1);
    }
    temp->data = e;
    temp->next = NULL;
    return temp;
}

NodeDouble *createNodeDouble(Employee e)
{
    NodeDouble *temp = (NodeDouble *)malloc(sizeof(NodeDouble));
    if (temp == NULL)
    {
        printf("Loi khong the cap phat bo nho");
        exit(1);
    }
    temp->data = e;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}


Employee* createEmployee()
{

    Employee* temp = (Employee*)malloc(sizeof(Employee));
    if (temp == NULL)
    {
        printf("Loi khong the cap phat bo nho");
        exit(1);
    }

    printf("Nhap id nhan vien:");
    scanf("%d", &temp->id);
    getchar();

    printf("Nhap ten nhan vien:");
    fgets(temp->name, MAX, stdin);
    temp->name[strcspn(temp->name, "\n")] = '\0';

    printf("Nhap tuoi nhan vien:");
    scanf("%d", &temp->age);
    getchar();

    printf("Nhap que quan cua nhan vien:");
    fgets(temp->hometown, MAX, stdin);
    temp->hometown[strcspn(temp->hometown, "\n")] = '\0';

    printf("Nhap phong ban truc thuoc cua nhan vien:");
    scanf("%d", &temp->division);
    getchar();

    printf("Nhap so dien thoai cua nhan vien :");
    fgets(temp->phone, MAX, stdin);
    temp->phone[strcspn(temp->phone, "\n")] = '\0';

    return temp;
}

void addEmployee(NodeSingly ** head)
{
    Employee *e = createEmployee(*head);

    NodeSingly *newNode = createNodeSingly(*e);
    if ((*head) == NULL)
    {
        *head = newNode;
    }else
    {
        NodeSingly *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    free(e);
    printf("Da them nhan vien vao danh sach!");
}

void printEmployee(NodeSingly *head)
{
    NodeSingly *temp = head;

    while (temp == NULL)
    {
       printf("Danh sach rong\n");
        return;
    }

    while (temp != NULL)
    {
        printf("Id: %d\n", temp->data.id);
        printf("Name: %s\n", temp->data.name);
        printf("Age: %d\n", temp->data.age);
        printf("Hometown: %s\n", temp->data.hometown);
        printf("Division: %d\n", temp->data.division);
        printf("Phone: %s\n", temp->data.phone);
        printf("\n");
        temp = temp->next;
    }
}

void deleteEmployee(NodeSingly **head)
{
    if (*head == NULL)
    {
        printf("Khong co phan tu de xoa");
        return;
    }
    int id;
    printf("Nhap id nhan vien can xoa:");
    scanf("%d", &id);
    getchar();

    NodeSingly *temp = *head;
    NodeSingly *prev = NULL;

    if(temp != NULL && temp->data.id == id)
    {
        *head = (*head)->next;
        free(temp);
        printf("Xoa nhan vien thanh cong \n");
        return;
    }


    while(temp != NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Danh sach rong \n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Xoa nhan vien thanh cong \n");

}

void updateEmployee(NodeSingly **head)
{

    if(*head == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }

    int id;
    printf("Nhap id cho nhan vien can cap nhat : ");
    scanf("%d", &id);
    getchar();

    NodeSingly *temp = *head;
    while(temp != NULL )
    {
        if(temp->data.id == id)
        {
            printf("Nhap ten moi cho nhan vien:");
            fgets(temp->data.name, MAX, stdin);
            temp->data.name[strcspn(temp->data.name, "\n")] = '\0';

            printf("Nhap tuoi moi cho nhan vien:");
            scanf("%d", &temp->data.age);
            getchar();

            printf("Nhap que quan moi cho nhan vien:");
            fgets(temp->data.hometown, MAX, stdin);
            temp->data.hometown[strcspn(temp->data.hometown, "\n")] = '\0';

            printf("Nhap phong ban truc moi cho nhan vien :");
            scanf("%d", &temp->data.division);
            getchar();

            printf("Nhap so dien thoai moi cho nhan vien :");
            fgets(temp->data.phone, MAX, stdin);
            temp->data.phone[strcspn(temp->data.phone, "\n")] = '\0';


            return;
        }
        temp = temp->next;
    }

    printf("Cap nhat thong tin nhan vien thanh cong \n");

}

void markEmployee(NodeSingly **head, NodeDouble **dbHead)
{
    if (*head == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }
    int id;
    printf("Nhap id cho nhan vien chuan bi sa thai:");
    scanf("%d", &id);
    getchar();

    NodeSingly *temp = *head;
    NodeSingly *prev = NULL;
    while(temp != NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Khong tim thay nhan vien\n");
        return;
    }

    NodeDouble *dbNode = createNodeDouble(temp->data);

    if ((*dbHead) == NULL)
    {
        *dbHead = dbNode;
    }else
    {
        NodeDouble* tail = *dbHead;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = dbNode;
        dbNode->prev = tail;
    }

    if (prev == NULL)
    {
        *head = temp->next;
    }else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("Nhan vien da duoc cho nghi viec \n");

}

void sortEmployee(NodeSingly **head )
{
    if(*head == NULL || (*head)->next == NULL)
    {
        printf("Danh sach rong \n");
        return;
    }

    int swap;
    NodeSingly *temp;
    NodeSingly *current = NULL;

    do
    {
        swap = 0;
        temp = *head;

        while (temp->next != current)
        {
            if (temp->data.division > temp->next->data.division)
            {
                Employee ptr = temp->data;
                temp->data = temp->next->data;
                temp->next->data = ptr;

                swap = 1;
            }
            temp = temp->next;
        }
        current = temp;
    }while (swap);

    printf("Sap xep nhan vien thanh cong \n");


}

void findEmployee(NodeSingly *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }

    char keyword[MAX];
    getchar();
    printf("Nhap ten nhan vien can tim: ");
    fgets(keyword, MAX, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    NodeSingly* temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->data.name, keyword) == 0)
        {
            printf("Id: %d\n", temp->data.id);
            printf("Name: %s\n", temp->data.name);
            printf("Age: %d\n", temp->data.age);
            printf("Hometown: %s\n", temp->data.hometown);
            printf("Division: %d\n", temp->data.division);
            printf("Phone: %s\n", temp->data.phone);
            printf("\n");
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("Khong tim thay nhan vien co ten '%s'\n", keyword);
    }
}



void menu()
{
    printf("\n====== EMPLOYEE MANAGER ======\n");
    printf("1. Them nhan vien\n");
    printf("2. Hien thi danh sach nhan vien\n");
    printf("3. Xoa nhan vien\n");
    printf("4. Cap nhat thong tin nhan vien\n");
    printf("5. Di chuyen nhan vien nghi viec\n");
    printf("6. Sap xep nhan vien\n");
    printf("7. Tim kiem nhan vien\n");
    printf("8. Thoat chuong trinh\n");
}

int main ()
{
    int choice;
    NodeSingly *head = NULL;
    NodeDouble *temp = NULL;

    do
    {
        menu();
        printf("Vui long nhap lua chon : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addEmployee(&head);
                break;
            case 2:
                printEmployee(head);
                break;
            case 3:
                deleteEmployee(&head);
                break;
            case 4:
                updateEmployee(&head);
                break;
            case 5:
                markEmployee(&head, &temp);
                break;
            case 6:
                sortEmployee(&head);
                break;
            case 7:
                findEmployee(head);
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le");
                break;

        }
    }while (choice !=8);

    return 0;
}