#pragma once
#include<string>
#include<cstdlib>//provides size_t and NULL
#include<cassert>
namespace sak_22 {

	class node {

	public:
		typedef int key_type;
		typedef std::string value_type;
		node(const value_type& init_value = "empty", key_type defkey = key_type(), node* init_link = NULL) {
			data = init_value;
			key = defkey;
			link = init_link;
		}

		node* getLink() { return link; }
		const node* getLink()const { return link; }
		value_type getData()const { return data; }
		key_type getKey() const{ return key; }

		void setkey(const key_type& newkey) { key = newkey; }
		void setData(const value_type& newdata) { data = newdata; }
		void setLink(node* newlink) { link = newlink; }

	private:
		key_type key;
		value_type data;

		node* link;

	};
	
	void list_head_insert(node*& head_ptr, const node::value_type& entry, const node::key_type& newkey);
	void list_insert(node* previous_ptr, const node::key_type& newkey, const node::value_type& entry);
	node* list_search(node* head_ptr, const node::key_type& target);
	const node* list_search(const node* head_ptr, const node::key_type& target);
	node* list_locate(node* head_ptr, std::size_t position);
	const node* list_locate(const node* head_ptr, std::size_t position);
	void list_head_remove(node*& head_ptr);
	void list_remove(node* previous_ptr);
	void list_clear(node*& head_ptr);
	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
}
