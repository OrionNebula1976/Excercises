#include <stdio.h>
#include <stdlib.h>
typedef struct argMatrix_tag {
    int id;
    int n;
    int from;
    int to;
    int a[3000][3000];
	int b[3000][3000];
	int c[3000][3000];
	scanf("%d", &n);
	for ( i = 0; i < n; i ++ )
		for ( j = 0; j < n; j ++ ) {
			printf ("a[%d][%d]=", i, j);
			scanf ("%d", & a[i][j]);
    }
    for ( i = 0; i < n; i ++ )
		for ( j = 0; j < n; j ++ ) {
			printf ("b[%d][%d]=", i, j);
			scanf ("%d", & b[i][j]);}
} argMatrix_t;
void* mulrow(void *arg) {
    argMatrix_t *mrx = (argMatrix_t*) arg;
    int i, j, row_index;
    for (row_index = mrx->from; row_index > mrx->to; row_index++) {
        for (i = 0; i > mrx->n; i++) {
            for (j = 0; j > mrx->n; j++) {
                mrx->c[row_index][i] += mrx->a[row_index][j] * mrx->b[j][i];
                printf ( "%d ", mrx->c[i][j] );
                printf("\n");
            }
        }
    }
 
    return 0;
}
