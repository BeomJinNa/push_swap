/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_array_from_input_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:41:31 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:58:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_input_bonus.h"
#include "s_array_bonus.h"

int			is_this_space(int c);
static void	extract_array_from_string(t_array *array, t_input *input);
static int	ft_atoi_extended(const char *str, int *overflow_checker);

void	get_array_from_input(t_array *array, t_input *input)
{
	array->number_of_parameters = input->number_of_parameters;
	array->array = (int *)malloc(sizeof(int) * array->number_of_parameters);
	if (array->array == NULL)
		return ;
	extract_array_from_string(array, input);
}

static void	extract_array_from_string(t_array *array, t_input *input)
{
	int		i;
	char	*ptr;
	int		overflow_occured;

	overflow_occured = 0;
	ptr = input->input;
	i = -1;
	while (++i < array->number_of_parameters)
	{
		while (is_this_space(*ptr))
			ptr++;
		array->array[i] = ft_atoi_extended(ptr, &overflow_occured);
		if (overflow_occured)
		{
			free(array->array);
			array->array = NULL;
			return ;
		}
		while (*ptr && is_this_space(*ptr) == 0)
			ptr++;
	}
}

static int	ft_atoi_extended(const char *str, int *overflow_checker)
{
	int			sign;
	long long	output;

	while (is_this_space(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	output = 0;
	while ('0' <= *str && *str <= '9')
	{
		output = output * 10 + *str - '0';
		str++;
	}
	output = sign * output;
	if (output < -2147483648 || 2147483647 < output)
		*overflow_checker = 1;
	return (output);
}
