#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
int main(){
DIR *dfd;
FILE *f1;
FILE *f2;
char *a, *zero;
a = malloc(sizeof(char)*255);
zero = malloc(sizeof(char)*255);
int N = 0, i = 0, j, l;
int Number = 0, flag = 1;
struct dirent *dp;
scanf("%s", a);
if((dfd = opendir(a)) == 0) {
perror("Can't open directory");
exit(-1);} 
while( (dp=readdir(dfd)) != NULL )
N++;
closedir(dfd);
char b[N][255];
int ex[N];
for(i = 0; i < N; i++) {
ex[i] = 0;}
for(i = 0; i < N; i++) {
for(j = 0; j < strlen(a); j++) {
b[i][j] = a[j];}
b[i][strlen(a)] = '/';
b[i][strlen(a) + 1] = '\0';}
for(j = 0; j < strlen(a); j++) {
zero[j] = a[j];}
zero[strlen(a)] = '/';
zero[strlen(a) + 1] = '.';
zero[strlen(a) + 2] = '\0';
i = 0;
dfd=opendir(a);
while( (dp=readdir(dfd)) != NULL ) {
strcat(b[i], dp->d_name);
i++;}
int k = 0;
int exFlag = 0;
for(i = 0; i < N; i++) {
int temp = Number;
for( j = i + 1; j < N; j++) {
f1 = fopen(b[i], "r"); 
f2 = fopen(b[j], "r");
fseek(f1, 0, SEEK_END);
fseek(f2, 0, SEEK_END);
if (i != 0) {
for(l = 0; l < N; l++) {
if(ex[l] == i)
exFlag++;}}
if((ftell(f1) == ftell(f2)) && (exFlag == 0)) {
ex[k] = j;
k++;
if(strcmp(b[i], zero) != 0) {
while(!feof(f1)) {
if(fgetc(f1) == fgetc(f2)) {
flag = 0;
break;}}}}
exFlag = 0;
if (flag == 0) 
Number++;
fclose(f1);
fclose(f2);
flag = 1;}
if(Number > temp) 
Number++;}
closedir(dfd);
printf("%d\n", Number);
free(a);
free(zero);
return 0;}