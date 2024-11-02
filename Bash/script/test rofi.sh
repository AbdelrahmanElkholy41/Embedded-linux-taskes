#!/bin/bash
#set -x

value=$(cat "abdo.txt")


selected=$(echo -e "$value" | rofi -dmenu -p "select/add/rm")

case "$selected" in
  add)

    add_value=$(rofi -dmenu -p "please enter value")
    
    if [ -n "$add_value" ]; then
      echo -e "$value\n$add_value" > "abdo.txt"
    fi
    ;;
    
  rm)
    remove_value=$(echo -e "$value" | rofi -dmenu -p "select value to remove")
    
    if [ -n "$remove_value" ]; then
      grep -vFx "$remove_value" "abdo.txt" > temp.txt && mv temp.txt "abdo.txt"
    fi
    ;;
    
esac
