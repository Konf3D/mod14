#include "node.h"
#include <iostream>
Node::Node(const char c) 
	: c(c) 
{
	//constructor
}

bool Node::addWord(const std::string& word)
{
	int i = 0;
	if (word.empty())
		throw std::exception("Empty word was parsed!");

	if (word[i] != this->c)
		throw std::exception("Wrong symbol was parsed!");
	++i;

	m_next.emplace(word[i],Node(word[i]));

	return m_next.at(word[i]).addWord(word, i);
}

std::string Node::searchWord(const std::string& word) const
{
	if (word.empty())
		throw std::exception("Empty word was parsed!");

	if (word[0] != this->c)
		throw std::exception("Wrong symbol was parsed!");

	if (m_next.find(word[1]) == m_next.end())
	{
		return std::string(1,c);
	}

	return std::string(c + m_next.at(word[1]).searchWord(word, 1));
}

bool Node::addWord(const std::string& word, int i)
{
	if (i < 1)
	{
		throw std::exception("Negative iterator was parsed!");
	}
	
	if (i == word.size() - 1)
	{
		return true;
	}
	++i;
	
	m_next.emplace(word[i], Node(word[i]));

	return m_next.at(word[i]).addWord(word, i);
}

std::string Node::searchWord(const std::string& word, int i) const
{
	if (i < 1)
	{
		throw std::exception("Negative iterator was parsed!");
	}
	// return first found
	if (i >= word.size() - 1)
	{
		if (m_next.empty())
			return std::string(1, c);


		return std::string(c + searchWord());
	}
	else
	{
		++i;
		if (m_next.find(word[i]) == m_next.end())
		{
			return std::string(1, c);
		}
		else
		{
			return std::string(c + m_next.at(word[i]).searchWord(word, i));
		}
	}
	throw std::exception("Search failed!");
}

std::string Node::searchWord() const
{
	//rng
	static auto counter = c;
	++counter;
	if (counter == 'z')
		counter = 'a';
	// idea for consecutive iteration -> not working
	/*
	static auto ptrCounter = m_next.begin();
	++ptrCounter;
	auto charCounter = ptrCounter->first;
	if (ptrCounter == m_next.end())
		ptrCounter = m_next.begin();*/

	//if this is the end of the word
	if (m_next.empty())
	{
		return std::string(1,c);
	}

	// random next word
	if (m_next.find(counter) != m_next.end())
		return std::string(c + m_next.at(counter).searchWord());

	// search first alphabetically and return
	for (const auto& data : m_next)
	{
		auto kek = std::string(c + data.second.searchWord());
		//return std::string( c + data.second.searchWord());
		return kek;
	}
}


