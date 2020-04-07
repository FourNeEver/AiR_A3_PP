#include <algorithm>
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

Koszyk koszyk = { {TypRosliny::Owoc, "Banan"} };

std::ostream& operator<<(std::ostream& out, const Roslina& roslina)
{
	if (roslina.typ == TypRosliny::Owoc) out << "Owoc: " << roslina.nazwa;
	else out << "Warzywo: " << roslina.nazwa;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Koszyk& koszyk)
{
	for (auto r : koszyk)
	{
		out << r << std::endl;
	}
	return  out;
}


bool czy_same_owoce(const Koszyk& koszyk) {
	return std::all_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
	);
}


bool czy_same_warzywa(const Koszyk& koszyk) {
	return std::all_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
	);
}

bool jeden_owoc(const Koszyk& koszyk) {
	return std::any_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
	);
}

bool jedno_warzywo(const Koszyk& koszyk) {
	return std::any_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
	);
}

bool zaden_owoc(const Koszyk& koszyk) {
	return std::none_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
	);
}

bool zadne_warzywo(const Koszyk& koszyk) {
	return std::none_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
	);
}

int main()
{
	Roslina pomidor;
	pomidor.typ = TypRosliny::Owoc;
	pomidor.nazwa = "Pomidor";
	koszyk.push_back(pomidor);

	Roslina burak(TypRosliny::Warzywo, "Burak");
	koszyk.emplace_back(burak);

	Roslina gruszka(TypRosliny::Owoc, "Gruszka");
	koszyk.emplace_back(gruszka);

	std::cout << koszyk;

	if (czy_same_owoce(koszyk)) std::cout << "W koszyku sa same owoce" << std::endl;
	if (czy_same_warzywa(koszyk)) std::cout << "W koszyku sa same warzywa" << std::endl;
	if (jeden_owoc(koszyk)) std::cout << "W koszyku jest conajmniej jeden owoc" << std::endl;
	if (jedno_warzywo(koszyk)) std::cout << "W koszyku jest conajmniej jedno warzywo" << std::endl;
	if (zaden_owoc(koszyk)) std::cout << "W koszyku nie ma zadnych owocow" << std::endl;
	if (zadne_warzywo(koszyk)) std::cout << "W koszyku nie ma zadnych warzyw" << std::endl;
	
	return 0;
};