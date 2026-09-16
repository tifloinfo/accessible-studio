# Audiofunktionen: Fragen und Antworten

Ergänzung zum [Benutzerhandbuch](README.de-DE.html). Für diese Funktionen ist kein API-Schlüssel nötig.

## Welches Werkzeug passt zu meiner Aufgabe?

Die **Lautstärkekonsole** steuert Pegel, Monitoring und Programmausgabe. **Audible Meter** warnt und liest Messwerte vor. **Sound Doctor** misst in einer eigenen Sitzung und schlägt Filter vor. Audible Meter und Sound Doctor können nicht gleichzeitig laufen.

Alle arbeiten lokal mit begrenzten Statistikdaten im Arbeitsspeicher. Sie nehmen keinen Ton auf, übertragen kein Audio und speichern keine Messverläufe oder Berichte. Einstellungen und Pre-Fader-Ausnahmen bleiben erhalten.

## Was bedeuten die Zahlen?

Der dB-Wert der Konsole ist die Verstärkung des Reglers: 0 dB lässt den Pegel unverändert, negative Werte senken ihn. Das ist keine Lautheitsmessung.

Spitzenwerte beschreiben kurze Signalspitzen. RMS beschreibt die Signalenergie und dient zur Bestimmung typischer Pegel und ihrer Schwankung. Messwerte in dBFS werden höher, je näher sie an 0 liegen. Pre-Fader bedeutet vor dem OBS-Regler, Post-Fader danach. Ein niedriger Reglerstand repariert keine bereits entstandene Verzerrung.

## Warum sagt JAWS den alten Wert?

Die Pfeiltastenbehandlung von JAWS kann den bisherigen Zahlenwert ausgeben, bevor das Plugin den richtigen neuen Wert mit „dB“ meldet. Im berichteten Test beseitigte Einfügen+3 vor der Pfeiltaste die veraltete Ansage. Die Lautstärkeänderung selbst ist korrekt. Das Problem wird Vispero gemeldet; die ausdrückliche Rückmeldung bleibt für JAWS und NVDA erhalten.

## Wann erklingen die Töne?

Automatische Ausgangswarnungen beruhen auf angesammelter Zeit oberhalb der Warnschwelle. Standard sind 1,5 Sekunden und die rote OBS-Grenze: −9 dBFS bei Sample Peak oder −2 dBFS bei True Peak. Unterschreitungen unter einer Sekunde setzen die Belastung nicht vollständig zurück; eine Sekunde darunter bereitet die nächste Warnung vor.

Bei aktivem Audible Meter reagiert die Konsole sofort: Gelb erzeugt den mittleren, Rot den hohen Ton. Die Grenzen Gelb/Rot sind bei Sample Peak −20/−9 dBFS, bei True Peak −13/−2 dBFS. Grün, Stille, fehlende Quellen oder Fokus außerhalb der Quellensteuerung bleiben stumm.

Der tiefe Ton begleitet eine bestätigte Eingangskorrektur, solange das Live-Signal vor dem Regler rot bleibt. Medienquelle und VLC-Videoquelle lösen keine Pre-Fader-Warnungen aus.

## Kann ich Warnungen abschalten und weiter messen?

Ja. I schaltet bei aktivem Audible Meter automatische Eingangs- und Ausgangswarnungen um. Erneutes Einschalten beginnt eine neue Belastungsmessung. Konsolentöne und H/J/K/L bleiben verfügbar. In Texteingaben werden die Buchstaben nicht abgefangen.

H nennt den aktuellen Ausgangspegel und die Zone der gewählten Quelle, J die momentan lauteste Quelle. K nennt den typischen aktiven RMS-Pegel der gewählten Quelle, L die Quelle mit dem höchsten solchen Sitzungswert. Gewählt ist die zuletzt in der Konsole fokussierte Quelle.

## Wie arbeitet die angeforderte Absenkung?

Drücken Sie Umschalt+I während einer Ausgangswarnung. Für jede verantwortliche Quelle ist das Ziel die Warnschwelle abzüglich Sicherheitsabstand. Die Berechnung nutzt den höchsten beobachteten Spitzenwert des Vorfalls, rundet die Absenkung auf 0,5 dB auf und begrenzt sie auf das eingestellte Maximum. Sie hebt nie an und reagiert nicht allein auf eine Pre-Fader-Warnung.

Standard sind 3 dB Abstand und höchstens 12 dB Absenkung. Das schützt Spitzen, ersetzt aber keinen ausgewogenen Mix.

Strg+Umschalt+I stellt nur Regler wieder her, die noch dem korrigierten Wert entsprechen. Starten oder Stoppen des Meters, Wechsel der Szenensammlung und Speichern von Meter-Einstellungen löschen diesen einstufigen Wiederherstellungsspeicher.

## Warum hat die Eingangskorrektur Vorrang?

Verzerrung vor dem OBS-Regler muss an der ursprünglichen Quelle behoben werden. Der erste Dialog ist stumm. Ja startet die Begleitung, Nein oder Escape speichert eine Ausnahme für die unveränderte Quelle. Ein anhaltend gesunder aktiver Pegel beendet den Vorfall. Geänderte Identität oder Einstellungen führen zu einer neuen Prüfung.

Stille ist kein Erfolg. Nach 2 und 12 Sekunden folgen Hinweise auf fehlendes Signal, nach 22 Sekunden eine Rückfrage. Fortsetzen wartet ohne Wiederholung dieser Folge auf Signal. Erst nach Bestätigung der Erfolgsmeldung laufen andere Warnungen weiter.

In der offenen Konsole pausiert die Ausgangswarnzeit. Eingangsprobleme werden vorgemerkt. Aktives gesundes Audio entfernt einen veralteten Eintrag; Stille nicht. Beim Schließen werden relevante Eingangsprobleme zuerst behandelt.

## Welche Meter-Einstellungen gibt es?

Unter **Audiowerkzeuge > Erweiterte Audioeinstellungen > Audible Meter**:

- Ausgangswarnschwelle: −30 bis 0 dBFS; Standard folgt dem OBS-Spitzenmodus.
- Belastungsdauer: 0,1–30 Sekunden; Standard 1,5 Sekunden.
- Sicherheitsabstand: 0–12 dB; Standard 3 dB.
- Maximale Absenkung: 0,5–30 dB; Standard 12 dB.
- Pre-Fader-Ausnahmeliste: Ausnahmen entfernen, damit Eingänge erneut geprüft werden.

Konsolenzonen, H/J/K/L und die rote Eingangsgrenze bleiben unverändert. Es gibt einen fensterlosen Modus. Anwenden speichert, OK speichert und schließt, Abbrechen verwirft Änderungen seit dem letzten Anwenden.

## Wie lange misst Sound Doctor?

Mindestens 120 Sekunden. Pro Quelle sind 45 Sekunden aktives Audio für Filtervorschläge erforderlich. Beide Zeiten sind fest. Während Stream oder Aufnahme können Messungen weiterlaufen; Ergebnisse erscheinen erst, wenn beides beendet ist. Verwenden Sie typische Inhalte. Das Tool erkennt keine Sprache und unterscheidet Musik nicht zuverlässig.

## Wann wird Kompression empfohlen?

Eine wahrscheinliche Live-Eingangsquelle muss lange genug aktiv und unverändert sein. Es darf weder einen Kompressor noch einen Limiter geben, auch keinen deaktivierten. Die Dynamikspanne muss mindestens den eingestellten Wert erreichen, standardmäßig 8 dB.

Die Spanne ist die Differenz zwischen dem Median des aktiven RMS-Pegels und dessen 95. Perzentil. RMS wird um die OBS-Reglerverstärkung korrigiert. Der neue Kompressor folgt vorhandener Verarbeitung und steht vor einem ebenfalls neu gewählten Limiter.

Die Schwelle beträgt Median plus 5 dB, gerundet und auf −24 bis −10 dB begrenzt. Attack: 6 ms; Release: 100 ms; Ausgangsverstärkung: 0 dB. Ratio: 2:1 bei unter 10 dB Spanne, 2,5:1 zwischen 10 und unter 14 dB, danach das konfigurierte Maximum. Wählen Sie Kompression für Musik nur bewusst.

## Wann wird ein Limiter empfohlen?

Standardmäßig für ausreichend aktive, unveränderte wahrscheinliche Live-Eingänge ohne Limiter. Bereits aufgetretenes Clipping ist nicht erforderlich. Ein neuer Limiter kommt ans Ende, mit −3 dBFS Standardgrenze und 60 ms Release. Er repariert keine frühere Verzerrung und garantiert nicht, dass die Summe aller Quellen nicht übersteuert.

Die Empfehlung lässt sich auf alle aktiven Quellen ausweiten; fertig bearbeitete Medien benötigen sie nicht unbedingt. Kompressor und Limiter werden unabhängig empfohlen. Der Bericht erläutert außerdem vorhandene Filter, einen nicht letzten Limiter, wiederholte Eingangsspitzen nahe Clipping und unzureichende oder veraltete Messungen.

## Welche Sound-Doctor-Einstellungen gibt es?

- Minimale Dynamikspanne: 6–15 dB; Standard 8 dB.
- Maximales Kompressorverhältnis: 2,5:1, 3:1 oder 3,5:1; Standard 3:1. Kleinere Verhältnisse bleiben möglich.
- Limiter-Auswahl: wahrscheinliche Live-Eingänge oder alle aktiven Quellen.
- Limiter-Grenze: −12 bis −1 dBFS; Standard −3 dBFS.

## Werden Änderungen ohne Zustimmung vorgenommen?

Nein. Kein Vorschlag ist anfangs markiert. Fertig übernimmt nur ausgewählte Änderungen nach erneuter Prüfung von Quelle, Regler und Filtern. Veränderte Quellen werden übersprungen. Escape schließt ohne Änderungen. Neue Sound-Doctor-Filter unterstützen Rückgängig und Wiederholen.

Strg+Umschalt+D kann die Messung nach Bestätigung verwerfen. Nein oder Escape setzt sie fort. Die Bestätigung lässt sich über die entsprechende Merkoption abschalten.
