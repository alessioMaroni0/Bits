# BITS Library

[![C Version](https://img.shields.io/badge/C-C99%20%2F%20C11-blue.svg)](#)
[![Library Type](https://img.shields.io/badge/Type-Header--Only-green.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](#)
[![Author](https://img.shields.io/badge/Author-Ale-orange.svg)](https://github.com/alessioMaroni0)
[![Version](https://img.shields.io/badge/Version-1.3.1-blue.svg)](#)

Una libreria in C sviluppata a scopo didattico e di apprendimento durante lo studio del Capitolo 2 di *Computer Systems: A Programmer's Perspective* (CS:APP).

Il progetto mira a comprendere a basso livello come i tipi di dato vengono rappresentati, memorizzati e manipolati in memoria, fornendo strumenti per il bit-twiddling e il controllo accurato dell'overflow aritmetico.

---

## Caratteristiche della Libreria

* **Header-Only:** La libreria non richiede compilazione separata o collegamenti a file binari dinamici. È composta da soli file header `.h` contenenti definizioni e macro.
* **Zero Overhead:** Sfrutta il preprocessore per garantire la massima efficienza a runtime, eliminando il costo di chiamata delle funzioni.
* **Sicurezza:** Fornisce macro avanzate per verificare preventivamente l'overflow in conformità con le specifiche di architettura dei calcolatori.

---

## Scelte architetturali
Nel progetto si usano solo file header per semplicità.
Vengono definite macros nel modo più semplice ed efficace possibili che poi vengono riutilizzate nella stesssa libreria 

---

## Struttura del Progetto

```text
Bits
├── lib/
│   ├── bits.h            # Header collettore principale
│   ├── limits/
│   │   └── limits.h      # Costanti di limite per interi a precisione fissa
│   ├── math/
│   │   └── math.h        # Controlli di sicurezza per operazioni aritmetiche
│   └── utils/
│       └── utils.h       # Macro di manipolazione bit-by-bit
├── test/
│   └── main.c            # File di test e verifica
├── Dockerfile            # Ambiente di testing isolato su Alpine Linux
└── Makefile              # Automazione del build di test