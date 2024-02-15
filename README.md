# Code Challenge
Welcome to the Nova CAD code challenge. The purpose of this test is to provide
a baseline understanding for us on your C++ coding skills. There is no one correct
solution. We will also give you a few ideas of what we will be looking for,
when reviewing the submission.

## Timeline
It should take 2-3hrs maximum. There is no requirement on start/stop times, but rather get it to us when you're done.

## Task
For this challenge, imagine you are building a medical device that takes in a
live video feed, runs some computation on the picture and then renders an overlay
on top of the output screen. 
Some parts of the application are already implemented by your team members and your task
is to add a bit of functionality and connect all pieces into a working application. They
left you a series of TODOs to follow.  
During testing your team realized, that the AI detection is taking too long and is slowing
down the application, so you are also tasked with running the detection in a separate thread.
Whenever a frame is drawn onto the screen, you would just show the most recently computed
bounding boxes.  

That means your tasks are:
1. complete the App::run method in `app.cpp` with all the steps required
2. implement the overlay function in `overlay.cpp`

There should not be any need to change any of the other files, but you are free to make
changes as you see fit. In particular, you are free to make changes to fix/improve the build
on your machine.

## Requisites
There are very few things that you should need to complete this challenge. How exactly
you will set them up, is up to you. There is only one external dependency (OpenCV),
but you are free to add other dependencies as needed. We believe the challenge can be
solved with just the C++ standard library, though.

You will have to install these:
* CMake
* C++ compiler
* We have added a VCPKG dependency with OpenCV, but if you want you can install it yourself. (on Mac, you can use `brew install opencv`)
	To install this, follow these commands (you need Git installed) from the challenge main folder
	cd external
	git clone https://github.com/microsoft/vcpkg.git

## Things that we are interested in
1. Readability  
   Code should be readable and understandable for any other engineer reviewing it
2. Function  
   The code should compile and do what it's supposed to do
3. Correctness  
   The code should make correct use of all the libraries and paradigms
   (e.g. correct memory management in a concurrent environment)

## Deliverable
Please send us a `zip` of your entire repo (including `.git` folder).
