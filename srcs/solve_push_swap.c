/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:26:07 by bena              #+#    #+#             */
/*   Updated: 2023/03/24 04:34:34 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array.h"
#include "s_stack.h"

static char	*find_the_answer(t_stack *A, t_stack *B);
static void	push_swap(t_status *stat);

char	*solve_push_swap(t_array *array)
{
	t_stack	A;
	t_stack	B;
	char	*answer_sheet;

	A = init_stack(array);
	if (A == NULL)
		return (NULL);
	B = init_stack(NULL);
	if (B == NULL)
	{
		release_stack(&A);
		return (NULL);
	}
	answer_sheet = find_the_answer(&A, &B);
	release_stack(&A);
	release_stack(&B);
	return (answer_sheet);
}

static char	*find_the_answer(t_stack *A, t_stack *B)
{
	t_status	stat;
	char		*answer_sheet;

	answer_sheet = (char *)malloc(sizeof(char) * 8192);
	if (answer_sheet == NULL)
		return (NULL);
	stat.number_of_elems = A->size;
	stat.A = A;
	stat.B = B;
	stat.answer_sheet = answer_sheet;
	stat.ptr = answer_sheet;
	push_swap(&stat);
	return (answer_sheet);
}

static void	push_swap(t_status *stat)
{
}
