/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 1;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 10;   /* systray spacing */
static const int scrolldirection = 1;        /* 1 means scroll up bigger tag, 0 opposite */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int extrabar	    = 0;	/* 0 means no extra bar */
static const char statussep	    = ';';	/* separator between status bars */
static const char *fonts[]          = { "Noto Sans M Nerd Font:size=12" };

static const char dark[]    = "#1a1b26";
static const char light[]   = "#a9b1d6";
static const char accent[]  = "#c0caf5";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { light, dark, dark },
	[SchemeSel]  = { dark, accent,  accent  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor  xkb_layout */
	{ "discord",  NULL,       NULL,           1<<8,         0,           1,       -1  },
	{ "steam",    NULL,       NULL,           1<<6,         0,           1,       -1  },
	{ "steam",    NULL,       "Friends List", 1<<6,         1,           1,       -1  },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* helper for doing statusbar action, signal is 34+signal value in dwmblocks config.h */
#define BLKCMD(cmd, action, signal) SHCMD("BLOCK_BUTTON=" #action " " #cmd " && pkill -" #signal " " STATUSBAR)

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-p", "Start:", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };
static const char *slockcmd[]  = { "slock", NULL };
static char selectedKeyboardLayout[2] = "0"; /* sluzi za notifyKeyboardChange menja se u dwm.c */
static const char *notifyKeyboardChange[] = { "write-current-kb", selectedKeyboardLayout, NULL };

static const Key keys[] = {
	/* modifier             key     function        argument */
	{ MODKEY,               33,     spawn,          {.v = dmenucmd } }, // p
	{ MODKEY|ShiftMask,     36,     spawn,          {.v = termcmd } }, // Return
	{ MODKEY|ShiftMask,	41,     spawn,          {.v = firefoxcmd } }, // f
	{ MODKEY,               56,     togglebar,      {0} },          // b
	{ MODKEY|ShiftMask,     56,     toggleextrabar, {0} },          // b
	{ MODKEY,               44,     focusstack,     {.i = +1 } },   // j
	{ MODKEY,               45,     focusstack,     {.i = -1 } },   // k
	{ MODKEY,               31,     incnmaster,     {.i = +1 } },   // i
	{ MODKEY,               40,     incnmaster,     {.i = -1 } },   // d
	{ MODKEY,               43,     setmfact,       {.f = -0.05} }, // h
	{ MODKEY,               46,     setmfact,       {.f = +0.05} }, // l
	{ MODKEY,               36,     zoom,           {0} },          // Return
	{ MODKEY,               23,     view,           {0} },          // Tab
	{ MODKEY|ShiftMask,     54,     killclient,     {0} },          // c
	{ MODKEY,               28,     setlayout,      {.v = &layouts[0]} }, // t
	{ MODKEY,               41,     setlayout,      {.v = &layouts[1]} }, // f
	{ MODKEY,               58,     setlayout,      {.v = &layouts[2]} }, // m
	{ MODKEY,               65,     setlayout,      {0} },          // space
	{ MODKEY|ShiftMask,     65,     togglefloating, {0} },          // space
	{ MODKEY,		 9,     spawn,          {.v = slockcmd } }, // esc
	{ MODKEY,               19,     view,           {.ui = ~0 } },  // 0
	{ MODKEY|ShiftMask,     19,     tag,            {.ui = ~0 } },  // 0
	{ MODKEY,               59,     focusmon,       {.i = -1 } },   // comma
	{ MODKEY,               60,     focusmon,       {.i = +1 } },   // period
	{ MODKEY|ShiftMask,     59,     tagmon,         {.i = -1 } },   // comma
	{ MODKEY|ShiftMask,     60,     tagmon,         {.i = +1 } },   // period
	{ MODKEY,               20,	setgaps,        {.i = -5 } },	// minus
	{ MODKEY,               21,	setgaps,        {.i = +5 } },	// equals
	{ MODKEY|ShiftMask,     20,	setgaps,        {.i = GAP_RESET } }, // minus
	{ MODKEY|ShiftMask,	21,	setgaps,        {.i = GAP_TOGGLE} }, // equals
	{ 0,			121,	spawn,		BLKCMD(sb-volume, 2, 41) },	//volume-mute
	{ MODKEY,		121,	spawn,		BLKCMD(sb-mic, 2, 40) },	//mic-mute
	{ 0,			122,	spawn,		BLKCMD(sb-volume, 5, 41) },	//volume-down
	{ MODKEY,		122,	spawn,		BLKCMD(sb-mic, 5, 40) },	//mic-down
	{ 0,			123,	spawn,		BLKCMD(sb-volume, 4, 41) },	//volume-up
	{ MODKEY,		123,	spawn,		BLKCMD(sb-mic, 4, 40) },	//mic-up
	{ 0,			232,	spawn,		BLKCMD(sb-brightness, 5, 45) },	//brightness-down
	{ 0,			233,	spawn,		BLKCMD(sb-brightness, 4, 45) },	//brightness-up
	{ MODKEY,		232,	spawn,		BLKCMD(sb-brightness, 10, 45) },//brightness-down
	{ MODKEY,		233,	spawn,		BLKCMD(sb-brightness, 9, 45) },	//brightness-up
	{ 0,			255,	spawn,		BLKCMD(sb-internet, 20, 43) },	//airplane
	{ 0,			200,	spawn,		BLKCMD(sb-trackpad, 1, 46) },	//trackpad on/off ima dva kljuca
	{ 0,			201,	spawn,		BLKCMD(sb-trackpad, 1, 46) },	//trackpad on/off ima dva kljuca
	{ 0,			107,	spawn,		SHCMD("maim -s | xclip -selection clipboard -t image/png") },	//print screen
	TAGKEYS(                10,                     0)              // 1
	TAGKEYS(                11,                     1)              // 2
	TAGKEYS(                12,                     2)              // 3
	TAGKEYS(                13,                     3)              // 4
	TAGKEYS(                14,                     4)              // 5
	TAGKEYS(                15,                     5)              // 6
	TAGKEYS(                16,                     6)              // 7
	TAGKEYS(                17,                     7)              // 8
	TAGKEYS(                18,                     8)              // 9
	{ MODKEY|ShiftMask,     24,     spawn,          BLKCMD(sb-power, 1, 39) }, // q
	{ MODKEY|ControlMask|ShiftMask, 24,	quit,    {1} }, // q restart dwn
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} }, // levi klik
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 3} }, // srednji klik
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 2} }, // desni klik
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} }, // skrol gore
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} }, // skrol dole
	{ ClkStatusText,        MODKEY,         Button1,        sigstatusbar,   {.i = 6} }, // levi + mod klik
	{ ClkStatusText,        MODKEY,         Button2,        sigstatusbar,   {.i = 8} }, // srednji + mod klik
	{ ClkStatusText,        MODKEY,         Button3,        sigstatusbar,   {.i = 7} }, // desni + mod klik
	{ ClkStatusText,	MODKEY,		Button4,	sigstatusbar,	{.i = 9} }, // skrol gore + mod klik
	{ ClkStatusText,	MODKEY,		Button5,	sigstatusbar,	{.i = 10} }, // skrol dole + mod klik
	{ ClkExBarMiddle,	0,		Button1,	spawn,		{.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            0,              Button4,        viewscroll,     {.i = 1 + scrolldirection} }, // skrol gore
	{ ClkTagBar,            0,              Button5,        viewscroll,     {.i = 2 - scrolldirection} }, // skrol dole
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
