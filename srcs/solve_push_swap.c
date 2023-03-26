/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:32:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/27 02:32:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array.h"
#include "s_stack.h"

t_stack		*init_stack(t_array *array);
t_stack		*release_stack(t_stack *stack);
static char	*find_the_answer(t_stack *a, t_stack *b);
//static void	push_swap(t_status *stat);

char	*solve_push_swap(t_array *array)
{
	t_stack	*a;
	t_stack	*b;
	char	*answer_sheet;

	a = init_stack(array);
	if (a == NULL)
		return (NULL);
	b = init_stack(NULL);
	if (b == NULL)
	{
		release_stack(a);
		return (NULL);
	}
	answer_sheet = find_the_answer(a, b);
	release_stack(a);
	release_stack(b);
	return (answer_sheet);
}

static char	*find_the_answer(t_stack *a, t_stack *b)
{
	t_status	stat;
	char		*answer_sheet;

	answer_sheet = (char *)malloc(sizeof(char) * 8192);
	if (answer_sheet == NULL)
		return (NULL);
	stat.number_of_elems = a->size;
	stat.a = a;
	stat.b = b;
	stat.answer_sheet = answer_sheet;
	stat.ptr = answer_sheet;
//	push_swap(&stat);
	return (answer_sheet);
}

//static void	push_swap(t_status *stat)
//{
//}
