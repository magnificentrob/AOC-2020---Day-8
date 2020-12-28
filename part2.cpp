#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//1643
int main() {
	ifstream input;
	input.open("input.txt");
	vector<string> instructions;
	vector<int> values;
	vector<int> visited;
	string a;
	int b;
	while (!input.eof()) {
		input >> a;
		input >> b;
		instructions.push_back(a);
		values.push_back(b);
		visited.push_back(0);
	}
	input.close();


	const int SIZE = instructions.size();
	int acc = 0;
	for (int i = 0; i < SIZE; i++) {
		string temp;
		vector<int> visited(SIZE, 0);
		if (instructions[i] == "acc")
			continue;
		if (instructions[i] == "jmp") {
			temp = "jmp";
			instructions[i] = "nop";
		}
		else if (instructions[i] == "nop") {
			temp = "nop";
			instructions[i] = "jmp";
		}
		for(int j = 0; j < SIZE; j++){
			if (visited[j] == 0) {
				visited[j] = 1;
			}
			else {
				acc = 0;
				break;
			}

			if (instructions[j] == "acc") {
				acc += values[j];
			}
			else if (instructions[j] == "jmp") {
				j += values[j]-1;
				continue;
			}
			else {
				continue;
			}
		}
		if (temp == "nop") {
			instructions[i] = "nop";
		}
		else if (temp == "jmp") {
			instructions[i] = "jmp";
		}
		if (acc != 0)
			cout << acc;
	}
}