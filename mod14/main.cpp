#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"
#include "node.h"
void gui();
int main()
{
	std::fstream file("dictionary.txt", std::fstream::in);
	if (!file)
		return -1;

	Trie root(file);

	return 1;
	
}

void gui(const Trie& root)
{

}