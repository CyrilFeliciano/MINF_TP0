/* 
 * File:   fonctions.h
 * Author: cyril feliciano
 * 
 * Description : Ce fichier contient les prototypes de mes fonctions.
 * 
 */

#ifndef FONCTIONS_H
#define	FONCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "app.h"
    
//Prototype des fonctions
    
void InitPeriph (void);
void LectureEtAffichageADC ();
void AllumerLEDS(void);
void EteindreLEDS(void);
void Chenillard(void);


#ifdef	__cplusplus
}
#endif

#endif	/* FONCTIONS_H */

