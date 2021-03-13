#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct users{
	char user_id[1024];
}*Users;

typedef struct reviews{
	char *review_id;
	char *user_id;
	char *business_id;
	float stars;
 	int useful;
 	int funny;
 	int cool;
}*Reviews;

typedef struct business{
	char *business_id;
	char *name;
	char *city;
	float stars;
	int review_count;
}*Business;

struct users *constroi_Users_list();
struct reviews *constroi_Reviews_list();
struct business *constroi_Business_list();

void alinea_a(struct business *business_list);
void alinea_b(struct business *business_list);
void alinea_c(struct business *business_list);
void alinea_d(struct business *business_list);
void alinea_e(struct reviews *reviews_list);

int menor(int a, int b, int c, struct reviews *reviews_list);
int maior(int a, int b, int c, struct reviews *reviews_list);
int medio(int a, int b, int c, struct reviews *reviews_list);
