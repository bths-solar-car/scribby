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

if systemd.found() and not get_option('systemd').disabled()
  scribbyd_service_conf_data = configuration_data()

  scribbyd_service_conf_data.set(
    'Description',
    'Scribby the Car Recording Intercompatibility Board Broadcast Yoinker'
  )

  scribbyd_service_conf_data.set(
    'ExecStart',
    join_paths(join_paths(prefix, bindir), program_name + 'd')
  )


  install_data(
    [
      'scribbyd.service'
    ],
    rename: [
      program_name + 'd.service'
    ],
    install_dir: '/usr/lib/systemd/system'
  )
endif
