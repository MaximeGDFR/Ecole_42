/* get_next_line 
-- Permet de lire une ligne a la fois --
-- Renvoie la ligne qui vient d'etre lue + \n (sauf derniere ligne) --
-- Si plus rien a lire ou erreur, renvoie NULL --
-- Comportement indetermine si changement de fichier entre deux appels --
-- Comportement indetermine pour un fichier en binaire --
-- Variables globales interdites, lseek interdit et libft interdit */

/* bonus 
-- Faire get_next_line avec une seule variable --
-- Permettre a la fonction de gerer plusieurs fd sans perdre le contenu */

#include "get_next_line.h"

//BUFFER = morceaux du fichier dans lequel on essaie de lire la ligne
//Peut etre utiliser comme autre variable mais sans etre redefini

char	*get_next_line(int fd)
{
	int	i;
	char	buffer[BUFFER_SIZE];
	ssize_t to_read;

	to_read = read(fd, buffer, BUFFER_SIZE);
	while (to_read[i])
	{
		i = 0;
		if (to_read > 0)
		{
			return ();
		}
		else if (to_read == 0)
		{

		}
		else
		{

		}
	}
	return (0);
}
