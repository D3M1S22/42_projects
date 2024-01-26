#include "../include/minishell.h"

void handle_quotes(const char *s, int *i, char quote_found, int *start)
{
    if(start && *start < 0)
        *start = *i;
    (*i)++;
    while (s[*i] != '\0')
    {
        if (s[*i] != quote_found)
        {
            (*i)++;
        }
        else
            break;
    }
}