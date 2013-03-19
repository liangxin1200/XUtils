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

static inline int x_list_is_last(const x_list_t *list,
				 const x_list_t *head)
{
	return list->next == head;
}

static inline int x_list_empty(const x_list_t *head)
{
	return head->next == head;
}

static inline void x_list_splice(x_list_t *list,
				 x_list_t *head)
{
	x_list_t *first = list->next;
	x_list_t *last = list->prev;
	x_list_t *at = head->next;

	first->prev = head;
	head->next = first;

	last->next = at;
	at->prev = last;
}

static inline void x_list_splice_tail(x_list_t *list,
				      x_list_t *head)
{
	x_list_t *first = list->next;
	x_list_t *last = list->prev;
	x_list_t *at = head;

	first->prev = at->prev;
	at->prev->next = first;

	last->next = at;
	at->prev = last;
}

#define x_list_entry(ptr, type, member) \
	((type *)((char *)(ptr) - (char *)(&((type *)0)->member)))

#define x_list_first_entry(ptr, type, member) \
	x_list_entry((ptr)->next, type, member)

#define x_list_for_each(pos, head) \
	for ((pos)=(head)->next; (pos)!=(head); (pos)=(pos)->next)

#define x_list_for_each_reverse(pos, head) \
	for ((pos)=(head)->prev; (pos)!=head; (pos)=(pos)->prev)

#endif
