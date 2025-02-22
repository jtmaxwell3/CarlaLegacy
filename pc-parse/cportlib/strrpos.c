/* STRRPOS.C - find offset of the last occurrence of a character in a string
 *****************************************************************************
 *
 * int strrpos(char *s, int ch)
 *
 *****************************************************************************
 * Copyright 1987, 1997 by the Summer Institute of Linguistics, Inc.
 * All rights reserved.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifndef NULL
#define NULL ((VOIDP)0)
#endif
#define NUL '\0'

#ifdef __STDC__
int strrpos(char *s, int ch);
#endif

/************************************************************************
 * NAME
 *    strrpos
 * ARGUMENTS
 *    s - address of NUL-terminated character string
 *    c - character to search for
 * DESCRIPTION
 *    strrpos() searches the NUL-terminated string s for the last
 *    occurrence of the character c.  If the character c is found in the
 *    string, the position of the last occurrence is returned (where the
 *    first character of s is considered to be at position 0).  If the
 *    character is not found, the value -1 is returned.  The terminating
 *    NUL character is considered to be part of s for the purposes of
 *    the search, so searching for NUL returns the position of the
 *    terminating NUL (which is equal to the length of the string), not
 *    the value -1.  strrpos(s,'\0') is the same as strpos(s,'\0'), and
 *    equivalent to strlen(s).
 * RETURN VALUE
 *    position of the last occurrence of c in s, or -1 if c does not
 *    occur in s
 */
int strrpos(s,ch)
char *	s;
int	ch;
{
char *	p;
char *	q;
char	c;

if ((p = s) == NULL)
	return( -1 );
q = NULL;
c = ch;
do  {
	if (*p == c)
	q = p;
	} while (*p++ != NUL);
return( (q != NULL) ? (int)(q-s) : -1 );
}

/*****************************************************************************
 * EDIT HISTORY
 * 24-Feb-87	Steve McConnel
 * 20-Oct-95	SRMc - fix for config.h (Autoconf)
 * 23-Jan-97	SRMc - add prototype for strict ANSI C
 */
