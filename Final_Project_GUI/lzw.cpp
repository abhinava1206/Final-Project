#include<unordered_map>
#include<string>
#include<fstream>
#include<iostream>

using namespace std; 
void LZW::compress( ifstream& in, ofstream& out )
{
  std::unordered_map<std::string,unsigned int> codes;
  for ( unsigned int i = 0 ; i < 256 ; i++ )
    codes[std::string(1,(char)i)] = i;

  unsigned int next_index = 257;
  std::string current_string;
  char c;
  while (!in.eof()) {
    
    in.read(&c, sizeof(char));
  
    current_string = current_string + c;
    if ( codes.find(current_string) == codes.end() ) {
      codes[ current_string ] = next_index++;
      current_string.erase(current_string.size()-1);
      out.write((const char*) (&(codes[current_string])), sizeof(unsigned int));
      current_string = c;
    }
  }
  out.write((const char*) (&(codes[current_string])), sizeof(unsigned int));
}

void LZW::decompress( ifstream& in, ofstream& out )
{
  std::unordered_map<unsigned int,std::string> strings;
  for ( int unsigned i = 0 ; i < 256 ; i++ )
    strings[i] = std::string(1,i);

  std::string previous_string;
  std::string current_string;

  char c;
  unsigned int code;
  unsigned int next_index = 257;

  while (!in.eof()) {
    
    in.read((char*)&code, sizeof(unsigned int));
    if ( strings.find( code ) == strings.end() ) 
      strings[ code ] = previous_string + previous_string[0];
    out << strings[code];
    if ( previous_string.size() )
      strings[next_index++] = previous_string + strings[code][0];
    previous_string = strings[code];
    current_string = "";
  }
}





