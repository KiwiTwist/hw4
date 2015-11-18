#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


void read_data(vector<double>& f, int& N) {
	string fname = "noisy.txt";
	ifstream input(fname.c_str());

	// get number of lines of txt
    	string line;

    	while(getline(input, line))
        	N++;

	// build array with correct size
	f.resize(N);

	input.clear();
	input.seekg(0, ios::beg);

	for(int i = 0; i < N; i++)
		input >> f[i];

	input.close();
}


void filter(vector<double>& f, int N) {
	double temp1 = f[0];
	double temp2 = f[1];
	double temp3 = temp1;

	f[0] = (f[N-1] + f[0] + f[1])/3.0;

	for(int i = 1; i < N-1; i++) {
		f[i] = (temp1 + f[i] + f[i+1])/3.0;
		temp1 = temp2;
		temp2 = f[i+1];
	}
	
	f[N-1] = (temp1 + f[N-1] + temp3)/3.0;
}


void print_data(vector<double> f, int N) {
	ofstream out("output.dat");

	for(int i = 0; i < N; i++) {
		out << f[i] << endl;
	}

	out.close();
}


int main(){
	int N = 0;
	vector<double> f(0);

	read_data(f, N);
	filter(f, N);
	print_data(f, N);

	return 0;
}
