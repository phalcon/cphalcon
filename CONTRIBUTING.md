# Contributing Guidelines

Phalcon is an open source project and a volunteer effort.

*We accept bug reports, new feature requests and pull requests only via GitHub*.

If you have a question about how to use Phalcon, please see the [support page](http://phalconphp.com/support).

If you have a change or new feature in mind, please fill an [NFR](https://github.com/phalcon/cphalcon/wiki/New-Feature-Request---NFR).


# Bug Reporting Guidelines

All bug reports are welcome. However, to make it easier for us to reproduce and fix the bug, please try to include the following information to your bug report:

  * what exactly you did to trigger the bug
  * what you expected to get
  * what actually happened

Please supply any information that may be useful in fixing the bug:
  * operating system
  * PHP version
  * Phalcon version
  * a short script that reproduces the problem (please!)
  * any other information unique or specific to your setup

If you are reporting a crash, please try to build Phalcon in the debug mode and try to get the backtrace.


## How to Build Phalcon in Debug Mode

```bash
cd ext
phpize
./configure CFLAGS="-O0 -g3 -Wall"
make
sudo make install
```


## How to Generate Backtrace (Linux)

To generate a meaningful backtrace, please build Phalcon in the debug mode (see above).

  1. Remove any limits you may have on core dump size from your shell:
    * bash/dash/sh: `ulimit -c unlimited`
    * tcsh: `unlimit coredumpsize`
  2. Please make sure that the directory in which you are running PHP has write permissions for the user who's running PHP.
  3. If you use Ubuntu, please make sure to stop `apport`: `sudo service apport stop`
  4. Make sure that core dumps are enabled; to do so, please run these commands (you need to be `root`): `echo core > /proc/sys/kernel/core_pattern; echo 1 > /proc/sys/kernel/core_uses_pid`
  5. Crash PHP:
    * PHP CGI: Simply run php with the script that crashes it
    * PHP Apache Module: Run `httpd -X`, and access the script that crashes PHP (*hint:* you may need to set [CoreDumpDirectory](http://httpd.apache.org/docs/2.2/mod/mpm_common.html#coredumpdirectory))

Once PHP (or Apache) crashes, you should have the core file (it will be named core.XXXXX, where `XXXXX` is a number (ID of the crashed process)).

Now install `gdb` if you have not installed it yet (`sudo apt-get install gdb` for Debian based systems) and run it with the path to the PHP or Apache (whichever you used) and the core file.
The command should look like this:

```bash
gdb /usr/bin/php /path/to/core
```

or

```bash
gdb /usr/sbin/apache2 /path/to/core
```

Then, at the gdb prompt, please type

```
bt full
```

and copy and paste the output to the bug report.

Use `quit` to exit gdb.



Thanks!  
Phalcon Team
