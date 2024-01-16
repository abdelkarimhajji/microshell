#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int err(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    return 1;
}
int cd(char **av, int i)
{
    if  (i != 2)
        return err("error: cd : bad argumens\n");
    else if(chdir(av[1]) == -1)
        return err ("error: cd: cannot change directory to"), err(av[1]), err(("\n"));
}

int exec(char **av, char **env, int i)
{
    int fd[2];
    int status;
    int haspipe 
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    int status = 0;
    
    if (ac > 1)
    {
        while (av[i] && av[++i])
        {
            av += i;
            i = 0;
            while (av[i] && strcmp(*av, "|") && strcmp(*av, ";"))
                i++;
            if(!strcmp(*av, "cd"))
                status = cd(av, i);
            else if(i)
                status = exec(av, env, i);
        }
    }
    return status;
}