#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Fonctions utiles pour les tests de striter/strmapi/lst */
void	f_iter(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}

char	f_map(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

void	f_del(void *content)
{
	(void)content;
}

// int	main(void)
// {
	
// 	printf("ft_isalpha: %d\n", ft_isalpha('a'));

// 	printf("ft_isdigit: %d\n", ft_isdigit('0'));
	
// 	printf("ft_isalnum: %d\n", ft_isalnum('?'));
	
// 	printf("ft_isascii: %d\n", ft_isascii(200));
	
// 	printf("ft_isprint: %d\n", ft_isprint(10));
	
// 	printf("ft_toupper): %c\n", ft_toupper('a'));
	
// 	printf("ft_tolower: %c\n", ft_tolower('A'));
	
// 	printf("ft_strlen: %zu\n", ft_strlen("123"));
	
// 	printf("ft_atoi(: %d\n", ft_atoi("  -42"));
	
// 	printf("ft_strncmp: %d\n", ft_strncmp("abc", "abd", 5));
	
// 	char buff[50];
	
// 	ft_memset(buff, 'A', 10);
	
// 	buff[10] = 0;
	
// 	printf("ft_memset: %s\n", buff);
	
// 	ft_bzero(buff, 10);
	
// 	printf("ft_bzero : %s\n", buff);
	
// 	ft_strlcpy(buff, "Bonjour", 50);
	
	
	
// 	printf("ft_strlcpy: %s\n", buff);
	
// 	ft_strlcat(buff, " Monde", 50);
	
// 	printf("ft_strlcat: %s\n", buff);
	
// 	printf("ft_strchr: %s\n", ft_strchr(buff, 'M'));
	
// 	printf("ft_strrchr : %s\n", ft_strrchr(buff, 'o'));
	
// 	printf("ft_strnstr: %s\n", ft_strnstr("aaabc", "abc", 5));
	
// 	char mem_src[] = "123456";
	
// 	char mem_dest[50];
	
// 	ft_memcpy(mem_dest, mem_src, 7);
	
// 	printf("ft_memcpy: %s\n", mem_dest);
	
// 	char move_test[] = "123456";
	
// 	ft_memmove(move_test + 2, move_test, 3);
	
// 	printf("ft_memmove : %s\n", move_test);
	
// 	printf("ft_memchr: %s\n", (char *)ft_memchr("abc", 'b', 3));
	
// 	printf("ft_memcmp: %d\n", ft_memcmp("a", "b", 1));
	
// 	char *dup = ft_strdup("dup test");
	
// 	printf("ft_strdup: %s\n", dup);
	
// 	free(dup);
	
// 	void *cal = ft_calloc(5, sizeof(int));
	
// 	printf("ft_calloc: %d\n", cal != NULL);
	
// 	free(cal);
	
// 	char *sub = ft_substr("0123456", 2, 3);
	
// 	printf("ft_substr: %s\n", sub);
	
// 	free(sub);
	
// 	char *join = ft_strjoin("A", "B");
	
// 	printf("ft_strjoin: %s\n", join);
	
// 	free(join);
	
// 	char *trim = ft_strtrim("  abc  ", " ");
	
// 	printf("ft_strtrim: %s\n", trim);
	
// 	free(trim);
	
// 	printf("ft_split:");
	
// 	char **tab = ft_split("aa bb cc", ' ');
	
// 	int i = 0;
	
// 	while (tab[i])
	
// 	{
	
// 		printf(" [%s]", tab[i]);
	
// 		free(tab[i]);
	
// 		i++;
	
// 	}
	
// 	printf("\n");
	
// 	free(tab);
	
// 	char *num = ft_itoa(-123);
	
// 	printf("ft_itoa: %s\n", num);
	
// 	free(num);
	
// 	char striter_buf[] = "abc";
	
// 	ft_striteri(striter_buf, f_iter);
	
// 	printf("ft_striteri: %s\n", striter_buf);
	
// 	char *strmap_res = ft_strmapi("abc", f_map);
	
// 	printf("ft_strmapi: %s\n", strmap_res);
	
// 	free(strmap_res);
	
// 	ft_putstr_fd("ft_putstr_fd: \n", 1);
	
// 	ft_putnbr_fd(123, 1);
	
// 	printf("\n");
	
// 	t_list *lst = ft_lstnew("Node 1");
	
// 	ft_lstadd_back(&lst, ft_lstnew("Node 2"));
	
// 	ft_lstadd_front(&lst, ft_lstnew("Node 0"));
	
// 	printf("ft_lstsize: %d\n", ft_lstsize(lst));
	
// 	printf("ft_lstlast: %s\n", (char *)ft_lstlast(lst)->content);
	
// 	printf("Liste content:");
	
// 	t_list *tmp = lst;
	
// 	while (tmp)
	
// 	{
	
// 		printf(" [%s]", (char *)tmp->content);
	
// 		tmp = tmp->next;
	
// 	}
	
// 	printf("\n");
	
// 	return (0);
// }
