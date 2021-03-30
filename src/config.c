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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>

#include "config.h"
#include "types.h"


/* load configuration options into memory */
int config_load(config_t *in)
{
	/* prepare for possible cleanup */
	FILE *file = NULL;
	yaml_parser_t parser;

	struct {
		unsigned int parser_initialize : 1;
	} state;
	memset(&state, 0, sizeof(state));


	/* prepare config for parsing */
	file = fopen(in->config_path, "r");
	if (!file) goto error;

	state.parser_initialize = yaml_parser_initialize(&parser);
	if (!state.parser_initialize) goto error;


	/* cleanup */
	fclose(file);
	yaml_parser_delete(&parser);

	return 1;


error:  /* cleanup */
	if (!file) fclose(file);
	if (!state.parser_initialize) yaml_parser_delete(&parser);

	return 0;
}
