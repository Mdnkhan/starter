#pragma once
namespace sequence_class {

	class sequence {
	public:
		typedef size_t size_type;
		typedef int value_type;
		static const size_type DEFAULT_CAPACITY = 5;

		//CONSTRUCTORS----------------------------------------------
		sequence(size_type capacity = DEFAULT_CAPACITY);//creats an array of specified size or default size;
		sequence(const sequence& source);

		//DESTRUCTORS------------------------------------------------
		~sequence() {
			//releases the allocated memory from the heap
			delete[] data;
		}


		//IOSTRESM OPERATORS AND FREIND FUNCTIONS---------------------
		friend std::ostream &operator<<(std::ostream &outs, const sequence &b);
		friend std::istream& operator >>(std::istream &ins, sequence & a);

		//MODIFYING FUNCTIONS-----------------------------------------
		void insert_at(size_type index, value_type input);
		void insert_first(value_type number);
		void insert(value_type number);//inserts a number at the end

		void erase_from(int index);
		void erase_first(value_type target);
		void erase_last(value_type target);
		void erase_occurance(value_type target, size_type occur);


		void operator=(const sequence& source);
		sequence& operator +(value_type input);
		friend sequence operator +(const sequence& addend, const sequence& addened2);
		sequence& operator+=(const sequence& addend);
		sequence& operator+=(value_type input);
		//COMPARISON OPERATOR OVERLOAD---------------------------------
		bool operator==(const sequence& test);

		//CONST NON-MEMBER FUNCTIONS-----------------------------------
		int count(value_type target)const;
		size_type size()const { return  used; }
		size_type capacity()const { return CAP; }

	private:
		void reserve(size_type newsize);
		void copy(value_type* from, value_type* to, size_type start, size_type finish);

		value_type* data;
		size_type used;
		size_type CAP;// capacity of the class

	};



}