/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_data_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:58:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "s_input_bonus.h"

int			does_input_error_exist(t_input *memory);
int			is_this_space(int c);
static int	does_empty_arg_exist(int ac, char **av);
static char	*get_linked_input_string(int ac, char **av);
static int	get_number_of_parameters(const char *str);

void	get_input_data(t_input *memory, int ac, char **av)
{
	if (does_empty_arg_exist(ac, av))
	{
		memory->input = NULL;
		return ;
	}
	memory->input = get_linked_input_string(ac, av);
	if (memory->input == NULL)
		return ;
	memory->number_of_parameters = get_number_of_parameters(memory->input);
	if (does_input_error_exist(memory))
	{
		free(memory->input);
		memory->input = NULL;
	}
}

static int	does_empty_arg_exist(int ac, char **av)
{
	char	*ptr;

	while (--ac > 0)
	{
		ptr = av[ac];
		while (*ptr)
		{
			if (ft_isdigit(*ptr))
				break ;
			ptr++;
		}
		if (*ptr == '\0')
			return (1);
	}
	return (0);
}

static char	*get_linked_input_string(int ac, char **av)
{
	char	*linked_string;
	int		counter;
	size_t	length;
	char	*ptr_to;
	char	*ptr_from;

	length = 0;
	counter = ac;
	while (--counter > 0)
		length += ft_strlen(av[counter]) + 1;
	linked_string = (char *)malloc(sizeof(char) * length);
	if (linked_string == NULL)
		return (NULL);
	ptr_to = linked_string;
	while (++counter < ac)
	{
		ptr_from = av[counter];
		while (*ptr_from)
			*ptr_to++ = *ptr_from++;
		*ptr_to++ = ' ';
	}
	*--ptr_to = '\0';
	return (linked_string);
}

static int	get_number_of_parameters(const char *str)
{
	int			number_of_parameters;
	const char	*ptr;

	number_of_parameters = 0;
	ptr = str;
	while (is_this_space(*ptr))
		ptr++;
	while (*ptr)
	{
		number_of_parameters++;
		while (*ptr && is_this_space(*ptr) == 0)
			ptr++;
		while (is_this_space(*ptr))
			ptr++;
	}
	return (number_of_parameters);
}
