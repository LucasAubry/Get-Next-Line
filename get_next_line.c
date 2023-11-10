#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	int bytes_read ;
	char *buffer;
	int i;

		buffer = malloc(BUFF_SIZE + 1 *sizeof (char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read <= 0)
			return (free (buffer), NULL);
	return (buffer);
}

int main(void)
{
	int    fd;
	char  *next_line;
	int  count;
	int i;

	i = 0;
	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		return (1);
		while (1)
		{
			next_line = get_next_line(fd);
			if (next_line == NULL)
				break;
			count++;
			printf("[%d]:%s\n", count, next_line);
			free(next_line);
			next_line = NULL;
		}
	close(fd);
	return (0);
}

















char *stock_buffer(buffer)
{
	static int i = 0;
	int j;
	char *line;

	j = 0;
	while (stock[i] != '\n')
	{
	buffer = malloc(BUFF_SIZE + 1 *sizeof (char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read <= 0)
			return (free (buffer), NULL);
	 	while (j != BUFF_SIZE)
		{
			stock[i] = buffer[j];
			i++;
			j++;
		}
	}
	//metre toute les read dans stock (il faut le malloc aussi,
	//une fois avoir fini le fichier, parcourire stock, 
	// et a chaque /n dans stock metre tout ce quil y avais avant
	// dans ligne et return ligne puis vider ligne.
	// et voila 
	return (line);
}





get_next_line(int fd)
{

	stock_buffer(buffer);

	return (stock);
}

