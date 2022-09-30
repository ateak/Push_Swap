/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:55:51 by ateak             #+#    #+#             */
/*   Updated: 2022/02/23 19:17:29 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;	
	struct s_stack	*next;
}					t_stack;

typedef struct s_arguments
{
	t_stack		*head_a;
	t_stack		*head_b;
	int			size_b;
}					t_arguments;

long	*glb_init_and_num_parsing(t_arguments *glb, long *arr,
			int argc, char **argv);
void	arguments_checking(long *arr, int argc);
long	*copy_arr_into_sorted_arr(long *arr, long *sorted_arr, int argc);
long	*selection_sort(long *num, int size);
void	creating_stack_a(t_arguments *glb, long *arr, int argc);
t_stack	*create_node(int num);
void	push_back(t_stack **list, int num);
void	ft_compare(char *instruction, t_arguments *glb, size_t len);
void	ft_compare_addition(char *instruction, t_arguments *glb, size_t len);
void	checking_sorted_stack(t_arguments *glb);
char	*get_next_line(int fd);
char	*ft_read_file_and_form_tail(int fd, char *tail);
char	*ft_create_tail(char *buf, char *tail);
char	*ft_create_line(char *tail);
char	*ft_new_tail(char *tail);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	swap_a(t_stack **head_a);
void	swap_b(t_stack **head_b);
void	push_a(t_stack **head_a, t_stack **head_b, t_arguments *glb);
void	push_b(t_stack **head_a, t_stack **head_b, t_arguments *glb);
void	rotate_a(t_stack **head_a);
void	rotate_b(t_stack **head_b);
void	reverse_rotate_a(t_stack **head_a);
void	reverse_rotate_b(t_stack **head_b);
long	*selection_sort(long *num, int size);
int		ft_isdigit(int l);
long	ft_atoi(const char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t len);
void	ft_exit(void);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif