#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _getline - Reads an entire line from stream.
 * @lineptr: Pointer to the buffer where the input line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 * Return: The number of characters read (including newline),
 * or -1 on failure (EOF or error).
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	char *buffer;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	buffer = *lineptr;

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF)
		{
			if (pos == 0)
				return (-1);
			break;
		}

		if (pos + 1 >= *n)
		{
			*n *= 2;
			buffer = realloc(*lineptr, *n);
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
		}

		buffer[pos++] = c;

		if (c == '\n')
		break;
	}

	buffer[pos] = '\0';
	return (pos);
}
