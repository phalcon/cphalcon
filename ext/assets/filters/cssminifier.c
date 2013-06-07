/* cssmin.c

Copyright (c) 2010  (www.ryanday.org)

w3c css spec: http://www.w3.org/TR/CSS2/syndata.html
this parser makes no attempt to understand css as such it does not interpret css to spec.

** cannot handle nested { blocks but will ignore aditional { in parens ()
** no in quote detection for ( or }

function get, peek and general lookahead structure taken from..

jsmin.c

Copyright (c) 2002 Douglas Crockford  (www.crockford.com)


Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

The Software shall be used for Good, not Evil.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdlib.h>
#include <stdio.h>

#define STATE_FREE 1
#define STATE_ATRULE 2
#define STATE_SELECTOR 3
#define STATE_BLOCK 4
#define STATE_DECLARATION 5
#define STATE_COMMENT 6

static int theLookahead = EOF;

static int tmp_state;

static int state = 1;

static int last_state = 1;

static int in_paren = 0;

/* get -- return the next character from stdin. Watch out for lookahead. If
the character is a control character, translate it to a space or
linefeed.
*/

static int
get()
{
	int c = theLookahead;
	theLookahead = EOF;
	if (c == EOF) {
		c = getc(stdin);
	}

	if (c >= ' ' || c == '\n' || c == EOF) {
		return c;
	}

	if (c == '\r') {
		return '\n';
	}

	return ' ';
}

/* peek -- get the next character without getting it.
*/

static int
peek()
{
	theLookahead = get();
	return theLookahead;
}

/* machine

*/
static int
machine(int c)
{

	if(state != STATE_COMMENT){
		if(c == '/' && peek() == '*'){
			tmp_state = state;
			state = STATE_COMMENT;
		}
	}

	switch (state){
		case STATE_FREE:
			if (c == ' ' && c == '\n' ) {
				c = 0;
			} else if (c == '@'){
				state = STATE_ATRULE;
				break;
			} else if(c > 0){
				//fprintf(stdout,"one to 3 - %c %i",c,c);
				state = STATE_SELECTOR;
			}
		case STATE_SELECTOR:
			if (c == '{') {
				state = STATE_BLOCK;
			} else if(c == '\n') {
				c = 0;
			} else if(c == '@'){
				state = STATE_ATRULE;
			} else if (c == ' ' && peek() == '{') {
				c = 0;
			}
			break;
		case STATE_ATRULE:
			/* support
				@import etc.
				@font-face{
			*/
			if (c == '\n' || c == ';') {
				c = ';';
				state = STATE_FREE;
			} else if(c == '{') {
				state = STATE_BLOCK;
			}
			break;
		case STATE_BLOCK:
			if (c == ' ' || c == '\n' ) {
				c = 0;
				break;
			} else if (c == '}') {
				state = STATE_FREE;
				//fprintf(stdout,"closing bracket found in block\n");
				break;
			} else {
				state = STATE_DECLARATION;
			}
		case STATE_DECLARATION:
			//support in paren because data can uris have ;
			if(c == '('){
				in_paren = 1;
			}
			if(in_paren == 0){

				if( c == ';') {
					state = STATE_BLOCK;
					//could continue peeking through white space..
					if(peek() == '}'){
						c = 0;
					}
				} else if (c == '}') {
					//handle unterminated declaration
					state = STATE_FREE;
				} else if ( c == '\n') {
				  //skip new lines
				  c = 0;
				} else if (c == ' ' ) {
				  //skip multiple spaces after each other
				  if( peek() == c ) {
					  c = 0;
					}
				}

			} else if (c == ')') {
				in_paren = 0;
			}

			break;
		case STATE_COMMENT:
			if(c == '*' && peek() == '/'){
				theLookahead = EOF;
				state = tmp_state;
			}
			c = 0;
			break;
	}

	return c;
}



/* cssmin -- minify the css
	removes comments
	removes newlines and line feeds keeping
	removes last semicolon from last property
*/

static void
cssmin()
{
	for (;;) {
		int c = get();

		if (c == EOF) {
			exit(0);
		}

		c = machine(c);

		if (c != 0) {
			putc(c,stdout);
		}
	}
}

/* main -- Output any command line arguments as comments
        and then minify the input.
*/
extern int
main(int argc, char* argv[])
{
    cssmin();
    return 0;
}

