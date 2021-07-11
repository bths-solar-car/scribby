/*
 * scribbyd
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

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "config.h"


int main(int argc, char **argv)
{
#ifndef SYSTEMD
	/* SysV daemonization */
	switch (fork()) {
		case -1: return EXIT_FAILURE;
		case 0:  break;
		default: return EXIT_SUCCESS;
	}

	if (setsid() < 0) return EXIT_FAILURE;

	switch (fork()) {
		case -1: return EXIT_FAILURE;
		case 0:  break;
		default: return EXIT_SUCCESS;
	}

	umask(0);
	chdir("/");

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
#endif /* SYSTEMD */


	/* load user setting overrides */
	config_t options;
	config_init(&options, SCRIBBYD_CONFIG_PATH);
	config_getopt(&options, argc, argv);
	config_load(&options);


	/* cleanup */
	config_del(&options);


	exit(EXIT_SUCCESS);
}
