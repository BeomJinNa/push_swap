/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:07:05 by bena              #+#    #+#             */
/*   Updated: 2023/03/13 11:47:16 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_array.h"

static void	sort(int *start, int *end);

void	sort_array(t_array *array)
{
	sort(array->array, array->array + array->number_of_parameters - 1);
}

static void	sort(int *start, int *end)
{
	int	pivot;
	int	*left;
	int	*right;

	pivot = *start;
	left = start;
	right = end;
}
