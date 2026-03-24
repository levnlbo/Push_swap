/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:37:30 by aravetis          #+#    #+#             */
/*   Updated: 2026/03/21 19:37:32 by aravetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_numbers(char *argv)
{
	int	in_number;
	int	count;

	in_number = 0;
	count = 0;
	while (*argv)
	{
		if (*argv != ' ' && in_number == 0)
		{
			in_number = 1;
			count++;
		}
		else if (*argv == ' ')
			in_number = 0;
		argv++;
	}
	return (count);
}

static int	ft_word_len(char const *argv)
{
	int	len;

	len = 0;
	while (argv[len] && argv[len] != ' ')
		len++;
	return (len);
}

static char	**ft_free_all(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	**ft_split(char *argv)
{
	char	**arr;
	int		number_count;
	int		i;

	if (!argv)
		return (NULL);
	number_count = ft_count_numbers(argv);
	arr = malloc(sizeof(char *) * (number_count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < number_count)
	{
		while (*argv == ' ')
			argv++;
		arr[i] = ft_substr(argv, 0, ft_word_len(argv));
		if (!arr[i])
			return (ft_free_all(arr, i));
		argv = argv + ft_word_len(argv);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
