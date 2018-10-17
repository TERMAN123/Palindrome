#include <QtCore/QCoreApplication>
#include <QString>
#include <iostream>

bool isPalindrome(const QString& word)
{
	if (word.size() == 1)
	{
		return true;
	}
	for (int i = 0, j = word.size() - 1; (i < word.size() / 2) && (j > word.size() / 2); i++, j--)
	{
		if (word.at(i) != word.at(j))
		{
			return false;
		}
	}
	return true;
}

QString getLongestPalindrome(const QString& line)
{
	QStringList words = line.split(" ", QString::SkipEmptyParts);

	QString longestPalindrome;

	foreach(QString word, words)
	{
		if (isPalindrome(word))
		{
			if (word.size() > longestPalindrome.size())
			{
				longestPalindrome = word;
			}
		}
	}

	return longestPalindrome.size() > 0 ? longestPalindrome : "No palindrome have been found.";
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QString line = "terret sun sooloos my hamletter sunburn";
	QString longestPalindrome = getLongestPalindrome(line);
	std::cout << longestPalindrome.toStdString();
	return a.exec();
}