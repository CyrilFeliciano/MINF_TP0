/* 
 * File:   fonctions.c
 * Author: cyril feliciano
 * 
 * Description : Ce fichier contient les déclarations de mes fonctions.
 * 
 */

#include "fonctions.h"
#include <stdint.h>
#include "Mc32DriverAdc.h"  //ajout de la librairie contenant les fonctions lié a l'ADC
#include "Mc32DriverLcd.h"  //ajout de la librairie contenant les fonctions lié au LCD

APP_DATA appData;

#define NOMBRELEDS 8

/* 
Auteur : Cyril Feliciano

Fonction :
void EteindreLEDS(void)

Description :
Cette fonction éteint chaque LED individuellement en appelant la fonction
BSP_LEDOff avec l'identifiant de chaque LED (de BSP_LED_0 à BSP_LED_7).
Elle peut être utilisée pour mettre tous les indicateurs lumineux dans un
état éteint.
 */
void EteindreLEDS(void)
{
    for (int i = 0; i <= NOMBRELEDS; i++) 
    {
        BSP_LEDOff(i);
    }
}

/* 
Auteur : Cyril Feliciano

Fonction :
void AllumerLEDS(void)

Description :
Cette fonction active chaque LED de la carte en appelant la fonction
BSP_LEDOn avec l'identifiant de chaque LED (de BSP_LED_0 à BSP_LED_7).
*/
void AllumerLEDS(void)
{
    for (int i = 0; i <= NOMBRELEDS; i++) 
    {
        BSP_LEDOn(i);
    }
}

/*
 Auteur : Cyril Feliciano

 Fonction :
 void Chenillard(void)

 Description :
 Cette fonction implémente un effet de chenillard en faisant défiler
 l'allumage des LED sur la carte. Elle utilise deux compteurs statiques,
 compteurLed et compteurEteint, pour gérer l'état du chenillard. Les LED
 sont allumées une à une dans l'ordre, puis éteintes simultanément avant
 de recommencer le cycle.
*/
void Chenillard(void)
{   
    static uint8_t compteurLed = 0;
    static uint8_t compteurEteint = 0;
    static int ledIndex = 0;
    
    if(compteurEteint == 0)
    {
        EteindreLEDS();
        compteurEteint++;
    }
    
    

    BSP_LEDOff(ledIndex); // Éteindre la LED précédente
    ledIndex++; // Passer à la LED suivante
    if (ledIndex >= NOMBRELEDS) 
    {
    ledIndex = 0; // Si on atteint la dernière LED, revenir à la première
    }
    BSP_LEDOn(ledIndex); // Allumer la nouvelle LED
}


/* 
 Auteur : Cyril Feliciano
  
 Fonction :
 void initPeriph(void)

 Description :
 Cette fonction initialise les périphériques nécessaires pour le projet.
 Elle utilise les fonctions spécifiques à l'écran LCD (lcd_init,
 lcd_gotoxy, printf_lcd, lcd_bl_on) pour afficher des informations
 d'identification et active le bloc d'ADC (convertisseur analogique-numérique)
 avec la fonction BSP_InitADC10.
*/
void InitPeriph (void)
{
            lcd_init();
            lcd_gotoxy(1,1);
            printf_lcd("Tp0 Led+AD 2023-2024");
            lcd_gotoxy(1,2);
            printf_lcd("Feliciano Cyril");
            lcd_bl_on();
            BSP_InitADC10();
}

/*
 Auteur : Cyril Feliciano
 
 Fonction :
 void lectureEtAffichageADC(void)

 Description :
 Cette fonction lit les valeurs ADC pour les canaux 0 et 1 à l'aide de
 la fonction BSP_ReadAllADC. Elle affiche ensuite ces valeurs sur l'écran
 LCD à des positions spécifiques à l'aide des fonctions lcd_gotoxy et
 printf_lcd.
*/

void LectureEtAffichageADC (void)  
{
            appData.AdcRes = BSP_ReadAllADC();
            lcd_gotoxy(1,3);
            printf_lcd("Ch0: %4d", appData.AdcRes.Chan0);
            lcd_gotoxy(11,3);
            printf_lcd("Ch1: %4d", appData.AdcRes.Chan1);
}

