# get_next_line - @WeThinkCode_

A C function that reads any valid file line by line until the end.

### Table of Content
* [What is get_next_line?](#what-is-get_next_line)
* [Why would I use/try it?](#why-would-i-usetry-it)
* [How do I use it?](#how-do-i-use-it)

### What is get_next_line?

get_next_line is an individual project at [WeThinkCode_][4] that basically reads a file line by line.

Disclaimer: *There are so many easier methods of doing this by using standard C functions. But the goal here is to be able to do it by using any functions from my libft and only the standard functions `read`, `malloc` and `free`.*

### Why would I use/try it?

You probably will never have to use this function if you are not a WeThinkCode_ student. The goal is to get better at C. As I said above, you can only use those three standard library functions:

* read
* malloc
* free

So it makes the project harder.

After finishing this project, I learned more about static variables, pointers, arrays, linked lists, dynamic memory allocation and file manipulation.

My code is not the best, but it passed all the [WeThinkCode_][4] tests successfully.

### How do I use it?

I added a main file called **main.c**, it takes a file name as an argument, opens it and passes the file descriptor (fd) to get_next_line until get_next_line returns -1 or 0.

**Note:** get_next_line returns -1, 0, 1 depending on wether an error has occurred, the reading has been completed or a line has been read respectively.

Alright, so first of all, download/clone this repo:

	git clone https://github.com/martian1431/gnl.git
	
Get into it and build the library:
	
	cd get_next_line
	make -C libft/

Give it some time to compile all the files.

Build the executable:
	
	gcc -Wall -Wextra -Werror -o gnl get_next_line.c main.c libft/libft.a

Alright, the last command created a `gnl`lyricsable in your directory. Now test it with:

	./gnl lyrics

It should read the whole file to you. Kinda like a basic `cat` implementation.

**NOTE:** The lyrics in the text file are from [Azlyrics][1] by [Russ][2])

That's it! If you're having some problems, just [send me a tweet][3].

Enjoy.

[1]: https://www.azlyrics.com/lyrics/russ/voicemail.html

[2]: https://open.spotify.com/album/48Kac3ieDtt9OSp9Fm4g9e

[3]: https://twitter.com/martian1431

[4]: https://www.wethinkcode.co.za/


