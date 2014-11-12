//

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		if (needle[j] == haystack[i])
			j++;
		i++;
		if (needle[j] == '\0' || j == n)
			return ((char *)&haystack[i - j]);
	}
	return (NULL);
}
