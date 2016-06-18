/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:19:12 by amulin            #+#    #+#             */
/*   Updated: 2016/06/09 18:54:27 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXTRA_H
# define LIBFT_EXTRA_H

# define BUFF_SIZE 32
# include <limits.h>
# include <wchar.h>

# include "../ft_printf/includes/ft_printf.h"
# include "errmgmt.h"
# include "libft.h"

/*
**	Convenience algorithms
*/
int					get_next_line(int const fd, char **line);
char				ft_parse_options(char **tested, char **valid,
		char ***checked);


/*
**	Simple math & variable value comparison
*/
int					ft_getmax(int a, int b);
int					ft_getmin(int a, int b);

int					ft_abs(int i);
long long			ft_abs_ll(long long i);

int					ft_tabmax(int *tab, int siz);
int					ft_tabmin(int *tab, int siz);


/*
**	Binary
**	(made for ft_printf)
*/
unsigned int		ft_endian_swap(unsigned int input);
int					ft_putbin(unsigned long long n, int sizeof_type);


/*
**	Hexa
**	(made for ft_printf)
*/
int					ft_ishexa(int c);
int					ft_hexchartoi(char c);
int					ft_hexbytetoi(char *hexbyte);
void				ft_puthex(unsigned int n, char *mode);


/*
**	Unicode / UTF-8
**	(made for ft_printf)
*/
int					ft_putwchar(wchar_t c);
int					ft_putwstr(wchar_t const *wstr);
unsigned int		ft_uni_to_utf8(wchar_t codepoint);
size_t				ft_wchar_utf8len(wchar_t const wchar);
size_t				ft_wstr_utf8len(wchar_t const *wstr);
size_t				ft_wstr_memsize(wchar_t const *wstr);
size_t				ft_wcslen(const wchar_t *s);
wchar_t				*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n);
wchar_t				*ft_utf8ncpy(wchar_t *dst, const wchar_t *src, size_t n);

/*
**	Other ft_printf
*/
char				*ft_itoa_ll(long long int n, unsigned int base);
char				*ft_itoa_ull(unsigned long long int n, unsigned int base);
void				ft_putoctal(unsigned long long n);
void				ft_puthex_ull(unsigned long long int n, char *made);
void				ft_putnbr_ull(unsigned long long int n);
void				ft_putnbr_ll(long long int n);

/*
**	Debug
*/
void				ft_print_memory(const void *addr, size_t size);


/*
**	Lists
*/
t_list				*ft_lstdetach(t_list *elem);
t_list				*ft_lstinsertright(t_list *elem, t_list *pos);
int					ft_lstsort(t_list **alst, int content_offset,
		int (*compare)(void*, void*));
void				ft_lstflip(t_list **alst);


/*
**	Str arrays
**	(used for ft_parse_options)
*/
char				*ft_find_double_str(char *needle, char **haystack);
char				**ft_strarray_dup(char **src);
void				ft_strarray_del(char ***array);

#endif
