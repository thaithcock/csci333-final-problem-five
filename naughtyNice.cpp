//Currently does not compile...
//takes one command that is the filename of the words file
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

//please don't hurt me
#include <string.h>

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::map;
using std::pair;

int main(int argC, char* args[]) {
 bool repeat;
 map<string, int> values = map<string, int>();
 char* line;
 string word;
 ifstream file (args[2]);
 if(file.is_open()) {
  while(file.good()){
   getline(file,line);
   //remembered that I needed to tokenize the words, but couldn't finish that...
   do{
    word = strtok((char*)line," ,.-");
    repeat = (values.insert(pair<string, int>(word, 1))).second;
    if(!repeat){
     (values[line]) += 1;
    }
   }while(word!=0);
  }
  file.close();
 }
 else cout << "File Not Found." << endl;

 //outputs words and number of word occurrences into file.
 ofstream newFile ("tweetWords");
 
 if(newFile.is_open()){
  map<string, int>::iterator it;
  for(it=values.begin(); it!=values.end(); it++){
   newFile << (*it).first << " " << (*it).second << "\n";
  }
  newFile.close();
 }
 return 0;
}
