/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:36:34 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:58:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_array_bonus.h"

static void	sort(int *start, int *end);
static void	finish_sort(int *start, int *end);
static void	swap(int *a, int *b);
static int	select_pivot(int *start);

void	sort_array(t_array *array)
{
	sort(array->array, array->array + array->number_of_parameters - 1);
}

static void	sort(int *start, int *end)
{
	int	pivot;
	int	*left;
	int	*right;

	if (end - start < 3)
		return (finish_sort(start, end));
	pivot = select_pivot(start);
	left = start;
	right = end;
	while (left < right)
	{
		while (left < end && *left < pivot)
			left++;
		while (right > start && *right >= pivot)
			right--;
		if (left < right)
			swap(left, right);
	}
	if (left == right)
		left++;
	sort(start, right);
	sort(left, end);
}

static void	finish_sort(int *start, int *end)
{
	if (end == start)
		return ;
	if (end - start == 1)
	{
		if (*start > *end)
			return (swap(start, end));
		else
			return ;
	}
	if (*start > *(start + 1))
		swap(start, start + 1);
	if (*start > *(start + 2))
		swap(start, start + 2);
	if (*(start + 1) > *(start + 2))
		swap(start + 1, start + 2);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	select_pivot(int *start)
{
	int	temp[3];

	temp[0] = *start;
	temp[1] = *(start + 1);
	temp[2] = *(start + 2);
	if (temp[0] > temp[1])
		swap(temp, temp + 1);
	if (temp[0] > temp[2])
		swap(temp, temp + 2);
	if (temp[1] > temp[2])
		swap(temp + 1, temp + 2);
	return (temp[1]);
}
