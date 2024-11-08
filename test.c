readed = resultat de read / secrase a chaque lecture / doit etre save
stash = save de readed
line = ligne precedente a retourner
rest = restant de readed une fois line extrait


char	*ft_fill_line(int fd, char *rest, char *buffer)
{
	char	*line;
	ssize_t	to_read;

	to_read = 1;
	while (to_read > 0)
	{
		to_read = read(fd, buffer, BUFFER_SIZE);
		if (to_read < 0)
			return (free(rest), NULL);
		if (to_read == 0)
			break ;
		buffer[to_read] = '\0';
		if (!rest)
			ft_strdup("");
		
	}
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

}