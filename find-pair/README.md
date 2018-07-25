You need cmake to build this project

```
cmake . ; make

```

This should build two executables: `find-pair` and `find-pair-test`. For testing I'm using a leightweight library called Catch that is shipped as a single header file. To run a test case:

```
find-pair prices.txt 2300
```

