# Week4-Assn4
Week 4 / Assignment 4 

Part 1:

1) Create structs necessary for hash tables that will be used for open addressing and separate chaining collision resolution methods.
1a) Open addressing will be done with an array of ints
1b) Separate chaining will be done with an array of pointers to node structures

2) Random ints between the vals of 1 - 30,000 will be generated and stored in an unsorted list of 5000 unique integers. There cannot
   be any duplicates

3) Minimum size for hash table is 6700

4) 3 Tests will be run
4a) Test 1: Quadratic Probing
4b) Test 2: Double Hashing
4c) Test 3: Separate Chaining
NOTE: Dynamic memory allocation will be validated

5) For each test run new memory will be dynamically allocated and program will exit gracefully if cannot be
5a) modulo-division will be utilized to figure out the key's initial addresses 
5b) after 5000 random integers are placed into a hash table the program will search for half of them using either odd or even
    cells
    
5c) Average load calculations will be performed along with Knuth averages for analysis

Sample Output:
      5000 items loaded into a 10009 element hash table
      Load Factor = 0.500

      Results of searching for 2500 items:

          Linear Probing
          3411 items examined (avg = 1.364 items examined per search)
              vs Knuth predicted avg = 1.499 items examined per search

          Double Hashing
          3228 items examined (avg = 1.291 items examined per search)
              vs predicted Knuth avg = 1.386 items examined per search
              
          Chained Hashing
          2890 items examined (avg = 1.156 items examined per search)
              vs Knuth predicted avg = 1.250 items examined per search

