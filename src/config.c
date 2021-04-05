/*
 * config.c -- configure scribby
 * Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <yaml.h>

#include "config.h"


/* load command-line arguments */
int config_getopt(config_t *in, int argc, char **argv)
{
	/* available flags */
	char *flags = "";
	struct option long_flags[] = {
		{0, 0, 0, 0}
	};

	config_t temp = *in;


	/* parse flags */
	while (1) {
		int opt, long_index;
		opt = getopt_long(argc, argv, flags, long_flags, &long_index);

		if (opt == -1) break;  // no more flags

		switch (opt) {
			// invalid option
			case '?':
			default:
				return 0;
		}
	}


	*in = temp;
	return 1;
}

/* load configuration options into memory */
int config_load(config_t *in)
{
	/* prepare for possible cleanup */
	FILE *file = NULL;
	yaml_parser_t parser;
	yaml_event_t  event;

	config_t temp = *in;

	struct {
		unsigned int parser_initialize : 1;
		unsigned int parser_parse : 1;
	} state;
	memset(&state, 0xFF, sizeof(state));  // errors are always zero


	/* prepare config for parsing */
	file = fopen(
		temp.config_path ? temp.config_path : DEFAULT_CONFIG_PATH,
		"r"  // load default config if not specified
	);
	if (!file) goto error;

	state.parser_initialize = yaml_parser_initialize(&parser);
	if (!state.parser_initialize) goto error;

	yaml_parser_set_input_file(&parser, file);


	/* parse config */
	do {
		// get the next event
		yaml_event_delete(&event);  // buf can be unallocated when run
		state.parser_parse = yaml_parser_parse(&parser, &event);
		if (!state.parser_parse) goto error;

		switch (event.type) {
			case YAML_NO_EVENT:
				break;

			case YAML_STREAM_START_EVENT:
				break;
			case YAML_STREAM_END_EVENT:
				break;

			case YAML_DOCUMENT_START_EVENT:
				break;
			case YAML_DOCUMENT_END_EVENT:
				break;

			case YAML_SEQUENCE_START_EVENT:
				break;
			case YAML_SEQUENCE_END_EVENT:
				break;

			case YAML_MAPPING_START_EVENT:
				break;
			case YAML_MAPPING_END_EVENT:
				break;

			case YAML_ALIAS_EVENT:
				break;
			case YAML_SCALAR_EVENT:
				break;

			default:
				goto error;
		}
	} while (event.type != YAML_STREAM_END_EVENT);


	/* cleanup */
	fclose(file);
	yaml_parser_delete(&parser);
	yaml_event_delete(&event);

	*in = temp;
	return 1;


error:  /* cleanup */
	if (file) fclose(file);
	if (!state.parser_initialize) yaml_parser_delete(&parser);
	if (!state.parser_parse) yaml_event_delete(&event);

	return 0;
}

/* initialize program configuration */
void config_init(config_t *in)
{
}
