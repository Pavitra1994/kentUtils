/* switchDbTss.c was originally generated by the autoSql program, which also 
 * generated switchDbTss.h and switchDbTss.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "switchDbTss.h"


void switchDbTssStaticLoad(char **row, struct switchDbTss *ret)
/* Load a row from switchDbTss table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->chrom = row[0];
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = row[3];
ret->score = sqlUnsigned(row[4]);
safecpy(ret->strand, sizeof(ret->strand), row[5]);
ret->confScore = sqlDouble(row[6]);
ret->gmName = row[7];
ret->gmChromStart = sqlUnsigned(row[8]);
ret->gmChromEnd = sqlUnsigned(row[9]);
ret->isPseudo = sqlUnsigned(row[10]);
}

struct switchDbTss *switchDbTssLoad(char **row)
/* Load a switchDbTss from row fetched with select * from switchDbTss
 * from database.  Dispose of this with switchDbTssFree(). */
{
struct switchDbTss *ret;

AllocVar(ret);
ret->chrom = cloneString(row[0]);
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = cloneString(row[3]);
ret->score = sqlUnsigned(row[4]);
safecpy(ret->strand, sizeof(ret->strand), row[5]);
ret->confScore = sqlDouble(row[6]);
ret->gmName = cloneString(row[7]);
ret->gmChromStart = sqlUnsigned(row[8]);
ret->gmChromEnd = sqlUnsigned(row[9]);
ret->isPseudo = sqlUnsigned(row[10]);
return ret;
}

struct switchDbTss *switchDbTssLoadAll(char *fileName) 
/* Load all switchDbTss from a whitespace-separated file.
 * Dispose of this with switchDbTssFreeList(). */
{
struct switchDbTss *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[11];

while (lineFileRow(lf, row))
    {
    el = switchDbTssLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct switchDbTss *switchDbTssLoadAllByChar(char *fileName, char chopper) 
/* Load all switchDbTss from a chopper separated file.
 * Dispose of this with switchDbTssFreeList(). */
{
struct switchDbTss *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[11];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = switchDbTssLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct switchDbTss *switchDbTssCommaIn(char **pS, struct switchDbTss *ret)
/* Create a switchDbTss out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new switchDbTss */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->chrom = sqlStringComma(&s);
ret->chromStart = sqlUnsignedComma(&s);
ret->chromEnd = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->score = sqlUnsignedComma(&s);
sqlFixedStringComma(&s, ret->strand, sizeof(ret->strand));
ret->confScore = sqlDoubleComma(&s);
ret->gmName = sqlStringComma(&s);
ret->gmChromStart = sqlUnsignedComma(&s);
ret->gmChromEnd = sqlUnsignedComma(&s);
ret->isPseudo = sqlUnsignedComma(&s);
*pS = s;
return ret;
}

void switchDbTssFree(struct switchDbTss **pEl)
/* Free a single dynamically allocated switchDbTss such as created
 * with switchDbTssLoad(). */
{
struct switchDbTss *el;

if ((el = *pEl) == NULL) return;
freeMem(el->chrom);
freeMem(el->name);
freeMem(el->gmName);
freez(pEl);
}

void switchDbTssFreeList(struct switchDbTss **pList)
/* Free a list of dynamically allocated switchDbTss's */
{
struct switchDbTss *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    switchDbTssFree(&el);
    }
*pList = NULL;
}

void switchDbTssOutput(struct switchDbTss *el, FILE *f, char sep, char lastSep) 
/* Print out switchDbTss.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->chrom);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->chromStart);
fputc(sep,f);
fprintf(f, "%u", el->chromEnd);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->name);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->score);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->strand);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%g", el->confScore);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->gmName);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->gmChromStart);
fputc(sep,f);
fprintf(f, "%u", el->gmChromEnd);
fputc(sep,f);
fprintf(f, "%u", el->isPseudo);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */
