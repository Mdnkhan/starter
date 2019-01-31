#include<iostream>
#include"sequence.h"

using namespace std;
using namespace sequence_class;
int main() {


	sequence test(4);
	sequence test2(3);

	cin >> test;
	cout << "test size: " << test.size() << endl;
	cout << "test cap: " << test.capacity() << endl;
	cout << test << endl;

	test2.insert(4);
	test2 + 10;
	test2 += 15;
	test2.insert_first(30);
	test2.insert_at(2, 50);
	test2.insert_at(1, 6);
	test2.insert(100);
	cout << test2 << endl;
	cout << "test2 size: " << test2.size() << endl;
	cout << "test2 cap: " << test2.capacity() << endl;

	sequence result = test2 + test;

	cout << "result: " << result << endl;
	cout << "result size: " << result.size() << endl;
	cout << "result cap: " << result.capacity() << endl;

	result += test2;
	cout << "result: " << result << endl;
	cout << "result size: " << result.size() << endl;
	cout << "result cap: " << result.capacity() << endl;

	result.erase_first(6);
	cout << result << endl;
	result.erase_last(10);
	cout << result << endl;

	result.erase_occurance(4, 2);
	cout << "After 2nd occurance of 4 deleted\n" << result << endl;

	result.erase_from(3);
	cout << endl << "after element erased from index 3\n" << result << endl;

	sequence result_duplicate = result;
	cout << result_duplicate << endl;

	result_duplicate + 500;
	result_duplicate.insert_at(4, 14);
	cout << "result_duplicate: " << result_duplicate << endl;

	sequence newseq(result_duplicate);

	cout << endl << newseq << endl;

	cout << "newseq==result_duplicate: " << (newseq == test2) << endl;

	





	system("pause");
	return  0;
}