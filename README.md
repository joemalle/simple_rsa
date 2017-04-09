# A simple demo of RSA

## Cast:
 - *Bob*	sends messages
 - *Alice*	receives messages
 - *Hacker*	hacks

## Compiling:

Compile everything using `make`.  By default, regular ints are used for everything.  If you compile with `make big_int`, then GMP (https://gmplib.org) will be used where necessary. GMP must be installed.

You can test with `make run` which encodes a message in a file called bob.out.  Alice reads this message and outputs alice.out.  Finally, the hacker tries to decrypt the message by naively factoring Alice's public key.  When compiled with GMP, the hacker will probably need to be stopped with Cntr+C.

## Usage

If you want to change p or q, edit `[big_]public_maker.cpp`.  It should be clear what to change.  Then compile and run that file before compiling the others.  To encrypt a message, run `echo "your message here" | ./bob`.  Decrypt with `cat encrypted_message | ./alice`.

Use `make clean` to remove extra files.
