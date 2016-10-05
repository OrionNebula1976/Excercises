#include<stdio.h>
int main(){
	int a[100][100];
	int at[100][100];
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for ( i = 0; i < m; i ++ )
		for ( j = 0; j < n; j ++ ) {
			printf ("a[%d][%d]=", i, j);
			scanf ("%d", & a[i][j]);
		}
		for ( i = 0; i < m; i ++ ) {
			for ( j = 0; j < n; j ++ )
    				printf ( "%d ", a[i][j] );
    				printf("\n");
		}
		for( i = 0; i < m; i ++ ) {
    			for( j = 0; j < n; j ++ ) {
            			at[j][i] = a[i][j];
			}
		}
		for ( i = 0; i < n; i ++ ) {
			for ( j = 0; j < m; j ++ )
    				printf ( "%d ", at[i][j] );
    				printf("\n");
		}
	return 0;
}
