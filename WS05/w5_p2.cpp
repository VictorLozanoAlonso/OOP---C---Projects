// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
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

enum AppErrors {
    CannotOpenFile = 1, // An input file cannot be opened
    BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book> &theCollection,
                       const Book &theBook) {
    std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie> &theCollection,
                        const Movie &theMovie) {
    std::cout << "Movie \"" << theMovie.title()
              << "\" added to collection \"" << theCollection.name()
              << "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char **argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    // get the books
    sdds::Collection<sdds::Book> library("Bestsellers");
    if (argc == 5) {
        // TODO: load the first 4 books from the file "argv[1]".
        //       - read one line at a time, and pass it to the Book constructor
        //       - store each book read into the collection "library" (use the += operator)
        //       - lines that start with "#" are considered comments and should be ignored
        //       - if the file cannot be open, print a message to standard error console and
        //                exit from application with error code "AppErrors::CannotOpenFile". Done
        size_t cnt = 0;
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
            exit(AppErrors::CannotOpenFile);
        }
        std::string strBook;
        do {
            std::getline(file, strBook);
            if (file) {
                if (strBook[0] != '#') {
                    library += Book(strBook);
                    ++cnt;
                }
            }
        } while (cnt < 4);
        /*
         ♪ Hey, I just met you,      ♪
         ♪ And this is crazy,        ♪
         ♪ But here's my number.     ♪    (register the observer)
         ♪ So, if something happens, ♪    (event)
         ♪ Call me, maybe?           ♪    (callback)
         */
        library.setObserver(bookAddedObserver);

        // ------- TODO: add the rest of the books from the file. ---- DONE -----
        do {
            std::getline(file, strBook);
            if (file) {
                if (strBook[0] != '#') {
                    library += Book(strBook);
                    ++cnt;
                }
            }
        } while (file);
        file.close();
    } else {
        std::cerr << "ERROR: Incorrect number of arguments.\n";
        exit(AppErrors::BadArgumentCount);
    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    // TODO: (from part #1) create a lambda expression that fixes the price of a book accoding to the rules
    //       - the expression should receive a single parameter of type "Book&"
    //       - if the book was published in US, multiply the price with "usdToCadRate"
    //            and save the new price in the book object
    //       - if the book was published in UK between 1990 and 1999 (inclussive),
    //            multiply the price with "gbpToCadRate" and save the new price in the book object. ---- DONE -----
    auto priceConv = [&](Book &theBook) {
        if (theBook.country() == "US")
            theBook.setPrice(theBook.price() * usdToCadRate);
        if (theBook.country() == "UK" && theBook.year() >= 1990 && theBook.year() <= 1999)
            theBook.setPrice(theBook.price() * gbpToCadRate);
    };


    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n\n";

    // TODO (from part #1): iterate over the library and update the price of each book
    //         using the lambda defined above. ---- DONE -----
    for (auto i = 0; i < 7; i++)
        priceConv(library[i]);

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n\n";

    Collection<Movie> theCollection("Action Movies");

    // Process the file
    Movie movies[5];
    if (argc > 2) {
        // TODO: load 5 movies from the file "argv[2]".
        //       - read one line at a time, and pass it to the Movie constructor
        //       - store each movie read into the array "movies"
        //       - lines that start with "#" are considered comments and should be ignored. ---- DONE -----
        size_t cnt = 0;
        std::ifstream file(argv[2]);
        if (!file) {
            std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
            exit(AppErrors::CannotOpenFile);
        }
        std::string strMovie;
        do {
            std::getline(file, strMovie);
            if (file) {
                if (strMovie[0] != '#') {
                    movies[cnt] = Movie(strMovie);
                    ++cnt;
                }
            }
        } while (cnt < 5);
        file.close();
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "Testing addition and callback function\n";
    std::cout << "-----------------------------------------\n";
    if (argc > 2) {
        // Add a few movies to collection; no observer is set
        ((theCollection += movies[0]) += movies[1]) += movies[2];
        theCollection += movies[1];
        // add more movies; now we get a callback from the collection
        theCollection.setObserver(movieAddedObserver);
        theCollection += movies[3];
        theCollection += movies[3];
        theCollection += movies[4];
    } else {
        std::cout << "** No movies in the Collection\n";
    }
    std::cout << "-----------------------------------------\n\n";

    std::cout << "-----------------------------------------\n";
    std::cout << "Testing exceptions and operator[]\n";
    std::cout << "-----------------------------------------\n";


    // TODO: The following loop can generate generate an exception
    //         write code to handle the exception
    //       If an exception occurs print a message in the following format. ---- DONE -----
    //** EXCEPTION: ERROR_MESSAGE<endl>
    //         where ERROR_MESSAGE is extracted from the exception object.
    bool isError = false;
    for (auto i = 0u; i < 10 && !isError; ++i){
        try {
            std::cout << theCollection[i];
        } catch (const std::out_of_range& error){
            std::cout << "** EXCEPTION: " << error.what() << std::endl;
            isError = true;
        }
    }
    std::cout << "-----------------------------------------\n\n";


    std::cout << "-----------------------------------------\n";
    std::cout << "Testing the functor\n";
    std::cout << "-----------------------------------------\n";
    for (auto i = 3; i < argc; ++i) {
        // TODO: The following statement can generate generate an exception
        //         write code to handle the exception
        //       If an exception occurs print a message in the following format. ---- DONE -----
        //** EXCEPTION: ERROR_MESSAGE<endl>
        //         where ERROR_MESSAGE is extracted from the exception object.
        try {
            SpellChecker sp(argv[i]);
            for (auto j = 0u; j < library.size(); ++j)
                library[j].fixSpelling(sp);
            sp.showStatistics(std::cout);

            for (auto j = 0u; j < theCollection.size(); ++j)
                theCollection[j].fixSpelling(sp);
            sp.showStatistics(std::cout);
        } catch (const char* msg){
            std::cout << "** EXCEPTION: " << msg << std::endl;
        }
    }
    if (argc < 3) {
        std::cout << "** Spellchecker is empty\n";
        std::cout << "-----------------------------------------\n";
    }
    std::cout << "\n";

    std::cout << "=========================================\n";
    std::cout << "Wrapping up this workshop\n";
    std::cout << "--------------- Movies ------------------\n";
    std::cout << theCollection;
    std::cout << "--------------- Books -------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n";
    std::cout << "Testing operator[] (the other overload)\n";
    std::cout << "-----------------------------------------\n";
    const Movie *aMovie = theCollection["Terminator 2"];
    if (aMovie == nullptr)
        std::cout << "** Movie Terminator 2 not in collection.\n";
    aMovie = theCollection["Dark Phoenix"];
    if (aMovie != nullptr)
        std::cout << "In this collection:\n" << *aMovie;
    std::cout << "-----------------------------------------\n\n";

    return 0;
}
