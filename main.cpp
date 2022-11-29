#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Clanarina {
    protected:
        string tip;
    public:
        Clanarina() {}
        Clanarina(string tip) {
            this->tip = tip;
        }
        void setTip(string tip) {
            this->tip = tip;
        }
        string getTip() {
            return tip;
        }
        ~Clanarina() {}

};

class KnjizevniZanr {
    protected:
        string zanr;
    public:
        KnjizevniZanr(string zanr) {
            this->zanr = zanr;
        }
        KnjizevniZanr(){}
        void setZanr(string zanr) {
            this->zanr = zanr;
        }
        string getZanr() {
            return zanr;
        }
        ~KnjizevniZanr() {}
        
};

class Osoba {
    protected:
        string ime;
        string prezime;
        string JMBG;
    protected:
        Osoba() {};
        Osoba(string ime, string prezime, string JMBG) {
            this->ime = ime;
            this->prezime = prezime;
            this->JMBG = JMBG;
        }
    public:
        string getIme() {
            return ime;
        }
        void setIme(string ime) {
            this->ime = ime;
        }
        string getPrezime() {
            return prezime;
        }
        void setPrezime(string prezime) {
            this->prezime = prezime;
        }
        string getJMBG() {
            return JMBG;
        }
        void setJMBG(string JMBG) {
            this->JMBG = JMBG;
        }
    protected:
        ~Osoba() {}

};

class Clan: public Osoba {
    protected:
        Clanarina clanarina;
    public: 
        Clan() {};
        Clan(string ime, string prezime, string JMBG, Clanarina clanarina) : Osoba(ime, prezime, JMBG) {
            this->clanarina = clanarina;
        }
        Clanarina getClanarina() {
            return clanarina;
        }
        void setClanarina(Clanarina clanarina) {
            this->clanarina = clanarina;
        }
        ~Clan() {}
};

class Radnik: public Osoba {
    public: 
        Radnik(string ime, string prezime, string JMBG) : Osoba(ime, prezime, JMBG) {}
};

class Knjiga {
    protected:
        string naziv;
        string imeAutora;
        string prezimeAutora;
        KnjizevniZanr knjizevniZanr;
        Clanarina clanarina;
        string serijskiBroj;
    public:
        Knjiga() {};
        Knjiga(string naziv, string imeAutora, string prezimeAutora, KnjizevniZanr knjizevniZanr, Clanarina clanarina) {
            this->naziv = naziv;
            this->imeAutora = imeAutora;
            this->prezimeAutora = prezimeAutora;
            this->knjizevniZanr = knjizevniZanr;
            this->clanarina = clanarina;

            kreirajSerijskiBroj();
        }
        void setNaziv(string naziv) {
            this->naziv = naziv;
        }
        string getNaziv() {
            return naziv;
        }
        void setImeAutora(string imeAutora) {
            this->imeAutora = imeAutora;
        }
        string getImeAutora() {
            return imeAutora;
        }
        void setPrezimeAutora(string prezimeAutora) {
            this->prezimeAutora = prezimeAutora;
        }
        string getPrezimeAutora() {
            return prezimeAutora;
        }
        void setKnjizevniZanr(KnjizevniZanr knjizevniZanr) {
            this->knjizevniZanr = knjizevniZanr;
            kreirajSerijskiBroj();
        }
        KnjizevniZanr getKnjizevniZanr() {
            return knjizevniZanr;
        }
        void setClanarina(Clanarina clanarina) {
            this->clanarina = clanarina;
        }
        Clanarina getClanarina() {
            return clanarina;
        }
        string getSerijskiBroj() {
            return serijskiBroj;
        }

    protected:
        void kreirajSerijskiBroj() {
            srand(time(0));
            int random = 0 + (rand() % 10000);
            serijskiBroj = "";

            string help = knjizevniZanr.getZanr();
            serijskiBroj = help[0];

            if (random > 1000) {
                serijskiBroj += to_string(random);
            } else if (random > 100) {
                serijskiBroj += "0";
                serijskiBroj += to_string(random);
            } else if (random > 10) {
                serijskiBroj += "00";
                serijskiBroj += to_string(random);
            } else if (random < 10) {
                serijskiBroj += "000";
                serijskiBroj += (to_string(random));
            }
        }

    public:
        ~Knjiga() {}
};

class Polica {
    protected:
        vector<Knjiga> knjige;
        KnjizevniZanr knjizevniZanr;
        int redniBrojPolice;
        string oznakaPolice;
    public:
        Polica(KnjizevniZanr knjizevniZanr, int redniBrojPolice) {
            this->knjizevniZanr = knjizevniZanr;
            this->redniBrojPolice = redniBrojPolice;
            kreirajOznaku();
        }
        string getOznakuPolice() {
            return oznakaPolice;
        }
        void setRedniBrojPolice(int broj) {
            this->redniBrojPolice = broj;
        }
        int getRedniBrojPolice() {
            return redniBrojPolice;
        }
        void setKnjizevniZanr(KnjizevniZanr knjizevniZanr) {
            this->knjizevniZanr = knjizevniZanr;
            kreirajOznaku();
        }
        KnjizevniZanr getKnjizevniZanr() {
            return knjizevniZanr;
        }
        vector<Knjiga> getKnjige() {
            return knjige;
        }
        void dodajKnjiguUPolicu(Knjiga knjiga) {
            knjige.push_back(knjiga);   
        }
        void sveKnjigeUjednojPolici() {
            int count = 1;
            for(Knjiga i : knjige) {
                KnjizevniZanr knjizevniZanr = i.getKnjizevniZanr();
                Clanarina Clanarina = i.getClanarina();
                cout<<count<<". "<<i.getNaziv()<<" "<<i.getImeAutora()<<" "<<i.getPrezimeAutora()<<" "<<knjizevniZanr.getZanr()<<" "<<Clanarina.getTip()<<" "<<i.getSerijskiBroj()<<endl;
                count++;
            } 
        }
        void obrisiKnjiguIzPolice(int index) {
            knjige.erase(knjige.begin() + index);
        }
        bool nadjiKnjigu(string serijskiBroj) {
            for(Knjiga i : knjige) {
                if(i.getSerijskiBroj() == serijskiBroj) {
                    return true;
                }
            } 
            return false;
        }

    protected:
        void kreirajOznaku() {
            this->oznakaPolice = "";
            string help = knjizevniZanr.getZanr();
            this->oznakaPolice = help[0];
            this->oznakaPolice += (to_string(redniBrojPolice));
        }
    public:
        ~Polica() {}
};


class PosudenaKnjiga {
    protected:
        Knjiga knjiga;
        Clan clan;
    public:
        PosudenaKnjiga(Knjiga knjiga, Clan clan) {
            this->knjiga = knjiga;
            this->clan = clan;
        }
        void setKnjiga(Knjiga knjiga) {
            this->knjiga = knjiga;
        }
        Knjiga getKnjiga() {
            return knjiga;
        }
        void setClan(Clan clan) {
            this->clan = clan;
        }
        Clan getClan() {
            return clan;
        }
};





void glavniMeni() {
    cout<<"  ** GLAVNI MENI **  "<<endl;
    cout<<"1. Upravljaj clanovima"<<endl;
    cout<<"2. Upravljaj radnicima"<<endl;
    cout<<"3. Upravljaj knjgama"<<endl;
    cout<<"4. Upravljaj knjizevnim zanrovima"<<endl;
    cout<<"5. Upravljaj policama za knjige"<<endl;
    cout<<"6. Upravljaj clanarinama"<<endl;
    cout<<"7. Upravljaj posudenim knigama"<<endl;
    cout<<"8. Izlaz"<<endl;
}

bool provjeriImePrezime(string &podatak) {
    bool valid = true;
    for (int i = 0; i < podatak.length(); i++) {

        if (!isalpha(podatak[i])) {
            valid = false;
        } else {
            if (i == 0) {
                podatak[i] = toupper(podatak[i]);
            } else {
                podatak[i] = tolower(podatak[i]);
            }
        }
    }
    return valid;
}

bool provjeriJMBG(string &podatak) {
    bool valid = true;
    for (int i = 0; i < podatak.length(); i++) {
        if (!isdigit(podatak[i])) {
            valid = false;
        }
    }
    return valid;
}

void clanarinaMeni() {
    cout<<"\n  ** CLANARINA MENI **  "<<endl;
    cout<<"1. Dodaj clanarinu"<<endl;
    cout<<"2. Uredi clanarinu"<<endl;
    cout<<"3. Obrisi clanarinu"<<endl;
    cout<<"4. Ispisi sve tipve clanarina"<<endl;
    cout<<"5. Izlaz"<<endl;
}

void dodajClanarinu(vector<Clanarina> &clanarine) {
    string tip;

    cout<<"\n-Unesite tip clanarine: ";
    cin>>tip;
    if (tip.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(tip)) {
            cout<<"\n*Greska! Prilikom unosa tipa koristiti iskljucivo slova abecede!*\n";
            return;
        } 
    }

    clanarine.push_back(Clanarina(tip));
    cout<<"\n*Novi tip clanarine je uspjesno dodan!*"<<endl;
}

void ispisiTipoveClanarina(vector<Clanarina> clanarine) {
    cout<<"\n*Tipovi clanarina:"<<endl;
    int count = 1; 
    for(Clanarina i : clanarine) {
        cout<<count<<". "<<i.getTip()<<endl;
        count++;
    } 
}

void urediClanarinu(vector<Clanarina> &clanarina) {
    ispisiTipoveClanarina(clanarina);
    int redniBroj;
    cout<<"\n-Unesite redni broj tipa clanarine kojeg zelite uredite: ";
    cin>>redniBroj;
    if (redniBroj > clanarina.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
    } else {
        cout<<"\n*Unesite novi tip clanarine: ";
        string noviTip;
        cin>>noviTip;
        if (noviTip.empty()) {
            cout<<"\n*Polje ne moze biti prazno!\n*";
        } else {
            if(provjeriImePrezime(noviTip)) {
                clanarina[redniBroj - 1].setTip(noviTip);
                cout<<"\n*Tip clanarine je uspjesno ureden!*"<<endl;
            } else {
                cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
            }
        }
    }
}

void obrisiTipClanarine(vector<Clanarina> &clanarine) {
    ispisiTipoveClanarina(clanarine);
    int redniBroj;
    cout<<"\n-Unesite redni broj tipa clanarine kojeg zelite da obrisete: ";
    cin>>redniBroj;
    if (redniBroj > clanarine.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
    } else {
        int index = redniBroj - 1;
        clanarine.erase(clanarine.begin() + index);
        cout<<"\n*Tip clanarine je uspjesno obrisan!*"<<endl;
    }
}

void upravljajClanarinom(vector<Clanarina> &clanarina) {
    while(true) {
        int clanarinaOdabir;
        clanarinaMeni();
        cout<<"\n-Odabir: ";
        cin>>clanarinaOdabir;
        switch (clanarinaOdabir) {
            case 1:
                dodajClanarinu(clanarina);
            break;

            case 2:
                urediClanarinu(clanarina);
            break;

            case 3:
                obrisiTipClanarine(clanarina);
            break;

            case 4:
                ispisiTipoveClanarina(clanarina);
            break;
            
            case 5:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
        }
    };
}


void knjizevniZanroviMeni() {
    cout<<"\n  ** KNJIZEVNI ZANROVI MENI **  "<<endl;
    cout<<"1. Dodaj knjizevni zanr"<<endl;
    cout<<"2. Uredi knjizevni zanr"<<endl;
    cout<<"3. Obrisi knjizevni zanr"<<endl;
    cout<<"4. Ispisi sve tipve knjizevnih zanrova"<<endl;
    cout<<"5. Izlaz"<<endl;
}

void dodajKnjizevniZanr(vector<KnjizevniZanr> &knjizevniZanrovi) {
    string knjizevniZanr;
    cout<<"\n-Unesite knjizevni zanr: ";
    cin>>knjizevniZanr;
    if (knjizevniZanr.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(knjizevniZanr)) {
            cout<<"\n*Greska! Prilikom unosa knjizevnog zanr koristiti iskljucivo slova abecede!*\n";
            return;
        } 
    }

    knjizevniZanrovi.push_back(KnjizevniZanr(knjizevniZanr));
    cout<<"\n*Novi knjizevni zanr je uspjesno dodat!*"<<endl;
}

void ispisiKnjizevneZanrove(vector<KnjizevniZanr> knjizevniZanrovi) {
    cout<<"\n*Tipovi knjizevnih zanrova:"<<endl;
    int count = 1; 
    for(KnjizevniZanr i : knjizevniZanrovi) {
        cout<<count<<". "<<i.getZanr()<<endl;
        count++;
    } 
}

void urediKnjizevniZanr(vector<KnjizevniZanr> &knjizevniZanrovi) {
    ispisiKnjizevneZanrove(knjizevniZanrovi);
    int redniBroj;
    cout<<"\n-Unesite redni broj knjizevnog zanra kojeg zelite uredite: ";
    cin>>redniBroj;
    if (redniBroj > knjizevniZanrovi.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
    } else {
        cout<<"\n*Unesite novi knjizevni zanr: ";
        string noviZanr;
        cin>>noviZanr;
        if (noviZanr.empty()) {
            cout<<"\n*Polje ne moze biti prazno!\n*";
        } else {
            if(provjeriImePrezime(noviZanr)) {
                knjizevniZanrovi[redniBroj - 1].setZanr(noviZanr);
                cout<<"\n*Knjizevni zanrovi je uspjesno ureden!*"<<endl;
            } else {
                cout<<"\n*Greska! Prilikom unosa knjizevnog zanra koristiti iskljucivo slova abecede!*\n";
            }
        }
    }
}

void obrisiKnjizevniZanr(vector<KnjizevniZanr> &knjizevniZanrovi) {
    ispisiKnjizevneZanrove(knjizevniZanrovi);
    int redniBroj;
    cout<<"\n-Unesite redni broj knjizevnog zanra kojeg zelite da obrisete: ";
    cin>>redniBroj;
    if (redniBroj > knjizevniZanrovi.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
    } else {
        int index = redniBroj - 1;
        knjizevniZanrovi.erase(knjizevniZanrovi.begin() + index);
        cout<<"\n*Knjizevni zanr je uspjesno obrisan!*"<<endl;
    }
}

void upravljajKnjizevnimZanrovima(vector<KnjizevniZanr> &knjizevniZanrovi) {
    while(true) {
        int clanarinaOdabir;
        knjizevniZanroviMeni();
        cout<<"\n-Odabir: ";
        cin>>clanarinaOdabir;
        switch (clanarinaOdabir) {
            case 1:
                dodajKnjizevniZanr(knjizevniZanrovi);
            break;

            case 2:
                urediKnjizevniZanr(knjizevniZanrovi);
            break;

            case 3:
                obrisiKnjizevniZanr(knjizevniZanrovi);
            break;

            case 4:
                ispisiKnjizevneZanrove(knjizevniZanrovi);
            break;
            
            case 5:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
        }
    };
}

void clanMeni() {
    cout<<"\n  ** CLAN MENI **  "<<endl;
    cout<<"1. Dodaj clana"<<endl;
    cout<<"2. Uredi clana"<<endl;
    cout<<"3. Obrisi clana"<<endl;
    cout<<"4. Ispisi sve clanove"<<endl;
    cout<<"5. Izlaz"<<endl;
}

void dodajClana(vector<Clan> &clanovi ,vector<Clanarina> &clanarine) {
    string ime;
    string prezime;
    string JMBG;

    cout<<"\n-Unesite ime clana: ";
    cin>>ime;
    if (ime.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(ime)) {
            cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
            return;
        } 
    }


    cout<<"-Unesite prezime clana: ";
    cin>>prezime;
    if (prezime.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(prezime)) {
            cout<<"\n*Greska! Prilikom unosa prezimena koristiti iskljucivo slova abecede!*\n";
            return;
        } 
    }

    cout<<"-Unesite JMBG clana(13 cifara): ";
    cin>>JMBG;
    if (JMBG.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if (JMBG.length() != 13) {
            cout<<"\n*JMBG mora se sastojati od tacno 13 cifara!*\n";
            return;
        } else {
            if(!provjeriJMBG(JMBG)) {
                cout<<"\n*Greska! Prilikom unosa JMBG-a koristiti iskljucivo cijele brojeve!*\n";
                return;
            } 
        }
    }

    ispisiTipoveClanarina(clanarine);
    int redniBroj;
    cout<<"\n-Unesite redni broj tipa clanarine za clana: ";
    cin>>redniBroj;
    if (redniBroj > clanarine.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }

    int index = redniBroj - 1;
    Clanarina clanarina = clanarine[index];


    clanovi.push_back(Clan(ime, prezime, JMBG, clanarina));
    cout<<"\n*Clan je uspjesno dodat!*"<<endl;
}

void ispisiClanove(vector<Clan> clanovi) {
    cout<<"\n*Clanovi:"<<endl;
    int count = 1; 
    for(Clan i : clanovi) {
        Clanarina clanarina = i.getClanarina();
        cout<<count<<". "<<i.getIme()<<" "<<i.getPrezime()<<" "<<i.getJMBG()<<" "<<clanarina.getTip()<<endl;
        count++;
    } 
}

void urediClana(vector<Clan> &clanovi, vector<Clanarina> &clanarine) {
    ispisiClanove(clanovi);
    int redniBroj;
    cout<<"\n-Unesite redni broj clana kojeg zelite uredite: ";
    cin>>redniBroj;
    if (redniBroj > clanovi.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
    } else {
        while (true) {
            int urediClanaOdabir;
            cout<<"\n  ** UREDI CLANA **  "<<endl;
            cout<<"1. Uredi ime"<<endl;
            cout<<"2. Uredi prezime"<<endl;
            cout<<"3. Uredi JMBG"<<endl;
            cout<<"4. Uredi tip clanarine"<<endl;
            cout<<"5. Izlaz"<<endl;
            cout<<"\n-Odabir: ";
            cin>>urediClanaOdabir;
            switch (urediClanaOdabir) {
                case 1: {
                        cout<<"\n*Unesite novo ime: ";
                        string novoIme;
                        cin>>novoIme;
                        if (novoIme.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {
                            if(provjeriImePrezime(novoIme)) {
                                clanovi[redniBroj - 1].setIme(novoIme);
                                cout<<"\n*Clan je uspjesno ureden!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
                            }
                        }
                    break;
                }
                case 2: {
                        cout<<"\n*Unesite novo prezime: ";
                        string novoPrezime;
                        cin>>novoPrezime;
                        if (novoPrezime.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {                        
                            if(provjeriImePrezime(novoPrezime)) {
                                clanovi[redniBroj - 1].setPrezime(novoPrezime);
                                cout<<"\n*Clan je uspjesno ureden!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa prezimena koristiti iskljucivo slova abecede!*\n";
                            }
                        }
                    break;
                }
                case 3: {
                        cout<<"\n*Unesite novi JMBG: ";
                        string noviJMBG;
                        cin>>noviJMBG;
                        if (noviJMBG.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {
                            if (noviJMBG.length() != 13) {
                                cout<<"\n*JMBG mora se sastojati od tacno 13 cifara!\n*";
                            } else {
                                if(provjeriJMBG(noviJMBG)) {
                                    clanovi[redniBroj - 1].setJMBG(noviJMBG);
                                    cout<<"\n*Clan je uspjesno ureden!*"<<endl;
                                } else {
                                    cout<<"\n*Greska! Prilikom unosa JMBG-a koristiti iskljucivo cijele brojeve!*\n";
                                }
                            }
                        }
                    break;
                }

                case 4: {
                        ispisiTipoveClanarina(clanarine);
                        int redniBrojClanarine;
                        cout<<"\n-Unesite redni broj tipa clanarine za clana: ";
                        cin>>redniBrojClanarine;
                        if (redniBrojClanarine > clanarine.size() || redniBrojClanarine < 1) {
                            cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
                            return;
                        } else {
                            int index = redniBrojClanarine - 1;
                            clanovi[redniBroj - 1].setClanarina(clanarine[index]);
                        }
                    break;
                }

                case 5: {
                        cout<<"\nIzlal...\n"<<endl;
                        return;
                    break;
                }

                default: {
                        cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
                    break;
                }

            }
        } 
    }
}

void obrisiClana(vector<Clan> &clanovi) {
    ispisiClanove(clanovi);
    int redniBroj;
    cout<<"\n-Unesite redni broj clana kojeg zelite da obrisete: ";
    cin>>redniBroj;
    if (redniBroj > clanovi.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
    } else {
        int index = redniBroj - 1;
        clanovi.erase(clanovi.begin() + index);
        cout<<"\n*Clan je uspjesno obrisan!*"<<endl;
    }
}

void upravljajClanovima(vector<Clan> &clanovi, vector<Clanarina> clanarine) {
    while(true) {
        int clanOdabir;
        clanMeni();
        cout<<"\n-Odabir: ";
        cin>>clanOdabir;
        switch (clanOdabir) {
            case 1:
                dodajClana(clanovi, clanarine);
            break;

            case 2:
                urediClana(clanovi, clanarine);
            break;

            case 3:
                obrisiClana(clanovi);
            break;

            case 4:
                ispisiClanove(clanovi);
            break;
            
            case 5:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
        }
    };
}

void radnikMeni() {
    cout<<"\n  ** RADNIK MENI **  "<<endl;
    cout<<"1. Dodaj radnika"<<endl;
    cout<<"2. Uredi radnika"<<endl;
    cout<<"3. Obrisi radnika"<<endl;
    cout<<"4. Ispisi sve radnike"<<endl;
    cout<<"5. Izlaz"<<endl;
}

void dodajRadnika(vector<Radnik> &radnici) {
    string ime;
    string prezime;
    string JMBG;

    cout<<"\n-Unesite ime radnika: ";
    cin>>ime;
    if (ime.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(ime)) {
            cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
            return;
        }
    }


    cout<<"-Unesite prezime radnika: ";
    cin>>prezime;
    if (prezime.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(prezime)) {
            cout<<"\n*Greska! Prilikom unosa prezimena koristiti iskljucivo slova abecede!*\n";
            return; 
        }
    }

    cout<<"-Unesite JMBG radnika(13 cifara): ";
    cin>>JMBG;
    if (JMBG.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";

        return;
    } else {
        if (JMBG.length() != 13) {
            cout<<"\n*JMBG mora se sastojati od tacno 13 cifara!*\n";
            return;
        } else {
            if(!provjeriJMBG(JMBG)) {
                cout<<"\n*Greska! Prilikom unosa JMBG-a koristiti iskljucivo cijele brojeve!*\n";
                return;
            }
        }
    }

    radnici.push_back(Radnik(ime, prezime, JMBG));
    cout<<"\n*Radnik je uspjesno dodat!*"<<endl;
    
}


void ispisiRadnike(vector<Radnik> radnici) {
    cout<<"\n*Radnici:"<<endl;
    int count = 1; 
    for(Radnik i : radnici) {
        cout<<count<<". "<<i.getIme()<<" "<<i.getPrezime()<<" "<<i.getJMBG()<<endl;
        count++;
    } 
}



void urediRadnika(vector<Radnik> &radnici) {
    ispisiRadnike(radnici);
    int redniBroj;
    cout<<"\n-Unesite redni broj radnika kojeg zelite uredite: ";
    cin>>redniBroj;
    if (redniBroj > radnici.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
    } else {
            cout<<"\n  ** UREDI RADNIKA **  "<<endl;
            cout<<"1. Uredi ime"<<endl;
            cout<<"2. Uredi prezime"<<endl;
            cout<<"3. Uredi JMBG"<<endl;
            cout<<"4. Izlaz"<<endl;
            cout<<"\n-Odabir: ";
            int urediRadnikaOdabir;
            cin>>urediRadnikaOdabir;
            switch (urediRadnikaOdabir) {
                case 1: {
                        cout<<"\n*Unesite novo ime: ";
                        string novoIme;
                        cin>>novoIme;
                        if (novoIme.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {
                            if(provjeriImePrezime(novoIme)) {
                                radnici[redniBroj - 1].setIme(novoIme);
                                cout<<"\n*Radnik je uspjesno ureden!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
                            }
                        }
                    break;
                }

                case 2: {
                        cout<<"\n*Unesite novo prezime: ";
                        string novoPrezime;
                        cin>>novoPrezime;
                        if (novoPrezime.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {                        
                            if(provjeriImePrezime(novoPrezime)) {
                                radnici[redniBroj - 1].setPrezime(novoPrezime);
                                cout<<"\n*Radnik je uspjesno ureden!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa prezimena koristiti iskljucivo slova abecede!*\n";
                            }
                        }
                    break;
                }

                case 3: {
                        cout<<"\n*Unesite novi JMBG: ";
                        string noviJMBG;
                        cin>>noviJMBG;
                        if (noviJMBG.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {
                            if(provjeriJMBG(noviJMBG)) {
                                radnici[redniBroj - 1].setJMBG(noviJMBG);
                                cout<<"\n*Radnik je uspjesno ureden!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa JMBG-a koristiti iskljucivo cijele brojeve!*\n";
                            }
                        }
                    break;
                }

                case 4: {
                        cout<<"\nIzlal...\n"<<endl;
                        return;
                    break;
                }

                default: {
                        cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
                    break;
                }
            } 
    }
}


void obrisiRadnika(vector<Radnik> &radnici) {
    ispisiRadnike(radnici);
    int redniBroj;
    cout<<"\n-Unesite redni broj radnika kojeg zelite da obrisete: ";
    cin>>redniBroj;
    if (redniBroj > radnici.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
    } else {
        int index = redniBroj - 1;
        radnici.erase(radnici.begin() + index);
        cout<<"\n*Radnik je uspjesno obrisan!*"<<endl;
    }
}

void upravljajRadnicima(vector<Radnik> &radnici) {
    while(true) {
        int radnikOdabir;
        radnikMeni();
        cout<<"\n-Odabir: ";
        cin>>radnikOdabir;
        switch (radnikOdabir) {
            case 1:
                dodajRadnika(radnici);
            break;

            case 2:
                urediRadnika(radnici);
            break;

            case 3:
                obrisiRadnika(radnici);
            break;

            case 4:
                ispisiRadnike(radnici);
            break;
        
            case 5:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
        }
    };
}

void korigujNaziv(string &podatak) {
    for (int i = 0; i < podatak.length(); i++) {
        if (isalpha(podatak[i])) {
            if (i == 0) {
                podatak[i] = toupper(podatak[i]);
            } else {
                podatak[i] = tolower(podatak[i]);
            }
        }
    }
}



void knjigaMeni() {
    cout<<"\n  ** KNJIGA MENI **  "<<endl;
    cout<<"1. Dodaj knjigu"<<endl;
    cout<<"2. Uredi knjigu"<<endl;
    cout<<"3. Obrisi knjigu"<<endl;
    cout<<"4. Ispisi sve knjige"<<endl;
    cout<<"5. Izlaz"<<endl;
}

void dodajKnjigu(vector<Knjiga> &knjige, vector<KnjizevniZanr> &knjizevniZanrovi, vector<Clanarina> &clanarine) {
    string naziv;
    string imeAutora;
    string prezimeAutora;
    string JMBG;

    cout<<"\n-Unesite naziv knjige: ";
    cin.ignore();
    getline(cin, naziv);
    if (naziv.empty()) {
        cout<<"\n*Polje ne moze biti prazno!*\n";
        return;
    } else {
        korigujNaziv(naziv);
    }


    cout<<"-Unesite ime autra: ";
    cin>>imeAutora;
    if (imeAutora.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(imeAutora)) {
            cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
            return; 
        }
    }

    cout<<"-Unesite prezime autora: ";
    cin>>prezimeAutora;
    if (prezimeAutora.empty()) {
        cout<<"\n*Polje ne moze biti prazno!\n*";
        return;
    } else {
        if(!provjeriImePrezime(prezimeAutora)) {
            cout<<"\n*Greska! Prilikom unosa prezimena koristiti iskljucivo slova abecede!*\n";
            return; 
        }
    }

    ispisiKnjizevneZanrove(knjizevniZanrovi);
    int redniBrojKnjizevnogZanra;
    cout<<"\n-Unesite redni broj knjizevnog zanra za knjigu: ";
    cin>>redniBrojKnjizevnogZanra;
    if (redniBrojKnjizevnogZanra > knjizevniZanrovi.size() || redniBrojKnjizevnogZanra < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }

    int indexKnjizevnogZanra = redniBrojKnjizevnogZanra - 1;
    KnjizevniZanr knjizevniZanr = knjizevniZanrovi[indexKnjizevnogZanra];

    ispisiTipoveClanarina(clanarine);
    int redniBrojClanarine;
    cout<<"\n-Unesite redni broj tipa clanarine za knjigu: ";
    cin>>redniBrojClanarine;
    if (redniBrojClanarine > clanarine.size() || redniBrojClanarine < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }

    int indexClanarine = redniBrojClanarine - 1;
    Clanarina clanarina = clanarine[indexClanarine];

    knjige.push_back(Knjiga(naziv, imeAutora, prezimeAutora, knjizevniZanr, clanarina));
    cout<<"\n*Knjiga je uspjesno dodana!*"<<endl;
    
}


void ispisiKnjige(vector<Knjiga> knjige) {
    cout<<"\n*Knjige:"<<endl;
    int count = 1; 
    for(Knjiga i : knjige) {
        KnjizevniZanr knjizevniZanr = i.getKnjizevniZanr();
        Clanarina clanarina = i.getClanarina();
        cout<<count<<". "<<i.getNaziv()<<" "<<i.getImeAutora()<<" "<<i.getPrezimeAutora()<<" "<<knjizevniZanr.getZanr()<<" "<<clanarina.getTip()<<" "<<i.getSerijskiBroj()<<endl;
        count++;
    } 
}



void urediKnjigu(vector<Knjiga> &knjige, vector<KnjizevniZanr> &knjizevniZanrovi, vector<Clanarina> &clanarine) {
    ispisiKnjige(knjige);
    int redniBroj;
    cout<<"\n-Unesite redni broj clana kojeg zelite uredite: ";
    cin>>redniBroj;
    if (redniBroj > knjige.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
    } else {
        while (true) {
            int urediKnjiguOdabir;
            cout<<"\n  ** UREDI KNJIGU **  "<<endl;
            cout<<"1. Uredi naziv"<<endl;
            cout<<"2. Uredi ime autora"<<endl;
            cout<<"3. Uredi prezime autora"<<endl;
            cout<<"4. Uredi Knjizevni zanr"<<endl;
            cout<<"5. Uredi tip clanarine"<<endl;
            cout<<"6. Izlaz"<<endl;
            cout<<"\n-Odabir: ";
            cin>>urediKnjiguOdabir;
            switch (urediKnjiguOdabir) {
                case 1: {
                        cout<<"\n*Unesite novi naziv: ";
                        string noviNaziv;
                        cin.ignore();
                        getline(cin, noviNaziv);
                        if (noviNaziv.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {
                            korigujNaziv(noviNaziv);
                            knjige[redniBroj - 1].setNaziv(noviNaziv);
                            cout<<"\n*Knjiga je uspjesno uredena!*"<<endl;
                        }
                    break;
                }
                case 2: {
                        cout<<"\n*Unesite novo ime autora: ";
                        string imeAutora;
                        cin>>imeAutora;
                        if (imeAutora.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {                        
                            if(provjeriImePrezime(imeAutora)) {
                                knjige[redniBroj - 1].setImeAutora(imeAutora);
                                cout<<"\n*Knjiga je uspjesno uredena!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
                            }
                        }
                    break;
                }
                case 3: {
                        cout<<"\n*Unesite novo prezime autora: ";
                        string prezimeAutora;
                        cin>>prezimeAutora;
                        if (prezimeAutora.empty()) {
                            cout<<"\n*Polje ne moze biti prazno!\n*";
                        } else {                        
                            if(provjeriImePrezime(prezimeAutora)) {
                                knjige[redniBroj - 1].setPrezimeAutora(prezimeAutora);
                                cout<<"\n*Knjiga je uspjesno uredena!*"<<endl;
                            } else {
                                cout<<"\n*Greska! Prilikom unosa imena koristiti iskljucivo slova abecede!*\n";
                            }
                        }
                    break;
                }
                case 4: {
                        ispisiKnjizevneZanrove(knjizevniZanrovi);
                        int redniBrojKnjizevnogZanra;
                        cout<<"\n-Unesite redni broj knjizevnog zanra za knjigu: ";
                        cin>>redniBrojKnjizevnogZanra;
                        if (redniBrojKnjizevnogZanra > knjizevniZanrovi.size() || redniBrojKnjizevnogZanra < 1) {
                            cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
                            return;
                        } else {
                            int indexKnjizevnogZanra = redniBrojKnjizevnogZanra - 1;
                            knjige[redniBroj - 1].setKnjizevniZanr(knjizevniZanrovi[indexKnjizevnogZanra]);
                        }
                    break;
                }

                case 5: {
                        ispisiTipoveClanarina(clanarine);
                        int redniBrojClanarine;
                        cout<<"\n-Unesite redni broj tipa clanarine za clana: ";
                        cin>>redniBrojClanarine;
                        if (redniBrojClanarine > clanarine.size() || redniBrojClanarine < 1) {
                            cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
                            return;
                        } else {
                            int index = redniBrojClanarine - 1;
                            knjige[redniBroj - 1].setClanarina(clanarine[index]);
                        }
                    break;
                }

                case 6: {
                        cout<<"\nIzlal...\n"<<endl;
                        return;
                    break;
                }

                default: {
                        cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
                    break;
                }

            }
        } 
    }
}


void obrisiKnjigu(vector<Knjiga> &knjige) {
    ispisiKnjige(knjige);
    int redniBroj;
    cout<<"\n-Unesite redni broj knjige kojeg zelite da obrisete: ";
    cin>>redniBroj;
    if (redniBroj > knjige.size() || redniBroj < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
    } else {
        int index = redniBroj - 1;
        knjige.erase(knjige.begin() + index);
        cout<<"\n*Knjiga je uspjesno obrisana!*"<<endl;
    }
}

void upravljajKnjigama(vector<Knjiga> &knjige, vector<KnjizevniZanr> &knjizevniZanrovi, vector<Clanarina> &clanarine) {
    while(true) {
        int knjigaOdabir;
        knjigaMeni();
        cout<<"\n-Odabir: ";
        cin>>knjigaOdabir;
        switch (knjigaOdabir) {
            case 1:
                dodajKnjigu(knjige, knjizevniZanrovi, clanarine);
            break;

            case 2:
                urediKnjigu(knjige, knjizevniZanrovi, clanarine);
            break;

            case 3:
                obrisiKnjigu(knjige);
            break;

            case 4:
                ispisiKnjige(knjige);
            break;
            
            case 5:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
            
        }
    };
}


void posudeneKnjigeMeni() {
    cout<<"\n  ** KNJIGA MENI **  "<<endl;
    cout<<"1. Izdaj knjigu"<<endl;
    cout<<"2. Vrati knjigu"<<endl;
    cout<<"3. Ispisi sve izdate knjige"<<endl;
    cout<<"4. Izlaz"<<endl;
}

void izdajKnjigu(vector<PosudenaKnjiga> &posudeneKnjige, vector<Knjiga> &knjige, vector<Clan> &clanovi) {
    ispisiClanove(clanovi);
    int redniBrojClana;
    cout<<"\n-Unesite redni broj clana kojem zelite da izdate knjigu: ";
    cin>>redniBrojClana;
    if (redniBrojClana > clanovi.size() || redniBrojClana < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
        return;
    }
    int indexClana = redniBrojClana - 1;
    Clan clan = clanovi[indexClana];



    ispisiKnjige(knjige);
    int redniBrojKnjige;
    cout<<"\n-Unesite redni broj knjige koju zelite da izdate odabranom clanu: ";
    cin>>redniBrojKnjige;
    if (redniBrojKnjige > clanovi.size() || redniBrojKnjige < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexKnjige = redniBrojKnjige - 1;
    Knjiga knjiga = knjige[indexKnjige];

    Clanarina clanarinaClana = clan.getClanarina();
    Clanarina clanarinaKnjige = knjiga.getClanarina();

    if (clanarinaClana.getTip() == clanarinaKnjige.getTip()) {
        knjige.erase(knjige.begin() + indexKnjige);
        posudeneKnjige.push_back(PosudenaKnjiga(knjiga, clan));
        cout<<"\n*Knjiga je uspjesno izdata!*\n";
    } else {
        cout<<"\n*Clan nema pravo da uzme tu knjigu!*\n";
    }
    
}

void ispisiPosudeneKnjige(vector<PosudenaKnjiga> posudeneKnjige) {
    cout<<"\n*Izdate knjige:"<<endl;
    int count = 1; 
    for(PosudenaKnjiga i : posudeneKnjige) {
        Knjiga knjiga = i.getKnjiga();
        Clan clan = i.getClan();
        cout<<count<<". "<<clan.getJMBG()<<" -> "<<knjiga.getSerijskiBroj()<<endl;
        count++;
    } 
}

void vratiPosudenuKnjigu(vector<PosudenaKnjiga> &posudeneKnjige, vector<Knjiga> &knjige) {
    ispisiPosudeneKnjige(posudeneKnjige);
    int redniPosudeneKnjige;
    cout<<"\n-Unesite redni broj posudene knjige koju zelite da vratite: ";
    cin>>redniPosudeneKnjige;
    if (redniPosudeneKnjige > posudeneKnjige.size() || redniPosudeneKnjige < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
        return;
    }
    int indexPosudeneKnjige = redniPosudeneKnjige - 1;
    PosudenaKnjiga posudenaKnjiga = posudeneKnjige[indexPosudeneKnjige];
    Knjiga knjiga = posudenaKnjiga.getKnjiga();
    knjige.push_back(knjiga);
    posudeneKnjige.erase(posudeneKnjige.begin() + indexPosudeneKnjige);
    cout<<"\n*Knjiga je uspjesno vracena!*\n";

}


void upravljajPosudenimKnjigama(vector<PosudenaKnjiga> &posudeneKnjige, vector<Knjiga> &knjige, vector<Clan> &clanovi) {
    while(true) {
        int posudeneKnjigekOdabir;
        posudeneKnjigeMeni();
        cout<<"\n-Odabir: ";
        cin>>posudeneKnjigekOdabir;
        switch (posudeneKnjigekOdabir) {
            case 1:
                izdajKnjigu(posudeneKnjige, knjige, clanovi);
            break;

            case 2:
                vratiPosudenuKnjigu(posudeneKnjige, knjige);
            break;

            case 3:
                ispisiPosudeneKnjige(posudeneKnjige);
            break;
            
            case 4:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
            
        }
    };
}


void policaMeni() {
    cout<<"\n  ** POLICA MENI **  "<<endl;
    cout<<"1. Dodaj policu"<<endl;
    cout<<"2. Uredi policu"<<endl;
    cout<<"3. Obrisi policu"<<endl;
    cout<<"4. Ispisi sve police"<<endl;
    cout<<"5. Dodaj knjigu u policu"<<endl;
    cout<<"6. Skloni knjigu iz police"<<endl;
    cout<<"7. Ispisi sve knjige u polici"<<endl;
    cout<<"8. Izlaz"<<endl;
}

void dodajPolicu(vector<Polica> &police, vector<KnjizevniZanr> &knjizevniZanrovi) {
    ispisiKnjizevneZanrove(knjizevniZanrovi);
    int redniBrojKnjizevnogZanra;
    cout<<"\n-Unesite redni broj knjizevnog zanra za knjigu: ";
    cin>>redniBrojKnjizevnogZanra;
    if (redniBrojKnjizevnogZanra > knjizevniZanrovi.size() || redniBrojKnjizevnogZanra < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }

    int indexKnjizevnogZanra = redniBrojKnjizevnogZanra - 1;
    KnjizevniZanr knjizevniZanr = knjizevniZanrovi[indexKnjizevnogZanra];

    int count = 1;

    int prvaPolica = -1;
    int sledecaPolica = -1;

    for (Polica i : police) {
        KnjizevniZanr knjizevniZanrPolice = i.getKnjizevniZanr();
        if (knjizevniZanrPolice.getZanr() == knjizevniZanr.getZanr()) {
            if(count % 2 != 0) {
                prvaPolica = i.getRedniBrojPolice();
            } else {
                sledecaPolica = i.getRedniBrojPolice();
            }
            count++;
        }
    }

    if(sledecaPolica > count - 1) {
        count = sledecaPolica - prvaPolica;
    }
    


    police.push_back(Polica(knjizevniZanr, count));
    cout<<"\n*Polica je uspjesno kreirana!*"<<endl;
    
}


void ispisiPolice(vector<Polica> police) {
    cout<<"\n*Police:"<<endl;
    int count = 1; 
    for(Polica i : police) {
        cout<<count<<". "<<i.getOznakuPolice()<<endl;
        count++;
    } 
}


void urediPolicu(vector<Polica> &police, vector<KnjizevniZanr> &knjizevniZanrovi) {
    ispisiPolice(police);
    int redniBrojPolice;
    cout<<"\n-Unesite redni broj police: ";
    cin>>redniBrojPolice;
    if (redniBrojPolice > police.size() || redniBrojPolice < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexPolice = redniBrojPolice - 1;

    ispisiKnjizevneZanrove(knjizevniZanrovi);
    int redniBrojKnjizevnogZanra;

    cout<<"\n-Unesite redni broj knjizevnog zanra za knjigu: ";
    cin>>redniBrojKnjizevnogZanra;
    if (redniBrojKnjizevnogZanra > knjizevniZanrovi.size() || redniBrojKnjizevnogZanra < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexKnjizevnogZanra = redniBrojKnjizevnogZanra - 1;
    KnjizevniZanr knjizevniZanr = knjizevniZanrovi[indexKnjizevnogZanra];

    int count = 1;
    for (Polica i : police) {
        KnjizevniZanr knjizevniZanrPolice = i.getKnjizevniZanr();
        if (knjizevniZanrPolice.getZanr() == knjizevniZanr.getZanr()) {
            count++;
        }   
    }

    police[indexPolice].setRedniBrojPolice(count);
    police[indexPolice].setKnjizevniZanr(knjizevniZanr);
    cout<<"\n*Polica je uspjesno uredena!*"<<endl;
    
}

void obrisiPolicu(vector<Polica> &police) {
    ispisiPolice(police);
    int redniBrojPolice;
    cout<<"\n-Unesite redni broj police: ";
    cin>>redniBrojPolice;
    if (redniBrojPolice > police.size() || redniBrojPolice < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexPolice = redniBrojPolice - 1;
    police.erase(police.begin() + indexPolice);
    cout<<"\n*Polica je uspjesno izbrisana!*"<<endl;
    
}

void dodajKnjiguUPolicu(vector<Polica> &police, vector<Knjiga> &knjige) {
    ispisiPolice(police);
    int redniBrojPolice;
    cout<<"\n-Unesite redni broj police: ";
    cin>>redniBrojPolice;
    if (redniBrojPolice > police.size() || redniBrojPolice < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
        return;
    }
    int indexPolice = redniBrojPolice - 1;


    ispisiKnjige(knjige);
    int redniBrojKnjige;
    cout<<"\n-Unesite redni broj knjige kojeg zelite da dodate u policu: ";
    cin>>redniBrojKnjige;
    if (redniBrojKnjige > knjige.size() || redniBrojKnjige < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!*\n";
        return;
    }
    int indexKnjige = redniBrojKnjige - 1;
    

    KnjizevniZanr knjizevniZanrPolice = police[indexPolice].getKnjizevniZanr();
    KnjizevniZanr knjizevniZanrKnjige = knjige[indexKnjige].getKnjizevniZanr();

    bool uPolici = false;
    string oznakaPolice = "";

    if(knjizevniZanrPolice.getZanr() == knjizevniZanrKnjige.getZanr()) {
        for(Polica i : police) {
            string serijskiBroj = knjige[indexKnjige].getSerijskiBroj();
            if(i.nadjiKnjigu(serijskiBroj)) {
                uPolici = true;
                oznakaPolice = i.getOznakuPolice();
                break;
            }
        }

        if(!uPolici) {
            police[indexPolice].dodajKnjiguUPolicu(knjige[indexKnjige]);
            cout<<"\n*Knjiga je uspjesno dodana u policu!*"<<endl;
        } else {
            if(!oznakaPolice.empty()) {
                cout<<"\n*Knjiga se nalazi u polici "<<oznakaPolice<<"!*"<<endl;
            } else {
                cout<<"\n*Greska!*"<<endl;
            }
        }


    } else {
        cout<<"\n*Polica i knjiga nisu istog zanra, te se ova njiga ne moze staviti u ovu policu*"<<endl;
    }   
}

void ispisiKnjigeUPolici(vector<Polica> police) {
    ispisiPolice(police);
    int redniBrojPolice;
    cout<<"\n-Unesite redni broj police: ";
    cin>>redniBrojPolice;
    if (redniBrojPolice > police.size() || redniBrojPolice < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexPolice = redniBrojPolice - 1;

    cout<<"\n*Knjige u polici "<<police[indexPolice].getOznakuPolice()<<endl;
    int count = 1; 

    ispisiKnjige(police[indexPolice].getKnjige());

}

void izbaciKnjiguIzPolice(vector<Polica> &police) {
    ispisiPolice(police);
    int redniBrojPolice;
    cout<<"\n-Unesite redni broj police: ";
    cin>>redniBrojPolice;
    if (redniBrojPolice > police.size() || redniBrojPolice < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexPolice = redniBrojPolice - 1;


    ispisiKnjige(police[indexPolice].getKnjige());
    int redniBrojKnjige;
    cout<<"\n-Unesite redni broj knjige: ";
    cin>>redniBrojKnjige;
    if (redniBrojKnjige > police[indexPolice].getKnjige().size() || redniBrojPolice < 1) {
        cout<<"\n*Unijeli ste nevazeci redni broj!\n*";
        return;
    }
    int indexKnjige = redniBrojKnjige - 1;

    police[indexPolice].obrisiKnjiguIzPolice(indexKnjige);
    cout<<"\n*Knjiga je izbacena iz police!\n*";

}

void upravljajPolicama(vector<Polica> &police, vector<Knjiga> &knjige, vector<KnjizevniZanr> &knjizevniZanrovi) {
    while(true) {
        int policeOdabir;
        policaMeni();
        cout<<"\n-Odabir: ";
        cin>>policeOdabir;
        switch (policeOdabir) {
            case 1:
                dodajPolicu(police, knjizevniZanrovi);
            break;

            case 2:
                urediPolicu(police, knjizevniZanrovi);
            break;

            case 3:
                obrisiPolicu(police);
            break;
            
            case 4:
                ispisiPolice(police);
            break;

            case 5:
                dodajKnjiguUPolicu(police, knjige);
            break;

            case 6:
                izbaciKnjiguIzPolice(police);
            break;

            case 7:
                ispisiKnjigeUPolici(police);
            break;

            case 8:
                cout<<"\nIzlal...\n"<<endl;
                return;
            break;

            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*"<<endl;
            break;
            
        }
    };
}

int main() {

    vector<Clan> clanovi;
    vector<Radnik> radnici;
    vector<Knjiga> knjige;
    vector<KnjizevniZanr> knjizevniZanrovi {KnjizevniZanr("Dramski romani"), KnjizevniZanr("Enciklopedistika"), 
                                            KnjizevniZanr("Fantastika"), KnjizevniZanr("Humoristicni romani"), 
                                            KnjizevniZanr("Kriminalisticki romani"), KnjizevniZanr("Putopis"),
                                            KnjizevniZanr("Znanstvena fantastika")};
    vector<Clanarina> clanarine {Clanarina("Basic"), Clanarina("Exclusive")};
    vector<PosudenaKnjiga> posudeneKnjige;
    vector<Polica> police;

    while(true) {
        int odabir;
        glavniMeni();
        cout<<"\n-Odabir: ";
        cin>>odabir;

        switch (odabir){
            case 1:
                upravljajClanovima(clanovi, clanarine);
            break;

            case 2:
                upravljajRadnicima(radnici);
            break;

            case 3:
                upravljajKnjigama(knjige, knjizevniZanrovi, clanarine);
            break;

            case 4:
                upravljajKnjizevnimZanrovima(knjizevniZanrovi);
            break;

            case 5:
                upravljajPolicama(police, knjige, knjizevniZanrovi);
            break;

            case 6:
                upravljajClanarinom(clanarine);
            break;

            case 7:
                upravljajPosudenimKnjigama(posudeneKnjige, knjige, clanovi); 
            break;

            case 8:
                cout<<"\nIzlal..."<<endl;
                return 0;
            break;
            
            default:
                cout<<"\n*Unjeli ste nevazecu opciju!*\n"<<endl;
            break;
        }
    };
    
    return 0;
}