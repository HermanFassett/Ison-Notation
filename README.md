# Ison-Notation
A Byzantine Notation sequencing software

This is a software that I [tried to make some years ago](https://sites.google.com/site/isonnotation/home); the basic idea of the app is that it will make it easier to write music in Byzantine Notation (as opposed to Western notation).

I have no grand dreams that this will every really come about, but this is my first legit attempt. I'm making it into more of a [Lilypond](http://lilypond.org/) style as opposed to my original idea of something like [Musescore](https://musescore.org/). If anyone wants to help, feel free since I doubt I'll have much time to work on this in the future.

## Installation / Build
First you will need Qt installed with Qt Creator. Then, once you have the reposity on your local machine, you can simply open the `IsonNotation.pro` file, run qmake from the Build menu, and then build and run the software. This is at least how I do it on Windows and Linux. I've only tested with Windows 10 and Fedora 25 though.

## Usage
Only the basics of symbols have been completed so far. A lot of the symbol groups have been set up now but there are some that still need to be added including all the Fthoras and lots of other special none movement symbols. The way I have the program setup, a lot of effort is probably going to have to be put in prettying up the score for output.

The idea of writing music is to enter code that will turn into the symbols (as Lilypond exemplifies).
To specify the direction of the note, either `+` or `-` need to be typed. This defaults in the begining to `+` (up) and once a direction is specified it remains constant until the direction is changed. After the direction is specified, an interval can be written simply in numeric format like `1`, `2`, `4`, etc.
A simple example to create a scale up and then down would be `0+1111111-1111111`. I'm not going to explain my whole idea for code yet, but an example can be seen in the screenshots below. If there are any suggestions, please feel free to share.

## Screenshots
Basics in the software where you can see some "code" converted to Byzantine Notation. Obviously some of the symbols aren't fully aligned with eachother yet, but that really isn't a priority right now.
![Basics](https://s17.postimg.org/mnj7f8kp9/Screenshot_from_2017-04-05_17-27-13.png)

There is also now a very basic MIDI export (as well as PDF and ODT) which can be listened to as audio or viewed as a Western Notation conversion. Here is the same score as shown above, exported to Midi, and viewed in Musescore:
![Western Notation](https://s17.postimg.org/ts5m20hcd/Screenshot_from_2017-04-05_17-33-01.png)
As you can see, it is obviously a work in progress, not correctly converting all the symbols, but it is heartening to have some progress even if it's in a different direction than the original project plan.
