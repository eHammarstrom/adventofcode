#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void fail(const char *Message) {
  cerr << Message << '\n';
  exit(1);
}

void solveA(stringstream *Buffer) {
  pair<int, int> IdCount(0, 0);
  string Line;
  while (std::getline(*Buffer, Line)) {
    map<char, int> Letters;

    for (char C : Line) {
      Letters[C]++;
    }

    bool C2 = false;
    bool C3 = false;
    for (auto &&[Key, Value] : Letters) {
      if (C2 && C3)
        break;

      if (Value == 3 && !C3) {
        ++IdCount.first;
        C3 = true;
      } else if (Value == 2 && !C2) {
        ++IdCount.second;
        C2 = true;
      }
    }
  }

  cout << IdCount.first * IdCount.second << '\n';
}

void solveB(stringstream *Buffer) {
  vector<string> Lines;
  string Line;
  while (std::getline(*Buffer, Line)) {
    Lines.push_back(Line);
  }

  int IdLength = Lines[0].length();

  string Answer;
  for (auto IA = Lines.begin(); IA < Lines.end(); ++IA) {
    string A = *IA;
    for (auto IB = IA + 1; IB < Lines.end(); ++IB) {
      string B = *IB;

      int Diffs = 0;
      for (int I = 0; I < IdLength && Diffs < 2; ++I) {
        if (A[I] != B[I]) {
          ++Diffs;
        }
      }

      if (Diffs == 1) {
        // building here is faster than while diffing
	for (int I = 0; I < IdLength; ++I) {
	  if (A[I] == B[I]) {
            Answer += A[I];
	  }
        }
        goto done;
      }
    }
  }
done:
  cout << Answer << '\n';
}

int main(int Argc, char *Argv[]) {
  int Answer = 0;

  if (Argc != 2)
    fail("Usage: Day1 INPUT_PATH");

  string FilePath = Argv[1];
  ifstream InputFile(FilePath);

  stringstream Buffer;
  Buffer << InputFile.rdbuf();

  solveA(&Buffer);
  // solveB(&Buffer);

  return 0;
}
