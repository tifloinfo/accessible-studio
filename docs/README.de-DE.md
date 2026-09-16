# Accessible Studio: Benutzerhandbuch

Accessible Studio ergänzt OBS Studio unter Windows um Tastaturbedienung, Sprachausgaben, Audiowerkzeuge und eine optionale Bildanalyse. Das Plugin richtet sich an blinde Menschen, die mit JAWS oder NVDA arbeiten.

Einzelheiten zu Messwerten und Filtern stehen in den [Fragen zu den Audiofunktionen](Sound-Features-FAQ.de-DE.html).

## Installieren, aktualisieren und entfernen

Vorausgesetzt werden Windows 10 oder 11 und OBS Studio 32.x, jeweils in der 64-Bit-Version. Einen OpenAI-API-Schlüssel benötigen nur die Bild- und Kompatibilitätsanalyse. Audiowerkzeuge und Tastaturfunktionen arbeiten ohne Schlüssel.

1. Installieren Sie OBS von der [offiziellen Downloadseite](https://obsproject.com/download).
2. Schließen Sie OBS und starten Sie das Installationsprogramm Ihrer Accessible-Studio-Version.
3. Folgen Sie den Anweisungen. Fehlende Komponenten von Microsoft WebView2 und Visual C++ werden von Microsoft heruntergeladen. Dafür ist Internetzugang erforderlich.
4. Starten Sie OBS und öffnen Sie **Werkzeuge > Accessible Studio**.

Fehlt OBS, ist es beschädigt oder älter als 32.0, wird die Installation abgebrochen. Bei OBS 33 oder neuer erscheint eine Kompatibilitätswarnung mit Verweis auf die [aktuelle Plugin-Version](https://github.com/tifloinfo/accessible-studio/releases/latest). Eine trotzdem durchgeführte Installation garantiert keine Kompatibilität. Setup fordert zum Schließen von OBS auf, beendet es aber nicht selbst.

Das Plugin liegt unter `C:\ProgramData\obs-studio\plugins\accessible-studio`. OBS- und Qt-Dateien werden nicht ersetzt. Auf der letzten Installationsseite lässt sich das Handbuch öffnen.

**Umstieg von Accessible OBS Studio 1.0:** Das alte Plugin samt eigenen Einstellungen, Tastenkombinationen, Cache und API-Schlüssel wird entfernt. Andere OBS-Einstellungen und Inhalte bleiben erhalten. Aktualisierungen innerhalb von Accessible Studio 1.1.x behalten Einstellungen und Schlüssel bei.

Zum Deinstallieren schließen Sie OBS und entfernen Accessible Studio über die installierten Apps von Windows. Einstellungen und API-Schlüssel bleiben dabei erhalten. Einen nicht mehr benötigten Schlüssel entfernen Sie vorher über die API-Schlüsselverwaltung.

## Befehle und Hilfe finden

Unter **Werkzeuge > Accessible Studio** finden Sie **Audiowerkzeuge** mit Lautstärkekonsole, Audible Meter, Sound Doctor und erweiterten Audioeinstellungen. **Videowerkzeuge** enthält Bildbeschreibungen, Text lesen, Personen und Hintergründe, die visuelle Prüfung und die API-Schlüsselverwaltung.

Dort stehen außerdem der Tastenkombinations-Editor und **Benutzerhandbuch öffnen** bereit. Das Handbuch öffnet sich im Browser in der OBS-Sprache, sofern vorhanden, sonst auf Englisch.

## Standard-Tastenkombinationen

Vorhandene Konflikte oder eigene Zuweisungen können diese Standards ändern.

### Navigation

- F6 / Umschalt+F6: nächster / vorheriger Hauptbereich.
- Strg+0: Videovorschau.
- Strg+1: Szenen.
- Strg+2: Quellen.
- Strg+3: Audiomixer.
- Strg+4: Szenenübergänge.
- Strg+5: Steuerung.
- Strg+M: sichtbare Mediensteuerung.
- Alt+1 bis Alt+9: erste neun Szenen in Listenreihenfolge; Alt+0: zehnte Szene.

Wird ausschließlich NVDA erkannt, wird der Bereichsname zusätzlich angesagt. Der native Audiomixer behält die normale OBS-Bedienung.

### Ausgabe und Audio

- F5: Stream starten oder stoppen.
- F7: Aufnahme starten oder stoppen, auch bei pausierter Aufnahme.
- Alt+F7: Aufnahme pausieren oder fortsetzen, sofern OBS dies unterstützt.
- F8: virtuelle Kamera starten oder stoppen.
- Alt+F2: Status von Stream, Aufnahme, virtueller Kamera und Studiomodus; Enter oder Escape schließt das Fenster.
- Strg+Gravis: Lautstärkekonsole. Gemeint ist die physische Taste direkt unter Escape, unabhängig von ihrer Beschriftung.
- Strg+I: Audible Meter ein- oder ausschalten.
- Strg+Umschalt+D: Sound Doctor starten oder unterbrechen.

Abgeschlossene Statusänderungen sowie Verbindungsabbruch und Wiederverbindung des Streams werden angesagt.

### Bildanalyse

Diese Befehle benötigen API-Schlüssel und Internetzugang. Die Vorschau muss nicht fokussiert sein.

- F3: Kurzbeschreibung mit höchstens 80 Zeichen.
- Umschalt+F3: ausführliche Beschreibung.
- Alt+F3: sichtbaren Text ohne Übersetzung oder Kommentar lesen.
- Strg+F3: sichtbare Personen und ihre unmittelbare Umgebung beschreiben.
- F4: visuelle Prüfung von Bildaufbau und Bildqualität.

## Tastenkombinationen ändern

Öffnen Sie den Tastenkombinations-Editor, suchen Sie einen Befehl und wählen Sie ihn mit den Pfeiltasten. Enter oder **Hinzufügen oder Bearbeiten** öffnet die Zuweisung. Drücken Sie dort die gewünschte Kombination. Weitere Kombinationen lassen sich hinzufügen. Erst OK im Hauptfenster speichert die Änderungen.

Bei Konflikten fragt der Editor nach einer Neuzuweisung. Entf oder Entfernen im Hauptfenster löscht alle Zuweisungen des gewählten Befehls. Beim Schließen ungespeicherter Änderungen können Sie speichern, verwerfen oder zurückkehren. Navigations- und reservierte Systemtasten werden nicht aufgezeichnet.

Ändern sich Profil, Szenensammlung oder betroffene Zuweisungen während der Bearbeitung, kann das Speichern abgelehnt werden. Öffnen Sie den Editor dann erneut.

Standardmäßig funktionieren OBS-Tastenkombinationen nur, wenn OBS aktiv ist. Aktivieren und speichern Sie die Option, OBS die Verwaltung von Tastenkombinationen außerhalb des Programms zu überlassen, um dessen eigene Fokuseinstellung zu verwenden.

Beim Start oder Profilwechsel können Sie vorhandene Konflikte beibehalten oder nur kollidierende Kombinationen durch Plugin-Standards ersetzen. Beibehalten lässt die betroffenen Standards unbelegt. Eine gespeicherte Entscheidung gilt profilübergreifend für diesen Build. Eigene, nicht leere Zuweisungen bleiben bei der Standardmigration erhalten. Der Befehl zum direkten Öffnen des Plugin-Menüs hat keine Standardkombination.

## Lautstärke und Abhören

Strg+Gravis öffnet die barrierefreie Lautstärkekonsole. Änderungen wirken sofort.

- Links / Rechts: vorherige / nächste Quelle.
- Hoch / Runter: fokussierten Regler um 1 dB anheben / absenken.
- Pos1: 0 dB einstellen.
- 1 bis 9, danach 0: Quellen 1 bis 10 direkt wählen.
- Leertaste: Monitoring und Programmausgabe gemeinsam umschalten.
- Strg+Leertaste: nur Monitoring umschalten.
- Umschalt+Leertaste: nur Programmausgabe umschalten.
- Escape: schließen und zum vorherigen OBS-Steuerelement zurückkehren.

Monitoring ist das lokale Abhören. Die Programmausgabe gelangt in Stream oder Aufnahme. Für beides gibt es auch eigene Schaltflächen.

Zunächst erscheinen aktive Programmquellen; reine Vorschauquellen im Studiomodus fehlen. **Alle Quellen anzeigen** wird mit Enter aktiviert, nicht mit Leertaste. Links und Rechts erreichen auch Quellen jenseits der ersten zehn. Liste und Werte werden zweimal pro Sekunde aktualisiert.

Normalerweise endet der Regelbereich bei 0 dB. Bereits anderswo eingestellte positive Verstärkung bleibt erreichbar. Ab OBS 32.2 sind Stummschaltung und Monitoring unabhängig; ältere unterstützte Versionen verwenden die bisherigen Monitoring-Zustände.

Nach Hoch oder Runter wird der neue dB-Wert angesagt, auch am Anschlag. Schnelle Eingaben fassen ausstehende Ansagen zusammen. Ein Fokuswechsel beendet ausstehende Lautstärkeansagen.

**JAWS-Hinweis:** JAWS kann zuerst den alten Zahlenwert ausgeben, danach folgt die richtige Plugin-Ansage mit „dB“. Die Lautstärke wird dennoch korrekt geändert. Im gemeldeten Test unterdrückte Einfügen+3 vor der Pfeiltaste die veraltete Ansage. Das Problem wird an Vispero weitergegeben; die zusätzliche dB-Rückmeldung bleibt für JAWS und NVDA erhalten.

## Audible Meter verwenden

Strg+I schaltet einen einzigen fensterlosen Modus um. Er überwacht aktive Quellen auch ohne laufenden Stream oder Aufnahme. Warnungen sind beim Start eingeschaltet. Das Tool öffnet die Konsole nicht selbst und verändert keine Filter.

Während Audible Meter aktiv ist:

- I: automatische Eingangs- und Ausgangswarnungen umschalten.
- H: aktueller Pegel und Zone der zuletzt in der Konsole gewählten Quelle.
- J: aktuell lauteste Quelle und ihr Pegel.
- K: typischer aktiver Pegel der gewählten Quelle in dieser Sitzung.
- L: Quelle mit dem höchsten typischen aktiven Pegel.
- Umschalt+I: bei einer Ausgangswarnung eine vorsichtige Absenkung anfordern.
- Strg+Umschalt+I: letzte Absenkung zurücknehmen, soweit die Regler inzwischen unverändert sind.

In Texteingabefeldern werden diese Buchstaben nicht abgefangen. Ohne ausgewählte Quelle melden H und K dies ausdrücklich.

### Töne und Warnungen

Der **tiefe Ton** bedeutet nach bestätigter Eingangskorrektur: Das Signal ist vor dem OBS-Regler weiterhin zu hoch. Senken Sie den Pegel am Gerät, in Windows oder im Quellprogramm. Der **mittlere Ton** kennzeichnet Gelb bei der fokussierten Konsolenquelle. Der **hohe Ton** kennzeichnet dort Rot oder eine automatische Ausgangswarnung. Grün, Stille, fehlende Quellen und Fokus außerhalb der Quellensteuerung bleiben stumm.

Konsolentöne reagieren unmittelbar. Automatische Warnungen benötigen eine bestimmte Belastungsdauer. I schaltet nur Warnungen ab, nicht die Messtöne der Konsole.

Eine Eingangswarnung öffnet zunächst einen stummen Dialog. Ja startet die Korrekturhilfe. Nein oder Escape speichert diese unveränderte Quelle in der Pre-Fader-Ausnahmeliste. Stille gilt nicht als erfolgreiche Korrektur; nach Hinweisen auf fehlendes Signal wird nachgefragt. Ein anhaltend gesunder aktiver Pegel beendet die Hilfe. Bestätigen Sie die Erfolgsmeldung, damit andere Warnungen fortgesetzt werden.

In der offenen Konsole pausiert die Zeitmessung für Ausgangswarnungen; Eingangsprobleme werden vorgemerkt. Beim Schließen werden noch aktuelle Probleme gemeldet. Wollen Sie die Konsole während einer Eingangskorrektur öffnen, fragt das Plugin nach; Nein speichert die Ausnahme und öffnet die Konsole.

Unter den erweiterten Audioeinstellungen ändern Sie Warnschwelle, Belastungsdauer, Sicherheitsabstand, maximale Absenkung und Ausnahmeliste. Konsolenzonen und H/J/K/L-Messungen bleiben unverändert. Es gibt keine zusätzlichen Messmodi, Verlaufsfenster oder Berichtsdateien.

## Sound Doctor

Sound Doctor und Audible Meter können nicht gleichzeitig laufen.

1. Strg+Umschalt+D drücken und den Start bestätigen.
2. Mindestens zwei Minuten typische Sprache und andere Klänge verwenden. Jede Quelle benötigt 45 Sekunden aktives Signal für Filtervorschläge.
3. Stream und Aufnahme beenden, bevor Ergebnisse angezeigt werden. Bis dahin kann die Messung weiterlaufen.
4. Vorschläge lesen und gewünschte Änderungen markieren; zunächst ist nichts ausgewählt.
5. Mit **Fertig** übernehmen oder mit Escape ohne Änderungen schließen.

Kompression kann starke Pegelschwankungen eines wahrscheinlichen Live-Eingangs ausgleichen. Ein Limiter kann unerwartete Spitzen begrenzen. Das Tool versteht keine Inhalte und unterscheidet Sprache nicht zuverlässig von Musik. Wählen Sie Musikkompression nur, wenn dieser Effekt erwünscht ist.

Quellen und Filter werden vor dem Übernehmen erneut geprüft. Veränderte Quellen werden übersprungen, vorhandene Verarbeitung wird nicht dupliziert. Neue Kompressoren folgen bestehenden Filtern; ein gleichzeitig hinzugefügter Limiter kommt danach ans Ende. Die neuen Filter tragen Sound-Doctor-Namen und unterstützen Rückgängig und Wiederholen in OBS.

Erneutes Strg+Umschalt+D unterbricht die Messung nach Bestätigung und verwirft sie. Nein oder Escape setzt sie fort. Die Bestätigung lässt sich dauerhaft abschalten. Ein bereits offener Bericht erhält stattdessen den Fokus und bleibt während Stream oder Aufnahme verborgen.

Die Sound-Doctor-Seite der erweiterten Audioeinstellungen steuert Vorschläge. Anwenden speichert; OK speichert und schließt; Abbrechen verwirft Änderungen seit dem letzten Anwenden. Details stehen in den [Audiofragen](Sound-Features-FAQ.de-DE.html).

## Medien durchsuchen

Strg+M fokussiert sichtbare Mediensteuerungen. Dort springen Links/Rechts um 5 Sekunden, Umschalt+Links/Rechts um 1 Minute und Bild auf/Bild ab um 5 Minuten zurück/vor. Außerhalb dieser Steuerung bleiben die Tasten unverändert.

## Bilder beschreiben und prüfen

Speichern Sie einen API-Schlüssel über die Videowerkzeuge. Er wird geprüft und für Ihr Windows-Konto in der Windows-Anmeldeinformationsverwaltung gespeichert, aber nie angezeigt. Eine fehlgeschlagene Ersetzung bewahrt den bisherigen Schlüssel; Löschen erfordert Bestätigung.

Ein Bildbefehl erfasst das gerenderte OBS-Bild. Ein Klick bestätigt den Auftrag. Ergebnisse erscheinen in einem zugänglichen WebView2-Fenster; neue Antworten werden einmal angesagt. Beim Schließen wird der Fokus nach Möglichkeit zurückgegeben. **Neuestes Ergebnis kopieren** kopiert nur die letzte Antwort.

Bildbezogene Rückfragen und angebotene Beschreibungen verwenden dieselbe Bildunterhaltung. Schließen oder eine neue direkte Aufnahme beendet sie. **Erneut prüfen** sendet ein neues Bild zum Vergleich.

Die visuelle Prüfung bewertet Sichtbarkeit, Licht, Ausschnitt, Skalierung, Unschärfe, Störungen und störende Hintergründe. Sie bewertet keine Aussagen, Rechtschreibung oder Meinungen. Text zählt nur als sichtbares Gestaltungselement. Gewöhnliche Zoom-Bedienelemente oder Ränder allein beweisen keinen Fenstermodus.

Vorgeschlagene automatische Korrekturen bieten eine Videoquelle und anschließend passende Transformationen mit Risiken an. Bei nur einer Quelle entfällt die Auswahl. Sie bestätigen jeweils eine Änderung. Strecken auf Bildschirmgröße wird nie angeboten; Audio, Ausgaben, Zugangsdaten und Szenenlöschung sind ausgeschlossen.

Nach dem Einpassen kann eine weitere Bildanalyse die Qualität prüfen. Bei schlechter oder unklarer Qualität stellt die Wiederherstellung die erfassten Transformationen nur dann wieder her und zentriert, wenn Szene und Zustand noch passen. Zwischenzeitliche Änderungen werden nicht durch einen allgemeinen Rückgängig-Befehl überschrieben. Im Studiomodus entfällt diese Onlineprüfung, weil Vorschau und Programm abweichen können.

## Datenschutz und Kompatibilität

Bildanalyse sendet Bild, OBS-Sprache, Anweisungen und Rückfragen an OpenAI. Eine Kompatibilitätsanalyse sendet Versions- und Abhängigkeitsdaten sowie eine Funktionsbeschreibung. Der Schlüssel dient der Anmeldung, nicht als Analyseinhalt. API-Kosten trägt der Schlüsselinhaber.

Bei neueren OBS-Hauptversionen stehen Abbrechen, trotzdem starten oder Kompatibilität analysieren zur Wahl. Die Analyse kombiniert lokale Leseprüfungen mit offiziellen OBS-Informationen über OpenAI. Sie schätzt Risiken, garantiert aber nichts. Erfolgreiche Berichte werden für die genaue OBS-/Plugin-Version und Architektur gespeichert und in die Zwischenablage kopiert.

Audiowerkzeuge arbeiten lokal ohne Tonaufnahmen, Audioübertragung oder Messverlauf. Einstellungen und Eingangsausnahmen bleiben gespeichert. Es gibt keine Werbung oder Telemetrie.

## Probleme lösen

Fehlt das Plugin, prüfen Sie 64-Bit-OBS und schließen Sie OBS vor einer erneuten Installation. Bei fehlenden Tastenkombinationen prüfen Sie Editor, Konflikte und OBS-Fokuseinstellung. Fehlende Mediensteuerungen erfordern eine abspielbare Quelle. Bei WebView2-Problemen reparieren Sie die Microsoft-Komponente oder starten Setup mit Internetzugang erneut.

## Projekt und Lizenz

Accessible Studio ist ein unabhängiges Drittanbieter-Plugin und wird nicht vom OBS Project oder dessen Mitwirkenden entwickelt, gesponsert oder unterstützt. OBS und OBS Studio sind eingetragene Marken von Wizards of OBS LLC.

© 2026 [Tiflo.Info](https://tiflo.info). GNU GPL Version 2 oder neuer; siehe [Lizenz](../LICENSE.txt). Namen und Logos bleiben gesondert geschützte Kennzeichen. [English](README.en-US.html).
