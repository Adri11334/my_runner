/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** help
*/

#include "my.h"

int display_help(void)
{
    blue_header("USAGE");
    my_putstr("\t./my_runner [-h] [map]\n");
    print_description();
    print_game_mode();
    print_commands();
    write_purple("\n\nHave fun !!\n");
    return 0;
}

void print_description(void)
{
    blue_header("DESCRIPTION");
    my_putstr("\tDiscover the new generation ");
    write_green("Shrek");
    my_putstr(" game !\n");
    my_putstr("\tThe story takes place in the first film of the saga, ");
    my_putstr("when ");
    write_green("Shrek");
    my_putstr(" goes to  ");
    write_red("Lord Farquad's");
    my_putstr(" castle to ask for the ");
    my_putstr("liberation of his marsh\n");
    my_putstr("\tTake part of the adventure, and be ");
    write_green("Shrek");
    my_putstr(" during his fight ");
    my_putstr("against the ");
    write_red("guards");
    my_putstr(" upon his arrival at the castle.\n");
    write_cyan("\tWill you be able to defeat them all ?\n\n");
}

void print_game_mode(void)
{
    blue_header("OPTIONs");
    my_putstr("\t- Play with a map. You can use the map/map1 for demo.");
    my_putstr("\n\t\tYou can also create your's with a text file.");
    write_red("\n\t\tATTENTION\tOnly support '1' '2' ' ' char in the file.");
    write_cyan("\n\t\t- '1' to spawn Lord Farquad.");
    write_cyan("\n\t\t- '2' to spawn a guard.");
    write_cyan("\n\t\t- ' ' to spawn nothing.\n");
    my_putstr("\t- If you dont provide a map, or if the map isn't in a valid");
    my_putstr(" format, you play in infinite mode, with random");
    my_putstr(" enemies spawning\n\n");
}

void print_commands(void)
{
    blue_header("USER INTERACTIONS");
    my_putstr("\t- Everywhere:\n");
    my_putstr("\t\t- ESCAPE_KEY -> leave the game\n");
    my_putstr("\t\t- Q_KEY -> leave the game\n");
    my_putstr("\t- In main menu:\n");
    my_putstr("\t\t- S_KEY -> start the game\n");
    my_putstr("\t- In game\n");
    my_putstr("\t\t- SPACE_KEY -> ");
    write_green("Shrek");
    my_putstr(" jump !!!\n");
    my_putstr("\t- In victory/defeat menu:\n");
    my_putstr("\t\t- R_KEY -> restart the game\n");
    my_putstr("\t\t- Q_KEY -> leave the game\n\n");
}
