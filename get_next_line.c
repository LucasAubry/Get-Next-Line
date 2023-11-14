#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


char *get_next_line(int fd)
{
	static int i = 0;
	int j;
	int bytes_read;
	char *line;
	char *buffer;
	char *stock;

	while (stock[i] != '\n')
	{
	buffer = malloc(BUFF_SIZE + 1 *sizeof (char));
		if (!buffer)
			return (NULL);
	stock = malloc(BUFF_SIZE + 1 *sizeof (char));
		if (!stock)
			return (NULL);
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read <= 0)
			return (free (buffer), NULL);
		j = 0;
	 	while (j < BUFF_SIZE)
		{
			stock[i] = buffer[j];
			i++;
			j++;
		}
	}
	return (line);
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
	//metre toute les read dans stock (il faut le malloc aussi,
	//une fois avoir fini le fichier, parcourire stock, 
	// et a chaque /n dans stock metre tout ce quil y avais avant
	// dans ligne et return ligne puis vider ligne.
	// et voila 


