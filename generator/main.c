/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main1
*/

#include "../include/dante.h"
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void print_map(char **maze, int y)
{
    int i = 0;
    for (i = 0; i != (y - 1); i++)
        printf("%s\n", maze[i]);
    printf("%s", maze[y - 1]);
    for (i = 0; i < y; i++)
        free(maze[i]);
    free(maze[i]);
    free(maze);
}

int *rand_two(int y, int x)
{
    int *rsl = malloc(sizeof(int) * 2);
    if (y == 2) {
        rsl[0] = rsl[1] = rand()%2;
    } else {
        rsl[0] = (rand()%(y/2));
        rsl[1] = y - rsl[0] - 2;
    }
    return (rsl);
}

int gene_imperfect(int x, int y)
{
    int *rand;
    char **maze = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        for (int o_p = 0; o_p < x; o_p++)
            maze[i][o_p] = (o_p%2 == 0) ? 'X': '*';
        maze[i][x] = '\0';
    }
    maze[y] = NULL;
    for (int o_p = 1; o_p < x; o_p++) {
        if (o_p % 2 == 0) {
            rand = rand_two(y, x);
            maze[rand[0]][o_p] = '*';
            maze[rand[1]][o_p] = '*';
            free(rand);
        }
    }
    maze[0][0] = '*';
    maze[y - 1][x - 1] = '*';
    print_map(maze, y);
}

int gene_perfect(int x, int y)
{
    char **maze = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        for (int o_p = 0; o_p < x; o_p++)
            maze[i][o_p] = (o_p%2 == 0) ? 'X': '*';
        maze[i][x] = '\0';
    }
    maze[y] = NULL;
    for (int o_p = 1; o_p < x; o_p++) {
        if (o_p%2 == 0)
            maze[rand()%y][o_p] = '*';
    }
    maze[0][0] = '*';
    maze[y - 1][x - 1] = '*';
    print_map(maze, y);
}

int main(int ac, char **av)
{
    srand(getpid());
    if (ac != 3 && ac != 4) return (84);
    for (int i = 1; i < 3; i++) {
        for (int o_p = 0; av[i][o_p] != '\0'; o_p++) {
            if (av[i][o_p] > '9' || av[i][o_p] < 0)
                return (84);
        }
    }
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        gene_perfect(atoi(av[1]), atoi(av[2]));
    else if (ac == 4 && strcmp(av[3], "perfect") == 0)
        gene_imperfect(atoi(av[1]), atoi(av[2]));
    else
        gene_imperfect(atoi(av[1]), atoi(av[2]));
    return (0);
}