#!/bin/bash
world=$(xclip -o)
url="https://translate.google.com/?sl=en&tl=ar&text=$(echo "$world" | sed 's/ /%20/g')&op=translate"
firefox "$url"
