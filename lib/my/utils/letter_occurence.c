/*
** EPITECH PROJECT, 2021
** lib
** File description:
** occurrence of a letter in a sting
*/

int is_letter(char *str, char letter)
{
    int letter_count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == letter) {
            ++letter_count;
        }
    }
    return letter_count;
}
