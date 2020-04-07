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

int zlicz_owoce(const Koszyk& koszyk) {
	return std::count_if(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
	);
}

int zlicz_warzywa(const Koszyk& koszyk) {
	return std::count_if(koszyk.begin(), koszyk.end(),
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

	std::cout << "Warzyw jest: " << zlicz_warzywa(koszyk) << std::endl;
	std::cout << "Owocow jest: " << zlicz_owoce(koszyk) << std::endl;
	
	return 0;
};