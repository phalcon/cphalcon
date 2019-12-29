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

$root = dirname(realpath(__DIR__) . DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;

/**
 * Setting this in the $_ENV so that DotLoad sets everything up properly
 */
$_ENV['PROJECT_PATH'] = $root;

require_once $root . 'tests/shim.php';

define('APP_DATA', dataDir());
define('APP_PATH', codecept_root_dir());
define('APP_PATH_OUTPUT', outputDir());

loadEnvironment($root);
loadFolders();

if (extension_loaded('xdebug')) {
    ini_set('xdebug.cli_color', 1);
    ini_set('xdebug.collect_params', 0);
    ini_set('xdebug.dump_globals', 'on');
    ini_set('xdebug.show_local_vars', 'on');
    ini_set('xdebug.max_nesting_level', 100);
    ini_set('xdebug.var_display_max_depth', 4);
}

unset($root);
