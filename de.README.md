# README

## Übersicht
Dieser Code überwacht die Feuchtigkeit im Boden und schaltet eine Pumpe an, wenn die Feuchtigkeit unter einem bestimmten Schwellwert liegt.

## Pin Definitionen
- Feuchtigkeitssensor Pin: A0
- Pumpe Pin: 2

## Konstanten
- Trockenster Punkt: 520 Volt
- Feuchtester Punkt: 260 Volt

## Variablen
- soilMoistureValue: Aktuell gemessene Feuchtigkeit in Volt
- soilmoisturepercent: Aktuell gemessene Feuchtigkeit in Prozent

## Funktionsbeschreibung
`setup()` initialisiert die Serielle Schnittstelle und setzt die Pinmodi für den Feuchtigkeitssensor, Licht und Pumpe.

`loop()` liest die Feuchtigkeit aus dem Sensor aus, berechnet den Wert in Prozent und gibt ihn über die Serielle Schnittstelle aus. Wenn die Feuchtigkeit unter 50% liegt, wird die Pumpe eingeschaltet, sonst ausgeschaltet.
