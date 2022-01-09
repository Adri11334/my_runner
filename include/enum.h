/*
** EPITECH PROJECT, 2021
** bs_myrunner
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_
    enum error_type {
        NOT_REQUIRED_PARAMETER
    };

    enum gameobject_type {
        NONE,
        LORD_F,
        SHREK,
        GUARD,
        BKG
    };

    enum gamestatus {
        MENU,
        PAUSE,
        PLAYING,
        DEAD,
        VICTORY,
    };
#endif /* !ENUM_H_ */
