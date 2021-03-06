# Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

project(
  'scribby',
  'c',
  version: '0.0.0',
  license: 'GPLv3',
  default_options: [
    'c_std=gnu18'
  ]
)


cc = meson.get_compiler('c')

prefix     = get_option('prefix')
bindir     = get_option('bindir')
sysconfdir = get_option('sysconfdir')


# options
program_name = get_option('program_name')


# QOL concatenations
conf_dir = join_paths(prefix, join_paths(sysconfdir, program_name))


# dependencies
libyaml = cc.find_library('yaml', required: true)


# sub directories
subdir('etc')
subdir('src')


# daemon
executable(
  program_name + 'd',
  c_args: scribbyd_args,
  sources: scribbyd_sources,
  dependencies: libyaml,
  install: true
)


# summaries
summary(
  {
    'program name': get_option('program_name')
  },
  section: 'OPTIONS'
)

summary(
  {
    'prefix': prefix,
    'bindir': join_paths(prefix, bindir),
    'sysconfdir': join_paths(prefix, sysconfdir)
  },
  section: 'DIRECTORIES'
)
