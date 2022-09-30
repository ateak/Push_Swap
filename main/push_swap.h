/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:55:51 by ateak             #+#    #+#             */
/*   Updated: 2022/02/22 20:59:26 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;	
	int				rb_score;
	int				rrb_score;
	int				ra_score;
	int				rra_score;
	int				var_ra_rb;
	int				var_rb_rra;
	int				var_rra_rrb;
	int				var_rrb_ra;
	int				final_score;
	int				var_arr[4];
	struct s_stack	*next;
}					t_stack;

typedef struct s_arguments
{
	t_stack		*head_a;
	t_stack		*head_b;
	int			size_a;
	int			size_b;
	int			min;
	int			max;
	int			mid;
	int			final_score_min;
}					t_arguments;

long	*glb_init_and_num_parsing(t_arguments *glb, long *arr, int argc,
			char **argv);
void	arg_checking(long *arr, t_arguments *glb, int argc);
long	*copy_arr_into_sorted_arr(long *arr, long *sorted_arr, int argc);
int		check_sorted_stack(long *arr, long *sorted_arr, int argc);
void	search_min_max_mid(t_arguments *glb, long *sorted_arr, int argc);
void	creating_stack_a(t_arguments *glb, long *arr, int argc);
t_stack	*create_node(int num);
void	push_back(t_stack **list, int num);
void	creating_stack_b(t_arguments *glb);
void	creating_stack_b_part2(t_arguments *glb);
void	sorting_min_max_mid(t_arguments *glb);
void	pushing_from_b_to_a(t_arguments *glb);
void	finding_ra_rb_rra_rrb_score_for_each_num(t_arguments *glb);
void	ra_rra_score(t_stack *tmp_a, t_stack *tmp_b, t_arguments *glb);
void	scoring_variants(t_arguments *glb);
void	final_scoring(t_arguments *glb);
void	finding_final_score_min(t_arguments *glb);
void	detecting_num_for_push(t_arguments *glb);
void	choose_var_ra_rb_or_var_rb_rra(t_arguments *glb, t_stack *tmp_b);
void	choose_var_rra_rrb_or_var_rrb_ra(t_arguments *glb, t_stack *tmp_b);
void	last_sort_for_stack_a(t_arguments *glb);

void	swap_a(t_stack **head_a);
void	swap_b(t_stack **head_b);
void	push_a(t_stack **head_a, t_stack **head_b);
void	push_b(t_stack **head_a, t_stack **head_b);
void	rotate_a(t_stack **head_a);
void	rotate_b(t_stack **head_b);
void	reverse_rotate_a(t_stack **head_a);
void	reverse_rotate_b(t_stack **head_b);
void	ra_rb_addition(t_arguments *glb, t_stack *tmp_b);
void	executing_ra_rb(t_arguments *glb, t_stack *tmp_b);
void	rra_rrb_addition(t_arguments *glb, t_stack *tmp_b);
void	executing_rra_rrb(t_arguments *glb, t_stack *tmp_b);
void	executing_rb_rra(t_arguments *glb, t_stack *tmp_b);
void	executing_rrb_ra(t_arguments *glb, t_stack *tmp_b);

long	*selection_sort(long *num, int size);
int		ft_isdigit(int l);
long	ft_atoi(const char *s);
void	ft_exit(void);

#endif