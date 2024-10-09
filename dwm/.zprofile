export TERMINAL=alacritty
export STATUSBAR=dwmblocks
export EDITOR=nvim
export VISUAL=$EDITOR
export PATH=$PATH:$HOME/.local/bin:/etc/android-studio/bin

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	exec startx
fi
