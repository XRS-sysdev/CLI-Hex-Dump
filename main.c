#include <stddef.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: ./hex <filename>\n");
		return 0;
	}

	FILE *file = fopen(argv[1], "rb");
	if (file == NULL) {
		printf("File Not Found\n");
		return 0;
	}

	int c;

	while ((c = fgetc(file)) != EOF) {
		if (isprint(c)) {
			printf("%c ", c);
		} else {
			printf("%02X ", c);
		}
	}

	printf("\n");

	fclose(file);

	return 0;
}