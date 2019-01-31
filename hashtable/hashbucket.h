#pragma once
#include"nodes.h"
namespace sak_22 {
	class hashbucket {
	public:

		hashbucket() {
			data_ptr = NULL;
			tail_ptr = NULL;
			linklist_m = true;
			tree_m = false;
			size = 0;
		}

		~hashbucket() {
			node* head_ptr = data_ptr;
			sak_22::list_clear(head_ptr);
		}
		node* getdata_ptr() { return data_ptr; }
		node* getTail_ptr() { return tail_ptr; }

		void setTail_ptr(node* ptr) { tail_ptr = ptr; }
		void setdata_ptr(node* newdatalink) {data_ptr = newdatalink; }
		void setlinklist(bool mode) { linklist_m = mode; }
		void settree(bool mode) { tree_m = mode; }

		bool getlinklist() const{ return linklist_m; }
		bool gettree() const{ return tree_m; }
		size_t getsize() const { return size; }
		void incrementsize(){ size++; }
		void decrementsize() { size--; }
		void setsize(size_t nsize) { size = nsize; }
	private:
		node* data_ptr;
		node* tail_ptr;
		bool linklist_m;
		bool tree_m;
		size_t size;
	};
}