#include "minishell.h"

void    ft_builtin_export(t_env **env, char   **argv)
{
    int i;

    i = 1;
    if(!argv)
        return ;
    if(!argv[1])
        print_export(*env);
    else
    {
        while (argv[i])
        {
            if(!is_var(*env, argv[i]))
                ft_lstadd_back(env, ft_lstnew(argv[i]));
            else
                ft_change_var(env, argv[i]);
            i++;
        }
    }     
}

void    ft_change_var(t_env **env, char *str)
{
    int i;
    char    *tmp;

    i = 0;
    tmp = ft_strdup("");
    while(str[i] != '=' && str[i])
    {
        tmp = ft_str_add(tmp, str[i]);
        i++;
    }
    while(env->str)
    {
        if(!ft_strncmp(env->str, tmp, ft_strlen(tmp)))
        {
            free((*env)->str);
            (*env)->str = ft_strdup(str);
            free(tmp);
            break;
        }
        env = env->next;
    }
    free(tmp);
}

void    print_export(t_env *env)
{
	int	x;

	x = 0;
	if (!env)
		perror("env");
	while (env)
	{
        ft_printf("declare -x ");
		ft_printf("%s\n", env->str);
		env = env->next;
	}
}

int is_var(t_env *env, char *str)
{
    int i;
    char    *tmp;

    i = 0;
    tmp = ft_strdup("");
    while(str[i] != '=' && str[i])
    {
        tmp = ft_str_add(tmp, str[i]);
        i++;
    }
    while(env->str)
    {
        if(!ft_strncmp(env->str, tmp, ft_strlen(tmp)))
        {
            free(tmp);
            return (1);
        }
        env = env->next;
    }
    free(tmp);
    return (0);
}