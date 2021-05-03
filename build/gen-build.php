<?php

declare(strict_types=1);

use Phalcon\Build\Autoloader;
use Phalcon\Build\Util;
use Phalcon\Build\Generator;

require_once 'util/Util.php';
require_once 'util/Autoloader.php';

$rootDir = Util::normalize(__DIR__ . DIRECTORY_SEPARATOR . '../');
$currentDir = Util::normalize(__DIR__ . DIRECTORY_SEPARATOR);

$autoloader = new Autoloader($currentDir . DIRECTORY_SEPARATOR . 'util');
$autoloader->register();

// Convert all warnings to exceptions, so that we're explicitly notified, when filesystem operations fail
error_reporting(E_ALL);

set_error_handler(function ($errno, $errstr, $errfile, $errline) {
    throw new \Exception("{$errstr} on line {$errline} in {$errfile}", $errno);
});

$generator = new Generator($rootDir, $currentDir . DIRECTORY_SEPARATOR . 'phalcon');
$generator->run();
