#include <stdio.h>
#include <rhash.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "config.h"
#ifdef USE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

enum types
{
	FILES, 
	STRINGS
};

int calculate_hash(const char* file, char* digest, char* output, enum rhash_ids alg_type, enum rhash_print_sum_flags pr_type, enum types arg_type)
{
	int res = 0;
	if (arg_type == FILES)
	{
		res = rhash_file(alg_type, file, digest);
		if(res < 0) {
     		fprintf(stderr, "LibRHash error: %s: %s\n", file, strerror(errno));
     		return 1;
   		}
	}
	else if (arg_type == STRINGS)
	{
		res = rhash_msg(alg_type, file, strlen(file), digest);
		if(res < 0) {
     		fprintf(stderr, "message digest calculation error\n");
     		return 1;
   		}
	}

	rhash_print_bytes(output, digest, rhash_get_digest_size(alg_type), pr_type);

	printf("%s\n", output);

	return 0;
}


int main(int argc, char* argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char delim = ' ';

	char digest[64];
	char output[130];
	rhash_library_init();
#ifndef USE_READLINE
	while((nread = getline(&line, &len, stdin)) != -1)
#else
	while((line = readline(NULL)) != NULL)
#endif
	{

		char* name = strtok(line, &delim);
		if (name == NULL)
		{
			fprintf(stderr, "Usage: comand file|string\n");
			continue;
		}
		char* file = strtok(NULL, &delim);
		if (file == NULL)
		{
			fprintf(stderr, "Usage: comand file|string\n");
			continue;
		}
	
		enum rhash_ids alg_type;
		enum rhash_print_sum_flags pr_type;
		enum types arg_type;
		if (strncasecmp(name, "sha1", len) == 0)
		{
			alg_type = RHASH_SHA1;
		}
		else if (strncasecmp(name, "md5", len) == 0)
		{
			alg_type = RHASH_MD5;
		}
		else if (strncasecmp(name, "tth", len) == 0)
		{
			alg_type = RHASH_TTH;
		}
		else
		{
			fprintf(stderr, "Command not found!\n");
			continue;
		}

		file[strlen(file) - 1] = '\0';
		if (*file == '"')
		{
			arg_type = STRINGS;
		}
		else
		{
			arg_type = FILES;
		}

		if(isupper(*name))
		{
			pr_type = RHPR_HEX | RHPR_UPPERCASE;
		}
		else
		{
			pr_type = RHPR_BASE64 | RHPR_UPPERCASE;
		}

		calculate_hash(file, digest, output, alg_type, pr_type, arg_type);
	}
	free(line);
	return 0;
}
