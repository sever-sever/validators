# validators
C validators.
This project is more for learning C language and practice in C.
The main idea is rewriting VyOS validators to C, as some of them slower that could be.
https://github.com/vyos/vyos-1x/tree/current/src/validators

It is a good idea to check them locally and practice in C.


Path for sources `src/validators-c/`

Path for binaries `src/validators/`

## build
Build binaries
```
$ make all

# or make validators
$ make validators
```

Check binaries:
```
$ ls src/validators/
numeric-range-c

$ ./src/validators/numeric-range-c -r 10-50 20 && echo "True" || echo "False"
True

$ ./src/validators/numeric-range-c -r 10-50 2220 && echo "True" || echo "False"
The value 2220 is out of the range 10-50
False

```

## tests
C validators faster even then OCAML validators.
Original `numeric` vs C `numeric-range-c`:
```
root@r14:/home/vyos# time bash -c 'for ((n=0;n<10000;n++)); do ./numeric --range 10-50 20; done' > /dev/null

real	0m15.207s
user	0m3.121s
sys	0m12.439s
root@r14:/home/vyos#
root@r14:/home/vyos#
root@r14:/home/vyos# time bash -c 'for ((n=0;n<10000;n++)); do ./numeric-range-c -r 10-50 20; done' > /dev/null

real	0m9.227s
user	0m2.635s
sys	0m6.779s
root@r14:/home/vyos#

```
