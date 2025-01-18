setxkbmap -layout "us,rs,gb,rs" -variant ",latin,," -option "grp:alt_shift_toggle,caps:swapescape"
xrandr --output HDMI-1 --left-of HDMI-0
feh --bg-scale ~/.background &
picom &
dunst &
dwmblocks &
exec dwm

