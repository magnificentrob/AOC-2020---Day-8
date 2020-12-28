#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


//1262
int main() {
	ifstream input;
	input.open("input.txt");
	vector<string> instructions;
	vector<int> values;
	vector<int> visited;
	string a;
	int b;
	int acc = 0;
	while (!input.eof()) {
		input >> a;
		input >> b;
		instructions.push_back(a);
		values.push_back(b);
		visited.push_back(0);
	}
	input.close();
	for (int i = 0; i < 654; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
		}
		else {
			cout << acc;
			break;
		}
		if (instructions[i] == "acc") {
			acc += values[i];
			continue;
		}
		if (instructions[i] == "jmp") {
			i += values[i] - 1;
			continue;
		}
		if (instructions[i] == "nop") {
			continue;
		}
	}
}