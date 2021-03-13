#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

struct users *constroi_Users_list(){
	//Users File
		printf("Processing Users File...\n");
		FILE *file_users= fopen("users.csv", "r");

		if(!file_users){
		printf("File does not exist\n");
		return NULL;
		}

		struct users *users_list= malloc(sizeof(struct users)*1000000);

		for(int i= 0; i< 1000000; i++){
		fgets(users_list[i].user_id, 1024, file_users);
		}
		fclose(file_users);
		return users_list;
}

struct reviews *constroi_Reviews_list(){
	//Reviews File
	printf("Processing Review File...\n");
		FILE *file_reviews= fopen("reviews.csv", "r");

		if(!file_reviews){
			printf("File does not exist\n");
			return NULL;
		} 

		struct reviews *reviews_list= malloc(sizeof(struct reviews)*1000000);
		char ponto_virgula[2]= ";";

		for(int i= 0; i< 1000000; i++){
			char *temp= malloc(sizeof(char)* 1024);
			fgets(temp, 1024, file_reviews);
			//reviews_list[i].review_id= malloc(sizeof(char)*1024);

			reviews_list[i].review_id= strtok(temp, ponto_virgula);

			//reviews_list[i].user_id= malloc(sizeof(char)*1024);
			reviews_list[i].user_id= strtok(NULL, ponto_virgula);

			//reviews_list[i].business_id= malloc(sizeof(char)*1024);
			reviews_list[i].business_id= strtok(NULL, ponto_virgula);

			reviews_list[i].stars= atof(strtok(NULL, ponto_virgula));
			reviews_list[i].useful= atoi(strtok(NULL, ponto_virgula));
			reviews_list[i].funny= atoi(strtok(NULL, ponto_virgula));
			reviews_list[i].cool= atoi(strtok(NULL, ponto_virgula));
	}
	fclose(file_reviews);
	return reviews_list;
}


struct business *constroi_Business_list(){
	//Business File

	printf("Processing Business File...\n");
		FILE *file_business= fopen("business.csv", "r");

		if(!file_business){
			printf("File does not exist\n");
			return NULL;
		} 

		struct business *business_list= malloc(sizeof(struct business)*160585);


		char ponto_virgula[2]= ";";
		for(int i= 0; i< 160585; i++){
			char *temp= malloc(sizeof(char)*1024);
			fgets(temp, 1024, file_business);

			business_list[i].business_id= strtok(temp, ponto_virgula);
			business_list[i].name= strtok(NULL, ponto_virgula);
			business_list[i].city= strtok(NULL, ponto_virgula);
			business_list[i].stars= atof(strtok(NULL, ponto_virgula));
			business_list[i].review_count= atoi(strtok(NULL, ponto_virgula));
	}
	fclose(file_business);
	return business_list;
}

void alinea_a(struct business *business_list){
	printf("Alinea a)\n");
	int count= 1;
	for(int i= 0; i< 160585; i++) if(business_list[i].review_count!= 0) count ++;
	printf("There are %d business with reviews\n", count);
}

void alinea_b(struct business *business_list){
	printf("Alinea b)\n");
	int count= 1;
	for(int i= 0; i< 160585; i++) if(business_list[i].stars>= 4) count ++;
	printf("There are %d business with 4 or more stars\n", count);
}

void alinea_c(struct business *business_list){
	printf("Alinea c)\n");
	int indice= 0;
	int max= 0;

	for(int i= 0; i< 160585; i++) 
		if(business_list[i].review_count> max){
			max= business_list[i].review_count;
			indice= i;
	} 
	printf("The business with the most review is the business %d\n", indice+ 1);
	printf("Business %d id: %s\n", indice+ 1, business_list[indice].business_id);
	printf("Name: %s\n", business_list[indice].name);
	printf("City: %s\n", business_list[indice].city);
	printf("Stars: %f\n", business_list[indice].stars);
	printf("Review count: %d\n", business_list[indice].review_count);
}

void alinea_d(struct business *business_list){
	printf("Alinea d)\n");
	//Super ineficiente!!!
	char *city= business_list[0].city;
	int max= 0, count = 0;
	for(int i= 0; i< 160585; i++){
		for(int j= i; j< 160585; j++){
			if(strcmp(business_list[i].city, business_list[j].city)== 0) count++;
		}
		if(max< count){
			max= count; city= business_list[i].city;
		}
		count= 0;
	}
	printf("The city with the most business is: %s\n", city);
}

int menor(int a, int b, int c, struct reviews *reviews_list){
	int menor;
	if(reviews_list[a].cool< reviews_list[b].cool) menor= a;
	else menor= b;
	if(reviews_list[menor].cool> reviews_list[c].cool) return c; 
	else return menor;
}

int maior(int a, int b, int c, struct reviews *reviews_list){
	int maior;
	if(reviews_list[a].cool<= reviews_list[b].cool) maior= b;
	else maior= a;
	if(reviews_list[maior].cool> reviews_list[c].cool) return maior; 
	else return c;
}

int medio(int a, int b, int c, struct reviews *reviews_list){
	int medio;
	if(reviews_list[a].cool<= reviews_list[b].cool) medio= a;
	else medio= b;
	if(reviews_list[medio].cool> reviews_list[c].cool) return medio;
	else return c;
}



void alinea_e(struct reviews *reviews_list){
	printf("Alinea e)\n");
	int small= menor(0, 1, 2, reviews_list);
	int med= medio(0, 1, 2, reviews_list);
	int big= maior(0, 1, 2, reviews_list);

	for(int i= 3; i< 1000000; i++){
		if(reviews_list[i].cool>= reviews_list[big].cool){
			small= med;
			med= big;
			big= i;
		}
		else if(reviews_list[i].cool>= reviews_list[med].cool){
			small= med;
			med= i;
		}
		else if(reviews_list[i].cool>= reviews_list[small].cool) small= i;
	}
	printf("The 3 most cool reviews are: %d, %d, %d\n", big+ 1, med+ 1, small+ 1);
	printf("Review %d id: %s; Cool: %d\n", big+ 1, reviews_list[big].review_id, reviews_list[big].cool);
	//printf("User %d id: %s\n", review_number+ 1, reviews_list[review_number].user_id);
	//printf("Business %d id: %s\n", review_number+ 1, reviews_list[review_number].business_id);
	//printf("Stars: %f\n", reviews_list[review_number- 1].stars);
	//printf("Useful: %d; Funny: %d;  Cool: %d;\n", reviews_list[review_number].useful, reviews_list[review_number].funny, reviews_list[review_number].cool);
	printf("Review %d id: %s; Cool: %d\n", med+ 1, reviews_list[med].review_id, reviews_list[med].cool);
	printf("Review %d id: %s; Cool: %d\n", small+ 1, reviews_list[small].review_id, reviews_list[small].cool);
}