export XCURSOR_SIZE=32
~/.screenlayout/kp.sh
setxkbmap -layout "us,rs,gb,rs" -variant ",latin,," -option "grp:alt_shift_toggle,caps:swapescape"
xset b off
feh --bg-scale ~/.background &
picom &
dunst &
dwmblocks &
exec dwm

