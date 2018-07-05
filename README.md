# `friday13`

This program calculates when Friday the 13th occurs. I was curious about this at some point, and hacked this program together from an earlier C++ calendar generation program I wrote.

## How do I use it?

Pretty easy. Just build it using the makefile (or not -- I'm not your mom.) The program can be called with a single year to calculate the months that have a Friday the 13th, or with two years to do that for every year in the range. It'll yell at you if you give it bogus arguments. (Or just try to turn your typoed command into an integer of some sort...)

## This seems like a lot of code for something so simple.

Yes. It is. Like I said, it was hacked together in an hour or so.

If you're gonna keep complaining, here it is as a bash one-liner:
```
for y in $(seq 1996 2018); do echo -n "$y -> "; for m in $(seq 1 12); do NDATE=$(date --date "$y-$m-13" +%w); if [ $NDATE -eq 5 ]; then PRINTME=$(date --date "$y-$m-13" +%B);echo -n "$PRINTME "; fi; done; echo; done
```
