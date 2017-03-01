#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX 1024
#define BUFFER 5

struct node {
	char c;
	struct node* next;
}

char *message;
FILE *fp;

int readf(FILE *fp) {
	if((fp = fopen("message.txt", "r")) == NULL) {
		printf("ERROR: Cannot open message.txt.\n");
		return 0;
	}

	message = (char *)malloc(sizeof(char) * MAX);
	if(message == NULL) {
		printf("ERROR: Out of memory.\n");
		return -1;
	}

	message = fgets(message, MAX, fp);
	if(message == NULL) {
		printf("ERROR: There was no message.\n");
		return -1;
	}
}

struct node* enqueue(char input) {
	struct node* temp = malloc(sizeof(struct node));
	strcpy(temp->c, input);
	temp->next = NULL;

	return temp;
}

struct node* dequeue(struct node* head) {
	struct node* temp = head->next;
	free(head);

	return temp;
}

int main(int argc, char *argv[]) {
	readf(fp);
	printf("readf(fp) was successful!\n");

	return 1;
}
