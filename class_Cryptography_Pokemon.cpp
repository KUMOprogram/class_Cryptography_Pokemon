#include <iostream>
#include <string>
#include <stdbool.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Alpha
{
	private:
		string realletter;
		string keyword1;
		string keyword2;
		string keyword3;
	public:
		Alpha(string& xrealletter, string& xkeyword1, string& xkeyword2, string& xkeyword3);
        void setrealletter(string& xrealletter);
		void setkeyword1(string& xkeyword1);
		void setkeyword2(string& xkeyword2);
		void setkeyword3(string& xkeyword3);
		string& getrealletter();
		string& getkeyword1();
		string& getkeyword2();
		string& getkeyword3();
		_Bool find_keyword(string& searcher);
};

Alpha::Alpha(string& xrealletter, string& xkeyword1, string& xkeyword2, string& xkeyword3)
{
	realletter = xrealletter;
	keyword1 = xkeyword1;
	keyword2 = xkeyword2;
	keyword3 = xkeyword3;
}

void Alpha::setrealletter(string& xrealletter)
{
	realletter = xrealletter;
}

void Alpha::setkeyword1(string& xkeyword1)
{
	keyword1 = xkeyword1;
}

void Alpha::setkeyword2(string& xkeyword2)
{
	keyword2 = xkeyword2;
}

void Alpha::setkeyword3(string& xkeyword3)
{
	keyword3 = xkeyword3;
}


string& Alpha::getrealletter()
{
	return realletter;
}

string& Alpha::getkeyword1()
{
	return keyword1;
}

string& Alpha::getkeyword2()
{
	return keyword2;
}

string& Alpha::getkeyword3()
{
	return keyword3;
}

_Bool Alpha::find_keyword(string& searcher)
{
	if (searcher.find(keyword1)!=string::npos)
	{
		return 1;
	}else if (searcher.find(keyword2)!=string::npos)
	{
		return 1;
	}else if (searcher.find(keyword3)!=string::npos)
	{
		return 1;
	}else{
		return 0;
	}
}

void menu();
void fill_alpha(vector <Alpha>& alpha, string realletter, string keyword1, string keyword2, string keyword3);
void print_alpha(vector <Alpha>& alpha);
void cryptme(vector <Alpha>& alpha, string& searcher);
void decryptme(vector <Alpha>& alpha, string& searcher);

int main()
{
system("color f1");
	int choose;
	string searcher, CPPbug;
	vector <Alpha> alpha;
	fill_alpha(alpha,"a","charmander","charmeleon","charizard");
	fill_alpha(alpha,"b","squirtle","wartortle","blastoise");
	fill_alpha(alpha,"c","bulbasaur","ivusaur","venusaur");
	fill_alpha(alpha,"d","caterpie","metapod","butterfree");
	fill_alpha(alpha,"e","weedle","kakuna","beedrill");
	fill_alpha(alpha,"f","pidgey","pidgeotto","pigdeotthuglife");
	fill_alpha(alpha,"g","pichu","pikacho","raichu");
	fill_alpha(alpha,"h","nidoran","nidorina","nidoqueen");
	fill_alpha(alpha,"i","poliwag","poliwirl","politoad");
	fill_alpha(alpha,"j","machop","machoke","machamp");
	fill_alpha(alpha,"k","bellsproot","weepingbell","victreebel");
	fill_alpha(alpha,"l","geodude","graveler","golem");
	fill_alpha(alpha,"m","slowpoke","slowbro","slowking");
	fill_alpha(alpha,"n","onix","steelix","kangaskan");
	fill_alpha(alpha,"o","hitmontop","hitmonlee","hitmonchan");
	fill_alpha(alpha,"p","magby","magmar","lapras");
	fill_alpha(alpha,"q","eevee","floreon","vaporeon");
	fill_alpha(alpha,"r","jolteon","umbreon","espeon");
	fill_alpha(alpha,"s","moltes","zapdos","articuno");
	fill_alpha(alpha,"t","dratini","dragonair","dragonite");
	fill_alpha(alpha,"u","mewone","mewtwo","aerodactyl");
	fill_alpha(alpha,"v","sonrlax","scyther","pinsir");
	fill_alpha(alpha,"w","abra","katambra","alakazam");
	fill_alpha(alpha,"x","oddish","gloom","vileplume");
	fill_alpha(alpha,"y","zubat","goldbat","crobat");
	fill_alpha(alpha,"z","lichitung","chansey","tangela");
	fill_alpha(alpha," ","ash","misty","brock");
	
	while(true)
	{
		menu();
		cin>>choose;
		cout<<endl;

		if (choose==1)
		{
			print_alpha(alpha);
		}

		if (choose==2)
		{
            getline(cin,CPPbug);
			cout<<" Give your sentense: ";
			getline(cin,searcher);

			cryptme(alpha,searcher);
		}

		if (choose==3)
		{
            getline(cin,CPPbug);
			cout<<" Give your sentense: ";
			getline(cin,searcher);
			
			decryptme(alpha,searcher);
		}

		if (choose==0)
		{
			break;
		}

		if ((choose!=0)&&(choose!=1)&&(choose!=2)&&(choose!=3))
		{
			cout<<" ERROR: WRONG CHOICE"<<endl;
		}
		
	system("pause");
	}
system("pause");
}

void menu()
{
	system("cls");
    cout<<endl;
	cout<<" Show Alpha --------------------------------------- 1"<<endl;
    cout<<" Enter text to encrypt ---------------------------- 2"<<endl;
    cout<<" Enter text to decrypt ---------------------------- 3"<<endl;
	cout<<" Close -------------------------------------------- 0"<<endl<<endl;
	cout<<" CHOICE: ";
}

void fill_alpha(vector <Alpha>& alpha, string realletter, string keyword1, string keyword2, string keyword3)
{
    Alpha alphaline(realletter,keyword1,keyword2,keyword3);
	alphaline.setrealletter(realletter);
	alphaline.setkeyword1(keyword1);
	alphaline.setkeyword2(keyword2);
	alphaline.setkeyword3(keyword3);
	alpha.push_back(alphaline);
}

void print_alpha(vector <Alpha>& alpha)
{
	for (int i = 0; i<alpha.size(); ++i)
	{
		cout<<" "<<alpha[i].getrealletter()<<" --> "<<alpha[i].getkeyword1()<<" , "<<alpha[i].getkeyword2()<<" , "<<alpha[i].getkeyword3()<<endl;
	}
	cout<<endl;
}

void cryptme(vector <Alpha>& alpha, string& searcher)
{
	srand(time(0));
	
	int counter = 0;
	string cryptedtext = "";
	for (int j = 0; j < searcher.size(); ++j)
	{
		_Bool flag = 0;
		int r = rand();
		r=(r%3)+1;
		for (int i = 0; i < alpha.size(); ++i)
		{
			if (searcher[j] == alpha[i].getrealletter()[0])
			{
				if (r==1)
				{
					cryptedtext += alpha[i].getkeyword1();
				}
				else if (r==2)
				{
                    cryptedtext += alpha[i].getkeyword2();
				}
				else if (r==3)
				{
                    cryptedtext += alpha[i].getkeyword3();
				}
				flag = 1;
			}
		}
		if (!flag)
		{
			cryptedtext += searcher[j];
		}
	}
	cout<<" Crypted Text: "<<cryptedtext<<endl<<endl;
}

void decryptme(vector <Alpha>& alpha, string& searcher)
{
	int counter = 0;
	int realsize = searcher.size();
	for (int j = 0; j < realsize; ++j)
	{
		for (int i = 0; i < alpha.size(); ++i)
		{
            if (searcher.find(alpha[i].getkeyword1())!=string::npos)
			{
                searcher.replace(searcher.find(alpha[i].getkeyword1()), alpha[i].getkeyword1().size(), alpha[i].getrealletter());
				realsize -= alpha[i].getkeyword1().size();
			}
			else if (searcher.find(alpha[i].getkeyword2())!=string::npos)
			{
                searcher.replace(searcher.find(alpha[i].getkeyword2()), alpha[i].getkeyword2().size(), alpha[i].getrealletter());
				realsize -= alpha[i].getkeyword2().size();
			}
			else if (searcher.find(alpha[i].getkeyword3())!=string::npos)
			{
                searcher.replace(searcher.find(alpha[i].getkeyword3()), alpha[i].getkeyword3().size(), alpha[i].getrealletter());
                realsize -= alpha[i].getkeyword3().size();
   			}
		}
 	}
	cout<<" Crypted Text: "<<searcher<<endl<<endl;
	//p.x. zubathitmonleemistyslowbrocharmeleonsteelix
}
