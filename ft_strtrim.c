//

#include "libft.h"

static void	my_strrev(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while(i <= len / 2)
	{
		s[i] = s[len - i];
		i++;
	}
}

static void	my_blankremove(char *s)
{
	size_t	i;
	size_t	j;
	char	flag;

	i = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == 32 || s[i] == '\t' || s[i] == '\n') && flag == 0)
			i++;
		else
		{
			s[j] = s[i];
			flag = 1;
			i++;
			j++;
		}
	}
	s[j] = '\0';
}

char	*ft_strtrim(char const *s)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (buf == NULL)
		return (NULL);
	ft_strcpy(buf, s);
	my_blankremove(buf);
	my_strrev(buf);
	my_blankremove(buf);
	my_strrev(buf);
	return (buf);
}
