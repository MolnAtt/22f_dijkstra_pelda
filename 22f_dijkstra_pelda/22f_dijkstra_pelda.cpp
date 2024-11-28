
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Csucs
{
public:

	int sorszam;
	int tavolsag;

	Csucs(int sorszam, int tavolsag)
	{
		this->sorszam = sorszam;
		this->tavolsag = tavolsag;
	}

	bool operator<(const Csucs& that) {
		return this->tavolsag < that.tavolsag;
	}

	~Csucs()
	{
	}

private:

};


vector<vector<int>> beolvas() {
	int N;
	cin >> N;

	vector<vector<int>> result(N, vector<int>(N, 0));

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> result[i][j];
		}
	}
	return result;
}

void beolvasas_ellenorzese(vector<vector<int>> m) {
	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m.size(); j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

vector<int> szomszedai(vector<vector<int>> m, int ennek) {
	vector<int> result;
	for (size_t i = 0; i < m.size(); i++)
	{
		if (-1 < m[ennek][i] && i != ennek) // itt feltettük, hogy nincsenek hurkok, és -1 jelöli azt, hogy nem szomszéd!
		{
			result.push_back(i);
		}
	}
	return result;
}

vector<vector<int>> dijkstra(vector<vector<int>> m, int start) {
	vector<int> tav(m.size(), INT_MAX);
	tav[start] = 0;
	vector<int> honnan(m.size(), -1);

	priority_queue<Csucs> tennivalok;
	tennivalok.push(Csucs(start, tav[start]));

	while (!tennivalok.empty())
	{
		Csucs tennivalo = tennivalok.top();
		tennivalok.pop();

		for (int& szomszed : szomszedai(m, tennivalo))
		{
			//...
		}

	}


	return { tav, honnan };
}

int main()
{
	//vector<vector<int>> m = beolvas();
	//beolvasas_ellenorzese(m);
	Csucs cs1 = Csucs(0, 5);
	Csucs cs2 = Csucs(2, 3);

	cout << (cs2 < cs1);

}



/*

5
0 6 -1 1 -1
6 0 5 2 2
-1 5 0 -1 5
1 2 -1 0 1
-1 2 5 1 0

*/