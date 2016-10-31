#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int k = 0;
int a[3000][3000];
int b[3000][3000];
int c[3000][3000];
pthread_mutex_t lock;

void *mythread(void *arg) {
    int i = 0, j = 0, el = 0, n;
    el = * (int *) arg;
    printf("Thread created, id %d\n", el);
    scanf("%d", &n);
    for ( i = 0; i < n; i ++ )
        for ( j = 0; j < n; j ++ ) {
            printf ("a[%d][%d]=", i, j);
            scanf ("%d", &a[i][j]);
        }
    for ( i = 0; i < n; i ++ )
        for ( j = 0; j < n; j ++ ) {
            printf ("b[%d][%d]=", i, j);
            scanf ("%d", &b[i][j]);}
    while (el <= n) {
        for (j = 0; j < n; j ++) {
            for (i = 0; i < n; i ++) {
                c[el][j] = c[el][j] + a[el][i]*b[i][j];
            }
        }
        el = el + 4;
    }
    printf("Thread complete, id %d\n", el);
    return NULL;
}

int main() {
    pthread_t thid[4];
    int i[4] = { 0, 1, 2, 3}, j = 0, z = 0, n, result;

    result = pthread_create(&thid[0], (pthread_attr_t *) NULL, mythread, &i[0]);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }

    result = pthread_create(&thid[1], (pthread_attr_t *) NULL, mythread, &i[1]);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }

    result = pthread_create(&thid[2], (pthread_attr_t *) NULL, mythread, &i[2]);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }

    result = pthread_create(&thid[3], (pthread_attr_t *) NULL, mythread, &i[3]);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }

    pthread_join(thid[0], (void **) NULL);
    pthread_join(thid[1], (void **) NULL);
    pthread_join(thid[2], (void **) NULL);
    pthread_join(thid[3], (void **) NULL);
    z = 0;
    j = 0;
    for (j = 0; j < n; j++) {
        for (z = 0; z < n; z++) {
            printf("%d ", c[j][z]);
        }
        printf("\n");
    }
    return 0;
}

