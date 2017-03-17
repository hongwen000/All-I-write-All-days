
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int dic_total;
	cin >> dic_total;
	string dict[1000];
	for (int n = 0; n < dic_total; n++)
	{
		cin >> dict[n];
	}
	string sentence;
	cin >> sentence;
	int word_find[1000][3];
	for (int i=0; i < 1000; i++)
	{
		for (int j=0; j < 3; j++)
		{
			word_find[i][j] = 0;
		}
	}
	int dic_iter = 0;
	int find_total = 0;
	int longest = dict[0].length();
	for (int n = 0; n < dic_total; n++)
	{
		if (dict[n].length()>longest)
		{
			longest = dict[n].length();
		}
	}
	//deal()
	int n0 = 0;
	while ((n0 < sentence.length()) && !((word_find[find_total + 1][1] == 0) && (word_find[find_total][0] + longest -1 >sentence.length())))
	{
		int n = 0;
		bool success = false;
		for (; n < dic_total; n++)
		{
			//comp()
			bool is_occured = true;
			if(!((n0+dict[n].length()-1) > sentence.length()))
			{
				for (int i = 0; i < (int)dict[n].length(); i++)
				{
					if (!(dict[n].at(i) == sentence.at(n0+i)))
					{
						is_occured = false;
						continue;
					}
				}
			}
			else
			{
				is_occured = false;
				continue;
			}
			//comp()end
			if (is_occured)
			{
				if (word_find[find_total][1] == 0)
				{
					word_find[find_total][1] = dict[n].length();
					word_find[find_total][2] = n;
					 success = true;
					 continue;
				}
				else
				{
					if ((int)dict[n].length()>word_find[find_total][1])
					{
						word_find[find_total][1] = dict[n].length();
						word_find[find_total][2] = n;
						 success = true;
						 continue;
					}
				}
		}
		}
		if (success)
		{
			n0 += dict[word_find[find_total][2]].length();
			find_total++;
			word_find[find_total][0] = n0;
		}
		else
		{
			n0++;
			word_find[find_total][0] = n0;
		}
	}
	int word_iter = 0;
	for (int this_iter = 0; this_iter < sentence.length(); this_iter++)
	{
			if (this_iter < (word_find[word_iter][1]+ word_find[word_iter][0]) && this_iter >= word_find[word_iter][0] && (word_iter != find_total-1))
			{
				cout << dict[word_find[word_iter][2]] << ' ';
				this_iter += word_find[word_iter][1]-1;
				word_iter++;
			}
			else if (this_iter < (word_find[word_iter][1] + word_find[word_iter][0]) && this_iter >= word_find[word_iter][0] && (word_iter == find_total - 1))
			{
				cout << dict[word_find[word_iter][2]]<<endl;
				this_iter += word_find[word_iter][1]-1;
				word_iter++;
			}
			else
			{
				cout << sentence.at(this_iter) << ' ';
			}

	}
	return 0;
}
//happy(*^__^*) 
