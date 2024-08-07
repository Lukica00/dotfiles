/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Noto Sans M Nerd Font:size=12"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

static const char dark[]    = "#1a1b26";
static const char light[]   = "#a9b1d6";
static const char accent[]  = "#c0caf5";
static const char accent_light[] = "#bb9af7";

static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { light, dark },
	[SchemeSel] = { dark, accent },
	[SchemeOut] = { dark, accent_light },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
