#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int		ft_write(int fd, const void *str, size_t len);
char	*ft_strdup(const char *s1);

void call_strlen(char *str)
{
	size_t	r_res;
	size_t	w_res;

	printf("str |%s|: ", str);
	if ((r_res = strlen(str)) != (w_res = ft_strlen(str)))
		printf("-wrong- expeceted %zu instead of %zu\n", r_res, w_res);
	else
		printf("[%zu] +right+\n", w_res);
}

void	test_strlen(void)
{
	printf("=================ft_strlen=============\n");
	char *str;

	str = "";
	call_strlen(str);
	str = "1";
	call_strlen(str);
	str = "!";
	call_strlen(str);
	str = "x";
	call_strlen(str);
	str = "1234567890";
	call_strlen(str);
	str = "/";
	call_strlen(str);
	str = "\\";
	call_strlen(str);
	str = "qwertyuiop[]asdfghjkl;'xcvbnm,./";
	call_strlen(str);
	str = "...Zz";
	call_strlen(str);
	str = "?*0_lvaf";
	call_strlen(str);
	str = "ss";
	call_strlen(str);
	str = "NULL";
	call_strlen(str);
}

void call_strcmp(char *str1, char *str2)
{
	int	r_res;
	int	w_res;

	printf("str1: |%s|, str2: |%s|: ", str1, str2);
	if ((r_res = strcmp(str1, str2)) != (w_res = ft_strcmp(str1, str2)))
		printf("-wrong- expeceted %d instead of %d\n", r_res, w_res);
	else
		printf("[%d] +right+\n", w_res);
}

void test_strcmp(void)
{
	char	*str1;
	char	*str2;
	printf("=================ft_strcmp=============\n");
	str1 = "a";
	str2 = "a";
	call_strcmp(str1, str2);
	str1 = "a";
	str2 = "b";
	call_strcmp(str1, str2);
	str1 = "aa";
	str2 = "ab";
	call_strcmp(str1, str2);
	str1 = "bbb";
	str2 = "b";
	call_strcmp(str1, str2);
	str1 = "czxbc";
	str2 = "ccc";
	call_strcmp(str1, str2);
	str1 = "!_S@";
	str2 = "";
	call_strcmp(str1, str2);
	str1 = "";
	str2 = "";
	call_strcmp(str1, str2);
	str1 = "aaaa";
	str2 = "bbbb";
	call_strcmp(str1, str2);
	str1 = "\\";
	str2 = "\\";
	call_strcmp(str1, str2);
	str1 = "!!!!!";
	str2 = "!!!!!";
	call_strcmp(str1, str2);
	str1 = "";
	str2 = "basdas";
	call_strcmp(str1, str2);
	str1 = "zaxcvbgqwe";
	str2 = "zaxcvb";
	call_strcmp(str1, str2);
}

void call_strcpy(char *dest, const char *src)
{
	char	*r_res;
	char	*w_res;
	char	*dest_c;
	
	dest_c = strdup(dest);

	printf("dest: |%s|, src: |%s|: ", dest, src);
	r_res = strcpy(dest_c, src);
	w_res = ft_strcpy(dest, src);
	if (strcmp(r_res, w_res) != 0)
		printf("-wrong- expeceted %s instead of %s\n", r_res, w_res);
	if (strcmp(dest_c, dest) != 0)
		printf("-wrong dest- expeceted %s instead of %s\n", dest_c, dest);
	else
		printf("+right+ [%s] \n", w_res);
}	

void test_strcpy(void)
{
	char	dst[4] = "aaa";
	char	src[4] = "bbb";
	
	printf("=================ft_strcpy=============\n");
	call_strcpy(dst, src);
	
}

void	call_write(int fd, char *str, int len)
{
	int		r_res;
	int		w_res;
	int		err_code1;
	int		err_code2;

	write(1, "std:|", 6);
	r_res = write(fd, str, len);
	err_code1 = errno;
	write(1, "|\n", 2);
	write(1, "ft: |", 6);
	w_res = ft_write(fd, str, len);
	err_code2 = errno;
	write(1, "|\n", 2);
	if (r_res != w_res)
		printf("-wrong- expected %d instead of %d\n", r_res, w_res);
	else if(err_code1 != err_code2)
		printf("-wrong- exxpected errno %d instead of %d\n", err_code1, err_code2);

	else
		printf("+correct+\n");
	printf("errno1 = %d, errno2 = %d\n", err_code1, err_code2);
}

void	test_write(void)
{
	char	*str = "Hello NASM";
	int	fd;
	
	printf("=================ft_write=============\n");
	call_write(1, str, strlen(str));
	call_write(-1, str, strlen(str));	
	call_write(1, str, -5);
	str = "\tI am here\t";
	call_write(2, str, strlen(str));
	str = "\\!!\\";
	call_write(1, str, 4);
	call_write(1, str, 10);
	call_write(1, str, 0);
	call_write(1, str, 1);
	str = "Am I in file? o_O";
}

void	call_strdup(char *str)
{
	char	*r_res;
	char	*w_res;
	int		err1;
	int		err2;

	r_res = strdup(str);
	err1 = errno;
	w_res = ft_strdup(str);
	err2 = errno;

	printf("str: |%s|\n", str);
	if (errno == 12)
		perror("Error: ");
	else if (strcmp(r_res, w_res) != 0)
		printf("-wrong- expected |%s| instead of |%s|\n", r_res, w_res);
	else
		printf("+correct+\n");
}

void	test_strdup(void)
{
	char	*str = "copy me!";
	printf("=================ft_strdup=============\n");
	call_strdup(str);
	str = "";
	call_strdup(str);
	str = "\\";
	call_strdup(str);


}

int	main(void)
{
	test_strlen();
	test_strcmp();	
	test_strcpy();
	test_write();
	test_strdup();

	return(0);
}
