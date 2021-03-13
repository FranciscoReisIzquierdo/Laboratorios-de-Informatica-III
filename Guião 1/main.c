#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.c"


int main(){
	printf("Which file do you want to see? (1 for User file, 2 for Review file, 3 for Business file and 4 for statistics)\n");
	int file;
	scanf("%d", &file);

	if(file== 1){

		FILE *file_users= fopen("users.csv", "r");

		struct users *users_list= constroi_Users_list();
		
		printf("Which user do you want to see? (From user 1 to user 1000000)\n");
		int user;
		while(1){
			scanf("%d", &user);
			if(user< 1 || user > 1000000) printf("User does not exist (user number must be between 1 and 1000000).\nWhich user do you want to see? (From user 1 to user 1000000)\n");
			else{
				printf("User %d id: %s", user, users_list[user- 1].user_id);
				free(users_list);
				return 0;
			}
		}
	}

	
	if(file== 2){
		//Review File

		struct reviews *reviews_list= constroi_Reviews_list();
		printf("Wihch review do you want to see? (From review 1 to review 1000000)\n\n");
	
		while(1){
			int review_number;
			scanf("%d", &review_number);
			if(review_number< 1 || review_number> 1000000) printf("Review %d does not exist (review number must be between 1 and 1000000).\nWhich review do you want to see? (From review 1 to review 1000000)\n", review_number);
			else{
				printf("Review %d id: %s\n", review_number, reviews_list[review_number- 1].review_id);
				printf("User %d id: %s\n", review_number, reviews_list[review_number- 1].user_id);
				printf("Business %d id: %s\n", review_number, reviews_list[review_number- 1].business_id);
				printf("Stars: %f\n", reviews_list[review_number- 1].stars);
				printf("Useful: %d; Funny: %d;  Cool: %d;\n", reviews_list[review_number- 1].useful, reviews_list[review_number- 1].funny, reviews_list[review_number- 1].cool);
				free(reviews_list);
				return 1;
			}
		}
	}
	
	
	if(file== 3){
	//Business File
	struct business *business_list= constroi_Business_list();	
	printf("Which business do you want to see? (From business 1 to business 160585)\n\n");
	
	while(1){
		int business_number;
		scanf("%d", &business_number);
		if(business_number< 1 || business_number> 160585) printf("Business %d does not exist (business number must be between 1 and 160585).\nWhich business do you want to see? (From business 1 to business 160585)\n", business_number);
		else{
			printf("Business %d id: %s\n", business_number, business_list[business_number- 1].business_id);
			printf("Name: %s\n", business_list[business_number- 1].name);
			printf("City: %s\n", business_list[business_number- 1].city);
			printf("Stars: %f\n", business_list[business_number- 1].stars);
			printf("Review count: %d\n", business_list[business_number- 1].review_count);
			free(business_list);
			return 2;
			}
		}
	}
	if(file== 4){
		printf("Statistics\n");
		struct users *users_list= constroi_Users_list();
		struct reviews *reviews_list= constroi_Reviews_list();
		struct business *business_list= constroi_Business_list();

		alinea_a(business_list);
		alinea_b(business_list);
		alinea_c(business_list);
		//alinea_d(business_list);
		alinea_e(reviews_list);
	}
	else printf("Invalid command number\n");
	return 0;
}


