# Wandering bot in a maze

This is a final project for EEP 520 Spring 2021. The goal of is to build a wandering robot in a maze for the user to watch it trying to get out of the maze and touch the green box. The main purpose is to build a system that is for user to watch relaxingly (like a screensaver) and not to get out of the maze efficiently and quickly. This system is built using [Elma](https://github.com/klavinslab/elma) and [Enviro](https://github.com/klavinslab/enviro).

![](/images/wanderingmaze.PNG)

## Overview

The goal of this project is to build a good enough robot to get out of the maze and not to be stucked in the maze forever and not moving. The key challenges include building a good enough robot that will not get stuck forever in the maze but at the same time not too good that it will get out of the maze quickly and efficiently. The goal of this project is to build a cute robot for a day to day software developer to stare at and zone out to comfort their eyes and soul.

## Key Challenges

1. Robot get stuck

It is easy to build a random wandering robot by using random number generator for the robot to rotate and move forward randomly. However, the robot tend to get stucked after colliding at the maze and will not be able to get out. To overcome this, an avoid colliding behavior is added to the robot. With this, the robot will decelerate before it knows it is going to collide to an object and avoid that from happening. 

## Installation

### Requirements

1. [Docker](https://docs.docker.com/get-docker/)
2. 


## How to run


## Acknowledgement

This system is built on top of [Elma](https://github.com/klavinslab/elma) and [Enviro](https://github.com/klavinslab/enviro). Elma is an event loop and process manager for embedded and reactive systems. Elma is structured as a C++ library of classes on top of which you build your own C++ project. It keeps track of processes, finite state machines, events, and communication channels, executing them at specified frequencies. Enviro is a multi-agent, multi-user, multi-everything simulator for users to play around and have fun coding C++.

The installation and running this is made easy by using a dockerhub image built by [Klavins Lab](https://github.com/klavinslab).

Both packages were built by [Klavins Lab](https://github.com/klavinslab).

