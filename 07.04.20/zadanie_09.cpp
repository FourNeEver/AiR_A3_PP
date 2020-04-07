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

auto IsGruszka = [](Roslina roslina) { return roslina.nazwa == "Gruszka"; };

bool czy_jest_gruszka(const Koszyk& koszyk)
{
	if (std::find_if(koszyk.begin(), koszyk.end(), IsGruszka) != koszyk.end()) return true;
	return false;
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
	if (czy_jest_gruszka(koszyk)) std::cout << "Jest gruszka";
	else std::cout<<"Nie ma gruszki";
	return 0;
};