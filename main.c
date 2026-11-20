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
		perror("fopen");
		return 0;
	}

	size_t bytes_read;
	size_t offset = 0;
	unsigned char buffer[16];

	while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
		printf("%08zx  ", offset);

		for (size_t i = 0; i < 16; i++) {
			if (i < bytes_read) {
				printf("%02x ", buffer[i]);
			} else {
				printf("   ");
			}

			if (i == 7) {
				printf(" ");
			}
		}

		printf(" |");
		for (size_t i = 0; i < bytes_read; i++) {
			printf("%c", isprint(buffer[i]) ? buffer[i] : '.');
		}
		printf("|\n");

		offset += bytes_read;
	}

	printf("%08zx\n", offset);

	fclose(file);

	return 0;
}