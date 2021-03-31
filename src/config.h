/*
 * config.h -- configure scribby
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

#ifndef CONFIG_H
#define CONFIG_H


#define DEFAULT_CONFIG_PATH "/etc/scribbyd/config.yml"


typedef struct {
	char *config_path;
} config_t;


/*
 * Load the configuration file.
 *
 * The configuration file specified in the passed config_t is parsed.  Options
 * in memory are only changed if the parsing was successful.
 *
 * returns 1 on success, 0 on failure
 */
int config_load(config_t *in);

#endif /* CONFIG_H */
