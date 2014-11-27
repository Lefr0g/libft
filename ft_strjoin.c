//

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*buf;

	lens1 = strlen(s1);
	lens2 = strlen(s2);
	i = 0;
	buf = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (buf == NULL)
		return (NULL);
	while (i <= lens1)
	{
		buf[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= lens2)
	{
		buf[lens1 + i] = s2[i];
		i++;
	}
	buf[lens1 + i] = '\0';
	return (buf);
}
