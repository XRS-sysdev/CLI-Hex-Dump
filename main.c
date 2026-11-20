#include <stddef.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: ./hex <file>\n");
	}

	FILE *file = fopen(argv[1], "rb");
	if (file == NULL) {
		printf("Error: Failed To Open File\n");
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

	fclose(file);

	return 0;
}