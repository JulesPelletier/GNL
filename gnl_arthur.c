#include "get_next_line.h"

int			cut_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')    // Permet de savoir la taille de la ligne
		len++;
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_substr(s[fd], 0, len)))        // Extraction de la ligne de taille len en partant du tout debut
			return (-1);
		if (!(tmp = ft_strdup(s[fd] + len + 1)))        // Duplication de la ligne de taille len dans tmp
			return (-1);
		free(s[fd]);                                    // On libere s[fd]    
		s[fd] = tmp;                                    // On y affecte la ligne qu'on vient de dupliquer
	}
	else                                                // Si fin du fichier
	{
		if (!(*line = ft_strdup(s[fd])))                // On fait juste une copie
			return (-1);
		free(s[fd]);                                    // On libere s[fd]
	}
	return (1);                                         // Si tout marche comme il faut, on renvoie 1
}

int			read_files(int fd, char **s, int ret)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, &buff, BUFFER_SIZE)) > 0)    // Tant que la lecture est possible
	{
		buff[ret] = '\0';                               // On dit bien qu'on termine la chaine buff
		if (!(tmp = ft_strjoin(s[fd], buff)))           // On join la ligne avec la chaine qu'on vient de lire
			return (-1);                                // Cas d'erreur si strjoin ne marche pas
		free(s[fd]);
		s[fd] = tmp;                                    // On affecte a s[fd] la chaine tmp
		if (ft_strchr(buff, '\n'))                      // Si on y trouve un '\n', cela veut dire qu'on a lu plus d'une ligne
			break ;
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[MAX_FD];
	int			ret;
	int			len;

	ret = 1;
	len = 0;
	if (line == NULL || fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (-1);
	if (!s[fd])
		if (!(s[fd] = malloc(1)))
			return (-1);
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
		return (cut_line(s, line, fd));
	else
	{
		ret = read_files(fd, s, ret);
		if (ret < 0)
			return (-1);
		if (ret == 0 && (s[fd][0] == '\0'))
			return (0);
	}
	return (cut_line(s, line, fd));
}