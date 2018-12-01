#include <iostream>
#include <ostream>
#include <fstream>
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

  if (Argc != 2)
    fail("Usage: Day1 INPUT_PATH");

  string FilePath = Argv[1];
  ifstream InputFile;
  InputFile.open(FilePath, ios::binary);

  if (!InputFile.is_open())
    fail("Unable to open file");

  unordered_set<int> SeenNumbers;
  SeenNumbers.insert(Answer);

  InputFile.seekg(0, ios::end);
  int end = InputFile.tellg();
  InputFile.seekg(0, ios::beg);

  string Line;
  bool FoundDouble = false;
  while (!FoundDouble) {
    if (InputFile.tellg() == end)
      InputFile.seekg(0, InputFile.beg);

    std::getline(InputFile, Line);

    // Problem A
    Answer += std::atoi(Line.c_str());

    // Problem B
    if (SeenNumbers.find(Answer) == SeenNumbers.end()) {
      SeenNumbers.insert(Answer);
    } else {
      cout << Answer << " has been inserted before.\n";
      FoundDouble = true;
      break; // We've met an answer for the second time
    }
  }

  cout << Answer << '\n';

  return 0;
}
