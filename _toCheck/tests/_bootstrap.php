<?php

error_reporting(-1);

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
setlocale(LC_ALL, 'en_US.utf-8');

date_default_timezone_set('UTC');

if (function_exists('mb_internal_encoding')) {
    mb_internal_encoding('utf-8');
}
if (function_exists('mb_substitute_character')) {
    mb_substitute_character('none');
}

clearstatcache();

$root = realpath(dirname(__FILE__)) . DIRECTORY_SEPARATOR;

defined('TESTS_PATH')   || define('TESTS_PATH', $root);
defined('PROJECT_PATH') || define('PROJECT_PATH', dirname(TESTS_PATH) . DIRECTORY_SEPARATOR);
defined('PATH_DATA')    || define('PATH_DATA', $root .  '_data' . DIRECTORY_SEPARATOR);
defined('PATH_CACHE')   || define('PATH_CACHE', $root . '_cache' . DIRECTORY_SEPARATOR);
defined('PATH_OUTPUT')  || define('PATH_OUTPUT', $root .  '_output' . DIRECTORY_SEPARATOR);
defined('PATH_FIXTURES')|| define('PATH_FIXTURES', $root .  '_fixtures' . DIRECTORY_SEPARATOR);

unset($root);

require_once PROJECT_PATH . 'vendor/autoload.php';
require_once TESTS_PATH . 'shim.php';

if (extension_loaded('xdebug')) {
    ini_set('xdebug.cli_color', 1);
    ini_set('xdebug.collect_params', 0);
    ini_set('xdebug.dump_globals', 'on');
    ini_set('xdebug.show_local_vars', 'on');
    ini_set('xdebug.max_nesting_level', 100);
    ini_set('xdebug.var_display_max_depth', 4);
}

$defaults = [
    // General
    "PATH_CACHE"            => TESTS_PATH . '_cache' . DIRECTORY_SEPARATOR,

    // Beanstalk
    "DATA_BEANSTALKD_HOST"              => '127.0.0.1',
    "DATA_BEANSTALKD_PORT"              => 11300,

    // Memcached
    "DATA_MEMCACHED_HOST"              => '127.0.0.1',
    "DATA_MEMCACHED_PORT"              => 11211,
    "DATA_MEMCACHED_WEIGHT"            => 1,

    // SQLite
    "DATA_SQLITE_NAME"       => PATH_OUTPUT . 'phalcon_test.sqlite',
    "DATA_SQLITE_I18N_NAME"  => PATH_OUTPUT . 'translations.sqlite',

    // MySQL
    "DATA_MYSQL_HOST"        => '127.0.0.1',
    "DATA_MYSQL_PORT"        => 3306,
    "DATA_MYSQL_USER"        => 'root',
    "DATA_MYSQL_PASS"      => '',
    "DATA_MYSQL_NAME"        => 'phalcon_test',
    "DATA_MYSQL_CHARSET"     => 'utf8',

    // Postgresql
    "DATA_POSTGRES_HOST"   => '127.0.0.1',
    "DATA_POSTGRES_PORT"   => 5432,
    "DATA_POSTGRES_USER"   => 'postgres',
    "DATA_POSTGRES_PASS" => '',
    "DATA_POSTGRES_NAME"   => 'phalcon_test',
    "DATA_POSTGRES_SCHEMA" => 'public',

    // Mongo
    "DATA_MONGO_HOST"        => '127.0.0.1',
    "DATA_MONGO_PORT"        => 27017,
    "DATA_MONGO_USER"        => 'admin',
    "DATA_MONGO_PASS"      => '',
    "DATA_MONGO_NAME"        => 'phalcon_test',

    // Redis
    "DATA_REDIS_HOST"              => '127.0.0.1',
    "DATA_REDIS_PORT"              => 6379,
    "DATA_REDIS_NAME"                => 0,
];



foreach ($defaults as $key => $defaultValue) {
    if (defined($key)) {
        continue;
    }

    $value = getenv($key) ?: $defaultValue;

    define($key, $value);
}
