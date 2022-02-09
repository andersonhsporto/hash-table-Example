#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdbool.h>

#define	SIZE 20

typedef	struct s_data
{
	int	data;
	int	key;
}	t_data;

t_data	*hashArray[SIZE];
t_data	*dummyItem;
t_data	*item;

int	hash_code(int key)
{
	return (key	% SIZE);
}


t_data *search(int key)
{
	int	hashIndex;	  //get	the	hash


	hashIndex =	hash_code(key);
	while(hashArray[hashIndex] != NULL)	  //move in array until	an empty
	{
		if(hashArray[hashIndex]->key == key)
		{
			return (hashArray[hashIndex]);
		}
		++hashIndex; //go to next cell
		hashIndex %= SIZE;		//wrap around the table
	}
	return (NULL);
}

void	insert(int key,int data)
{

	t_data *item = (t_data *)malloc(sizeof(t_data));
	item->data = data;
	item->key =	key;
	int	hashIndex =	hash_code(key);	 //get the hash	

   //move in array until an empty or deleted cell
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key	!= -1)
	{
		++hashIndex;	   //go	to next	cell
		hashIndex %= SIZE;		 //wrap	around the table
	}
	hashArray[hashIndex] = item;
}

t_data	*delete(t_data *item)
{
	int	key	= item->key;
	int	hashIndex =	hash_code(key);	  //get	the	hash
	while(hashArray[hashIndex] != NULL)
	{
		if(hashArray[hashIndex]->key == key)
		{
			t_data	*temp = hashArray[hashIndex];
			hashArray[hashIndex] =	dummyItem; 		 //assign a	dummy item at deleted position
			return	(temp);
		}
		++hashIndex;	  //go to next cell
		hashIndex	%= SIZE; 	  //wrap around	the	table
	}
	return (NULL);
}

void	display(void)
{
	int i;

	i = 0;
	while(i < SIZE)
	{
		if(hashArray[i] != NULL)
		{
			printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
		}
		else
		{
			printf(" ~~ ");
		}
		i++;
	}
	printf("\n");
	return ;
}

void	is_valid(t_data *item)
{
	if (item != NULL)
	{
		printf("Element found: %d\n", item->data);
	}
	else
	{
		printf("Element not found\n");
	}
}

int main (void)
{
	dummyItem = (t_data *)malloc(sizeof(t_data));
	dummyItem->data = -1;
	dummyItem->key = -1;

	insert(1, 20);
	insert(2, 70);
	insert(42, 80);
	insert(4, 25);
	insert(12, 44);
	insert(14, 32);
	insert(17, 11);
	insert(13, 78);
	insert(37, 97);

	display();
	item = search(37);
	is_valid(item);

	delete(item);

	item = search(37);
	is_valid(item);
}
