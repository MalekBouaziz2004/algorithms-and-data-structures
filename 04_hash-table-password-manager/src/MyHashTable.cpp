#include "MyHashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cmath>


/**
 * @brief Berechnet den Hash-Wert eines gegebenen Schl�ssels (String) mithilfe der DJB2-Hashfunktion.
 *
 * @param key Der Schl�ssel, der gehasht werden soll.
 * @return Der berechnete Hash-Wert modulo der Tabellengr��e.
 */
unsigned int MyHashTable::hash(const std::string& key) const {
    // DJB2 Variante
    unsigned int h = 5381;
    for (char c : key) {
        h = ((h << 5) + h) + c; // h * 33 + c
    }
    return h % table.size();
}

/**
 * @brief Vergr��ert die Hash-Tabelle und f�hrt ein Rehashing aller existierenden Eintr�ge durch.
 *
 * Diese Methode wird aufgerufen, wenn maxLoadFactor �berschritten wird.
 */
void MyHashTable::rehash() {

   int newSize = getNextPrime(2 * table.size());
    std::vector<Entry> oldTable = table;// copie de la table actuelle pour garder les anciens éléments à réinsérer
    table.clear();
    table.resize(newSize);
    numElements = 0;

    for (size_t i = 0; i < oldTable.size(); ++i) {
    if (oldTable[i].occupied) {
        insert(oldTable[i].acc);
    }
}
}

        


/**
 * @brief F�gt einen neuen Account in die Hash-Tabelle ein.
 *
 * Je nach gew�hlter Kollisionsbehandlungsstrategie (linear, quadratisch oder doppeltes Hashing)
 * wird ein freier Platz gesucht. Falls maxLoadFactor �berschritten ist, wird vor dem Einf�gen rehashed.
 *
 * @param acc Der einzuf�gende Account.
 */
void MyHashTable::insert(const Account& acc) {
   double loadFactor = double(numElements) / table.size();
    if (loadFactor >= maxLoadFactor) {
        rehash();
    }

    unsigned int hashVal = hash(acc.website);
    int index = hashVal;
    int i = 0;

    while (table[index].occupied) {
        if (hashMethod == 1) { // Lineares Sondieren
            index = (hashVal + i) % table.size();
        } else if (hashMethod == 2) { // Quadratisches Sondieren
            index = (hashVal + i * i) % table.size();
        } else if (hashMethod == 3) { // Doppeltes Hashing
            int R = getLastPrime(table.size());
            int step = R - (hashVal % R);
            index = (hashVal + i * step) % table.size();
        }
        i++;
    }

    table[index].acc = acc;
    table[index].occupied = true;
    numElements++;
}


/**
 * @brief �berpr�ft Login-Daten (Website, Benutzername und Passwort-Hash).
 *
 * Durchsucht die Hash-Tabelle nach einem passenden Eintrag und vergleicht den Passwort-Hash.
 *
 * @param website Die Website des Accounts.
 * @param username Der Benutzername.
 * @param passwordHash Der gehashte Wert des Passworts.
 * @return true, wenn die Login-Daten g�ltig sind, sonst false.
 */
bool MyHashTable::login(const std::string& website, const std::string& username, const std::string& passwordHash) const {
    
     unsigned int hashVal = hash(website);
    int index = hashVal;
    int i = 0;

    while (table[index].occupied) {
        const Account& acc = table[index].acc;
        if (acc.website == website && acc.username == username && acc.passwordHash == passwordHash) {
            return true;
        }

        if (hashMethod == 1) {
            index = (hashVal + i) % table.size();
        } else if (hashMethod == 2) {
            index = (hashVal + i * i) % table.size();
        } else if (hashMethod == 3) {
            int R = getLastPrime(table.size());
            int step = R - (hashVal % R);
            index = (hashVal + i * step) % table.size();
        }
        i++;
    }

    return false;
}

/**
 * @brief Gibt alle gespeicherten Eintr�ge (Website + Benutzername) auf der Konsole aus.
 */
void MyHashTable::listEntries() const {
    
    for (int i = 0; i < table.size(); ++i) {
    if (table[i].occupied) {
        std::cout << table[i].acc.website << " | Benutzer: " << table[i].acc.username << std::endl;
    }
}
}


/**
 * @brief Bestimmt die n�chstgr��ere Primzahl nach einer gegebenen Zahl.
 *
 * @param x Startwert f�r die Suche.
 * @return Die n�chstgr��ere Primzahl.
 */
int MyHashTable::getNextPrime(int x)
{
    x = x + 1;
    bool found = true;
    while (true)
    {
        found = true;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return x;
        }
        x += 1;
    }
}

/**
 * @brief Bestimmt die n�chstkleinere Primzahl vor einer gegebenen Zahl.
 *
 * @param x Startwert f�r die Suche.
 * @return Die n�chstkleinere Primzahl.
 */
int MyHashTable::getLastPrime(int x) const
{
    x = x - 1;
    bool found = true;
    while (true)
    {
        found = true;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return x;
        }
        x -= 1;
    }
}

