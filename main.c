#include <stdio.h>

#define MAX 5

struct Queue{
    char data[MAX];
    int front, rear;
};

void inisialisasiQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1);
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, char c) {
    if (isFull(q)) {
        printf("Queue anda penuh, masukkan dibawah 5 character\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->data[q->rear] = c;
}

char dequeue(struct Queue *q) {
    char c;
    if (isEmpty(q)) {
        printf("Dequeue kosong\n");
        return '\0';
    }
    c = q->data[q->front];
    if (q->front == q->rear) {
        inisialisasiQueue(q);
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return c;
}

void printQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong\n");
        return;
    }
    printf("Queue: \n");
    int i = q->front;
    while (i != q->rear) {
        printf("%c ", q->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", q->data[q->rear]);
}

int main() {
    struct Queue q;
    inisialisasiQueue(&q);
    int pilihan;
    char value;

    do {
        printf("\nMenu:\n");
        printf("1. Masukkan Enqueue\n");
        printf("2. Masukkan Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan enqueue: ");
                scanf(" %c", &value);
                enqueue(&q, value);
                break;
            case 2:
                printf("Dequeue anda adalah: %c\n", dequeue(&q));
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Program selesai, Terima Kasih\n");
                break;
            default:
                printf("Pilihan anda salah, masukkan pilihan yang benar\n");
        }
    } while (pilihan != 4);

    return 0;
}
