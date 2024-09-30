xrandr --output VGA-0 --left-of HDMI-A-0 &
setxkbmap -layout "us,rs,gb,rs" -variant ",latin,," -option "grp:alt_shift_toggle"
feh --bg-scale ~/.background &
picom &
dunst &
dwmblocks &
exec dwm

