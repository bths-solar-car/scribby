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

define_str = '-D@0@="@1@"'

scribbyd_args = [
  define_str.format('CONF_DIR',     conf_dir),
  define_str.format('PROGRAM_NAME', program_name),
  define_str.format('VERSION',      meson.project_version())
]

if systemd.found() and not get_option('systemd').disabled()
  scribbyd_args += '-DSYSTEMD'
endif

scribbyd_sources = files(
  'scribbyd.c',
  'config.c'
)
