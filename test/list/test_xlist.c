#include "../../list/xlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct user {
	int data;
	x_list_t list;
}user_t;

int main(void)
{
	x_list_t head;
	x_list_init(&head);
	x_list_t *pos = NULL;	

	user_t *ptr_user = NULL;
	user_t *new = NULL;	
	user_t *old = NULL;

	printf("insert data\n");
	int i;
	for (i=0; i<5; i++) {
		ptr_user = (user_t *)malloc(sizeof(user_t));
		ptr_user->data = i;
		x_list_add(&ptr_user->list, &head);
	}

	x_list_for_each(pos, &head) {
		ptr_user = x_list_entry(pos, user_t, list);
		printf("data is %d\n", ptr_user->data);
	}

	printf("\ninsert in tail\n");
	for (i=0; i<5; i++) {
		ptr_user = (user_t *)malloc(sizeof(user_t));
		ptr_user->data = i;
		x_list_add_tail(&ptr_user->list, &head);
	}

	x_list_for_each(pos, &head) {
		ptr_user = x_list_entry(pos, user_t, list);
		printf("data is %d\n", ptr_user->data);
	}

	printf("\ndel some data\n");
	x_list_for_each(pos, &head) {
		ptr_user = x_list_entry(pos, user_t, list);
		if (ptr_user->data % 2 == 0) {
			x_list_del(&ptr_user->list);
			free(ptr_user);
		}
	}	

	x_list_for_each(pos, &head) {
		ptr_user = x_list_entry(pos, user_t, list);
		printf("data is %d\n", ptr_user->data);
	}	

	printf("\nreplace some data\n");
	new = (user_t *)malloc(sizeof(user_t));
	new->data = 234;
	
	x_list_for_each(pos, &head) {
		ptr_user = x_list_entry(pos, user_t, list);
		if (ptr_user->data == 3) {
			x_list_replace(&new->list, &ptr_user->list);
		}
	}	

	x_list_for_each(pos, &head) {
		ptr_user = x_list_entry(pos, user_t, list);
		printf("data is %d\n", ptr_user->data);
	}	

	return 0;
}
