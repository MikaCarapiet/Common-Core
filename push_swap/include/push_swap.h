/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:19:36 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 09:51:30 by mcarapie         ###   ########.fr       */
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
int					deallocate(t_stack **head);
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
void				push(t_stack **src, t_stack **dst);
void				swap(t_stack **head);
void				rotate(t_stack **head);
void				swap_both(t_stack **a, t_stack **b);
void				rotate_both(t_stack **a, t_stack **b);

#endif
