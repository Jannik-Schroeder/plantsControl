# README

Dieses Arduino-Programm misst die Feuchtigkeit und Helligkeit und schaltet gegebenenfalls eine Pumpe bzw. ein Licht an.

## Hardware-Anforderungen
- Arduino-Board
- Feuchtigkeitssensor
- Lichtsensor
- Pumpe
- Licht

## Pin-Zuordnung
- Feuchtigkeitssensor: A0
- Lichtsensor: A1
- Pumpe: 2
- Licht: 3

## Verwendung
1. Verbinden Sie den Feuchtigkeitssensor mit dem entsprechenden Pin (A0) am Arduino-Board.
2. Verbinden Sie den Lichtsensor mit dem entsprechenden Pin (A1) am Arduino-Board.
3. Verbinden Sie die Pumpe mit dem entsprechenden Pin (2) am Arduino-Board.
4. Verbinden Sie das Licht mit dem entsprechenden Pin (3) am Arduino-Board.
5. Laden Sie den Code auf das Arduino-Board hoch.

## Anmerkungen
- Der Schwellenwert für die Feuchtigkeit, ab dem die Pumpe eingeschaltet wird, ist derzeit auf 50% festgelegt. Dieser Wert kann nach Bedarf angepasst werden.
- Der Schwellenwert für die Helligkeit, ab dem das Licht eingeschaltet wird, ist derzeit auf 800 festgelegt. Dieser Wert kann nach Bedarf angepasst werden.
- Der Schwellenwert für Trockensten Punkt ist auf 620 und für Feuchtesten Punkt auf 310 festgelegt. Dieser Wert kann nach Bedarf angepasst werden.

## Troubleshooting
- Stellen Sie sicher, dass alle Verbindungen korrekt hergestellt sind und alle benötigten Komponenten vorhanden sind.
- Überprüfen Sie die Schwellenwerte für Feuchtigkeit und Helligkeit und stellen Sie sicher, dass sie den Anforderungen entsprechen.
- Überprüfen Sie die Schwellenwerte für Trockensten Punkt und Feuchtesten Punkt und stellen Sie sicher, dass sie den Anforderungen entsprechen.
- Wenn das Programm nicht wie erwartet funktioniert, überprüfen Sie die serielle Ausgabe, um mögliche Fehler zu erkennen.
