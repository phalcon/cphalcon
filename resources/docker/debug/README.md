# Debug image

This image is for debugging crashes and memory errors in the extension. It is not part of the
compose stack. Build it and start it with the commands below when you need it, and remove it
when you are done.

The image compiles PHP again from the source of the official image (NTS) with debug
information. It has:

- PHP with symbols, and optionally with the PHP debug checks or AddressSanitizer (ASan)
- the extensions of the CI unit jobs, and pcov
- Xdebug (optional, from git)
- gdb with the PHP macros (`zbacktrace`, `printzv`), and valgrind
- the PHP source in `/usr/src/php` (and the pcov and Xdebug sources) for gdb

This image found the cause of the PHP 8.6 unit suite segfault (issue #17766): ASan showed a
`heap-use-after-free` in `Phalcon\Session\Manager::destroy()` in one run.

## Build arguments

| Argument      | Default | Description                                                                   |
|---------------|---------|-------------------------------------------------------------------------------|
| `PHP_VERSION` | `8.6`   | The tag of the official `php:<version>-cli` image                             |
| `PHP_DIGEST`  | empty   | Optional base image digest (`sha256:...`)                                     |
| `PHP_DEBUG`   | `1`     | `1`: `--enable-debug` (`-O0`, PHP debug checks). `0`: release flags with `-g` |
| `PHP_ASAN`    | `0`     | `1`: `--enable-address-sanitizer`                                             |
| `XDEBUG_REF`  | empty   | Xdebug git branch, tag or commit to install. Empty: no Xdebug                 |
| `UID`, `GID`  | `1000`  | Your user and group IDs, so that the files in `/srv` have the correct owner   |

## Build the image

Run the commands from the cphalcon folder. The build compiles PHP, so it takes some minutes.

| Variant | Use it for                                           | Command                                                          |
|---------|------------------------------------------------------|------------------------------------------------------------------|
| debug   | PHP debug checks (arginfo, return types, assertions) | `docker build ... -t cphalcon-debug-8.6 .`                       |
| release | gdb, valgrind; the closest to the CI PHP build       | `docker build ... -t cphalcon-debug-8.6:release --build-arg PHP_DEBUG=0 .` |
| asan    | memory errors (use after free, overflows)            | `docker build ... -t cphalcon-debug-8.6:asan --build-arg PHP_DEBUG=0 --build-arg PHP_ASAN=1 .` |

The full command for the debug variant:

```bash
docker build -f resources/docker/debug/Dockerfile \
    -t cphalcon-debug-8.6 \
    --build-arg UID=$(id -u) --build-arg GID=$(id -g) \
    .
```

Add `--build-arg XDEBUG_REF=master` (or a tag) to install Xdebug. The CI unit jobs run with
Xdebug and pcov, so use Xdebug when you want the same environment as CI.

## Start the container

The compose stack must be up, because the container connects to its network for the services.

```bash
docker run -d --name cphalcon-debug-8.6 \
    --network cphalcon_default \
    --add-host host.docker.internal:host-gateway \
    --cap-add SYS_PTRACE --security-opt seccomp=unconfined --ulimit core=-1 \
    -v "$PWD":/srv -w /srv \
    cphalcon-debug-8.6
```

gdb and valgrind need `SYS_PTRACE` and `seccomp=unconfined`. Use a different name for each
variant, for example `cphalcon-release-8.6` and `cphalcon-asan-8.6`, with the image tag of
that variant.

## Compile the extension

```bash
docker exec cphalcon-debug-8.6 resources/docker/debug/build-so [debug|release|asan]
```

| Mode      | Flags                                                                      | Use it with              |
|-----------|----------------------------------------------------------------------------|--------------------------|
| `debug`   | `-O0 -g -fno-omit-frame-pointer -fvisibility=hidden -DZEPHIR_RELEASE=1`    | gdb, valgrind            |
| `release` | the flags of `ext/install` with `-g` (`-O2 ... -flto`)                     | gdb, the same code as CI |
| `asan`    | `-O1 -g -fno-omit-frame-pointer ... -fsanitize=address`                    | the asan image only      |

The script runs `zephir fullclean`, `zephir generate`, and a copy of `ext/install` with these
flags. The tracked `ext/install` does not change.

## Run the unit suite

Plain run:

```bash
docker exec cphalcon-debug-8.6 \
    php -d extension=ext/modules/phalcon.so vendor/bin/phpunit -c resources/phpunit.xml.dist
```

### gdb

```bash
docker exec cphalcon-release-8.6 gdb -q -batch \
    -ex "handle SIGPIPE SIGUSR1 SIGUSR2 SIGALRM SIGCHLD SIGTERM SIGINT SIGQUIT nostop noprint pass" \
    -ex run -ex bt -ex zbacktrace \
    --args php -d extension=ext/modules/phalcon.so vendor/bin/phpunit -c resources/phpunit.xml.dist
```

- Some tests send signals with `posix_kill()` (for example the Queue worker tests). The
  `handle` line passes them to PHP, so that gdb does not stop on them.
- `bt` shows the C stack. `zbacktrace` shows the PHP stack: the PHP functions and their
  arguments.

### AddressSanitizer

```bash
docker exec -e USE_ZEND_ALLOC=0 -e ZEND_DONT_UNLOAD_MODULES=1 cphalcon-asan-8.6 \
    php -d extension=ext/modules/phalcon.so vendor/bin/phpunit -c resources/phpunit.xml.dist
```

- `USE_ZEND_ALLOC=0` makes PHP use `malloc()`, so that ASan sees each allocation.
- `ZEND_DONT_UNLOAD_MODULES=1` keeps the extensions loaded at shutdown, so that the report
  shows their function names.
- ASan stops at the first error. The report has three parts: the bad access, where the memory
  was freed, and where it was allocated.
- ASan finds an error when the bad access occurs, also when it does not cause a crash. Use it
  first when a crash point moves or occurs only in one environment.

### valgrind

Use the release image, not the asan image. valgrind is very slow, so run a part of the suite.

```bash
docker exec -e USE_ZEND_ALLOC=0 -e ZEND_DONT_UNLOAD_MODULES=1 cphalcon-release-8.6 \
    valgrind --error-exitcode=1 --track-origins=yes \
    php -d extension=ext/modules/phalcon.so vendor/bin/phpunit -c resources/phpunit.xml.dist \
    --filter '<test name>'
```

### Long runs

Run the command in the background and write the output to `tests/_output/` (git ignores it):

```bash
docker exec -d cphalcon-asan-8.6 sh -c 'USE_ZEND_ALLOC=0 ZEND_DONT_UNLOAD_MODULES=1 \
    php -d extension=ext/modules/phalcon.so vendor/bin/phpunit -c resources/phpunit.xml.dist \
    > tests/_output/asan-unit.log 2>&1; echo "exit=$?" >> tests/_output/asan-unit.log'
```

## Warnings

- **Do not commit `ext/` after `build-so`.** `zephir generate` writes `ext/` again with the
  PHP version of the container. Some generated files change (constants, cache numbers). Before
  you commit, generate and compile `ext/` again in the development container.
- **`ext/modules/phalcon.so` is shared.** The development containers load the same file. After
  `build-so`, compile again in the development container before you use it. An `asan` build
  loads only in the asan image.
- **The debug variant stops at the first PHP debug check that fails.** A debug PHP checks the
  arginfo and the return types of internal functions, and stops with a fatal error. Each stop is
  a bug in the extension. For example, `Phalcon\Http\Request\Bag\AbstractBag::normalizeKey()`
  declares `-> string` but returns an int for an int key. Fix the bug, compile, and run again
  until the suite runs clean. A release PHP does not do these checks.
- **`USE_ZEND_ALLOC=0` makes `memory_get_usage()` return 0.** PHPUnit shows "Memory: 0 bytes",
  and `Support\Debug\ReportBuilderTest::testRequestBlacklistIsApplied` fails. This is expected.
- **The asan mode compiles at `-O1`.** `ext.h` includes `phalcon.h`, which includes all the
  class headers. At `-O0`, GCC keeps the unused `static const` arginfo in each object file.
  With the ASan red zones, the data of the `.so` is larger than 2 GB, and the link fails with
  "relocation truncated to fit".
- **The asan image turns off the leak check** (`ASAN_OPTIONS=detect_leaks=0`). PHP does not
  free all memory at exit, and the leak check stops each `php` command with an error.

## PHP versions that are not released yet

The default `PHP_VERSION=8.6` was not released when this image was made. Some parts of the
Dockerfile exist only for that reason. For a released PHP version, change them:

- PIE installs the development branches of igbinary, apcu, imagick, phpredis, yaml
  (`dev-php7`), msgpack and memcached. Use the releases, for example
  `pie install igbinary/igbinary`.
- pcov 1.0.12 gets a `sed` patch, because PHP 8.6 removed the `INI_BOOL`, `INI_INT` and
  `INI_STR` macros (the same patch as the CI PHP builds of shivammathur/php-builder). Remove the
  `sed` commands for an older PHP version, or for a pcov release that has the fix.
- Xdebug: an Xdebug release can be too old for the PHP version. Use `XDEBUG_REF=master` then.

## Clean up

```bash
docker rm -f cphalcon-debug-8.6 cphalcon-release-8.6 cphalcon-asan-8.6
docker rmi cphalcon-debug-8.6 cphalcon-debug-8.6:release cphalcon-debug-8.6:asan
```

Then compile the extension again in the development container.
