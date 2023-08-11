#ifndef FONCTION_H
#define FONCTION_H
#include <stdio.h>
typedef struct information{
	char nom[30];
	char prenom[30];
	char mention[30];
	char niveau[10];
	char adresse[60];
	char inscription[20];
}information;

int nbr_info(FILE *fichier,int nbr); //c'est le nombre d'information (nombre de lignes)

information *recuperation(information personne[],FILE *fichier);//la recuperation des informations qui etait deja dans information.csv

information *trie(information personne[],const int indice);//trie de toutes les informations

#endif 
