                                                         Misburg, den 13.08.93

README zu Mag!X V2.00 f�r (Mega) ST(E) und TT
=============================================

Diese Datei enth�lt wichtige Hinweise zur Installation und und zum Betrieb
von Mag!X. Ferner werden ggf. �nderungen zum Handbuch hier untergebracht.
Ihnen sollten folgende Handb�cher vorliegen:

     1. Mag!X
     2. Mag!X 2.00

Das erste Handbuch wird seit V1.0 ausgeliefert, seit V2.0 gibt es ein
Zusatzhandbuch, das die neuen Features von Mag!X beschreibt. Diese Datei
enth�lt daher nur Informationen, die nicht mehr im Mag!X 2.00- Erg�nzungs-
Handbuch untergebracht werden konnten.
Au�erdem sind hier alle Zusatzprogramme und -dateien aufgef�hrt, auf die im
Handbuch nicht n�her eingegangen wird.
Um den Betriebssystem- Zusatz Mag!X zu benutzen, gen�gt das Starten des
Programms INSTMAGX und die Vorgehensweise nach Handbuch.
Sollte das System sich von Ihrer Platte nicht starten lassen, so klemmen Sie
Ihre Platte ab und versuchen es von Diskette. Funktioniert Mag!X jetzt, liegt
das Problem an Ihrem Plattentreiber. Setzen Sie sich mit dem Hersteller Ihrer
Platte bzw. der zugeh�rigen Software in Verbindung oder verwenden Sie einen
alternativen Plattentreiber.
Achtung:  Bestimmte (�ltere) Versionen des Plattentreibers von der Scheiben-
          kleister- Diskette ("CBHD") haben die Eigenschaft, unter Mag!X
          einen Virus zu melden. Dies resultiert in einer fehlerhaften
          Abfrage und kann zun�chst getrost ignoriert werden. Sie sollten
          sich aber eine neue Version besorgen, bei der der Fehler behoben
          ist.
Achtung:  Wenn Sie zusammen mit Mag!X ein GDOS verwenden m�chten, m�ssen Sie
          folgendes beachten:

          Der Mag!X-Booter MAGXBOOT.PRG mu� im AUTO-Ordner unbedingt vor
          NVDI und auch vor einem anderen GDOS liegen. Wenn Sie kein AUTO-
          Ordner-Sortierprogramm haben, kopieren Sie den ganzen AUTO-Ordner
          etwa in einen neuen AUTO-Ordner AUTO2, l�schen den AUTO-Ordner und
          kopieren jetzt MAGXBOOT.PRG als erstes Programm in den neuen AUTO-
          Ordner zur�ck, danach die anderen Dateien.

          Wenn Sie nicht FSMGDOS oder NVDI in einer Version 2.02 oder gr��er
          verwenden, sollten Sie alle Fonts f�r Bildschirmtreiber resident
          laden, um Konflikte mit dem Multitasking zu vermeiden.

          Wenn Sie die virtuelle Speicherverwaltung OUTSIDE verwenden,
          k�nnen Sie statt MAGXBOOT auch MAGXBO32 verwenden. Dieses alterna-
          tive Bootprogramm erm�glicht, da� OUTSIDE den Speicherbereich von
          Mag!X schreibsch�tzen kann.


� Dateien auf dieser Diskette:

     \INSTMAGX.PRG            Installationsprogramm
     \INSTMAGX.RSC            zugeh�rige Ressourcen
     \README.TXT              ?
     \MAGX\                   Das Multitaskingsystem
     \MAGX\ICNEDIT            Diese Dateien ben�tigen Sie, um in MAGXDESK
                              bestimmten Programmen oder Dateien bestimmte
                              Icons zuzuweisen, neue Icons zu erstellen oder
                              bestehende zu �ndern. Diese Dateien werden
                              NICHT von INSTMAGX automatisch auf Ihre
                              Festplatte kopiert.
                              N�heres in den Kapiteln B10 und B11 des
                              Handbuchs
     \MAGX\ZUSATZ             Diese Dateien werden NICHT von INSTMAGX
                              automatisch auf Ihre Festplatte kopiert, da sie
                              nicht in jedem Fall ben�tigt werden.
     ZUSATZ\GMNIMAGX          Ein Programm von Oliver Scheel, das es erm�g-
                              licht, unter Mag!X und Gemini Programme
                              parallel zu starten
     ZUSATZ\CPX               Ein Programm von Stefan Radermacher, das die
                              Funktion von MAGXCONF.ACC als CPX zusammen mit
                              dem XCONTROL.ACC von Atari bietet.
     ZUSATZ\AES_LUPE          Ein Programm von Laurenz Pr��ner, das
                              eigentlich als Accessory gedacht ist, aber
                              hervorragend die Multitasking-Eigenschaften
                              von Mag!X demonstriert.
                              Die Lupe ist weder Public Domain noch
                              Shareware, sondern lizensiert!!!
     ZUSATZ\CLOCK             Shareware- Uhrenprogramm von Stefan Hintz.
                              Ein bestechendes Programm, das eigentlich als
                              Accessory gedacht ist, aber unter Mag!X
                              problemlos im Hintergrund l�uft.
                              Besonders dann, wenn es als nicht oberstes
                              Fenster verschoben wird, zeigt es schonungs- und
                              erbarmungslos den Unterschied zwischen TOS und
                              Mag!X.
                              Sollte einfach in den GEM-AUTO-Ordner kopiert
                              werden.
     ZUSATZ\MAGX.INF          Beispieldatei mit genauer Erkl�rung aller
                              Einstellm�glichkeiten, die z.T. im Handbuch
                              nicht erw�hnt und nur f�r Spezialisten geeignet
                              sind.
     ZUSATZ\ROMDRVR.PRG       Ein Treiberprogramm f�r ROM-Module. Legen Sie
                              dieses Programm in den AUTO- Ordner, wird ein
                              neues Laufwerk R: eingerichtet, das die Dateien
                              des Moduls enth�lt. Sie k�nnen Ihr Modul dann
                              von MAGXDESK oder KCMD oder jedem anderen
                              Programm aus nutzen, das Laufwerke mit Namen R:
                              nicht verbietet.
     ZUSATZ\MAGXDEMO.PRG      Demoprogramm f�r die erweiterten Dialogboxen in
                              Mag!X
     ZUSATZ\DEMO5.PRG         Demoprogramm f�r die Multitaskingf�higkeiten
                              von Mag!X. L�uft auch unter anderen eventuellen
                              Multitaskingsystemen und unter TOS (nat�rlich
                              allein) sowie auch als Accessory. Zeigt seine
                              besonderen F�higkeiten erst, wenn unter einem
                              nicht-Mag!X mehrfach gestartet.
     ZUSATZ\MAGX.H            Headerdatei f�r das Programmieren in 'C' zur
                              Verwendung von MAGXLIB.LIB
     ZUSATZ\MAGXLIB.LIB       Bibliothek f�r Turbo/Pure C mit allen neuen
                              Systemaufrufen von Mag!X
     \KCMD\                   ist ein Shareware- Kommandoprozessor, der als
                              Batchprozessor f�r MAGXDESK verwendet werden
                              kann (im Dialog Optionen/Programme unter
                              "Command" eintragen).
                              Wenn Sie TOS-Programme per VT52.PRG im Fenster
                              laufen lassen m�chten, m�ssen Sie MCMD.TOS
                              verwenden, andernfalls gibt es Schwierigkeiten
                              mit dem Ein- und Abschalten des Mauszeigers.
                              Die Anleitung CMD.DOC liegt im WORDPLUS- Format
                              vor, da davon ausgegangen wird, da� jeder die
                              M�glichkeit hat, solche Dateien selbst auszu-
                              drucken oder ausdrucken zu lassen.  Mit Hilfe
                              des Programms \KCMD\BIN\WORDTOAS.TTP kann man
                              die Dateien auch in reines ASCII- Format umwan-
                              deln (als Parameter den vollst�ndigen Pfad der
                              .DOC-Datei angeben). Hierbei gehen jedoch wich-
                              tige Hervorhebungen wie  Fett- oder Kursiv-
                              schrift verloren.

� Das Verzeichnis \MAGX\ enth�lt das Programm VT52, mit Hilfe dessen TOS-
  Programme in Fenstern ausgef�hrt werden. Au�erdem gew�hrleistet VT52, da�
  diese Programme nicht beim Warten auf Tastatureingaben die restlichen
  Programme lahmlegen.
  Wer VT52 nicht verwenden m�chte, mu� in MAGX.INF die Zeile l�schen oder
  auskommentieren, die mit #_TRM beginnt. Notfalls gen�gt es auch, das
  Programm VT52.PRG, das vom Installationsprogramm nach \UTILITY Ihrer
  Bootpartition kopiert wird, zu l�schen oder umzubenennen (das kostet einen
  kurzen Plattenzugriff bei jedem gestarteten TOS-Programm, da jedesmal
  vorher versucht wird, VT52 zu starten).
� Nur f�r Programmierer:
  Seit geraumer Zeit (AES Version 4.0, also auch im MultiTOS 1.0) existiert
  die AES- Funktion appl_getinfo(), die seit MultiTOS 1.07 (AES V4.01) in
  neuen Unterfunktionen (ab Funktionsnummer 4) auch Informationen �ber
  vorhandene Funktionsaufrufe und Eigenschaften sowohl von Mag!X als auch
  von MultiTOS liefert.
  Mit Hilfe dieser in Mag!X 2.00 und MultiTOS vorhandenen Funktion lassen
  sich gezielt Eigenschaften beider Systeme auch zur Laufzeit erfragen.
  Gewisserma�en ist dies die Absegnung der neuen Mag!X- Funktionen seitens
  Atari. Ferner werden wir uns bem�hen, zuk�nftige Erweiterungen beiderseitig
  abzustimmen, um Unvertr�glichkeiten zwischen Mag!X und MultiTOS zu
  verhindern.

  Man �bergibt eine Unterfunktionsnummer und erh�lt 4 R�ckgabewerte.
  Es gibt folgende Unterfunktionen; sie sind auch unter Mag!X vorhanden:

  Funktion 0: Informationen �ber den normalen AES- Zeichensatz
  -> Wort 1    Fonth�he
     Wort 2    Font-ID
     Wort 3    Font-Typ (0=system,1=FSM)
  Funktion 1: dito f�r den kleinen Zeichensatz
  Funktion 2: Farben
  -> Wort 1    VDI-Ger�tenummer (device id)
     Wort 2    Farben f�r OBJECTs
     Wort 3    Farbicons vorhanden (1) bzw. nicht (0)
     Wort 4    neues RSC-Format vorhanden (1) oder nicht (0)
  Funktion 3: Sprache
  -> Wort 1    z.B. Englisch (0) oder Deutsch (1)
  Funktion 4: allgemeine Information Nr. 1
  -> Wort 1    Multitasking pr�emptiv (1) oder nicht (0)
     Wort 2    appl_find konvertiert MiNT und AES-IDs (1) oder nicht (0)
     Wort 3    appl_search vorhanden (1) oder nicht (0)
     Wort 4    rsrc_rcfix vorhanden (1) oder nicht (0)
  Funktion 5: allgemeine Information Nr. 2
  -> Wort 1    objc_xfind vorhanden (1) oder nicht (0)
     Wort 2    reserviert, immer 0
     Wort 3    menu_click (GEM/3 + Mag!X) vorhanden (1) oder nicht (0)
     Wort 4    shel_r/wdef (GEM/3 + Mag!X) vorhanden (1) oder nicht (0)
  Funktion 6: allgemeine Information Nr. 3
  -> Wort 1    appl_read(-1) vorhanden (1) oder nicht (0)
     Wort 2    shel_get(-1) vorhanden (1) oder nicht (0)
     Wort 3    menu_bar(-1) vorhanden (1) oder nicht (0)
     Wort 4    menu_bar(MENU_INSTL) (Mag!X) vorhanden (1) oder nicht (0)
  Funktion 7: reserviert f�r Mag!X und andere Erweiterungen, MultiTOS setzt
              alle R�ckgabewerte immer auf 0
  Funktion 8: Maus
  -> Wort 1    graf_mouse- Modi 258-260 vorhanden (1) oder nicht (0)
     Wort 2    Mausform vom AES f�r jede App. verwaltet (1) oder nicht (0)
  Funktion 9: Men�s
  -> Wort 1    MultiTOS-Submen�s vorhanden (1) oder nicht (0)
     Wort 2    MultiTOS-Popups vorhanden (1) oder nicht (0)
     Wort 3    MultiTOS-Scrollmen�s vorhanden (1) oder nicht (0)
     Wort 4    erweiterte MN_SELECTED- Nachricht vorhanden (1) oder nicht (0)
  Funktion 10: shel_write
  -> Wort 1    vorhandene Modi
               Bit 0..7:  h�chster zul�ssiger Wert f�r sh_wdoex & 0x00ff
               Bit 8..15: Bits von sh_wdoex & 0xff00, die wie in MultiTOS
                          behandelt werden
     Wort 2    1: shel_write(0) macht vorherige shel_write- Aufrufe ung�ltig
                  (d.h. das Desktop wird Nachfolgeprogramm) (TOS 1.4 &
                   Mag!X)
               0: startet Programm (MultiTOS)
     Wort 3    1: shel_write(1) startet Programm nach Beendigung des
                  laufenden (TOS 1.4 & Mag!X)
               0: startet Programm sofort (MultiTOS)
     Wort 4    ARGV via sh_wiscr unterst�tzt (1) oder nicht (0)
  Funktion 11: Fenster
  -> Wort 1    gesetzte Bits signalisieren unterst�tzte Funktionen:
               Bit 0: WF_TOP liefert zweitoberstes Fenster
                   1: wind_get(WF_NEWDESK)
                   2: wind_g/set(WF_COLOR)
                   3: wind_g/set(WF_DCOLOR)
                   4: wind_get(WF_OWNER)
                   5: wind_g/set(WF_BEVENT)
                   6: WF_BOTTOM
                   7: WF_ICONIFY
                   8: WF_UNICONIFY
                   9..15: reserviert, immer 0
     Wort 2    reserviert, 0
     Wort 3    vorhandene Fensterbuttons:
               Bit 0: Iconifier
                   1: Backdrop-Button (Mag!X)
                   2: Shift-Click f�r Backdrop
                   3: "Hot" Closebox (GEM/3 & Mag!X)
                   4..15: reserviert, 0
     Wort 4    wind_update check_and_set vorhanden (1) oder nicht (0)
  Funktion 12: Nachrichten
  -> Wort 1    gesetzte Bits signalisieren unterst�tzte Nachrichten:
               Bit 0: WM_NEWTOP
                   1: WM_UNTOPPED
                   2: WM_ONTOP
                   3: AP_TERM
                   4: MultiTOS- Aufl�sungswechsel
                   5: CH_EXIT
                   6: WM_BOTTOM
                   7: WM_ICONIFY
                   8: WM_UNICONIFY
                   9: WM_ALLICONIFY
     Wort 2    reserviert, alle 0
     Wort 3    WM_ICONIFY liefert Koordinaten (1) oder nicht (0)
  Funktion 13: OBJECTs
  -> Wort 1    3D- Objekte �ber ob_flags vorhanden (1) oder nicht (0)
     Wort 2    objc_sysvar vorhanden (1) oder nicht (0)
     Wort 3    Speedo- und GDOS- Fonts im TEDINFO erlaubt (1) oder nicht (0)
     Wort 4    reserviert f�r Mag!X, wird von MultiTOS auf 0 gesetzt
               Bit 0: G_SWBUTTON vorhanden
                   1: G_POPUP vorhanden
                   2: WHITEBAK steuert Unterstriche und Buttons
  Funktion 14: Formulare (Mag!X form_xdo und form_xdial)
  -> Wort 1    Mag!X- Flydials vorhanden (1) oder nicht (0)
     Wort 2    Mag!X- Tastaturtabellen vorhanden (1) oder nicht (0)
     Wort 3    letzte Cursorposition wird zur�ckgegeben (1) oder nicht (0)
     Wort 4    reserviert, 0
