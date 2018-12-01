# Phalcon Unit Tests

Welcome to the Phalcon Testing Suite.

This folder contains all the tests for the Phalcon Framework. 

## Getting Started

This testing suite uses [Travis CI][0] for each run. Every commit pushed to this repository 
will queue a build into the continuous integration service and will run all tests to ensure 
that everything is going well and the project is stable.

The testing suite can be run on your own machine. The only dependencies for running the 
testing suite or even developing on Phalcon is `nanobox`.
The main dependency is [Codeception][1] which can be installed using [Composer][6]:

```sh
# run this command from project root
composer install --dev --prefer-source
```

You can read more about installing and configuring Codeception from the following resources:

- [Codeception Introduction][2]
- [Codeception Console Commands][3]

A MySQL/PostgreSQL databases is also bundled in this suite. You can create a databases as follows:

*MySQL*
```sh
echo 'create database phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;' | mysql -u root
mysql -uroot phalcon_test < tests/_data/schemas/mysql/phalcon_test.sql
```

*PostgreSQL*
```sh
psql -c 'create database phalcon_test;' -U postgres
psql -U postgres phalcon_test -q -f tests/_data/schemas/postgresql/phalcon_test.sql
```

**Note:** For these MySQL-related we use the user `root` without a password.
You may need to change this in `codeception.yml` file.

Obviously, Beanstalk-tests use Beanstalk, Memcached-tests use Memcached, etc.

We use the following settings of these services:

**Beanstalk**

* Host: `127.0.0.1`
* Port: `11300`

**Memcached**

* Host: `127.0.0.1`
* Port: `11211`

**SQLite**

* DB Name: `tests/_output/tests/phalcon_test.sqlite`

**MySQL**

* Host: `127.0.0.1`
* Port: `3306`
* Username: `root`
* Password: `''` (empty string)
* DB Name: `phalcon_test`
* Charset: `utf8`

**PostgreSQL**

* Host: `127.0.0.1`
* Port: `5432`
* Username: `postgres`
* Password: `''` (empty string)
* DB Name: `phalcon_test`

**Mongo**

* Host: `127.0.0.1`
* Port: `27017`
* Username: `admin`
* Password: `''` (empty string)
* DB Name `phalcon_test`

**Redis**

* Host: `127.0.0.1`
* Port: `6379`
* DB Index `0`

You can change the connection settings of these services **before** running tests by using [environment variables][8]:

```sh
# Beanstalk
export DATA_BEANSTALKD_HOST="127.0.0.1"
export DATA_BEANSTALKD_PORT="11300"

# Memcached
export DATA_MEMCACHED_HOST="127.0.0.1"
export DATA_MEMCACHED_PORT="11211"
export DATA_MEMCACHED_WEIGHT="1"

# SQLite
export DATA_SQLITE_NAME="/tmp/phalcon_test.sqlite"

# MySQL
export DATA_MYSQL_DSN="mysql:host=localhost;dbname=phalcon_test"
export DATA_MYSQL_HOST="127.0.0.1"
export DATA_MYSQL_PORT="3306"
export DATA_MYSQL_USER="root"
export DATA_MYSQL_PASS=""
export DATA_MYSQL_NAME="phalcon_test"
export DATA_MYSQL_CHARSET="utf8"

# Postgresql
export DATA_POSTGRES_HOST="127.0.0.1"
export DATA_POSTGRES_PORT="5432"
export DATA_POSTGRES_USER="postgres"
export DATA_POSTGRES_PASS=""
export DATA_POSTGRES_NAME="phalcon_test"

# Mongo
export DATA_MONGO_HOST="127.0.0.1"
export DATA_MONGO_PORT="27017"
export DATA_MONGO_USER="admin"
export DATA_MONGO_PASS=""
export DATA_MONGO_NAME="phalcon_test"

# Redis
export DATA_REDIS_HOST="127.0.0.1"
export DATA_REDIS_PORT="6379"
export DATA_REDIS_NAME="0"

export PATH_CACHE="/tmp"
```

## Run tests

First you need to re-generate base classes for all suites:

```sh
vendor/bin/codecept build
```

Once the database is created, run the tests on a terminal:

```sh
vendor/bin/codecept run
# OR
vendor/bin/codecept run --debug # Detailed output
```

Execute `unit` test with `run unit` command:

```sh
vendor/bin/codecept run unit
```

Execute all tests from a folder:

```sh
vendor/bin/codecept run tests/unit/some/folder/
```

Execute single test:

```sh
vendor/bin/codecept run tests/unit/some/folder/some/test/file.php
```

## Todo

- [ ] Tests for foreign keys cascade in the ORM
- [ ] Tests for many-to-many relations
- [ ] Tests for `+=`, `-=`, `*=`, `/=`, `++`, `--` in Volt
- [ ] Tests for `Alc::allow('*', '*', 'index')`
- [ ] Tests for `Alc::allow('*', '*', '*')`
- [ ] Tests for `Alc::deny('user', '*', '*')` - should deny all resources

## Help

**Note:** Cache-related tests are slower than others tests because they use wait states (sleep command) to expire generated caches.

The file `.travis.yml` contains full instructions to test Phalcon Framework on Ubuntu 12+
If you cannot run the tests, please check the file `.travis.yml` for an in depth view on how test Phalcon.
Additional information regarding our testing environment can be found by looking at the `tests/_bootstrap.php` file.

<hr>
Please report any issue if you find out bugs or memory leaks.<br>Thanks!

Phalcon Framework Team<br>2017

[0]: https://travis-ci.org/
[1]: http://codeception.com/
[2]: http://codeception.com/docs/01-Introduction
[3]: http://codeception.com/docs/reference/Commands
[6]: http://getcomposer.org
[7]: https://github.com/phalcon/cphalcon/tree/master/tests/_proxies
[8]: https://wiki.archlinux.org/index.php/Environment_variables
