# Daemon

Sensor data from our telemetry system will need to be logged as well as
accessible to multiple persons.  To prevent processes from trampling over one
another we need to create a daemon.

Multiple person(s) will need to have access to the telemetry system at any one
time.  To prevent processes from trampling over one another we need to create a
daemon-client system.


## Job of the daemon

The job of the daemon will primarily consist of logging all sensor data to log
files.  Users will able to set a logging rate per sensor, or a global logging
rate.  Along with logging all sensor data, the daemon will be able communicate
with client process(es).  When communicating with the client process, the
daemon will need to dynamically adapt logging to the request rate of the
client.

When logging, output should be generated in such a manner to work easily with
standard UNIX text-stream-manipulation.  This is done to modularize the
telemetry system and allow for easy access to any data when the time comes to
run some kind of analysis.


## Possible output

Logs will be kept plain-text to cut down on unneeded complexity.

> When logged to a sensor-specific log file:

```
# SENSOR
[YYYY-MM-DD  HHHH:MM:SS:SSSS]: foo bar
```

> When sending all output to stdout:

```
[YYYY-MM-DD  HHHH:MM:SS:SSSS] [SENSOR]: foo bar
```

> When asked for a specific sensor, and just for values:
```
foo bar
```

What's to note is that all metadata is output first, meaning it can be easily
removed with a regex when crawling through logs later on.  Along with this, the
daemon will be capable of adjusting output to meet the needs of the client i.e.
removing unnecessary metadata to allow for easy piping into other processes.
One final note is that log file comments will begin with `#`.  This will allow
for the daemon to include miscellaneous information when logging.


## Other notes

Along with logging, the daemon process will responsible for communication with
the various microcontrollers scattered around the vehicle to aggregate data.
