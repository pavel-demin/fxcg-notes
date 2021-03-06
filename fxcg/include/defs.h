#ifndef fxcg_defs_h
#define fxcg_defs_h

#define LCD_WIDTH_PX 384
#define LCD_HEIGHT_PX 216

#define DSA_CLEAR 0
#define DSA_SETDEFAULT 1

#define SAF_BATTERY            0x0001
#define SAF_ALPHA_SHIFT        0x0002
#define SAF_SETUP_INPUT_OUTPUT 0x0004
#define SAF_SETUP_FRAC_RESULT  0x0008
#define SAF_SETUP_ANGLE        0x0010
#define SAF_SETUP_COMPLEX_MODE 0x0020
#define SAF_SETUP_DISPLAY      0x0040
#define SAF_TEXT               0x0100
#define SAF_GLYPH              0x0200

#define CREATEMODE_FILE 1
#define CREATEMODE_FOLDER 5

#define READ 0
#define READ_SHARE 1
#define WRITE 2
#define READWRITE 3
#define READWRITE_SHARE 4

#define TEXT_COLOR_BLACK 0
#define TEXT_COLOR_BLUE 1
#define TEXT_COLOR_GREEN 2
#define TEXT_COLOR_CYAN 3
#define TEXT_COLOR_RED 4
#define TEXT_COLOR_PURPLE 5
#define TEXT_COLOR_YELLOW 6
#define TEXT_COLOR_WHITE 7

#define TEXT_MODE_NORMAL 0x00
#define TEXT_MODE_INVERT 0x01
#define TEXT_MODE_TRANSPARENT_BACKGROUND 0x20
#define TEXT_MODE_AND 0x21

typedef unsigned short color_t;

#define COLOR_ALICEBLUE 0xF7DF
#define COLOR_ANTIQUEWHITE 0xFF5A
#define COLOR_AQUA 0x07FF
#define COLOR_AQUAMARINE 0x7FFA
#define COLOR_AZURE 0xF7FF
#define COLOR_BEIGE 0xF7BB
#define COLOR_BISQUE 0xFF38
#define COLOR_BLACK 0x0000
#define COLOR_BLANCHEDALMOND 0xFF59
#define COLOR_BLUE 0x001F
#define COLOR_BLUEVIOLET 0x895C
#define COLOR_BROWN 0xA145
#define COLOR_BURLYWOOD 0xDDD0
#define COLOR_CADETBLUE 0x5CF4
#define COLOR_CHARTREUSE 0x7FE0
#define COLOR_CHOCOLATE 0xD343
#define COLOR_CORAL 0xFBEA
#define COLOR_CORNFLOWERBLUE 0x64BD
#define COLOR_CORNSILK 0xFFDB
#define COLOR_CRIMSON 0xD8A7
#define COLOR_CYAN 0x07FF
#define COLOR_DARKBLUE 0x0011
#define COLOR_DARKCYAN 0x0451
#define COLOR_DARKGOLDENROD 0xBC21
#define COLOR_DARKGRAY 0xAD55
#define COLOR_DARKGREEN 0x0320
#define COLOR_DARKKHAKI 0xBDAD
#define COLOR_DARKMAGENTA 0x8811
#define COLOR_DARKOLIVEGREEN 0x5345
#define COLOR_DARKORANGE 0xFC60
#define COLOR_DARKORCHID 0x9999
#define COLOR_DARKRED 0x8800
#define COLOR_DARKSALMON 0xECAF
#define COLOR_DARKSEAGREEN 0x8DF1
#define COLOR_DARKSLATEBLUE 0x49F1
#define COLOR_DARKSLATEGRAY 0x2A69
#define COLOR_DARKTURQUOISE 0x067A
#define COLOR_DARKVIOLET 0x901A
#define COLOR_DEEPPINK 0xF8B2
#define COLOR_DEEPSKYBLUE 0x05FF
#define COLOR_DIMGRAY 0x6B4D
#define COLOR_DODGERBLUE 0x1C9F
#define COLOR_FIREBRICK 0xB104
#define COLOR_FLORALWHITE 0xFFDE
#define COLOR_FORESTGREEN 0x2444
#define COLOR_FUCHSIA 0xF81F
#define COLOR_GAINSBORO 0xDEFB
#define COLOR_GHOSTWHITE 0xFFDF
#define COLOR_GOLD 0xFEA0
#define COLOR_GOLDENROD 0xDD24
#define COLOR_GRAY 0x8410
#define COLOR_GREEN 0x0400
#define COLOR_GREENYELLOW 0xAFE5
#define COLOR_HONEYDEW 0xF7FE
#define COLOR_HOTPINK 0xFB56
#define COLOR_INDIANRED 0xCAEB
#define COLOR_INDIGO 0x4810
#define COLOR_IVORY 0xFFFE
#define COLOR_KHAKI 0xF731
#define COLOR_LAVENDER 0xE73F
#define COLOR_LAVENDERBLUSH 0xFF9E
#define COLOR_LAWNGREEN 0x7FE0
#define COLOR_LEMONCHIFFON 0xFFD9
#define COLOR_LIGHTBLUE 0xAEDC
#define COLOR_LIGHTCORAL 0xF410
#define COLOR_LIGHTCYAN 0xE7FF
#define COLOR_LIGHTGOLDENRODYELLOW 0xFFDA
#define COLOR_LIGHTGRAY 0xD69A
#define COLOR_LIGHTGREEN 0x9772
#define COLOR_LIGHTPINK 0xFDB8
#define COLOR_LIGHTSALMON 0xFD0F
#define COLOR_LIGHTSEAGREEN 0x2595
#define COLOR_LIGHTSKYBLUE 0x867F
#define COLOR_LIGHTSLATEGRAY 0x7453
#define COLOR_LIGHTSTEELBLUE 0xB63B
#define COLOR_LIGHTYELLOW 0xFFFC
#define COLOR_LIME 0x07E0
#define COLOR_LIMEGREEN 0x3666
#define COLOR_LINEN 0xFF9C
#define COLOR_MAGENTA 0xF81F
#define COLOR_MAROON 0x8000
#define COLOR_MEDIUMAQUAMARINE 0x6675
#define COLOR_MEDIUMBLUE 0x0019
#define COLOR_MEDIUMORCHID 0xBABA
#define COLOR_MEDIUMPURPLE 0x939B
#define COLOR_MEDIUMSEAGREEN 0x3D8E
#define COLOR_MEDIUMSLATEBLUE 0x7B5D
#define COLOR_MEDIUMSPRINGGREEN 0x07D3
#define COLOR_MEDIUMTURQUOISE 0x4E99
#define COLOR_MEDIUMVIOLETRED 0xC0B0
#define COLOR_MIDNIGHTBLUE 0x18CE
#define COLOR_MINTCREAM 0xF7FF
#define COLOR_MISTYROSE 0xFF3C
#define COLOR_MOCCASIN 0xFF36
#define COLOR_NAVAJOWHITE 0xFEF5
#define COLOR_NAVY 0x0010
#define COLOR_OLDLACE 0xFFBC
#define COLOR_OLIVE 0x8400
#define COLOR_OLIVEDRAB 0x6C64
#define COLOR_ORANGE 0xFD20
#define COLOR_ORANGERED 0xFA20
#define COLOR_ORCHID 0xDB9A
#define COLOR_PALEGOLDENROD 0xEF55
#define COLOR_PALEGREEN 0x9FD3
#define COLOR_PALETURQUOISE 0xAF7D
#define COLOR_PALEVIOLETRED 0xDB92
#define COLOR_PAPAYAWHIP 0xFF7A
#define COLOR_PEACHPUFF 0xFED7
#define COLOR_PERU 0xCC27
#define COLOR_PINK 0xFE19
#define COLOR_PLUM 0xDD1B
#define COLOR_POWDERBLUE 0xB71C
#define COLOR_PURPLE 0x8010
#define COLOR_RED 0xF800
#define COLOR_ROSYBROWN 0xBC71
#define COLOR_ROYALBLUE 0x435C
#define COLOR_SADDLEBROWN 0x8A22
#define COLOR_SALMON 0xFC0E
#define COLOR_SANDYBROWN 0xF52C
#define COLOR_SEAGREEN 0x2C4A
#define COLOR_SEASHELL 0xFFBD
#define COLOR_SIENNA 0xA285
#define COLOR_SILVER 0xC618
#define COLOR_SKYBLUE 0x867D
#define COLOR_SLATEBLUE 0x6AD9
#define COLOR_SLATEGRAY 0x7412
#define COLOR_SNOW 0xFFDF
#define COLOR_SPRINGGREEN 0x07EF
#define COLOR_STEELBLUE 0x4416
#define COLOR_TAN 0xD5B1
#define COLOR_TEAL 0x0410
#define COLOR_THISTLE 0xDDFB
#define COLOR_TOMATO 0xFB08
#define COLOR_TURQUOISE 0x471A
#define COLOR_VIOLET 0xEC1D
#define COLOR_WHEAT 0xF6F6
#define COLOR_WHITE 0xFFFF
#define COLOR_WHITESMOKE 0xF7BE
#define COLOR_YELLOW 0xFFE0
#define COLOR_YELLOWGREEN 0x9E66

#define KEY_CHAR_0          0x30
#define KEY_CHAR_1          0x31
#define KEY_CHAR_2          0x32
#define KEY_CHAR_3          0x33
#define KEY_CHAR_4          0x34
#define KEY_CHAR_5          0x35
#define KEY_CHAR_6          0x36
#define KEY_CHAR_7          0x37
#define KEY_CHAR_8          0x38
#define KEY_CHAR_9          0x39
#define KEY_CHAR_DP         0x2e
#define KEY_CHAR_EXP        0x0f
#define KEY_CHAR_PMINUS     0x87
#define KEY_CHAR_PLUS       0x89
#define KEY_CHAR_MINUS      0x99
#define KEY_CHAR_MULT       0xa9
#define KEY_CHAR_DIV        0xb9
#define KEY_CHAR_FRAC       0xbb
#define KEY_CHAR_LPAR       0x28
#define KEY_CHAR_RPAR       0x29
#define KEY_CHAR_COMMA      0x2c
#define KEY_CHAR_STORE      0x0e
#define KEY_CHAR_LOG        0x95
#define KEY_CHAR_LN         0x85
#define KEY_CHAR_SIN        0x81
#define KEY_CHAR_COS        0x82
#define KEY_CHAR_TAN        0x83
#define KEY_CHAR_SQUARE     0x8b
#define KEY_CHAR_POW        0xa8
#define KEY_CHAR_IMGNRY     0x7f50
#define KEY_CHAR_LIST       0x7f51
#define KEY_CHAR_MAT        0x7f40
#define KEY_CHAR_EQUAL      0x3d
#define KEY_CHAR_PI         0xd0
#define KEY_CHAR_ANS        0xc0
#define KEY_CHAR_LBRCKT     0x5b
#define KEY_CHAR_RBRCKT     0x5d
#define KEY_CHAR_LBRACE     0x7b
#define KEY_CHAR_RBRACE     0x7d
#define KEY_CHAR_CR         0x0d
#define KEY_CHAR_CUBEROOT   0x96
#define KEY_CHAR_RECIP      0x9b
#define KEY_CHAR_ANGLE      0x7f54
#define KEY_CHAR_EXPN10     0xb5
#define KEY_CHAR_EXPN       0xa5
#define KEY_CHAR_ASIN       0x91
#define KEY_CHAR_ACOS       0x92
#define KEY_CHAR_ATAN       0x93
#define KEY_CHAR_ROOT       0x86
#define KEY_CHAR_POWROOT    0xb8
#define KEY_CHAR_SPACE      0x20
#define KEY_CHAR_DQUATE     0x22
#define KEY_CHAR_VALR       0xcd
#define KEY_CHAR_THETA      0xce

#define KEY_CHAR_A          0x41
#define KEY_CHAR_B          0x42
#define KEY_CHAR_C          0x43
#define KEY_CHAR_D          0x44
#define KEY_CHAR_E          0x45
#define KEY_CHAR_F          0x46
#define KEY_CHAR_G          0x47
#define KEY_CHAR_H          0x48
#define KEY_CHAR_I          0x49
#define KEY_CHAR_J          0x4a
#define KEY_CHAR_K          0x4b
#define KEY_CHAR_L          0x4c
#define KEY_CHAR_M          0x4d
#define KEY_CHAR_N          0x4e
#define KEY_CHAR_O          0x4f
#define KEY_CHAR_P          0x50
#define KEY_CHAR_Q          0x51
#define KEY_CHAR_R          0x52
#define KEY_CHAR_S          0x53
#define KEY_CHAR_T          0x54
#define KEY_CHAR_U          0x55
#define KEY_CHAR_V          0x56
#define KEY_CHAR_W          0x57
#define KEY_CHAR_X          0x58
#define KEY_CHAR_Y          0x59
#define KEY_CHAR_Z          0x5a

#define KEY_CHAR_LOWER_A    0x61
#define KEY_CHAR_LOWER_B    0x62
#define KEY_CHAR_LOWER_C    0x63
#define KEY_CHAR_LOWER_D    0x64
#define KEY_CHAR_LOWER_E    0x65
#define KEY_CHAR_LOWER_F    0x66
#define KEY_CHAR_LOWER_G    0x67
#define KEY_CHAR_LOWER_H    0x68
#define KEY_CHAR_LOWER_I    0x69
#define KEY_CHAR_LOWER_J    0x6a
#define KEY_CHAR_LOWER_K    0x6b
#define KEY_CHAR_LOWER_L    0x6c
#define KEY_CHAR_LOWER_M    0x6d
#define KEY_CHAR_LOWER_N    0x6e
#define KEY_CHAR_LOWER_O    0x6f
#define KEY_CHAR_LOWER_P    0x70
#define KEY_CHAR_LOWER_Q    0x71
#define KEY_CHAR_LOWER_R    0x72
#define KEY_CHAR_LOWER_S    0x73
#define KEY_CHAR_LOWER_T    0x74
#define KEY_CHAR_LOWER_U    0x75
#define KEY_CHAR_LOWER_V    0x76
#define KEY_CHAR_LOWER_W    0x77
#define KEY_CHAR_LOWER_X    0x78
#define KEY_CHAR_LOWER_Y    0x79
#define KEY_CHAR_LOWER_Z    0x7a

#define KEY_CTRL_NOP        0
#define KEY_CTRL_EXE        30004
#define KEY_CTRL_DEL        30025
#define KEY_CTRL_AC         30015
#define KEY_CTRL_FD         30046
#define KEY_CTRL_UNDO       30045
#define KEY_CTRL_XTT        30001
#define KEY_CTRL_EXIT       30002
#define KEY_CTRL_SHIFT      30006
#define KEY_CTRL_ALPHA      30007
#define KEY_CTRL_OPTN       30008
#define KEY_CTRL_VARS       30016
#define KEY_CTRL_UP         30018
#define KEY_CTRL_DOWN       30023
#define KEY_CTRL_LEFT       30020
#define KEY_CTRL_RIGHT      30021
#define KEY_CTRL_F1         30009
#define KEY_CTRL_F2         30010
#define KEY_CTRL_F3         30011
#define KEY_CTRL_F4         30012
#define KEY_CTRL_F5         30013
#define KEY_CTRL_F6         30014
#define KEY_CTRL_CATALOG    30100
#define KEY_CTRL_FORMAT     30101
#define KEY_CTRL_CAPTURE    30055
#define KEY_CTRL_CLIP       30050
#define KEY_CTRL_PASTE      30036
#define KEY_CTRL_INS        30033
#define KEY_CTRL_MIXEDFRAC  30054
#define KEY_CTRL_FRACCNVRT  30026
#define KEY_CTRL_QUIT       30029
#define KEY_CTRL_PRGM       30028
#define KEY_CTRL_SETUP      30037
#define KEY_CTRL_PAGEUP     30052
#define KEY_CTRL_PAGEDOWN   30053
#define KEY_CTRL_MENU       30003
#define KEY_SHIFT_OPTN      30059
#define KEY_CTRL_RESERVE1   30060
#define KEY_CTRL_RESERVE2   30061
#define KEY_SHIFT_LEFT      30062
#define KEY_SHIFT_RIGHT     30063

#define KEY_PRGM_ACON 10
#define KEY_PRGM_DOWN 37
#define KEY_PRGM_EXIT 47
#define KEY_PRGM_F1 79
#define KEY_PRGM_F2 69
#define KEY_PRGM_F3 59
#define KEY_PRGM_F4 49
#define KEY_PRGM_F5 39
#define KEY_PRGM_F6 29
#define KEY_PRGM_LEFT 38
#define KEY_PRGM_NONE 0
#define KEY_PRGM_RETURN 31
#define KEY_PRGM_RIGHT 27
#define KEY_PRGM_UP 28
#define KEY_PRGM_0 71
#define KEY_PRGM_1 72
#define KEY_PRGM_2 62
#define KEY_PRGM_3 52
#define KEY_PRGM_4 73
#define KEY_PRGM_5 63
#define KEY_PRGM_6 53
#define KEY_PRGM_7 74
#define KEY_PRGM_8 64
#define KEY_PRGM_9 54
#define KEY_PRGM_A 76
#define KEY_PRGM_F 26
#define KEY_PRGM_ALPHA 77
#define KEY_PRGM_SHIFT 78
#define KEY_PRGM_OPTN 68
#define KEY_PRGM_MENU 48

#endif /* fxcg_defs_h */
