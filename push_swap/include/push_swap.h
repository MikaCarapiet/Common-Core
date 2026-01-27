/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:19:36 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/27 10:25:19 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_Node
{
	int				content;
	struct s_Node	*next;
}					t_Node;

int					main(int argc, char **argv);

//validate.c
int					print_error(char *str);
int					validate_arg(int argc, char **argv, int *size, long **list);
long				*check_duplicate(long *list, int *size);
long				*parse_arg(int argc, char **argv, int *index);
long				ft_strtol(const char *strg);

#endif
