#include<iostream>
#include "sequence.h"

//CONSTRUCTOR----------------------------------------------
sequence_class::sequence::sequence(size_type capacity)
{
	data = new value_type[capacity];
	used = 0;
	CAP = capacity;
}
sequence_class::sequence::sequence(const sequence & source)
{
	if (this == &source) { return; }

	this->data = new value_type[source.CAP];
	for (int i = 0; i < source.used; i++) {
		data[i] = source.data[i];
	}
	this->CAP = source.CAP;
	this->used = source.used;
}

//MEMBER FUNCTIONS-----------------------------------------
void sequence_class::sequence::reserve(size_type newsize)
{
	value_type* longer_array;
	longer_array = new value_type[newsize];
	copy(data, longer_array, 0, used);
	delete[]data;
	data = longer_array;
	CAP = newsize;
}

void sequence_class::sequence::copy(value_type * from, value_type * to, size_type start, size_type finish)
{
	for (int i = start; i < finish; i++) {
		to[i] = from[i];
	}
}

//MODIFYING FUNCTIONS-----------------------------------------
void sequence_class::sequence::insert_at(size_type index, const value_type input)
{
	if (index > used) {
		std::cout << "sequence may be disrupted" << std::endl;
		return;
	}
	if (used == CAP) {
		reserve(used + 3);
	}
	for (int i = used; i > index; i--) {
		data[i] = data[i - 1];
	}

	data[index] = input;
	used++;

}
void sequence_class::sequence::insert_first(const value_type number)
{
	if (used == CAP) {
		reserve(used + 3);
	}
	for (int i = used; i > 0; i--) {
		data[i] = data[i - 1];
	}

	data[0] = number;
	used++;
}
void sequence_class::sequence::insert(value_type number)
{
	if (used == CAP) {
		reserve(used + 3);
	}
	data[used] = number;
	used++;
}

void sequence_class::sequence::erase_from(int index)
{
	if (index >= used) {
		std::cout << "invalid index!!!" << std::endl;
		return;
	}
	for (int i = index; i < (used - 1); i++) {
		data[i] = data[i + 1];
	}

	used--;
}

void sequence_class::sequence::erase_first(value_type target)
{
	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			erase_from(i);
			std::cout << "first occurance of "<<target<<" was deleted" << std::endl;
			return;
		}
	}

	std::cout << "number wasn't found" << std::endl;
}

void sequence_class::sequence::erase_last(value_type target)
{
	int index = used;
	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			index = i;
		}
	}
	if (index < used) {
		erase_from(index);
		std::cout << "last occurence of "<<target<< " was deleted" << std::endl;
		return;
	}

	std::cout << "number not found" << std::endl;
}

void sequence_class::sequence::erase_occurance(value_type target, size_type occur)
{
	if (occur <= 0) {
		std::cout << "invalid INPUT" << std::endl;
		return;
	}
	size_type occurance = 0;
	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			occurance++;
			if (occurance == occur) {

				erase_from(i);
				std::cout << "occurance was deleted from sequence :D" << std::endl;
				return;

			}
		}
	}
	if ((occurance == 0) || (occurance != occur)) {
		std::cout << "number occurance wasn't found!!!" << std::endl;
	}
}

void sequence_class::sequence::operator=(const sequence & source)
{
	value_type* newdata;
	if (this == &source) {
		return;
	}

	if (this != &source) {
		newdata = new value_type[source.CAP];
		delete[] data;
		data = newdata;
		CAP = source.CAP;
	}
	copy(source.data, data, 0, source.used);
	used = source.used;
	// TODO: insert return statement here
}

sequence_class::sequence& sequence_class::sequence::operator+(value_type input)
{
	this->insert(input);
	return *this;
}


sequence_class::sequence & sequence_class::sequence::operator+=(const sequence & addend)
{
	if (CAP < (this->used + addend.used)) {
		reserve(used + addend.used);
	}
	for (int i = 0; i < addend.used; i++) {
		this->data[this->used] = addend.data[i];
		used++;
	};

	return *this;

	// TODO: insert return statement here
}

sequence_class::sequence & sequence_class::sequence::operator+=(value_type input)
{
	this->insert(input);

	return *this;
}

//BOOLIAN FUNCTION------------------------------------
bool sequence_class::sequence::operator==(const sequence & test)
{
	bool result = false;
	if (this->used != test.used) { return result; }
	for (int i = 0; i < (this->used); i++) {
		if (this->data[i] == test.data[i]) {
			result = true;
		}
		else {
			result = false;
			return result;
		}
	}
	return result;
}

int sequence_class::sequence::count(value_type target)const
{

	int numOfelements = 0;
	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			numOfelements++;
		}
	}
	return numOfelements;
}
//Freind functions
//IOSTREAM OPERATOR OVER LOADED------------------------------------------
std::ostream & sequence_class::operator<<(std::ostream & outs, const sequence & b) {
	outs << "{" << std::flush;

	for (int i = 0; i < b.used; i++) {
		outs << b.data[i] << ", " << std::flush;

	}

	outs << "}";
	return outs;
}

std::istream & sequence_class::operator>>(std::istream & ins, sequence & a)
{
	int i = 0;
	int input;
	while ((ins >> input)) {
		a.data[i] = input;
		a.used++;
		if (a.used == a.CAP) { break; }
		i++;
	}

	return ins;
	// TODO: insert return statement here
}

sequence_class::sequence  sequence_class::operator+(const sequence & addend, const sequence & addened2)
{
	sequence result(addend.used + addened2.used);

	result += addend;
	result += addened2;

	return result;
	// TODO: insert return statement here
}
