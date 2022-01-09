/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** load_characters
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_runner.h"

void redirect_all_stdout(void);

Test(load_shrek_test, load_shrek_test)
{
    entity_t *entity = malloc(sizeof(entity_t));
    int result = load_shrek(entity);

    cr_assert_eq(result, 0);
    free(entity);
}

Test(load_f_test, load_f_test)
{
    entity_t *entity = malloc(sizeof(entity_t));
    int result = load_lord_f(entity);

    cr_assert_eq(result, 0);
    free(entity);
}

Test(load_guard_test, load_guard_test)
{
    entity_t *entity = malloc(sizeof(entity_t));
    int result = load_lord_f(entity);

    cr_assert_eq(result, 0);
    free(entity);
}
