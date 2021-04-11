# Phalcon Unit Tests

Welcome to the Phalcon Testing Suite.

This folder contains all the tests for the Phalcon Framework. 

## Getting Started

This testing suite uses [GitHub Actions][actions] for each run.
Every commit pushed to this repository will queue a build into the continuous integration service and will run alltests to ensure that everything
is going well and the project is stable.

The testing suite can be run on your own machine. The dependencies for
running the testing suite are:

- [Docker][docker]
- [Nanobox][nanobox] (or [Docker Compose][compose])
- [Codeception][codeception]

Nanobox can also be used for developing Phalcon, and its installation
instructions can be found [in the Nanobox documentation][nanobox-doc].
Codeception can be installed using [Composer][composer].

```shell script
# run this command from project root
$ composer install --prefer-source
```

You can read more about installing and configuring Codeception from the
following resources:

- [Codeception Introduction][codeception-intro]
- [Codeception Console Commands][codeception-cmds]

The container based environment contains all the services you need to write
and run your tests. These services are:

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
- intl
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
- sqlite3
- tokenizer
- yaml
- zephir_parser
- xdebug
- xml
- xmlwriter
- zip
- zlib

## Docker Compose Way

### Setup databases

To generate the necessary database schemas, you need to run the relevant script:

```shell script
$ php tests/_ci/generate-db-schemas.php
```

### Run tests

First you need to re-generate base classes for all suites:

```shell script
$ php vendor/bin/codecept build
```

You will also need to provide Codeception configuration and run Docker containers:
 
```shell script
# Create Codeception configuration
$ cp tests/_ci/.env.default .env

# Run Docker containers
$ cd tests
$ docker-compose up -d
$ cd ..
```

Then, run the tests on a terminal:

```shell script
php vendor/bin/codecept run
# OR
php vendor/bin/codecept run --debug # Detailed output
```

Execute `unit` test with `run unit` command:

```shell script
$ php vendor/bin/codecept run unit
```

To run database related tests you need to run the `database` suite specifying
the RDBMS and group:

```shell script
$ php vendor/bin/codecept run database -g common
$ php vendor/bin/codecept run database -g mysql --env mysql
$ php vendor/bin/codecept run database -g sqlite --env sqlite
$ php vendor/bin/codecept run database -g pgsql --env pgsql
```

Available options:

```shell script
--env mysql
--env sqlite
--env pgsql
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
is not there to allow for more flexibility. We have three setup files for
PHP 7.2, PHP 7.3 and PHP 7.4. If you wish to set up an environment for Phalcon
using PHP 7.2, you can copy the relevant file at the root of your folder:

```shell script
$ cp -v ./tests/_ci/nanobox/boxfile.7.2.yml ./boxfile.yml
```

You can also create a 7.3 or 7.4 environment by copying the relevant file.

Run
```shell script
$ nanobox run
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
```shell script
/app $ zephir
```

This should show you the help screen. You can now compile the extension:
```shell script
/app $ zephir fullclean
/app $ zephir build

```

After the compilation is completed, you can check if the extension is loaded:
```shell script
/app $ php -m | grep phalcon
```

Note that Phalcon v4+ requires the [PSR][psr] extension to be loaded before Phalcon. In this environment we have compiled it for you. Once you see `phalcon` in the list, you have the extension compiled and ready to use.

### Setup databases

First, we need to have a `.env` file in the project root.

```shell script
/app $ cp tests/_ci/nanobox/.env.example .env
```

To generate the necessary database schemas, you need to run the relevant script:

```shell script
/app $ php tests/_ci/generate-db-schemas.php
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

To populate the databases you will need to run the following script:

```shell script
/app $ tests/_ci/nanobox/setup-dbs-nanobox.sh
```  

### Run tests

First you need to re-generate base classes for all suites:

```shell script
/app $ php vendor/bin/codecept build
```

The output should show:
```bash
Building Actor classes for suites: cli, database, integration, unit
 -> CliTesterActions.php generated successfully. 152 methods added
\CliTester includes modules: Asserts, Cli, \Helper\Cli, \Helper\Unit
 -> DatabaseTesterActions.php generated successfully. 252 methods added
\DatabaseTester includes modules: Phalcon4, Redis, Asserts, Filesystem, Helper\Database, Helper\Unit
 -> IntegrationTesterActions.php generated successfully. 251 methods added
\IntegrationTester includes modules: Phalcon4, Redis, Asserts, Filesystem, Helper\Integration, Helper\PhalconLibmemcached, Helper\Unit
 -> UnitTesterActions.php generated successfully. 166 methods added
\UnitTester includes modules: Apc, Asserts, Filesystem, Helper\Unit
```

Then, run the tests on a terminal:

```shell script
/app $ php vendor/bin/codecept run
# OR
/app $ php vendor/bin/codecept run --debug # Detailed output
```

Execute `unit` test with `run unit` command:

```shell script
/app $ php vendor/bin/codecept run unit
```

Execute all tests from a folder:

```shell script
/app $ php vendor/bin/codecept run tests/unit/some/folder/
```

Execute single test:

```shell script
/app $ php vendor/bin/codecept run tests/unit/some/folder/some/test/file.php
```

To run database related tests you need to run the `database` suite specifying
the RDBMS and group:

```shell script
/app $ php vendor/bin/codecept run tests/database -g common
/app $ php vendor/bin/codecept run tests/database -g mysql --env mysql
/app $ php vendor/bin/codecept run tests/database -g sqlite --env sqlite
/app $ php vendor/bin/codecept run tests/database -g pgsql --env pgsql
```

Available options:

```shell script
--env mysql
--env sqlite
--env pgsql
```

## Help

**Note:** Cache-related tests are slower than others tests because they use
wait states (sleep command) to expire generated caches.

<hr>
Please report any issue if you find out bugs or memory leaks.

Thanks!

<3 Phalcon Framework Team

[actions]: https://github.com/phalcon/cphalcon/actions
[nanobox]: https://nanobox.io
[nanobox-doc]: https://docs.nanobox.io/install
[docker]: https://www.docker.com
[codeception]: http://codeception.com
[compose]: https://docs.docker.com/compose
[composer]: http://getcomposer.org
[codeception-intro]: http://codeception.com/docs/01-Introduction
[codeception-cmds]: http://codeception.com/docs/reference/Commands
[psr]: https://github.com/jbboehr/php-psr
