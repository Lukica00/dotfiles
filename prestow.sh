#!/bin/bash

# Instaliraj oh-my-zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
rm ~/.zshrc

# Instaliraj pulse mixer
curl https://raw.githubusercontent.com/GeorgeFilipkin/pulsemixer/master/pulsemixer > ~/.local/bin/pulsemixer && chmod +x ~/.local/bin/pulsemixer
