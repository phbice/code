#define END			0

#define NUMBER		0x10000000

#define BRACKET		0x20000000
#define BRACKET_L	0x20000001
#define BRACKET_R   0x20000002

#define OPERATOR	0x40000000
#define ADD			1
#define SUB			2
#define MUL			3
#define DIV			4
#define POW			5
#define NEG         6

#define CAL_ERROR				0x80000000
#define UNKNOWN_EXPRESSION		1
#define UNBALENCED_BRACKET		2
#define DIVIDED_BY_ZERO			3
#define SYNTAX_ERROR			4

#define FLAG_MASK 0xF0000000

LIST * PreProcess(char * szInput);
int getnum(char string[], ITEM * item);
int MatchChar(char cData, char * szList);
