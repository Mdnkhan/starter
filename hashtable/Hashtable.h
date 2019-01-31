#pragma once
#include "nodes.h"
#include "hashbucket.h"
#include<cassert>

namespace sak_22 {
	class hashtable{

	public:
		static const size_t CAPACITY= 20;

		hashtable(size_t capacity= CAPACITY);
		~hashtable();

		int hash(node::key_type key)const;

		void put(node::value_type value, node::key_type key);
		void remove(node::key_type key);

		node::value_type search(node::key_type key);

		void extanding();
	private:
		
		hashbucket* table;

		size_t cap;
		size_t sizeOftable;




	};
}