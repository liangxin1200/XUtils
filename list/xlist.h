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

static inline void x_list_add_tail(x_list_t *element,
				   x_list_t *head)
{
	head->prev->next = element;
	element->next = head;
	element->prev = head->prev;
	head->prev = element;
}

static inline void x_list_del(x_list_t *element)
{
	element->next->prev = element->prev;
	element->prev->next = element->next;
}

static inline void x_list_replace(x_list_t *new,
				  x_list_t *old)
{
	old->next->prev = new;
	new->next = old->next;
	new->prev = old->prev;
	old->prev->next = new;
}

#define x_list_entry(ptr, type, member) \
	((type *)((char *)(ptr) - (char *)(&((type *)0)->member)))

#define x_list_for_each(pos, head) \
	for ((pos) = (head)->next ; (pos) != (head); (pos) = (pos)->next)

#endif
