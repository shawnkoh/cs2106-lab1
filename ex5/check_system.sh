#!/bin/bash

####################
# Lab 1 Exercise 5
# Name: Koh Zheng Qiang Shawn
# Student No: A0185892L
# Lab Group: 10
####################

# Fill the below up
hostname=$(hostname)
machine_hardware=
max_user_process_count=
user_process_count=$(ps -e | wc -l)
user_with_most_processes=
mem_free_percentage=

echo "Hostname: $hostname"
echo "Machine Hardware: $machine_hardware"
echo "Max User Processes: $max_user_process_count"
echo "User Processes: $user_process_count"
echo "User With Most Processes: $user_with_most_processes"
echo "Memory Free (%): $mem_free_percentage"
