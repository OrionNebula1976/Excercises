#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern char ** environ;
int main (){
	int i;
	char *user = "username"; //вместо username вставить реальное имя пользователя, возвращенное командой whoami
	for ( i = 0; i < 1000; i ++ ){
		if ((strstr (environ[i], user)) != NULL) {
			printf ("%s\n", environ[i]);
		}
	}
	return 0;
}

   
