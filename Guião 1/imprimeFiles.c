#include <stdlib.h>
#include <stdio.h>

int main(){
	printf("Which file do you want to print? (1 for User file, 2 for Review file and 3 for Business file)\n");
	int file;
	scanf("%d", &file);
	if(file== 1){
	
		//User File
		FILE *file_users= fopen("users.csv", "r");

		if(!file_users){
			printf("File does not exist\n");
			return -1;
		}

		printf("Users list\n");
	
		char **users= malloc(sizeof(char*)* 1000000);

		for(int i= 0; i< 1000000; i++){
		users[i]= malloc(sizeof(char)* 1024);
				fgets(users[i], 1024, file_users);
			printf("%s", users[i]); 
		}
		fclose(file_users);
		return 0;
 	}

 	if(file== 2){

		//Review File
		FILE *file_reviews= fopen("reviews.csv", "r");

		if(!file_reviews){
			printf("File does not exist\n");
			return -1;
		} 

		printf("Reviews list\n");

		char **reviews= malloc(sizeof(char*)* 1000000);
		for(int i= 0; i< 1000000; i++){
			reviews[i]= malloc(sizeof(char)*1024);
			fgets(reviews[i], 1024, file_reviews);
			printf("%s", reviews[i]);
		}
		fclose(file_reviews);
		return 1;
	}
	
	if(file== 3){
		//Business File
		FILE *file_business= fopen("business.csv", "r");

		if(!file_business){
			printf("File does not exist\n");
			return -1;
		}

		printf("Business list\n");
	
		char **business= malloc(sizeof(char*)* 1000000);

		for(int i= 0; i< 1000000; i++){
			business[i]= malloc(sizeof(char)* 1024);
			fgets(business[i], 1024, file_business);
			printf("%s", business[i]); 
		}
		fclose(file_business);
		return 2;
	}

	else{
		printf("File does not exist\n");
		return -1;
	}
}