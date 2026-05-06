/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Abdullah Athaaya Fauzan (13224094)
 *   Nama File           : soal1.c
 *   Deskripsi           : Terminal Medis Orbit
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char id[11];
    int duration;
    struct Node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
}Queue;

void init(Queue *q){
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, char *id, int duration){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->id, id);
    newNode->duration = duration;
    newNode->next = NULL;

    if (q->rear == NULL){
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(Queue *q){
    if (q->front == NULL) return;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}

int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Queue q;
    init(&q);

    for (int i = 0; i<n; i++){
        char id[11];
        int durasi;
        scanf("%s %d", id, &durasi);
        enqueue(&q, id, durasi);
    }

    printf("ORDER ");
    Node *temp = q.front;
    while (temp->next != NULL){
        printf("%s ", temp->id);
        temp = temp->next;
    }
    printf("%s", temp->id);
    printf("\n");

    int totaltunggu = 0;
    int waktutunggusekarang = 0;
    
    temp = q.front;
    while (temp != NULL){
        totaltunggu += waktutunggusekarang;
        waktutunggusekarang += temp->duration; 
        temp = temp->next;
    }

    printf("WAIT %d\n", totaltunggu);
    
    while (q.front != NULL){
        dequeue(&q);
    }
    return 0;
}
