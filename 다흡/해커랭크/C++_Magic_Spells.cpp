#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell() : scrollName("") { }
    Spell(string name) : scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private: int power;
public:
    Fireball(int power) : power(power) { }
    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: int power;
public:
    Frostbite(int power) : power(power) { }
    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private: int power;
public:
    Thunderstorm(int power) : power(power) { }
    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private: int power;
public:
    Waterbolt(int power) : power(power) { }
    void revealWaterpower() {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell* spell) {

    /* Enter your code here */
    Fireball* spellFire = dynamic_cast<Fireball*>(spell);
    Frostbite* spellFrost = dynamic_cast<Frostbite*>(spell);
    Thunderstorm* spellThunder = dynamic_cast<Thunderstorm*>(spell);
    Waterbolt* spellWater = dynamic_cast<Waterbolt*>(spell);

    if (spellFire != nullptr)
    {
        spellFire->revealFirepower();
    }
    else if (spellFrost != nullptr)
    {
        spellFrost->revealFrostpower();
    }
    else if (spellThunder != nullptr)
    {
        spellThunder->revealThunderpower();
    }
    else if (spellWater != nullptr)
    {
        spellWater->revealWaterpower();
    }
    else // Custom Spell
    {
        // Use LCS(Longest Common Algorithm) 
        // between spell->revealScrollName() and SpellJournal::journal
        string spellStr1 = spell->revealScrollName();
        string spellStr2 = SpellJournal::read();

        int spellStr1_len = spellStr1.length();
        int spellStr2_len = spellStr2.length();

        vector< vector<int>> LCS(spellStr1_len + 1, vector<int>(spellStr2_len + 1, 0));

        for (int idx1 = 1; idx1 <= spellStr1_len; ++idx1)
        {
            for (int idx2 = 1; idx2 <= spellStr2_len; ++idx2)
            {
                if (spellStr1[idx1 - 1] == spellStr2[idx2 - 1])
                    LCS[idx1][idx2] = LCS[idx1 - 1][idx2 - 1] + 1;
                else
                    LCS[idx1][idx2] += LCS[idx1 - 1][idx2] > LCS[idx1][idx2 - 1] ? LCS[idx1 - 1][idx2] : LCS[idx1][idx2 - 1];
            }
        }

        cout << LCS[spellStr1_len][spellStr2_len] << '\n';
    }

}

class Wizard {
public:
    Spell* cast() {
        Spell* spell;
        string s; cin >> s;
        int power; cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        }
        else if (s == "frost") {
            spell = new Frostbite(power);
        }
        else if (s == "water") {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell* spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}