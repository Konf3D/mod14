#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"
#include "node.h"
int main()
{
	std::fstream file("dictionary.txt", std::fstream::in);
	if (!file)
		return -1;

	Trie root(file);

	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("hig") << std::endl;
	std::cout << root.findWord("aa") << std::endl;
	std::cout << root.findWord("se") << std::endl;
	// does not support single words... Is this a feature or a bug?
	std::cout << root.findWord("s") << std::endl;
	std::cout << root.findWord("h") << std::endl;
	std::cout << root.findWord("z") << std::endl;
	return 1;
	
}
