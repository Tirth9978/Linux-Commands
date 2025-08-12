#!/bin/bash

read -p "Please Enter the File Name : " name 

if [-e "$name"] then 
     if [-f "$name"] then 
          echo "'$name' is a regular file."
     elif [-d "$name"] then 
          echo "'$name' is a directory."
     else 
          echo "'$name' exists but is not a regular file or directory."

else 
     echo "'$name' does not exist."
fi