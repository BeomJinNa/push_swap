/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:32:40 by bena              #+#    #+#             */
/*   Updated: 2023/04/24 16:32:50 by bena             ###   ########.fr       */
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
static int		does_the_array_need_to_arrange(t_status *stat);
static double	get_ratio(int N);

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
	while (stat->residual_elems > 3 && does_the_array_need_to_arrange(stat))
	{
		ratio = get_ratio(stat->residual_elems);
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

static int	does_the_array_need_to_arrange(t_status *stat)
{
	t_elem	*ptr;

	ptr = stat->a->gate;
	while (ptr != NULL && ptr->next != stat->a->gate)
	{
		if (ptr->value + 1 != ptr->next->value)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static double	get_ratio(int N)
{
	int				i;
	double			before;
	double			result;
	double			gap;
	const double	gap_epsilon = 0.0001;

	result = 0.29;
	if ((int)(N * result) >= 16)
		return (result);
	i = 0;
	before = 0;
	result = (double)N;
	gap = 1.0;
	while (i < 30 && (gap >= gap_epsilon || - gap >= gap_epsilon))
	{
		before = result;
		result = (result + ((double)N / result)) / 2;
		gap = result - before;
		i++;
	}
	result = 1.8 / result;
	return (result);
}
