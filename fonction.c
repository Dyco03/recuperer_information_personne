#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int nbr_info(FILE *fichier,int nbr){  
	nbr=0;
	char ligne[300];
	rewind(fichier);
	while(fgets(ligne,sizeof(ligne),fichier)){
		nbr++;
	}
	return nbr;
}
information *recuperation(information personne[],FILE *fichier){
	char ligne[300];
	int nbr_ligne=0;
	nbr_ligne=nbr_info(fichier,nbr_ligne);
	personne=(information*)malloc(nbr_ligne*sizeof(information)); //premier allocation de personne
	int i=0;
	rewind(fichier);
	while((fgets(ligne,sizeof(ligne),fichier))!=NULL){
		sscanf(ligne,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",personne[i].nom,personne[i].prenom,personne[i].mention,
						personne[i].niveau,personne[i].adresse,personne[i].inscription);
		i++;
						
	}
	return personne;
}

information *trie(information personne[],const int indice){
	for(int i=1; i<indice; i++){
		for(int j=i+1; j<indice; j++){
			if(strcmp(personne[i].nom,personne[j].nom)>0){
				information temp;
				temp=personne[i];
				personne[i]=personne[j];
				personne[j]=temp;
			}
			else if(strcmp(personne[i].nom,personne[j].nom)==0){
				for(int k=1; k<indice; k++){
					for(int p=k+1; p<indice; p++){
						if(strcmp(personne[k].prenom,personne[p].prenom)>0){
							information temp;
							temp=personne[k];
							personne[k]=personne[p];
							personne[p]=temp;
						}
					}
				}
			}
		}
	}
	return personne;
}	
