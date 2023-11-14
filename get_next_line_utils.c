
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 3

char *stock_buffer(int fd) 
{
    static char buffer[BUFF_SIZE];
    static int i = 0;
    int j;
    int bytes_read;
	char *line;

	j = 0;
   // while (1)
	//{
        if (i == 0) 
		{
            bytes_read = read(fd, buffer, BUFF_SIZE);
            if (bytes_read <= 0)
                return NULL;
        }

        while (i < bytes_read && buffer[i] != '\n')
            i++;

        line = malloc(i + 1);
        if (!line) 
            return (NULL);

        j = 0; 
		while (j < i) 
		{
			line[j] = buffer[j];
			j++;
        }

        line[i] = '\0';

        i = 0;
        return buffer;
  //}
}

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char *line;

    while ((line = stock_buffer(fd)) != NULL) 
	{
        printf("%s\n", line);
        free(line);
    }

    close(fd);

    return 0;
}