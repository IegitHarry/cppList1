# Singly Linked List Manager

A simple console program in C++ that manages a singly linked list of integers. Data is loaded from a text file, and a menu lets you view, search, delete from, and reverse the list.

## Features

- **Load data from file**: reads integers from `data.txt` and appends them to the list
- **Display list**: prints every value with its position (starting at 1)
- **Find value**: reports every position where a value occurs
- **Delete entry**: removes the node at a chosen position
- **Reverse list**: reverses the order of the nodes in place
- **Exit and free memory**: releases all allocated nodes before quitting

## Requirements

- A C++11 (or newer) compiler, such as `g++` or `clang++`

## Build and Run

```bash
g++ -std=c++11 main.cpp -o linkedlist
./linkedlist
```

On Windows, run `linkedlist.exe` instead.

## Input File

Create a file named `data.txt` in the same directory as the program. It should contain whitespace-separated integers:

```
12 7 45 3
99 18
```

## Usage

```
1 | Load data from file
2 | Display list
3 | Find value
4 | Delete entry
5 | Reverse list
6 | Exit and Free Memory
```

Example session:

```
1            -> Data read from file.
2            ->
                1 | 12
                2 | 7
                3 | 45
3, Value: 45 -> Value found at index 3.
4, Index: 2  -> Value '7' at index 2 removed.
5            -> reverses the list
6            -> frees memory and exits
```

## How It Works

Each node stores an integer and a pointer to the next node:

```cpp
struct customList {
    int id;
    customList *next;
};
```

| Function | Description |
|---|---|
| `readFromFile` | Reads integers from `data.txt` and appends a node for each one |
| `displayList` | Walks the list and prints each value with its position |
| `findValue` | Scans the whole list and prints every matching position |
| `deleteValue` | Unlinks and frees the node at the given position |
| `reverseList` | Reverses the `next` pointers using three pointers (`prev`, `curr`, `next`) |
| `truncateList` | Frees every node in the list |

Functions that can change the head of the list (`readFromFile`, `deleteValue`, `reverseList`, `truncateList`) take it by reference (`customList *&l`).

## Notes and Limitations

- Positions shown to the user start at **1**, while the delete function uses 0-based indexes internally.
- Loading the file twice **appends** the data again, so values will be duplicated.
- If `data.txt` is missing, the program still prints "Data read from file." and the list stays empty.
- Menu input is not validated: entering a non-numeric choice will cause the menu to repeat endlessly.
- Operations are O(n), and the append step in particular is O(n) per element, since it uses a tail pointer only within a single load.

## License

Add a license of your choice here (for example, MIT).

## Credits

Add authorship or attribution here if the code is based on someone else's work.
