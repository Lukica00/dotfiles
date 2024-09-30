/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#a9b1d6",     /* after initialization */
	[INPUT] =  "#c0caf5",   /* during input */
	[FAILED] = "#f7768e",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* lock screen opacity */
static const float alpha = 0.3;

/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 4;

/* default message */
static const char * message = "Screen locked. Enter password.";

/* text color */
static const char * text_color = "#15161e";

/* text size (must be a valid size) */
static const char * font_name = "Noto Sans M Nerd Font:size=18";
