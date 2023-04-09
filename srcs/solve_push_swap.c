/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:32:40 by bena              #+#    #+#             */
/*   Updated: 2023/04/09 23:32:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array.h"
#include "s_stack.h"

t_stack			*init_stack(t_array *array);
t_stack			*release_stack(t_stack *stack);
void			sort_residual_elems(t_status *stat);
void			push_less_elems(t_status *stat, int number_of_elems_to_push);
void			recall_one_elem(t_status *stat);
static char		*find_the_answer(t_stack *a, t_stack *b);
static void		push_swap(t_status *stat);

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

	stat.answer.sheet = (char *)malloc(sizeof(char) * 8192);
	if (stat.answer.sheet == NULL)
		return (NULL);
	stat.answer.size = 8192;
	stat.number_of_elems = a->size;
	stat.residual_elems = a->size;
	stat.a = a;
	stat.b = b;
	stat.answer.ptr = stat.answer.sheet;
	push_swap(&stat);
	*stat.answer.ptr = '\0';
	return (stat.answer.sheet);
}

static void	push_swap(t_status *stat)
{
	double	ratio;
	int		elems_to_push;

	if (stat->number_of_elems <= 3)
		return (sort_residual_elems(stat));
	while (stat->residual_elems > 3)
	{
		ratio = 2.0 / 3.0;
		elems_to_push = (int)(stat->residual_elems * ratio);
		if (elems_to_push < 1)
			elems_to_push = 1;
		if (stat->residual_elems - elems_to_push <= 3)
			elems_to_push = stat->residual_elems - 3;
		push_less_elems(stat, elems_to_push);
	}
	sort_residual_elems(stat);
	while (stat->b->gate != NULL)
		recall_one_elem(stat);
}
