#include <iostream>
#include <vector>

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
	TypRosliny typ;
	std::string nazwa;
	Roslina() { typ = TypRosliny::Warzywo; nazwa = "warzywo"; }
	Roslina(TypRosliny t, std::string n) { typ = t; nazwa = n; }
};

using Koszyk = std::vector<Roslina>;

Koszyk koszyk = {{TypRosliny::Owoc, "Banan"}};

int main()
{
	Roslina pomidor;
	pomidor.typ = TypRosliny::Owoc;
	pomidor.nazwa = "Pomidor";
	koszyk.push_back(pomidor);
	
	Roslina burak(TypRosliny::Warzywo, "Burak");
	koszyk.emplace_back(burak);
	
	return 0;
};