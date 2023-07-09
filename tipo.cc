#include <cstring>
#include <iostream>

using namespace std;

#include "tipo.h"

/**
 * @brief Restituisce la differenza tra 's1' e 's2'
 *
 * @param s1
 * @param s2
 * @return differenza tra 's1' e 's2'
 */
int compare(tipo_inf s1, tipo_inf s2) {
	if (strcmp(s1.data, s2.data) == 0 && strcmp(s1.ora_i, s2.ora_i) != 0) {
		return strcmp(s1.ora_i, s2.ora_i);
	}

	return strcmp(s1.data, s2.data);
}

/**
 * @brief Copia in 'dest' il valore contenuto in 'source'
 *
 * @param dest destinazione del valore copiato
 * @param source valore da copiare
 */
void copy(tipo_inf &dest, tipo_inf source) {
	dest = source;
}

/**
 * @brief Stampa il valore dell'oggetto
 *
 * @param inf oggetto
 */
void print(tipo_inf inf) {
	cout << inf.data << " " << inf.ora_i << " " << inf.ora_f << " " << inf.descr
			<< endl;
}
