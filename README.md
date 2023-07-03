#  bank - cli app [C++]

a cli application of a bank. 

## requirements

#### De code bevat geen overbodige defines en bevat geen magische constanten.

Hier is overal rekening mee gehouden. 

#### De code gebruikt op ten minste 1 plek op een zinnige wijze van overerving en virtuele functie(s).

Bij het aanmaken van rekeningen is er gebruik gemaakt van overerving. BankAccounts is de Base Class. Hierin wordt er gebruik gemaakt van virtuele functies. Checking en Savings overerft deze en voegt hier eigen functionaliteit aan toe.

#### De code heeft ten minste 1 unit-test waarbij het resultaat in een bestand wordt weggeschreven.

Met behulp van GoogleTest zijn er twee unit-tests beschikbaar de de import/export functies test van de data.

`tests/Tests.cpp`

#### Met behulp van FileIO, bestanden kunnen lezen en schrijven.

Binnen de Import/Export wordt er gebruikt gemaakt van `ifstream/ofstream` om de data JSON veilig te lezen en te schrijven.

`cli/ie/Export.cpp`

#### Toepassen van standaard datastructuren in C++.

Binnen de applicatie wordt er gebruik gemaakt van `std::list<>` voor de Persons en een `std::vector<>` voor Bankaccounts.

`cli/cli.h`
`Person/Person.cpp`

#### Gebruik maken van streams.

Voor de Import/Export wordt ifstream/ofstream gebruikt. Voor het aanmaken van een random rekeningsnummer wordt gebruikt gemaakt van een `std::stringstream` op een random character te appenden.

`BankAccounts/BankAccount.cpp`

#### Rekening gehouden met het voorkomen van memory leaks.

Bij het exiten van de CLI worden alle persons en backaccounts gepurged.

`Person/Person.cpp`

#### Zinnige foutmeldingen mocht er iets fout gaan, afhandeling via exceptions.

Binnen de Import/Export wordt er gebruik gemaakt van `std::cerr` om errors af te handelen.

`cli/ie/Export.cpp`

#### Weloverwogen gebruik van algoritmes binnen de applicatie (zowel zelfgeschreven alsmede de STL-bibliotheek).

Er wordt gebruikt gemaakt van de JSON library samen met de vector en lists uit de STL biblitheek.

## how to run

- first run cmake .. in the build folder
- make to build the project
- using `./bank` start the CLI
- using `./tests` run the tests

