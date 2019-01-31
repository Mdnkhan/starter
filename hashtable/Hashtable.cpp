#include <iostream>
#include "Hashtable.h"

sak_22::hashtable::hashtable(size_t capacity)
{
	table = new hashbucket[capacity];
	cap = capacity;
	sizeOftable = 0;
}

sak_22::hashtable::~hashtable()
{
	for (size_t i = 0; i < cap; i++)
	{
		table[i].~hashbucket();
	}

	delete[] table;
}

int sak_22::hashtable::hash(node::key_type key)const {
	return (key%cap);
}

void sak_22::hashtable::put(node::value_type value, node::key_type key)
{
	int comparison = (0.75* cap);
	if ((sizeOftable == comparison) || (sizeOftable > comparison)) {
		extanding();
	}
	int index = hash(key);
	node* head_ptr = (table[index].getdata_ptr());

	if ((table[index].getsize()) == 0) {
		sak_22::list_head_insert(head_ptr, value, key);
		table[index].setTail_ptr(head_ptr);

		table[index].incrementsize();
	}

	else if ((table[index].getsize()) > 0) {

		sak_22::list_head_insert(head_ptr, value, key);// link list head insert func used
		table[index].incrementsize();// increments the size of the bucket
	}

	sizeOftable++;
}

void sak_22::hashtable::remove(node::key_type key)
{

	int index = hash(key);
	assert(((table[index].getsize()) > 0) && (sizeOftable > 0));

	node* cursor;
	size_t i = 1;
	size_t itterator = 0;

	node* head_ptr = table[index].getdata_ptr();
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink()) {
		if ((cursor->getKey()) == key) {
			itterator = i;
			break;
		}
		i++;
	}
	if (itterator == 0) { std::cout << "NO MATCHING KEY!!" << std::endl; }

	else if (itterator == 1) {
		list_head_remove(head_ptr);

		table[index].decrementsize();
	}

	else if (itterator > 1) {
		node*previus_ptr = list_locate(head_ptr, (itterator - 1));
		list_remove(previus_ptr);

		if (itterator== table[index].getsize()) { table[index].setTail_ptr(previus_ptr); }

		table[index].decrementsize();
	}

	sizeOftable--;
}

sak_22::node::value_type sak_22::hashtable::search(node::key_type key)
{
	assert(sizeOftable > 0);
	int index = hash(key);

	node* result_ptr= sak_22::list_search((table[index].getdata_ptr()), key); //uses link list class list search by getting the head pointer from hash bucket

	if (result_ptr != nullptr) {
		return (result_ptr->getData());
	}
	else {

		return "KEY NOT FOUND";
	}
}

void sak_22::hashtable::extanding()
{
	hashbucket* longer_array = new hashbucket[cap * 2];

	for (int i = 0; i < cap; i++) {
		longer_array[i].setsize((table[i].getsize()));
		longer_array[i].setlinklist((table[i].getlinklist()));
		longer_array[i].settree((table[i].gettree()));

		node* source_ptr = table[i].getdata_ptr();
		node* head_ptr = longer_array[i].getdata_ptr();
		node* tail_ptr = longer_array[i].getTail_ptr();

		sak_22::list_copy(source_ptr, head_ptr, tail_ptr);

	}

	cap = cap * 2;

	this->~hashtable();
	table = longer_array;
}




