#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 3

char *get_next_line(int fd)
{
    int i;
    int j;
    int boul;
	int bytes_read;
	static char buffer[BUFFER_SIZE] = {0};
    char *stock;

   //verif si buf est null, si pas nul passer a la suite, si null read, si read = 0 return null, sinon passer a la suite et mettre ce que ta lu dans stock
    while (buffer[i] != '\n')
    {
        
        stock = malloc((BUFF_SIZE + 1) * sizeof(char));
        if (!stock)
            return (NULL);
        bytes_read = read(fd, buffer, BUFF_SIZE);
        if (bytes_read = 0)
        {
            stock = strcat(stock, buf);
            buffer[0] = '\0';
            return (stock);
        }
        if (bytes_read < 0)
            return (NULL);
        i = 0;
        while (i < bytes_read && buffer[i])
        {
            stock[j] = buffer[i];
            i++;
            j++;
        }
    boul = 0;
    }
    return (stock)
}

pour supper les premier caracters de buffer utilise memmoove;
dans la boucle, si bytes_read = 0 alors juste return strcat(stock, buffer)
si pas de '\n' 
si buffer est vide verifier si read renvoie zero si ces le cas return NULL;
recode realloc
"salut\nca va ?"



int main(void)
{
    int fd;
    char *line;

    fd = open("exemple.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne lue : %s\n", line);

        free(line);
    }
    close(fd);

    return 0;
}




//c la fin du fichier quqnd read renvoie 0

/* 
read la premiere ligne jusqua un \n et la stocker dans buffer
laisser un pointeur statique a la position apres le \n
quand on va rappeler la fonction elle va rexectuer gnl
*/
