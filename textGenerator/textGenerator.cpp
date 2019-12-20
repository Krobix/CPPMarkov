#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

struct _TextGenDict_Element{  //This struct used for indivisual elements in a TextGenDict
std::string word;
std::vector<std::string> vect;
};

class TextGenDict{ //Class that represents the dict (like an associative array) that is used to store probabilities

std::vector<_TextGenDict_Element> elements;

public:
TextGenDict();
	
void createElement(std::string word);

void addElementToWord(std::string word, std::string element);

void writeToDataFile(std::string fileName);

std::string chooseFromWord(std::string word);
	
_TextGenDict_Element *getElementByWord(std::string word);

}; 

struct Creature{
Creature();
TextGenDict articleNames;
TextGenDict authorNames;
TextGenDict articleContent;
};

class Generation{
std::vector<Creature> creatures;
int creatureNumber;
	
public:

};

//FUNCTION AND METHOD DEFINITIONS BEGIN HERE

TextGenDict::TextGenDict(){
	this->elements = {};
}

void TextGenDict::createElement(std::string word){
	_TextGenDict_Element tempElement;
	tempElement.word = word;
	this->elements.push_back(tempElement);
}

void TextGenDict::addElementToWord(std::string word, std::string element){
	_TextGenDict_Element *elementptr = this->getElementByWord(word);  
	elementptr->vect.push_back(element);
}
