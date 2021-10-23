#include <stdio.h>
#include "configInput.c"
#include "gameInterface.c"

/* prototype fungsi */
int mainMenu();
void title();

/* Fungsi utama yang akan di-run */
void main(){
    mainMenu();
}

/* Fungsi mainMenu */
int mainMenu()
{
    title();
    printf("========MENU========\n");
    printf("1. New Game\n");
    printf("0. Exit Game\n");
    printf("Masukkan pilihan: \n>>> ");

    int option;
    gameMatrix MainGM;
    startToken();
    option = currentToken.val;
    switch (option)
    {
    case 1:
        /* printf("\nMasukkan direktori file konfigurasi:\nmis. .//config/config.txt\n>>>  ");
            char fileName[100];
            scanf("%s", &fileName);*/
        MainGM = configInput("placeholder");
        gameMenu(&MainGM);
    case 0:
        return 0;
    }
}

void title()
{
    printf("  __                         \n");
    printf(" /  )  _ _ _ _      (   //   \n");
    printf("/(_/()/ (-(///)()/) |/|//)(/ \n");
    printf("                          /  \n");
}