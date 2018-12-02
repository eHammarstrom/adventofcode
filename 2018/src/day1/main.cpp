#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

void fail(const char* Message) {
  cerr << Message << '\n';
  exit(1);
}

int main(int Argc, char* Argv[]) {
  int Answer = 0;

  /*
  if (Argc != 2)
    fail("Usage: Day1 INPUT_PATH");

  string FilePath = Argv[1];
  */
  string FilePath = "/home/ehammarstrom/git/adventofcode/2018/basse_input";
  ifstream InputFile (FilePath);

  stringstream Buffer;
  Buffer << InputFile.rdbuf();

  unordered_set<int> SeenNumbers;
  SeenNumbers.insert(Answer);

  Buffer.seekg(0, ios::end);
  int end = Buffer.tellg();
  Buffer.seekg(0, ios::beg);

  string Line;
  for (;;) {
    if (Buffer.tellg() == end)
      Buffer.seekg(0, ios::beg);

    std::getline(Buffer, Line);
    Answer += std::atoi(Line.c_str());

    if (SeenNumbers.find(Answer) == SeenNumbers.end()) {
      SeenNumbers.insert(Answer);
    } else {
      break; // We've met an answer for the second time
    }
  }

  cout << Answer << '\n';

  return 0;
}
