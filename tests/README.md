# Phalcon Unit Tests

Welcome to the Phalcon Testing Suite.

This folder contains all the tests for the Phalcon Framework. 

## Getting Started

This testing suite uses [Travis CI][travis], [GitHub Actions][actions] and
[AppVeyor][appveyor] for each run. Every commit pushed to this repository
will queue a build into the continuous integration service and will run all
tests to ensure that everything is going well and the project is stable.

The testing suite can be run on your own machine. The dependencies for
running the testing suite are:

- [Docker][docker]
- [Nanobox][nanobox] (or [Docker Compose][compose])
- [Codeception][codeception]

Nanobox can also be used for developing Phalcon, and its installation
instructions can be found [in the Nanobox documentation][nanobox-doc].
Codeception can be installed using [Composer][composer].

```sh
# run this command from project root
composer install --prefer-source
```

You can read more about installing and configuring Codeception from the
following resources:

- [Codeception Introduction][codeception-intro]
- [Codeception Console Commands][codeception-cmds]

The container based environment contains all the services you need to write
and run your tests. These services are:

- Beanstalkd
- Memcached
- Mongodb
- Mysql
- Postgresql
- Redis

The PHP extensions enabled are:

- apcu
- ctype
- curl
- dom
- fileinfo
- gd
- gmp
- gettext
- imagick
- iconv
- igbinary
- json
- memcached
- mbstring
- mongodb
- opcache
- phar
- pdo
- pdo_mysql
- pdo_pgsql
- pdo_sqlite
- redis
- session
- simplexml
- tokenizer
- yaml
- zephir_parser
- xdebug
- xml
- xmlwriter
- zip
- zlib

## Docker Compose Way

```shell script
# Create Codeception configuration
cp tests/_ci/.env.default .env

# Run Docker containers
cd tests
docker-compose up -d
cd ..

# Generate database schemas
php tests/_ci/generate-db-schemas.php

# Generate Codeception classes for all suites
./vendor/bin/codecept build

# Run unit tests
./vendor/bin/codecept run unit

# Run CLI tests
./vendor/bin/codecept run cli

# Run integration tests
./vendor/bin/codecept run integration
```

To run database related tests you need to run the `database` suite specifying
the RDBMS and group:

```shell script
./vendor/bin/codecept run database -g common
./vendor/bin/codecept run database -g mysql --env mysql
./vendor/bin/codecept run database -g sqlite --env sqlite
./vendor/bin/codecept run database -g pgsql --env pgsql
```

Note that certain tests are grouped as `common`. Those do not require a
specific database connection. Any other type of test requires the group
parameter for Codeception `-g` in order to run. There are certain tests that
can only run in specific RDBMs, and for that our tests use the `@group`
annotation from Codeception.

## Nanobox Way

### Start the environment

We will need a terminal window, so open one if you don't have one already and
navigate to the folder where you have cloned the repository (or a fork of it).

Nanobox reads its configuration, so as to start the environment, from a file
called `boxfile.yml` located at the root of your folder. By default, the file
is not there to allow for more flexibility. We have two setup files, one for
PHP 7.2 and one for PHP 7.3. If you wish to set up an environment for Phalcon
using PHP 7.2, you can copy the relevant file at the root of your folder:

```bash
cp -v ./tests/_ci/nanobox/boxfile.7.2.yml ./boxfile.yml
```

You can also create a 7.3 environment by copying the relevant file.

Run
```bash
nanobox run
```

The process will take a while (for the first time) and once it is done you will
be inside the environment. The prompt of your terminal will be:

```shell script
Preparing environment :

....

                                   **
                                ********
                             ***************
                          *********************
                            *****************
                          ::    *********    ::
                             ::    ***    ::
                           ++   :::   :::   ++
                              ++   :::   ++
                                 ++   ++
                                    +
                    _  _ ____ _  _ ____ ___  ____ _  _
                    |\ | |__| |\ | |  | |__) |  |  \/
                    | \| |  | | \| |__| |__) |__| _/\_

--------------------------------------------------------------------------------
+ You are in a Linux container
+ Your local source code has been mounted into the container
+ Changes to your code in either the container or desktop will be mirrored
+ If you run a server, access it at >> 172.18.0.2
--------------------------------------------------------------------------------

/app $
```

Now that zephir is in your environment, you can check it by typing:
```bash
/app $ zephir
```

This should show you the help screen. You can now compile the extension:
```bash
/app $ zephir fullclean
/app $ zephir build

```

After the compilation is completed, you can check if the extension is loaded:
```bash
/app $ php -m | grep phalcon
```

### Setup databases

To generate the necessary database schemas, you need to run the relevant script:

```sh
/app $ php ./tests/_ci/generage-db-schemas.php
```
The script looks for classes located under `tests/_data/fixtures/Migrations`.
These classes contain the necessary code to create the relevant SQL statements
for each RDBMS. You can easily inspect one of those files to understand its
structure. Additionally, these migration classes can be instantiated in your
tests to clear the target table, insert new records etc. This methodology
allows us to create the database schema per RDBMS, which will be loaded
automatically from Codeception, but also allows us to clear tables and insert
data we need to them so that our tests are more controlled and isolated.

If there is a need to add an additional table, all you have to do is create the
Phalcon model of course but also create the migration class with the relevant
SQL statements. Running the generate script (as seen above) will update the
schema file so that Codeception can load it in your RDBMS prior to running the
tests.

### Run tests

First you need to re-generate base classes for all suites:

```sh
/app $ codecept build
```

Then, run the tests on a terminal:

```sh
/app $ codecept run
# OR
/app $ codecept run --debug # Detailed output
```

Execute `unit` test with `run unit` command:

```sh
/app $ codecept run unit
```

Execute all tests from a folder:

```sh
/app $ codecept run tests/unit/some/folder/
```

Execute single test:

```sh
/app $ codecept run tests/unit/some/folder/some/test/file.php
```

To run database related tests you need to run the `database` suite specifying
the RDBMS and group:

```sh
/app $ codecept run tests/database -g common
/app $ codecept run tests/database -g mysql --env mysql
/app $ codecept run tests/database -g sqlite --env sqlite
```

Available options:

```sh
-- env mysql
-- env sqlite
```

## Help

**Note:** Cache-related tests are slower than others tests because they use
wait states (sleep command) to expire generated caches.

<hr>
Please report any issue if you find out bugs or memory leaks.

Thanks!

<3 Phalcon Framework Team

[travis]: https://travis-ci.org/github/phalcon/cphalcon
[actions]: https://github.com/phalcon/cphalcon/actions
[appveyor]: https://ci.appveyor.com/project/sergeyklay/cphalcon
[nanobox]: https://nanobox.io
[nanobox-doc]: https://docs.nanobox.io/install
[docker]: https://www.docker.com
[codeception]: http://codeception.com
[compose]: https://docs.docker.com/compose
[composer]: http://getcomposer.org
[codeception-intro]: http://codeception.com/docs/01-Introduction
[codeception-cmds]: http://codeception.com/docs/reference/Commands
