<?php

use Phalcon\Mvc\View\Engine\Volt\Compiler;

// turn on all errors
error_reporting(-1);

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

setlocale(LC_ALL, 'en_US.utf-8');
set_time_limit(-1);

if (!ini_get('date.timezone')) {
    ini_set('date.timezone', 'UTC');
}

clearstatcache();

if (extension_loaded('xdebug')) {
    ini_set('xdebug.cli_color', 1);
    ini_set('xdebug.collect_params', 0);
    ini_set('xdebug.dump_globals', 'on');
    ini_set('xdebug.show_local_vars', 'on');
    ini_set('xdebug.max_nesting_level', 100);
    ini_set('xdebug.var_display_max_depth', 4);
}


define('SYNTAX_TESTS_ROOT', __DIR__);
define('SYNTAX_TESTS_SOURCE', __DIR__ . DIRECTORY_SEPARATOR . 'source');

function syntax_source($path = '') {
    if (empty($path) === false) {
        $normalized = str_replace(['\\', '/'], DIRECTORY_SEPARATOR, $path);
        $path = ltrim($normalized, DIRECTORY_SEPARATOR);
  }

  return SYNTAX_TESTS_SOURCE . DIRECTORY_SEPARATOR . $path;
}

function parse_string($string) {
    $compiler = new Compiler();

    return $compiler->parse($string);
}
