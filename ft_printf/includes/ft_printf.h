/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:15 by amulin            #+#    #+#             */
/*   Updated: 2016/04/14 18:44:50 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define SYS_OS "darwin"
#  define NULL_PTR "0x0"
# elif __linux__
#  define SYS_OS "linux"
#  define NULL_PTR "(nil)"
#  include <stdint.h>
# else
#  define SYS_OS "unknown"
#  define NULL_PTR "0x0"
# endif

# define DEBUG_MODE	0

# if DEBUG_MODE == 1
#  define PRECIS_ZERO 'p'
#  define PRECIS_PLUS '.'
#  define PRECIS_MINUS '='
#  define CONV_MINUS '|'
#  define FW_PLUS '*'
#  define FW_MINUS '_'
#  define FLAG_0_SPACER 'o'
# else
#  define PRECIS_ZERO '0'
#  define PRECIS_PLUS '+'
#  define PRECIS_MINUS '-'
#  define CONV_MINUS '-'
#  define FW_PLUS '+'
#  define FW_MINUS '-'
#  define FLAG_0_SPACER '0'
# endif

# include "libft.h"
# include "libft_extra.h"
# include <stdarg.h>

typedef union	u_param
{
	size_t				st;
	int					i;
	short				sh;
	unsigned short		ush;
	unsigned int		u;
	long				l;
	unsigned long		ul;
	long long			ll;
	unsigned long long	ull;
	char				c;
	signed char			sc;
	unsigned char		uc;
	wchar_t				wc;
	wint_t				wi;
	wchar_t				*ws;
	intmax_t			imax;
	uintmax_t			uimax;
	char				*s;
}				t_param;

typedef struct	s_ftpf_env
{
	char				*os;
	t_param				*param;
	int					index;
	char				*flags;
	char				*lenmods;
	char				*conversions;
	int					alt;
	int					zero;
	int					neg;
	int					space;
	int					plus;
	int					field_width;
	int					precisflag;
	int					precision;
	int					outputlen;
	char				*mod;
	unsigned char		conversion;
	char				spacer;
	char				*x_prefix;
	int					p_conv;
	int					null_printed;
	void				(*conversion_function)(va_list *ap,
			struct s_ftpf_env *e);
	void				(*conv_funct_table[128])(va_list *ap,
			struct s_ftpf_env *e);
	int					isneg;
	int					isnull;
	int					noconv;
	int					error;
}				t_ftpf_env;

int				ft_printf(const char *restrict format, ...);
void			ftpf_conversion_call(t_ftpf_env *e, const char *restrict format,
		va_list *ap, int *convlen);

/*
**	ftpf_init.c
*/
int				ftpf_init_env(t_ftpf_env *e);
void			ftpf_init_mallocs(t_ftpf_env *e);
int				ftpf_reinit_env(t_ftpf_env *e);
void			ftpf_init_convfunctions_pointers(t_ftpf_env *e);
void			ftpf_free_all(t_ftpf_env *e);

/*
**	ftpf_directives.c
*/
int				ftpf_directives(const char *restrict format, va_list *ap,
		t_ftpf_env *e);
void			ftpf_directives_action(const char *restrict f, va_list *ap,
		t_ftpf_env *e);
void			ftpf_get_precision(const char *restrict format, va_list *ap,
		t_ftpf_env *e);
void			ftpf_wrongchar_handler(const char *restrict format,
		t_ftpf_env *e);
void			ftpf_get_field_width(const char *restrict format, va_list *ap,
		t_ftpf_env *e);

/*
**	ftpf_conversions_signed.c
*/
void			ftpf_convert_di(va_list *ap, t_ftpf_env *e);
void			ftpf_write_di_param(t_ftpf_env *e);

/*
**	ftpf_conversions_unsigned.c
*/
void			ftpf_convert_u(va_list *ap, t_ftpf_env *e);
void			ftpf_convert_o(va_list *ap, t_ftpf_env *e);
void			ftpf_convert_xp(va_list *ap, t_ftpf_env *e);
void			ftpf_write_o_param(t_ftpf_env *e);
void			ftpf_write_xp_param(t_ftpf_env *e);

/*
**	ftpf_conversions_text.c
*/
void			ftpf_convert_c(va_list *ap, t_ftpf_env *e);
void			ftpf_convert_s(va_list *ap, t_ftpf_env *e);

/*
**	ftpf_conversions_bonus.c
*/
void			ftpf_convert_b(va_list *ap, t_ftpf_env *e);

/*
**	ftpf_output_rules.c
*/
void			ftpf_process_output_rules(t_ftpf_env *e);
int				ftpf_manage_precision(void *value, t_ftpf_env *e);
int				ftpf_manage_field_width(t_ftpf_env *e);

/*
**	ftpf_lenmods_signed.c
*/
void			ftpf_manage_lenmod_di(va_list *ap, t_ftpf_env *e);
void			ftpf_manage_lenmod_di_sub(va_list *ap, t_ftpf_env *e,
		char **ret);

/*
**	ftpf_lenmods_text.c
*/
void			ftpf_manage_lenmod_c(va_list *ap, t_ftpf_env *e);
void			ftpf_manage_lenmod_s(va_list *ap, t_ftpf_env *e);
void			ftpf_manage_lenmod_s_wide(va_list *ap, t_ftpf_env *e);
void			ftpf_s_nullexception(t_ftpf_env *e);

/*
**	ftpf_lenmods_unsigned.c
*/
void			ftpf_manage_lenmod_u(va_list *ap, t_ftpf_env *e);
void			ftpf_manage_lenmod_u_sub(va_list *ap, t_ftpf_env *e,
		char **ret);
void			ftpf_manage_lenmod_o(va_list *ap, t_ftpf_env *e);
void			ftpf_manage_lenmod_o_sub(va_list *ap, t_ftpf_env *e,
		char **ret);

/*
**	ftpf_lenmods_xp.c
*/
void			ftpf_manage_lenmod_xp(va_list *ap, t_ftpf_env *e);
void			ftpf_manage_lenmod_xp_sub(va_list *ap, t_ftpf_env *e,
		char **ret);

/*
**	ftpf_flags.c
*/
int				ftpf_get_flags(const char *restrict format, t_ftpf_env *e);
int				ftpf_process_flags(t_ftpf_env *e);
void			ftpf_process_flag_alt(t_ftpf_env *e);
void			ftpf_process_flag_plus(t_ftpf_env *e);

#endif
