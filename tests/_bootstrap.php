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

if (!file_exists(PROJECT_PATH . 'vendor/autoload.php')) {
    throw new RuntimeException(
        'Unable to locate autoloader. ' .
        'Install dependencies from the project root directory to run test suite: `composer install`.'
    );
}

include_once PROJECT_PATH . 'vendor/autoload.php';
include_once TESTS_PATH . 'shim.php';

if (extension_loaded('xdebug')) {
    ini_set('xdebug.cli_color', 1);
    ini_set('xdebug.collect_params', 0);
    ini_set('xdebug.dump_globals', 'on');
    ini_set('xdebug.show_local_vars', 'on');
    ini_set('xdebug.max_nesting_level', 100);
    ini_set('xdebug.var_display_max_depth', 4);
}

// Beanstalk
defined('TEST_BT_HOST') || define('TEST_BT_HOST', getenv('TEST_BT_HOST') ?: '127.0.0.1');
defined('TEST_BT_PORT') || define('TEST_BT_PORT', getenv('TEST_BT_PORT') ?: 11300);

// Memcached
defined('TEST_MC_HOST') || define('TEST_MC_HOST', getenv('TEST_MC_HOST') ?: '127.0.0.1');
defined('TEST_MC_PORT') || define('TEST_MC_PORT', getenv('TEST_MC_PORT') ?: 11211);

// MySQL
defined('TEST_DB_MYSQL_HOST')    || define('TEST_DB_MYSQL_HOST',    getenv('TEST_DB_MYSQL_HOST')    ?: '127.0.0.1');
defined('TEST_DB_MYSQL_PORT')    || define('TEST_DB_MYSQL_PORT',    getenv('TEST_DB_MYSQL_PORT')    ?: 3306);
defined('TEST_DB_MYSQL_USER')    || define('TEST_DB_MYSQL_USER',    getenv('TEST_DB_MYSQL_USER')    ?: 'root');
defined('TEST_DB_MYSQL_PASSWD')  || define('TEST_DB_MYSQL_PASSWD',  getenv('TEST_DB_MYSQL_PASSWD')  ?: '');
defined('TEST_DB_MYSQL_NAME')    || define('TEST_DB_MYSQL_NAME',    getenv('TEST_DB_MYSQL_NAME')    ?: 'phalcon_test');
defined('TEST_DB_MYSQL_CHARSET') || define('TEST_DB_MYSQL_CHARSET', getenv('TEST_DB_MYSQL_CHARSET') ?: 'utf8');

// Mongo
defined('TEST_DB_MONGO_HOST') || define('TEST_DB_MONGO_HOST', getenv('TEST_DB_MONGO_HOST') ?: '127.0.0.1');
defined('TEST_DB_MONGO_PORT') || define('TEST_DB_MONGO_PORT', getenv('TEST_DB_MONGO_PORT') ?: 27017);
defined('TEST_DB_MONGO_USER') || define('TEST_DB_MONGO_USER', getenv('TEST_DB_MONGO_USER') ?: 'admin');
defined('TEST_DB_MONGO_PASSWD') || define('TEST_DB_MONGO_PASSWD', getenv('TEST_DB_MONGO_PASSWD') ?: '');
defined('TEST_DB_MONGO_NAME') || define('TEST_DB_MONGO_NAME', getenv('TEST_DB_MONGO_NAME') ?: 'phalcon_test');

// Redis
defined('TEST_RS_HOST') || define('TEST_RS_HOST', getenv('TEST_RS_HOST') ?: '127.0.0.1');
defined('TEST_RS_PORT') || define('TEST_RS_PORT', getenv('TEST_RS_PORT') ?: 6379);
