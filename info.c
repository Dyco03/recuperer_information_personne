#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(){
	/*************************/
	FILE* fichier;
	fichier=fopen("information.csv","a+");
	if(fichier==NULL){
		printf("erreur de flux");
		exit(1);
	}
	/*************************/
	rewind(fichier);
	char test[200];//sert a tester si les noms,prenoms sont deja existant
	if(fgets(test,200,fichier)==NULL){
	fprintf(fichier,"Nom,Prenom,Mention,Niveau,Adresse,n° d'inscription\n");
	}
	
	/*************************/
	int nbr_recup=0;
	nbr_recup=nbr_info(fichier,nbr_recup);
	information *personne=NULL;
	personne=recuperation(personne,fichier);
	
	/*************************/
	int choix;
	printf("Combien de personne etes-vous:");scanf("%d",&choix);
	getchar();//pour prendre le '\n'
	printf("Vous allez entrer les informations.\n");
	/*************************premier teste*/
	int nbr_total=nbr_recup + choix;
	personne=realloc(personne,nbr_total*sizeof(information));  //deuxieme allocation de personne
	/*************************/
	for(int i=nbr_recup; i<nbr_total; i++){
		printf("personne%d\n",choix);
		printf("Entrer les informations.\n");
		printf("Nom:");fgets(personne[i].nom,30,stdin);
		personne[i].nom[strcspn((personne[i].nom),"\n")]='\0';//pour supprimer les caracteres de fin de chaines
		printf("Prenom:");fgets(personne[i].prenom,30,stdin);	
		personne[i].prenom[strcspn((personne[i].prenom),"\n")]='\0';
		printf("Mention:");fgets(personne[i].mention,30,stdin);
		personne[i].mention[strcspn((personne[i].mention),"\n")]='\0';
		printf("Niveau:");fgets(personne[i].niveau,10,stdin);
		personne[i].niveau[strcspn((personne[i].niveau),"\n")]='\0';
		printf("Adresse:");fgets(personne[i].adresse,60,stdin);
		personne[i].adresse[strcspn((personne[i].adresse),"\n")]='\0';
		printf("n° d'inscrption:");fgets(personne[i].inscription,20,stdin);
		personne[i].inscription[strcspn((personne[i].inscription),"\n")]='\0';
		system("clear");
	}
	/*********************************/
	fclose(fichier);
	fichier=fopen("information.csv","w+");
	if(fichier==NULL){
		printf("erreur de flux");
		exit(1);
	}
	/*********************************/
	personne=trie(personne,nbr_total);
	/*********************************/
	
	for(int i=0; i<nbr_total; i++){//ajout de toutes les informations dans informations.csv
		fprintf(fichier,"%s,%s,%s,%s,%s,%s\n",personne[i].nom,personne[i].prenom,personne[i].mention,
						personne[i].niveau,personne[i].adresse,personne[i].inscription);
	}
	printf("Enregistrement effectue\n");
	fclose(fichier);
	return 0;
}
