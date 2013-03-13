#ifndef X_LIST_H_DEFINED
#define X_LIST_H_DEFINED

typedef struct x_list x_list_t;

struct x_list {
	x_list_t *next;
	x_list_t *prev;
};

static inline void x_list_init(x_list_t *head)
{
	head->next = head;
	head->prev = head;
}

static inline void x_list_add(x_list_t *element,
			      x_list_t *head)
{
	head->next->prev = element;
	element->next = head->next;
	element->prev = head;
	head->next = element;	
}

#define x_list_entry(ptr, type, member) \
	((type *)((char *)(ptr) - (char *)(&((type *)0)->member)))

#define x_list_for_each(pos, head) \
	for ((pos) = (head)->next ; (pos) != (head); (pos) = (pos)->next)

#endif
