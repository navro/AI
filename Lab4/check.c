#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define J
// #define M (Magnus)
typedef struct list_t	list_t;

struct list_t {
	list_t*		succ;
	list_t*		pred;
	void*		data;
};

static list_t* free_list;

static double sec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);

	return tv.tv_sec + 1e-6 * tv.tv_usec;
}

int empty(list_t* list)
{
	return list == list->succ;
}

list_t *new_list(void* data)
{
	list_t*		list;

	#ifdef J
	if(free_list != NULL)
	{
		list = free_list;
		free_list = free_list->succ;
	}
	else
	{
		list = malloc(sizeof(list_t));
	}
	#endif
	
	#ifdef M
	list = malloc(sizeof(list_t));
	#endif

	assert(list != NULL);

	list->succ = list->pred = list;
	list->data = data;

	return list;
}

void free_list_memory()
{
	list_t* p;
	list_t* q;

	p = free_list;
	while(p != NULL)
	{
		q = p->succ;
		free(p);
		p = q;
	}	
}

// LÃgger till ett nytt element med data innan elementet list
void add(list_t* list, void* data)
{
	list_t*		link;
	list_t*		temp;

	link		= new_list(data);

	list->pred->succ= link;
	link->succ	= list;
	temp		= list->pred;
	list->pred	= link;
	link->pred	= temp;
}

// Tar bort det aktuella objektet frÃn listan
void take_out(list_t* list)
{
	list->pred->succ = list->succ;
	list->succ->pred = list->pred;
	list->succ = list->pred = list;
}

// Takes out the successor
void* take_out_first(list_t* list)
{
	list_t*	succ;
	void*	data;

	if (list->succ->data == NULL)
		return NULL;

	data = list->succ->data;

	succ = list->succ;
	take_out(succ);
	
	#ifdef M
	free(succ);
	#endif

	#ifdef J
	if(free_list == NULL)
	{
		free_list = succ;
		succ->succ = NULL;
	}
	else
	{
		succ->succ = free_list->succ;
		free_list->succ = succ;
	}
	#endif

	return data;
}

static size_t nextsize()
{
#if 1
	return rand() % 4096;
#else
	size_t		size;
	static int	i;
	static size_t	v[] = { 24, 520, 32, 32, 72, 8000, 16, 24, 212 };

	size = v[i];

	i = (i + 1) % (sizeof v/ sizeof v[0]);
	
	return size;
#endif
}

static void fail(char* s)
{
	fprintf(stderr, "check: %s\n", s);
	abort();
}

int main(int ac, char** av)
{
	int		n = 500000;		/* mallocs in main. */
	int		n0;
	list_t*		head;
	double		begin;
	double		end;
	double		t = 2.5e-9;

	if (ac > 1)
		n = atoi(av[1]);

	n0 = n;

	#ifdef J
	free_list = malloc(sizeof(list_t));
	free_list->succ = NULL;
	//free_list->succ = free_list;
	//free_list->pred = free_list;
	#endif

	head = new_list(NULL);

	printf("check starts\n");

	begin = sec();

	while (n > 0)
	{
		add(head, malloc(nextsize()));
		n--;

		if ((n & 1) && !empty(head)) 
			free(take_out_first(head));
	}

	while (!empty(head)) 
		free(take_out_first(head));

	free(head);
	free_list_memory();

	end = sec();

	printf("check is ready\n");
	printf("total = %1.3lf s\n", end-begin);
	printf("m+f   = %1.3g s\n", (end-begin)/(2*n0));
	printf("cy    = %1.3lf s\n", ((end-begin)/(2*n0))/t);

	return 0;
}
