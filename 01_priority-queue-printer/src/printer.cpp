// ADS Praktikum 1.1 Printer
// Name: Malek Bouaziz
#include <iostream>
#include <queue>
#include "job.hpp"
#include "printer.h"
int Job::count = 0;
/**
 * @brief Konstruktor der Printer-Klasse.
 * 
 * Initialisiert die maximale Größe der Warteschlange.
 *
 * @param size Maximale Anzahl an Jobs in der Warteschlange.
 */

Printer::Printer(int size)
{
    queueSize = size;
}

/**
 * @brief Fügt einen neuen Job zur Warteschlange hinzu.
 *
 * @param job Der Job, der in die Warteschlange eingefügt werden soll.
 * @return true, wenn der Job erfolgreich hinzugefügt wurde;
 *         false, wenn die Warteschlange voll ist.
 */

bool Printer::addNewJob(const Job& job)
    {
        if (jobs.size() == queueSize)
            return false;
        std::cout << "Added job in the queue: " << job;
        jobs.push(job);
        return true;
    }



/**
 * @brief Startet den Druckprozess und verarbeitet alle Jobs in der Warteschlange.
 *
 * Druckt alle hinzugefügten Jobs, bis die Warteschlange leer ist.
 */

void Printer::startPrinting()
{
    while (not jobs.empty())
    {
        std::cout << "Processing job: " << jobs.top();
        jobs.pop();
    }
}



