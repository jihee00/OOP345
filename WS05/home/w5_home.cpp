// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored

		std::fstream f(argv[1], std::ios::in);
		if (!f) {
			std::cerr << "ERROR: Cannot open file ["
				<< argv[1] << "].\n";
			return 1;
		}
		std::string line;
		int books = 0;
		while (books < 4) {
			std::getline(f, line);
			if (!line.empty()) {
				if (line.at(0) != '#') {
					Book temp(line);
					library += temp;
					books++;
				}
			}
		}

		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the books from the file.
		while (std::getline(f, line)) {
			if (!line.empty()) {
				if (line.at(0) != '#') {
					library += sdds::Book(line);
					books++;
				}
			}
		}
		f.close();
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto fixPrice = [=](Book& book) {
		if (book.country() == "US") { book.price() *= usdToCadRate;}
		if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) { book.price() *= gbpToCadRate;}};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from in-lab): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (int i = 0; i < 7; i++)
	{
		fixPrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored

		std::fstream fm(argv[2], std::ios::in);
		if (!fm) {
			std::cerr << "ERROR: Cannot open file ["
				<< argv[2] << "].\n";
			return 1;
		}
		std::string line;
		int nmovie = 0;
		while (nmovie < 5) {
			std::getline(fm, line);
			if (!line.empty()) {
				if (line.at(0) != '#') {
					movies[nmovie] = sdds::Movie(line);
					nmovie++;
				}
			}
		}
		fm.close();

		std::cout << "-----------------------------------------\n";
		std::cout << "Testing addition and callback function\n";
		std::cout << "-----------------------------------------\n";
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
		std::cout << "-----------------------------------------\n\n";

		std::cout << "-----------------------------------------\n";
		std::cout << "Testing exceptions and operator[]\n";
		std::cout << "-----------------------------------------\n";

		// TODO: The following loop can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		try {
			for (size_t i = 0; i < 10; ++i) {
				std::cout << theCollection[i];
			}
		}
		catch (std::out_of_range & error) {
			std::cerr << "EXCEPTION: " << error.what() << std::endl;
		}
		catch (...) {
			std::cerr << "ERROR" << std::endl;
		}

		std::cout << "-----------------------------------------\n\n";


		std::cout << "-----------------------------------------\n";
		std::cout << "Testing the functor\n";
		std::cout << "-----------------------------------------\n";
		for (auto i = 3u; i <= 4u; ++i)
		{
			// TODO: The following statement can generate generate an exception
			//         write code to handle the exception
			//       If an exception occurs print a message in the following format
			//EXCEPTION: ERROR_MESSAGE<endl>
			//         where ERROR_MESSAGE is extracted from the exception object.
			try {
				SpellChecker sp(argv[i]);
				for (auto j = 0u; j < theCollection.size(); ++j)
					theCollection[j].fixSpelling(sp);
				for (auto j = 0u; j < library.size(); ++j)
					library[j].fixSpelling(sp);
			}
			catch (const char* msg) {
				std::cerr << "EXCEPTION: " << msg << std::endl;
			}
			catch (...) {
				std::cerr << "ERROR" << std::endl;
			}

		}
		std::cout << "--------------- Movies ------------------\n";
		std::cout << theCollection;
		std::cout << "--------------- Books -------------------\n";
		std::cout << library;
		std::cout << "-----------------------------------------\n\n";


		std::cout << "-----------------------------------------\n";
		std::cout << "Testing operator[] (the other overload)\n";
		std::cout << "-----------------------------------------\n";
		const Movie* aMovie = theCollection["Terminator 2"];
		if (aMovie == nullptr)
			std::cout << "Movie Terminator 2 not in collection.\n";
		aMovie = theCollection["Dark Phoenix"];
		if (aMovie != nullptr)
			std::cout << "In collection:\n" << *aMovie;
		std::cout << "-----------------------------------------\n\n";

		return 0;
	}
}
