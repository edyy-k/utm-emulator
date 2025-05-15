# Universal Turing Machine Emulator

This program parses a binary-encoded [Universal Turing machine](https://en.wikipedia.org/wiki/Universal_Turing_machine) (UTM) and emulates it with an input word.

More in-depth details can be found here: https://universal-turing-machine.ch/

# Quick start

**Assumption:** Compiled to `/main`

`test-tms.txt` contains an UTM for each line.\
`square-tm.txt` contains an UTM that can square a number (`n^2`).

Normal mode (only shows results):\
`./main < test-tms.txt`

Step mode (shows with each calculation step):\
`./main --step-mode < test-tms.txt`

# Why?

This was an assignment from university (Zürcher Hochschule für Angewandte Wissenschaften).
