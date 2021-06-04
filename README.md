# Odyssey Bot

This is a final project for EEP 520 Spring 2021 intended to show the user a wandering robot searching for the way out of a maze to reach its goal, the green box. Rather than the robot exiting the maze as efficiently and quickly as possible, the main purpose is for the robot's journey to calm the user. Just as we often struggle to find our way through life's labyrinth of hardships, the robot strives to find its path, and eventually it does, just as we will. The robot's long but ultimately fruitful journey reassures us that maybe our journeys will be long and hard, but there is a light at the end of the tunnel, and our green boxes are out there, waiting for us, even if we can't see them from the dead end we're up against right now. 



This system is built using [Elma](https://github.com/klavinslab/elma) and [Enviro](https://github.com/klavinslab/enviro).

![](/images/wanderingbot.gif)

## Overview

This project is intended to capture the everyday struggles we all go through in life as we strive towards our goals. Oftentimes we lose our way or find ourselves wandering, but the robot and its journey are meant to serve as a gentle reminder that even if we don't travel the quickest path or even the easiest one, we will still get to where we want to be. 

This project aims to build a robot that will find the maze's exit and not instead be eternally trapped in a corner of the maze, unmoving. The key challenges include building a good enough robot that will not get stuck forever in the maze but at the same time not too good that it will get out of the maze quickly and efficiently. 

Before colliding into an object (wall/maze/box) the robot will decelerate and prevent the collision. The sensor will also detect the object and print the name.

#### Maze

The maze is made out of different objects

- wall : horizontal wall (outer layer of maze)
- wall2 : vertical wall ( outer layer of maze)
- maze1 : short vertical wall ( inner layer of maze)
- maze2 : medium length horizontal wall ( inner layer of maze)
- maze3 : short horizontal wall ( inner layer of maze)

#### Box
- box : The red box is just to show the starting point of the maze.
- box2 : The green box is the goal(end point) of the maze.

#### Robot

- my_robot : a wandering robot(Odysseús) with multiple behaviors

## Key Challenges

1. Robot get stuck

It is easy to build a random wandering robot by using random number generator for the robot to rotate and move forward randomly. However, the robot tend to get stucked after colliding at the maze and will not be able to get out. To overcome this, an avoid colliding behavior is added to the robot. With this, the robot will decelerate before it knows it is going to collide to an object and avoid that from happening. 

2. Tuning the physics parameters for the robot

It is challenging to tune the velocity, angular velocity, momentum, friction, controls and the sensors for the robot to the most optimal and desired settings. The only way to do it is to through trial and error. I did a bunch of testing and just iterate over and over again to find the best hyperparameters that I want.

## Installation

### Requirements
Please make sure that you have docker and Git installed before proceeding to the installation steps.

1. [Docker](https://docs.docker.com/get-docker/)
2. [Git](https://git-scm.com/)

### Step by step installation instruction


1. Open up command prompt or bash.
2. Type in 
```bash
git clone https://github.com/inoejj/odyssey_bot.git
```
3. Change to the project directory
```bash
cd odyssey_bot/project
```
4. Before starting the docker image, please change the **$PWD** to your project folder. Then start the docker image environment (It will automatically download the docker image if you do not have it in your local machine),

For an example 

`docker run -p80:80 -p8765:8765 -v C:\Users\TheGoldenLab\Desktop\odysseybot\odyssey_bot\project:/source -it klavins/enviro:v1.61 bash`

```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash
```
5. To start the project, 
```bash
esm start
```
```bash
enviro
```
6. Open your web browser and type in localhost and you should be able to see this.

![](/images/wanderingmaze.PNG)


## Acknowledgement

This system is built on top of [Elma](https://github.com/klavinslab/elma) and [Enviro](https://github.com/klavinslab/enviro). 

- Elma is an event loop and process manager for embedded and reactive systems. Elma is structured as a C++ library of classes on top of which you build your own C++ project. It keeps track of processes, finite state machines, events, and communication channels, executing them at specified frequencies. 
- Enviro is a multi-agent, multi-user, multi-everything simulator for users to play around and have fun coding C++.

The installation and running this is made easy by using a dockerhub image built by [Klavins Lab](https://github.com/klavinslab).

Both packages were built by [Klavins Lab](https://github.com/klavinslab).

Special thanks to a rising neuroscientist/poet Valerie Tsai for the inspiration of this project.

