
# Library Book Manager

A console-based library management system written in C++. Users can add books, view the collection, search by title, and track borrow and return status.

## Features

- Add one or multiple books in a single session
- View all books with availability status
- Search for a book by title
- Borrow and return books with status tracking
- Input validation on all menu interactions

## How to Run

1. Open the project in Visual Studio
2. Build the solution with `Ctrl + Shift + B`
3. Run with `Ctrl + F5`

No external libraries or dependencies required.

## Concepts Practiced

**Structs** — book data (title, author, genre, borrow status) is grouped into a `Book` struct rather than managed as separate parallel arrays.

**std::vector** — the library collection uses `std::vector<Book>` for dynamic sizing, replacing fixed-size arrays.

## Project Structure

```
main.cpp       — entry point and menu loop
```

## What I Learned

This project introduced grouping related data with structs and dynamic collections with `std::vector`. It also reinforced passing by reference vs const reference depending on whether a function needs to modify data.
