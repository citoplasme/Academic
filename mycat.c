#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mycat(char *file) {
	int i;
	int ch; 
	char line[1024];
	FILE *fd;
	fd = fopen(file, "r");
    
	if (fd == NULL) {
	perror ("Not possible"), exit (1);
    }
	while ((ch = fgetc(fd)) > 0 && isascii(ch)) {
 		putchar( ch );
    }	
    fclose(fd);
    printf("\n");
}

int main () {
	char* s;
	printf("Insert path to file \n");
	scanf("%s", s);
	mycat(s);
	return 0;
}
