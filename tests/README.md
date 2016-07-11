# Phalcon Unit Tests

Welcome to the Phalcon Testing Suite.

This folder includes all the unit tests that test Phalcon components, ensuring that you enjoy a bug free framework.

## Getting Started

This testing suite uses [Travis CI][0] for each run. Every commit pushed to this repository will queue a build into the continuous integration service and will run all
tests to ensure that everything is going well and the project is stable.

The testing suite can be run on your own machine. The main dependency is  [Codeception][1] which can be installed using [Composer][6]:

```sh
# run this command from project root
$ composer install --dev --prefer-source
```

You can read more about installing and configuring Codeception from the following resources:

- [Codeception Introduction][2]
- [Codeception Console Commands][3]

## Run tests

First you need to re-generate base classes for all suites:

```sh
$ vendor/bin/codecept build
```

A MySQL database is also bundled in this suite.
The SQL file is required for several tests. You can create a database as follows:

```sh
$ echo 'create database phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;' | mysql -u root
```

**Note:** For these tests we use the user `root` without a password.
You may need to change this in `codeception.yml` file.

Obviously, Beanstalk-tests use Beanstalk, Memcached-tests use Memcached, etc.

We use the following settings of these services:

**Beanstalk**

* Host: `127.0.0.1`
* Port: `11300`

**Memcached**

* Host: `127.0.0.1`
* Port: `11211`

**MySQL**

* Host: `127.0.0.1`
* Port: `3306`
* Username: `root`
* Password: `''` (empty string)
* DB Name: `phalcon_test`
* Charset: `utf8`

**Mongo**

* Host: `127.0.0.1`
* Port: `27017`
* Username: `admin`
* Password: `''` (empty string)
* DB Name `phalcon_test`

**Redis**

* Host: `127.0.0.1`
* Port: `6379`

You can change the connection settings of these services **before** running tests by using [environment variables][8]:

```sh
# Beanstalk
export TEST_BT_HOST="127.0.0.1"
export TEST_BT_PORT="11300"

# Memcached
export TEST_MC_HOST="127.0.0.1"
export TEST_MC_PORT="11211"

# MySQL
export TEST_DB_MYSQL_DSN="mysql:host=localhost;dbname=phalcon_test"
export TEST_DB_MYSQL_HOST="127.0.0.1"
export TEST_DB_MYSQL_PORT="3306"
export TEST_DB_MYSQL_USER="root"
export TEST_DB_MYSQL_PASSWD=""
export TEST_DB_MYSQL_NAME="phalcon_test"
export TEST_DB_MYSQL_CHARSET="utf8"

# Mongo
export TEST_DB_MONGO_HOST="127.0.0.1"
export TEST_DB_MONGO_PORT="27017"
export TEST_DB_MONGO_USER="admin"
export TEST_DB_MONGO_PASSWD=""
export TEST_DB_MONGO_NAME="phalcon_test"

# Redis
export TEST_RS_HOST="127.0.0.1"
export TEST_RS_PORT="6379"
```

Once the database is created, run the tests on a terminal:

```sh
$ vendor/bin/codecept run
# OR
$ vendor/bin/codecept run --debug # Detailed output
```

Execute `unit` test with `run unit` command:

```sh
$ vendor/bin/codecept run unit
```

Execute all tests from a folder:

```sh
$ vendor/bin/codecept run test/unit/some/folder
```

Execute single test:

```sh
$ vendor/bin/codecept run test/unit/some/folder/some/test/file.php
```

## CodeCoverage

How can we learn of CodeCoverage?

Actually, for the reason that Phalcon is ultimately a binary file (`phalcon.so` or `phalcon.dll`),
it is quite difficult to learn of code coverage at the moment. For example, Xdebug can apply it only to php files.

We create a **Proxy Class** for each internal class and place all former ones into [a special directory][7].
We test these proxy classes by enabling **CodeCoverage**, in doing so we get information about code coverage.

Of course, it does not give us an insight into the coverage of control structures, but at least we cover the method
execution result.

**Note:** That if you create such proxy class then its method signatures must fully accord with the original.
So only we can learn of the real code coverage and find out the missing tests.
If you delete or change a method in the original class, you must do the same in the proxy class.
Also, it should be noted that all of the aforesaid holds only for public methods.
You must not create protected or private methods.

## Todo

- [ ] Tests for foreign keys cascade in the ORM
- [ ] Tests for many-to-many relations
- [ ] Tests for `+=`, `-=`, `*=`, `/=`, `++`, `--` in Volt
- [ ] Tests for `Alc::allow('*', '*', 'index')`
- [ ] Tests for `Alc::allow('*', '*', '*')`
- [ ] Tests for `Alc::deny('user', '*', '*')` - should deny all resources

## Help

**Note:** Cache unit-tests are slower than others tests because they use wait states (sleep command) to expire generated caches.

The file `.travis.yml` contains full instructions to test Phalcon Framework on Ubuntu 12+
If you cannot run the tests, please check the file `.travis.yml` for an in depth view on how test Phalcon.
Additional information regarding our testing environment can be found by looking at the `tests/_bootstrap.php` file.

<hr>
Please report any issue if you find out bugs or memory leaks.<br>Thanks!

Phalcon Framework Team<br>2016

[0]: https://travis-ci.org/
[1]: http://codeception.com/
[2]: http://codeception.com/docs/01-Introduction
[3]: http://codeception.com/docs/reference/Commands
[6]: http://getcomposer.org
[7]: https://github.com/phalcon/cphalcon/tree/master/tests/_proxies
[8]: https://wiki.archlinux.org/index.php/Environment_variables
