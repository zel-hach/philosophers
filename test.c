void *function(void *t)
{
   t_info_philo *p;

    p = (t_info_philo *)t; 
    printf("%d\n", p->id);
    pthread_mutex_lock(&p[0]->fork[p->id]);
    pthread_mutex_lock(&p[0]->fork[(p->id % 5) + 1]);
    // sleep(1);
    pthread_exit(EXIT_SUCCESS);
}

void    cree_thread(char **arg)
{
    t_info_philo    *p;
    int              i;
    int             *tab;
    int               j;
    
    i = 0;
    j=0;
    tab = malloc(sizeof(int));
    if (is_integer(arg) == 0)
		     write(1,"Error\n",6);
    else
    {  
        while(arg[i])
         {
            tab[i] = ft_atoi(arg[i]);
            i++;
         }
        p = malloc(sizeof(t_info_philo) * tab[0]);
        printf("%d\n",tab[0]);
        pthread_mutex_init(p->fork,NULL);
        i = 0;
        while (i < tab[0])
        {
            p[i].id = i;
            pthread_create(&p[i].philo, NULL, &function, &p[i]);
            printf("hello : %d\n",p[i].id);
            i++;
   
        }
         i = 0;
        while (i < tab[0])
        {
            pthread_join(p[i].philo, NULL);
            i++;
        }
        printf("Après la création du thread.\n");
    }
}