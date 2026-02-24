/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:19:36 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/24 15:25:53 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

// main.c
int					main(int argc, char **argv);
t_stack				*ft_lstnew_stack(int content);
t_stack				*ft_lstlast_stack(t_stack *head);
t_stack				*ft_lstpen_stack(t_stack *head);
int					deallocate(t_stack **a, t_stack **b);
void				insert_beginning(t_stack **root, int content);
// validate.c
int					print_error(char *str);
int					validate_arg(int argc, char **argv, long **list);
long				*check_duplicate(long *list, int size);
long				*parse_arg(int argc, char **argv);
long				ft_strtol(const char *strg);

// initialize.c
int					initialize_stacks(t_stack **a, t_stack **b, long *list,
						int size);
t_stack				*initialize_stack_a(long *list, int size);
t_stack				*initialize_stack_b(void);

void				print_stack(char *str, t_stack *head);
void				push(t_stack **src, t_stack **dst, char *str);
void				swap(t_stack **head, char *str);
void				rotate(t_stack **head, char *str);
void				swap_both(t_stack **a, t_stack **b);
void				rotate_both(t_stack **a, t_stack **b);
void				reverse_rotate_both(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **head, char *str);

int					sort(t_stack **a, t_stack **b, int size);
int					hardcode_sort(t_stack **a, t_stack **b, int size);
int					is_unsorted(t_stack *a);
int					two_sort(t_stack **a);
int					three_sort(t_stack **a);
int					four_sort(t_stack **a, t_stack **b);
void				get_min_val(t_stack **a, int *min_pos);
void				push_min_val(t_stack **a, t_stack **b, int min_pos);
int					five_sort(t_stack **a, t_stack **b);
#endif
