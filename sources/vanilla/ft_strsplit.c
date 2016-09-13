#include "libft.h"

static int	count_elems(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i] && s[i] == c)
			while (s[i] && s[i] == c)
				i++;
	}
	return (count);
}

static int	strlentochar(char const *s, char c)
{
	int	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	return (pos);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		word;
	int		count;

	count = count_elems(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count = strlentochar(&s[i], c);
			if (!(tab[word] = ft_strnew(count + 1)))
				return (NULL);
			ft_strncpy(tab[word], &s[i], count);
			word++;
		}
		i = s[i] != c ? i + count : i + 1;
	}
	tab[word] = NULL;
	return (tab);
}
