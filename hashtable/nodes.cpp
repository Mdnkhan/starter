#include "nodes.h"

namespace sak_22 {

	void sak_22::list_head_insert(node *& head_ptr, const node::value_type & entry, const node::key_type & newkey)
	{
		node* insert_ptr = new node(entry,newkey, head_ptr);
		head_ptr = insert_ptr;
	}

	void list_insert(node * previous_ptr, const node::key_type & newkey, const node::value_type & entry)
	{
		node* insert = new node(entry,newkey);
		insert->setLink(previous_ptr->getLink());
		previous_ptr->setLink(insert);
	}
	
	//----------
	node * list_search(node * head_ptr, const node::key_type & target)
	{
		 node* cursor;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink()) {
			if (target == cursor->getKey()) { return cursor; }
		}
		return nullptr;
	}

	//-----------------
	const node * list_search(const node * head_ptr, const node::key_type & target)
	{
		const node* cursor;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink()) {
			if (target == cursor->getKey()) { return cursor; }
		}
		return nullptr;
	}
	
	//-------------------
	node * list_locate(node * head_ptr, std::size_t position)
	{
		node* cursor;

		cursor = head_ptr;
		size_t i;
		assert(position > 0);

		for (i = 1; (i < position && cursor != NULL); i++) {
			cursor = cursor->getLink();
		}

		return cursor;
	}

	//------
	const node * list_locate(const node * head_ptr, std::size_t position)
	{
		const node* cursor;

		cursor = head_ptr;
		size_t i;
		assert(position > 0);

		for (i = 1; (i < position && cursor != NULL); i++) {
			cursor = cursor->getLink();
		}

		return cursor;
	}
	
	//------
	void list_head_remove(node *& head_ptr)
	{
		node* remove_ptr = head_ptr;
		head_ptr = head_ptr->getLink();
		delete remove_ptr;
	}

	//--------
	void list_remove(node * previous_ptr)
	{
		node* remove_ptr;
		remove_ptr = previous_ptr->getLink();
		previous_ptr->setLink(remove_ptr->getLink());

		delete remove_ptr;
	}

	//------
	void list_clear(node *& head_ptr)
	{
		while (head_ptr != NULL) {
			list_head_remove(head_ptr);
		}
	}

	//---------
	void list_copy(const node * source_ptr, node *& head_ptr, node *& tail_ptr)
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->getData(), source_ptr->getKey());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->getLink();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->getKey(),source_ptr->getData());
			tail_ptr = tail_ptr->getLink();
			source_ptr = source_ptr->getLink();
		}
	}
}