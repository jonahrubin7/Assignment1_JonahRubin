#include "Translator.h" // include header file to make sure you have all the libraries you need

#include <string> //not sure why I need this but it doesnt work without it

Translator::Translator(){ // default constructor
  m_model = new Model();
}

Translator::Translator(Model* model){ //overloaded constructor
  m_model = model;
}

Translator::~Translator(){  // destructor
  delete m_model;
}


string Translator::translateEnglishWord(string word){ // create method to translate each word
  string newWord = ""; //create variables
  string nonAlpha = "";
  string punc = "";
  string ret = "\n";
  for(int i = 0; i < word.length(); ++i){  //for the length of the word
    if(isalpha(word[i])){ //if its a letter
      if(tolower(word[i]) == tolower(word[i+1])){  //if its a double letter
        newWord = newWord + m_model->translateDoubleCharacter(word[i]); //translate the double letter and add it to the word
        i++; // skip the next one because its a double
      }
      else{
        newWord = newWord + m_model->translateSingleCharacter(word[i]); // translate single letter and add it to the word
      }
    }
    else if(word[i] == '.'){ // split by sentance.
      punc = word[i] + ret;
      newWord = newWord + punc;
      }
    else{
      nonAlpha = nonAlpha + word[i]; // handling punctuation
      newWord = newWord + nonAlpha;
      nonAlpha = "";
    }
  }
  return newWord; //return the translated word
}

string Translator::translateEnglishSentance(string line){ //create method for translating each sentance
  string newWord = ""; // create variables
  string newLine = "";
  for(int i = 0; i < line.length(); ++i){ //for the length of the line
    if(line[i] == ' '){ //if its a space
      newLine = newLine + translateEnglishWord(newWord) + " "; //translate the word
      newWord = "";//and set the word back to empty
    }

    else{
      newWord = newWord + line[i]; //add the translated word to the line
    }
  }
  newLine = newLine + translateEnglishWord(newWord) + " "; //translate the last word in the sentance and add it to the line
  return newLine; // return the line
}
