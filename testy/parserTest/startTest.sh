clear
echo -e '\E[47;31m'"Kopiuje pliki "; tput sgr0

cp ../../Generator.cpp ./
cp ../../Generator.h ./
cp ../../Dodaj.cpp ./
cp ../../Dodaj.h ./
cp ../../Exceptions.h ./
cp ../../loader.h ./
cp ../../lotto.h ./
cp ../../Para.h ./
cp ../../sample.h ./
cp ../../TableWindow.h ./
cp ../../Trojka.h ./
cp ../../Exceptions.cpp ./
cp ../../loader.cpp ./
cp ../../lotto.cpp ./
cp ../../Para.cpp ./
cp ../../sample.cpp ./
cp ../../TableWindow.cpp ./
cp ../../Trojka.cpp ./
cp ../../lottoMain.ui ./
cp ../../lotto.ui ./
cp ../../dodaj.ui ./

echo -e '\E[47;31m'"Kompiluje testy"; tput sgr0

rm parserTest
qmake
make clean
make

clear
echo -e '\E[47;31m'"Uruchamiam testy"; tput sgr0

./parserTest
