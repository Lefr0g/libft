//

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	i;

	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
