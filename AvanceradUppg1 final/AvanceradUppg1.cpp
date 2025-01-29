// AvanceradUppg1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include <cassert>

int main()
{
    std::cout << "Hello World!\n";

	//Level 1
	Vector<char> v;
	assert(v.size() == 0);
	assert(v.capacity() >= 0);
	assert(v.Invariant());

	//Level 2
	/*Vector<char> fox("fox");
	assert(fox.size() == 3);
	assert(fox == fox);
	Vector<char> bar("bar");
	assert(!(fox == bar));*/

	//level 3
	/*Vector<char> fox("fox"), bar("bar");
	assert(fox == fox && !(fox != fox));
	assert(bar < fox && !(bar > fox));
	assert(bar <= fox && !(bar >= fox));
	assert(bar <= bar && fox >= fox);
	Vector<char> foxa("foxa");
	assert(fox != foxa && foxa != fox);
	assert(fox<foxa && foxa>fox);*/

	//Level 4
	/*Vector<char> fox("fox"), bar("bar");
	Vector<char> fox2(fox);
	assert(fox2.Invariant() && fox2.size() == 3);
	assert(fox == fox2);
	fox2 = bar;
	assert(fox2 == bar);
	assert(fox2.size() == 3);
	assert(fox2.capacity() >= 3);*/

	//level 5
	/*Vector<char> fox("fox"), bar("");
	assert(fox[0] == 'f' && fox[1] == 'o');
	fox[0] = 'g';
	assert(fox[0] == 'g' && fox[1] == 'o');
	const Vector<char> bar2("bar");
	static_assert(std::is_const_v<std::remove_reference_t< decltype(bar2[0])>>, "fel med const i operator[]");

	fox.at(1);
	bar2.at(2);*/

	//Level 6
	/*Vector<char> fox("fox"), bar("");
	fox.push_back('x');
	assert(fox == "foxx");
	bar.push_back('y');
	assert(bar == "y");
	fox.pop_back();
	assert(fox == "fox");
	fox.pop_back();
	assert(fox == "fo");*/

	//Level 7
	// 	//FOX BAR;
	//Vector Fox2(std::move(Fox));
	//assert(Fox2.Invariant() && Fox.Invariant());
	//assert(Fox2 == "Fox" && Fox == "");
	//Bar = std::move(Fox2);
	//assert(Fox2.Invariant() && Bar.Invariant());
	//assert(Bar == "Fox");
	//assert(Fox2 == "" || Fox2 == "Bar"); //Tillåt swap lösning

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
