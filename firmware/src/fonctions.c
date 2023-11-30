/* 
 * File:   fonctions.c
 * Author: cyril feliciano
 * 
 * Description : Ce fichier contient les déclarations de mes fonctions.
 * 
 */

#include "fonctions.h"

APP_DATA appData;


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
    BSP_LEDOff(BSP_LED_0);
    BSP_LEDOff(BSP_LED_1);
    BSP_LEDOff(BSP_LED_2);
    BSP_LEDOff(BSP_LED_3);
    BSP_LEDOff(BSP_LED_4);
    BSP_LEDOff(BSP_LED_5);
    BSP_LEDOff(BSP_LED_6);
    BSP_LEDOff(BSP_LED_7);
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
    BSP_LEDOn(BSP_LED_0);
    BSP_LEDOn(BSP_LED_1);
    BSP_LEDOn(BSP_LED_2);
    BSP_LEDOn(BSP_LED_3);
    BSP_LEDOn(BSP_LED_4);
    BSP_LEDOn(BSP_LED_5);
    BSP_LEDOn(BSP_LED_6);
    BSP_LEDOn(BSP_LED_7);
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
    
    if(compteurEteint == 0)
    {
        EteindreLEDS();
        compteurEteint++;
    }
    
    switch (compteurLed)
    {
        case 0:
            BSP_LEDOff(BSP_LED_7);
            BSP_LEDOn(BSP_LED_0);
            compteurLed++;
            break;
        case 1:
            BSP_LEDOff(BSP_LED_0);
            BSP_LEDOn(BSP_LED_1);
            compteurLed++;
            break;
        case 2:
            BSP_LEDOff(BSP_LED_1);
            BSP_LEDOn(BSP_LED_2);
            compteurLed++;
            break;
        case 3:
            BSP_LEDOff(BSP_LED_2);
            BSP_LEDOn(BSP_LED_3);
            compteurLed++;
            break;
        case 4:
            BSP_LEDOff(BSP_LED_3);
            BSP_LEDOn(BSP_LED_4);
            compteurLed++;
            break;
        case 5:
            BSP_LEDOff(BSP_LED_4);
            BSP_LEDOn(BSP_LED_5);
            compteurLed++;
            break;
        case 6:
            BSP_LEDOff(BSP_LED_5);
            BSP_LEDOn(BSP_LED_6);
            compteurLed++;
            break;
        case 7:
            BSP_LEDOff(BSP_LED_6);
            BSP_LEDOn(BSP_LED_7);
            compteurLed = 0;
            break;
        default :
            break;    
    }   
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

