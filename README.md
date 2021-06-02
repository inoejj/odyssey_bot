# Wandering in the Maze

This is a final project for EEP 520 Spring 2021. The goal of is to build a wandering robot in a maze for the user to watch it trying to get out of the maze and touch the green box. The main purpose is to build a system that is for user to watch relaxingly (like a screensaver) and not to get out of the maze efficiently and quickly. This system is built using [Elma](https://github.com/klavinslab/elma) and [Enviro](https://github.com/klavinslab/enviro).

![](/images/wanderingbot.gif)

## Overview

The goal of this project is to build a good enough robot to get out of the maze and not to be stucked in the maze forever and not moving. The key challenges include building a good enough robot that will not get stuck forever in the maze but at the same time not too good that it will get out of the maze quickly and efficiently. The goal of this project is to build a cute robot for a day to day software developer to stare at and zone out to comfort their eyes and soul.

Before colliding into an object (wall/maze/box) the robot will decelerate and prevent the collision. The sensor will also detect the object and print the name.

#### Maze
The maze is made out of different objects

- wall : horizontal wall (outer layer of maze)
- wall2 : vertical wall ( outer layer of maze)
- maze1 : short vertical wall ( inner layer of maze)
- maze2 : medium length horizontal wall ( inner layer of maze)
- maze3 : short horizontal wall ( inner layer of maze)

#### Box
- box : The red box is just to show the starting point of the maze, while the green box is the goal of the maze.

#### Robot

- my_robot : a wandering robot with multiple behaviors

## Key Challenges

1. Robot get stuck

It is easy to build a random wandering robot by using random number generator for the robot to rotate and move forward randomly. However, the robot tend to get stucked after colliding at the maze and will not be able to get out. To overcome this, an avoid colliding behavior is added to the robot. With this, the robot will decelerate before it knows it is going to collide to an object and avoid that from happening. 

2. Tuning the physics parameters for the robot

It is challenging to tune the velocity, angular velocity, momentum, friction, controls and the sensors for the robot to the most optimal and desired settings. The only way to do it is to through trial and error. I did a bunch of testing and just iterate over and over again to find the best hyperparameters that I want.

## Installation

### Requirements
Please make sure that you have docker installed before proceeding to the installation steps.

1. [Docker](https://docs.docker.com/get-docker/)
2. [Git](https://git-scm.com/)

### Step by step installation instruction


1. Open up command prompt or bash.
2. Type in 
```bash
git clone https://github.com/inoejj/EEP_520_Project.git
```
3. Change to the project directory
```bash
cd EEP_520_Project/project
```
4. Before starting the docker image, please change the **$PWD** to your project folder. Then start the docker image environment (It will automatically download the docker image if you do not have it in your local machine),
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

