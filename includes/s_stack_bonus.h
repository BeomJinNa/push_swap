/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:42:52 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:59:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_BONUS_H
# define S_STACK_BONUS_H

typedef struct s_elem
{
	int				value;
	struct s_elem	*before;
	struct s_elem	*next;
}					t_elem;

typedef struct s_stack
{
	int		size;
	t_elem	*gate;
}			t_stack;

typedef struct s_answer
{
	char	*sheet;
	char	*ptr;
	int		size;
}			t_answer;

typedef struct s_status
{
	int			number_of_elems;
	int			residual_elems;
	t_stack		*a;
	t_stack		*b;
	t_answer	answer;
}			t_status;
#endif
