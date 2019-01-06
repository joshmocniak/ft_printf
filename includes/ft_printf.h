/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:40:51 by jmocniak          #+#    #+#             */
/*   Updated: 2019/01/06 13:31:33 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_JOSH
# define FT_PRINTF_JOSH

# include "../libft/libft.h"
# include <stdarg.h>

# define LD_SIGNIFICANDWIDTH 64
# define D_SIGNIFICANDWIDTH 52
# define LD_EXPONENTWIDTH 15
# define D_EXPONENTWIDTH 11


typedef	struct	s_spec
{
	char		*flags;
	int			width;
	int			precision;
	int			ispos;
	int			isunsigned;
}				t_spec;

int					ft_printf(const char *format, ...);
int					conv_s(va_list *ap, t_spec *spec);
void				width_s(char **str, t_spec *spec);
char				*width_s_2(int pad_len, char *padding, char c);
int					conv_c(va_list *ap, t_spec *spec);
int					conv_p(va_list *ap, t_spec *spec);
int					conv_d(va_list *ap, t_spec *spec);
void				itoa_d(long long num, char **str, t_spec *spec);
void				itoa_u(unsigned long long num, char **str);
void				itoa_octal(unsigned long long num, char **str);
void				precision_d(char **str, t_spec *spec);
void				width_d(char **str, t_spec *spec);
int					conv_u(va_list *ap, t_spec *spec);
int					conv_o(va_list *ap, t_spec *spec);
unsigned long long	lenmod_unsigned(va_list *ap, t_spec *spec);
long long			lenmod(va_list *ap, t_spec *spec);
int					conv_x(va_list *ap, t_spec *spec);
void				itoa_hex(unsigned long long num, char **str, t_spec *spec);
void				prefix(char *pre, char **str);
void				suffix(char **str, char *post);
int					conv_f(va_list *ap, t_spec *spec);
void				ldtoa(long double num, char **str, t_spec *spec);
void				dtoa(double num, char **str, t_spec *spec);

#endif
