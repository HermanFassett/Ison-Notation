# Ison-Notation
A Byzantine Notation sequencing software

This is a software that I [tried to make some years ago](https://sites.google.com/site/isonnotation/home); the basic idea of the app is that it will make it easier to write music in Byzantine Notation (as opposed to Western notation).

I have no grand dreams that this will every really come about, but this is my first legit attempt. I'm making it into more of a [Lilypond](http://lilypond.org/) style as opposed to my original idea of something like [Musescore](https://musescore.org/). If anyone wants to help, feel free since I doubt I'll have much time to work on this in the future.

## Installation
First you will need Qt installed with Qt Creator. Then, once you have the reposity on your local machine, you can simply open the `IsonNotation.pro` file, run qmake from the Build menu, and then build and run the software. This is at least how I do it on Windows; technically it should work cross-platform but I haven't tried any of that yet.

## Usage
Only the basics of symbols have been completed so far. That means Ison, Oligon, Elaphron, and Apostrophos, though structure is set up for some further symbols.

The idea of writing music is to enter code that will turn into the symbols (as Lilypond exemplifies).
To specify the direction of the note, either `+` or `-` need to be typed. This defaults in the begining to `+` (up) and once a direction is specified it remains constant until the direction is changed. After the direction is specified, an interval can be written simply in numeric format like `1`, `2`, `4`, etc.
A simple example to create a scale up and then down would be `0+1111111-1111111`.

## Screenshots
Basics in the software where you can see some "code" converted to Byzantine Notation.
![Basics](https://xh7org.dm2301.livefilestore.com/y3m4a6wiJ33ZbnUsp76JjLfdig5VeBPnuRgFW9okad8YfIwY_YsGzIDZvX-0kkh0ElStnwvaa7ykwkBJjxlAqT3D3gcIhniabyib8UUu5FspbFqEZzvGQUh5ZdY1Lffsf_gJgMx0K5p8jPttQNU35gh9yEfH-Eq2a4ufKQHT5gedc8/2017-03-20.png?psid=1)
