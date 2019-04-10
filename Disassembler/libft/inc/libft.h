/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:21:11 by amerlon-          #+#    #+#             */
/*   Updated: 2019/04/10 23:01:23 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);

int					ft_putchar(char c);
int					ft_putstr(char const *s);
int					ft_putendl(char const *s);
int					ft_putnbr(int n);
int					ft_putchar_fd(char s, int fd);
int					ft_putstr_fd(char const *s, int fd);
int					ft_putendl_fd(char const *s, int fd);
int					ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	My functions
**	int		ft_iswhitespace(char c) : checks if char is whitespace
**	int		ft_nbrlen(int c) : length of int
**	int		ft_wordcount(const char *str, char del) : count words in string
**	char	*ft_nextword(char const *s, char c) : next word in string
**	char	*ft_strndup(const char *s1, size_t n) : man strndup
**	void	ft_lstclr(t_list *lst) : clears linked list
**	void	*ft_realloc(void *ptr, size_t size, size_t new_size) : man realloc
**	char	*ft_strshift(char **str, size_t n) : delete first n chars
**	char	*ft_strjoinch(char **str, char c) : appends char to string
**	char	*ft_copyuntil(char *str, int c) : copys until meets char
**	char	*ft_strchr_safe(const char *s, int c) : safe strchr
**	char	*ft_strdup_safe(const char *s1) : safe strdup
**	int		get_next_line(const int fd, char **line) : reading one line from fd
**
**	void	ft_iloveyoupeer(void) : expressing my love for peer ^_^
*/

void				swap(int *a, int *b);
int					ft_iswhitespace(int c);
int					ft_nbrlen(unsigned long long int nbr);
int					ft_wordcount(const char *str, char del);
char				*ft_nextword(char const *s, char c);
char				*ft_strndup(const char *s1, size_t n);
void				ft_lstclr(t_list *lst);
void				ft_iloveyoupeer(void);
void				*ft_realloc(void *ptr, size_t size, size_t new_size);
char				*ft_strshift(char **str, size_t n);
char				*ft_copyuntil(char *str, int c);
char				*ft_strchr_safe(const char *s, int c);
char				*ft_strdup_safe(const char *s1);
int					ft_strnchr(const char *s, char ch, int n);
long long int		ft_abs(long long int a);
char				*ft_ltoa_base(long long int n, int base);
int					ft_putstr_until(char *s, char c);
int					ft_nbrlen_base(unsigned long long int nbr, int base);
char				*ft_strjoinch(char **str, char c, int flag);
char				*ft_chjoinstr(char c, char **str, int flag);
char				*ft_strjoinnch(char **str, char c, int n, int flag);
char				*ft_nchjoinstr(char c, int n, char **str, int flag);
char				*ft_mstrjoin(char **s1, char **s2, int flag);
int					ft_deldoublearr(char ***res);

# define BUFF_SIZE 32

int					ft_gnl(const int fd, char **line);

#endif
