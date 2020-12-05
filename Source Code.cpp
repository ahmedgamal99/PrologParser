#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

int chars;
char lexeme[100];
char nextC;
int length;
int token;
int nextT;

#define upper 0
#define lower 1
#define unknown 99

//These are the tokens
#define Upr_case 10
#define Lwr_case 11
#define digit 15
#define Add 21
#define Sub 22
#define Mult 23
#define Div 24
#define L_Paranthesis 25
#define R_Paranthesis 26
#define Single_Quote 31
#define Comma 32
#define Amper_Sign 33
#define Dollar 34
#define Hash 35
#define space 36
#define Question 37
#define Period 38
#define Colon 39
#define Tilde 40
#define Caret 40
#define B_Slash 41
#define New_Line 12

int search(char c);
void cllist();
void program();
void errorInDisplay();
void nums();
void alphanum();
void characs();
void tlist();
void pdc();
int LexicalAnalyzer();
void SpecialC();
void clause();
void plist();
void query();
void strings();
void atms();
void var();
void clist();
void satm();
void structs();
void term();

FILE* in;
FILE* out;

void sysPause() {

#ifdef _WIN32

	printf("Error Occurred! Press any key to continue...\n");

	system("pause");

#else

	system("read -p \"Press enter to continue...\n\"");

#endif

}

void errorInDisplay(string m)
{
	if (!m.empty()) {

		fprintf(out, "Error is Present in the terminal -> = %s", m.c_str());
		fflush(out);
	}
}

void findChar() {

	if ((nextC = getc(in)) != EOF)

	{

		if (nextC == '(' || nextC == ')')

			chars = unknown;

		else if (isalpha(nextC))
		{

			if (isupper(nextC))

				chars = upper;

			else

				chars = lower;
		}

		else if (isdigit(nextC))

			chars = digit;

		else if (nextC == '_')

			chars = upper;

		else chars = unknown;

	}

	else

		chars = EOF;

}
void newChar()
{
	if (length <= 98)
	{

		lexeme[length++] = nextC;

		lexeme[length] = 0;

	}

	else

		fprintf(out, "Error, this lexeme is too long!");
	fflush(out);
}

int search(char c) {
	switch (c)
	{
	case '(':

		newChar();

		nextT = L_Paranthesis;

		break;

	case ')':

		newChar();

		nextT = R_Paranthesis;

		break;

	case ',':

		newChar();

		nextT = Comma;

		break;

	case '\'':

		newChar();

		nextT = Single_Quote;

		break;

	case '&':

		newChar();

		nextT = Amper_Sign;

		break;


	case '#':

		newChar();

		nextT = Hash;

		break;

	case ' ':

		newChar();

		nextT = space;

		break;

	case '$':

		newChar();

		nextT = Dollar;

		break;

	case '?':

		newChar();

		nextT = Question;

		break;

	case '.':

		newChar();

		nextT = Period;

		break;


	case '^':

		newChar();

		nextT = Caret;

		break;

	case ':':

		newChar();

		nextT = Colon;

		break;

	case '~':

		newChar();

		nextT = Tilde;

		break;

	case '\\':

		newChar();

		nextT = B_Slash;

		break;


	case '+':

		newChar();

		nextT = Add;

		break;

	case '-':

		newChar();

		nextT = Sub;

		break;

	case '*':

		newChar();

		nextT = Mult;

		break;

	case '/':

		newChar();

		nextT = Div;

		break;

	case '\n':

		newChar();

		nextT = New_Line;

		break;

	default:

		newChar();

		nextT = EOF;

		break;

	}

	return nextT;
}

int LexicalAnalyzer()
{
	length = 0;

	switch (chars) {

	case upper:

		newChar();

		findChar();

		while (chars == upper || chars == lower) {

			newChar();

			findChar();

		}

		nextT = Upr_case;

		break;

	case lower:

		newChar();

		findChar();

		while (chars == lower || chars == upper) {

			newChar();

			findChar();

		}

		nextT = Lwr_case;

		break;


	case digit:

		newChar();

		findChar();

		while (chars == digit) {

			newChar();

			findChar();

		}

		nextT = digit;

		break;

	case unknown:

		search(nextC);

		findChar();

		break;

	case EOF:

		nextT = EOF;

		lexeme[0] = 'E';

		lexeme[1] = 'O';

		lexeme[2] = 'F';

		lexeme[3] = 0;

		break;
	}

	fprintf(out, "The next token would be: %d, The next lexeme would be %s\n", nextT, lexeme);
	fflush(out);
	return nextT;

}
void SpecialC() {

	fprintf(out, "\tEnter <special>\n");
	fflush(out);
	if (nextT == Add || nextT == Sub || nextT == Mult || nextT == Div || nextT == B_Slash || nextT == Caret || nextT == Tilde || nextT == Colon || nextT == Period || nextT == Question || nextT == space || nextT == Hash || nextT == Dollar || nextT == Amper_Sign)
	{

		LexicalAnalyzer();

	}

	else

		errorInDisplay("in <special>");

	fprintf(out, "\tExit <special>\n");
	fflush(out);
}
int fLexicalAnalyzer()
{
	length = 0;

	findChar();

	switch (chars) {

	case upper:

		newChar();

		findChar();

		while (chars == upper || chars == lower) {

			newChar();

			findChar();

		}

		nextT = Upr_case;

		break;

	case lower:

		newChar();

		findChar();

		while (chars == lower || chars == upper) {

			newChar();

			findChar();

		}

		nextT = Lwr_case;

		break;

	case digit:

		newChar();

		findChar();

		while (chars == digit) {

			newChar();

			findChar();

		}

		nextT = digit;

		break;

	case unknown:

		search(nextC);

		break;

	case EOF:

		nextT = EOF;

		lexeme[0] = 'E';

		lexeme[1] = 'O';

		lexeme[2] = 'F';

		lexeme[3] = 0;

		break;

	}

	fprintf(out, "Next token would be: %d, Next lexeme would be %s\n", nextT, lexeme);
	fflush(out);
	return nextT;

}
void alphanum() {

	fprintf(out, "\tInput <alphanumeric>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == Lwr_case || nextT == Upr_case || nextT == digit)

		LexicalAnalyzer();

	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	fprintf(out, "\Ignoring the terminal <alphanumeric>\n");;
	fflush(out);
}

void characs()
{

	fprintf(out, "\tTerminal <character>\n");
	fflush(out);

	if (nextT == Lwr_case || nextT == Upr_case || nextT == digit) {

		alphanum();

	}

	else {

		SpecialC();

	}
	fprintf(out, "\tIgnoring <character>\n");
	fflush(out);
}

void strings() {

	fprintf(out, "\tInput <string>\n");
	fflush(out);
	characs();

	if (nextT == Add || nextT == Sub || nextT == Mult || nextT == Div || nextT == B_Slash || nextT == Caret || nextT == Tilde || nextT == Colon || nextT == Period || nextT == Question || nextT == space || nextT == Hash || nextT == Dollar || nextT == Amper_Sign || nextT == Upr_case || nextT == Lwr_case || nextT == digit)

		strings();

	else

		errorInDisplay("in <string>");

	fprintf(out, "\tLeave <string>\n");
	fflush(out);
}

void nums() {

	fprintf(out, "\tInput <numeral>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == digit) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

	}

	else

		errorInDisplay("in <numeral>");

	fprintf(out, "\tLeave <numeral>\n");
	fflush(out);
}

void clist() {

	fprintf(out, "\tInput <character-list>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	alphanum();

	if (nextT == Upr_case || nextT == Lwr_case || nextT == digit) {

		clist();

	}

	fprintf(out, "\tLeave <character-list>\n");
	fflush(out);
}
void satm() {

	fprintf(out, "\tInput <small-atom>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == Lwr_case) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		if (nextT == Lwr_case || nextT == Upr_case || nextT == digit) {

			clist();

		}

	}

	else

		errorInDisplay("in <small-atom>");

	fprintf(out, "\tLeave <small-atom>\n");
	fflush(out);
}

void atms() {

	fprintf(out, "\tInput <atom>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == Lwr_case) {

		satm();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

	}

	else if (nextT == Single_Quote) {

		LexicalAnalyzer();

		strings();

		if (nextT == Single_Quote) {

			LexicalAnalyzer();

			while (nextT == space || nextT == New_Line)

				LexicalAnalyzer();
		}

		else

			errorInDisplay("in <atom>, unmatched \'");

	}

	else

		errorInDisplay("in <atom>");

	fprintf(out, "\tLeave <atom>\n");
	fflush(out);
}
void var() {

	fprintf(out, "\tInput <variable>\n");
	fflush(out);
	if (nextT == Upr_case) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		if (nextT == Upr_case || nextT == Lwr_case || nextT == digit) {

			clist();

		}

	}

	else
		errorInDisplay("in <variable>");

	fprintf(out, "\tLeave <variable>\n");
	fflush(out);
}
void structs() {

	fprintf(out, "\tInput <structure>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	atms();

	if (nextT == L_Paranthesis) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		tlist();

		if (nextT == R_Paranthesis) {

			LexicalAnalyzer();

			while (nextT == space || nextT == New_Line)

				LexicalAnalyzer();
		}

		else

			errorInDisplay("in <structure>");

	}

	fprintf(out, "\tLeave <structure>\n");
	fflush(out);
}

void term() {

	fprintf(out, "\tInput <term>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == digit) {

		nums();

	}

	else if (nextT == Upr_case) {

		var();

	}

	else if (nextT == Lwr_case)

		structs();

	else

		errorInDisplay("in <term>");

	fprintf(out, "\tLeave <term>\n");
	fflush(out);
}

void tlist() {

	fprintf(out, "\tInput <term-list>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	term();

	if (nextT == Comma) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		tlist();

	}

	fprintf(out, "\tLeave <term-list>\n");
	fflush(out);
}

void pdc() {

	fprintf(out, "\tInput <predicate>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	atms();

	if (nextT == L_Paranthesis) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		tlist();

		if (nextT == R_Paranthesis) {

			LexicalAnalyzer();

			while (nextT == space || nextT == New_Line)

				LexicalAnalyzer();

		}

		else

			errorInDisplay("in <predicate>");

	}

	fprintf(out, "\tLeave <predicate>\n");
	fflush(out);
}

void plist() {

	fprintf(out, "\tInput <predicate-list>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	pdc();

	if (nextT == Comma) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		plist();

	}

	fprintf(out, "\tLeave <predicate-list>\n");
	fflush(out);
}

void clause() {

	fprintf(out, "\tInput <clause>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	pdc();

	if (nextT == Colon) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		if (nextT == Sub) {

			LexicalAnalyzer();

			while (nextT == space || nextT == New_Line)

				LexicalAnalyzer();

			plist();

		}

		else

			errorInDisplay("in <clause> , missing a dash after the Colon");

	}

	if (nextT == Period) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

	}

	else errorInDisplay("in <clause> missing Period/period");

	fprintf(out, "\tLeave <clause>\n");
	fflush(out);
}

void cllist() {

	fprintf(out, "\tInput <clause-list>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	clause();

	if (nextT == Lwr_case || nextT == Single_Quote) {

		cllist();

	}

	fprintf(out, "\tLeave <clause-list>\n");
	fflush(out);
}
void query() {

	fprintf(out, "\tInput <query>\n");
	fflush(out);
	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == Question) {

		LexicalAnalyzer();

		while (nextT == space || nextT == New_Line)

			LexicalAnalyzer();

		if (nextT == Sub) {

			LexicalAnalyzer();

			if (nextT == space) {

				LexicalAnalyzer();

				plist();

				if (nextT == Period)

					LexicalAnalyzer();

				else

					errorInDisplay("in <query> missing a period");

			}

			else

				errorInDisplay("in <query> missing a space");

		}

		else

			errorInDisplay("in <query> missing a -");

	}

	else

		errorInDisplay("in <query> missing a ?");

	fprintf(out, "\tLeave <query>\n");
	fflush(out);
}
void program() {

	fprintf(out, "\tInput <program>\n");
	fflush(out);
	fLexicalAnalyzer();

	if (nextT == -1) {

		fprintf(out, "\tLeave <program>\n");
		fflush(out);
		return;

	}

	while (nextT == space || nextT == New_Line)

		LexicalAnalyzer();

	if (nextT == Question) {

		query();

	}

	else {

		cllist();

		query();

	}

	fprintf(out, "\tInput <program>\n");
	fflush(out);
}

int main()
{

	cout << "Welcome to the Prolog Parser for the CMP321 Project!" << endl;

	int i = 1;

	in = fopen((to_string(i) + ".txt").c_str(), "r");
	while (in != NULL) {

		out = fopen(("Parser_output" + to_string(i) + ".txt").c_str(), "w+");
		do
			program();
		while (nextT != EOF);

		fclose(out);
		in = fopen((to_string(++i) + ".txt").c_str(), "r");
	}

	cout << "The parser has completed processing " << i - 1 << " program(s)\n";

	sysPause();

	return 0;
}
