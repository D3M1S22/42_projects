/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:14 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/25 22:57:02 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	handle_quotes(const char *s, int *i, char quote_found)
// {
// 	(*i)++;
// 	while (s[*i] != '\0')
// 	{
// 		if (s[*i] != quote_found)
// 			(*i)++;
// 		else
// 			break ;
// 	}
// 	i --;
// }

// int	check_double_pipe(char const *s, char c)
// {
// 	int	i;
// 	int	p;

// 	i = -1;
// 	while (s[++i])
// 	{
// 		if (s[i] == '\'' || s[i] == '\"')
// 			handle_quotes(s, &i, s[i]);
// 		if (s[i] == c)
// 		{
// 			p = i;
// 			p++;
// 			while (s[p] == ' ')
// 				p++;
// 			if (s[p] == c)
// 				return (-1);
// 		}
// 	}
// }

// static int	strlen_neg_pos(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// static int	count_nbr_words(const char *str, char c)
// {
// 	int	i;
// 	int	trigger;

// 	i = 0;
// 	trigger = 0;
// 	if (check_double_pipe(str, '|'))
// 		return (-1);
// 	while (*str)
// 	{
// 		if (str[i] == '\'' || str[i] == '\"')
// 			handle_quotes(str, &i, str[i]);
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*copy_words(const char *str, int *start, int end)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((end - *start + 1) * sizeof(char));
// 	if (!word)
// 		return (0);
// 	while (*start < end)
// 	{
// 		word[i] = str[*start];
// 		i++;
// 		(*start)++;
// 	}
// 	word[i] = '\0';
// 	*start = -1;
// 	return (word);
// }

// char	**prova(int start, int j, char const *s, char c)
// {
// 	char	**split;
// 	int		i;
// 	int		n_words;

// 	if (!s)
// 		return (0);
// 	n_words = count_nbr_words(s, c);
// 	if (n_words == -1)
// 		return (0);
// 	split = malloc((n_words + 1) * sizeof(char *));
// 	if (!split)
// 		return (0);
// 	i = -1;
// 	while (++i <= strlen_neg_pos(s))
// 	{
// 		if (s[i] == '\'' || s[i] == '\"')
// 			handle_quotes(s, &i, s[i]);
// 		if ((s[i] != c && start < 0))
// 			start = i;
// 		else if ((s[i] == c || i == strlen_neg_pos(s)) && start >= 0)
// 			split[j++] = copy_words(s, &start, i);
// 	}
// 	split[j] = 0;
// 	return (split);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int	start;
// 	int	j;

// 	start = -1;
// 	j = 0;
// 	return (prova(start, j, s, c));
// }

int check_double_pipe(char const *s, char c)
{
    int i;
    int p;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\'' ||  s[i] == '\"')
            handle_quotes(s, &i, s[i], NULL);
        if (s[i] == c)
        {
            p = i + 1;
            while (s[p] == ' ')
                p++;
            if (s[p] == c)
                return (-1);
        }
        i++;
    }
    return(0);
}

static int strlen_neg_pos(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

static int count_nbr_words(const char *str, char c)
{
    int i;
    int j;
    int trigger;

    i = -1;
    j = 0;
    trigger = 0;
    if (check_double_pipe(str, '|'))
        return (-1);
    while (str[++i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            handle_quotes(str, &i, str[i], NULL);
        if (!str[i])
            return (j);
        if (str[i] != c && trigger == 0)
        {
            trigger = 1;
            j++;
        }
        else if (str[i] == c)
            trigger = 0;
    }
    return (j);
}

static char *copy_words(const char *str, int *start, int end)
{
    char *word;
    int i;

    i = 0;
    word = malloc((end - *start + 1) * sizeof(char));
    if (!word)
        return (0);
    while (*start < end)
    {
        word[i] = str[*start];
        i++;
        (*start)++;
    }
    word[i] = '\0';
    *start = -1;
    return (word);
}

char **prova(int start, int j, char const *s, char c)
{
    char **split;
    int i;
    int n_words;

    n_words = count_nbr_words(s, c);
    if (n_words == -1)
        return (0);
    split = malloc((n_words + 1) * sizeof(char *));
    if (!split)
        return (0);
    i = -1;
    while (++i <= strlen_neg_pos(s))
    {
        if (s[i] == '\'' || s[i] == '\"')
            handle_quotes(s, &i, s[i], &start);
        if (s[i] != c && start < 0)
            start = i;
        else if ((s[i] == c || i == strlen_neg_pos(s)) && start >= 0)
            split[j++] = copy_words(s, &start, i);
    }
    split[j] = 0;
    return (split);
}

char **ft_split(char const *s, char c)
{
    int start;
    int j;

    start = -1;
    j = 0;
    if (!s)
        return (0);
    return (prova(start, j, s, c));
}