#include <stdio.h>
#include <stdarg.h>
#include <time.h>

extern bool Debug;
extern FILE	*outf;

void
debug(char *fmt, ...)
{
	va_list		ap;
	time_t		now;
	struct tm	*tm;

	if (!Debug)
		return;

	if (outf == NULL)
		outf = fopen("mille-debug.log", "w");

	now = time(NULL);
	tm = localtime(&now);
	fprintf(outf, "%02d:%02d:%02d ", tm->tm_hour, tm->tm_min, tm->tm_sec);
	va_start(ap, fmt);
	vfprintf(outf, fmt, ap);
	va_end(ap);
	fflush(outf);
}
