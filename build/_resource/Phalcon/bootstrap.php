<?php
namespace Phalcon\Build;

require_once 'Build/Util.php';
require_once 'Build/Autoloader.php';

$baseDir = Util::normalize(__DIR__ . '/..');
$autoloader = new Autoloader($baseDir);
$autoloader->register();

// Convert all warnings to exceptions, so that we're explicitly notified, when filesystem operations fail
error_reporting(E_ALL);
set_error_handler(function ($errno, $errstr, $errfile, $errline) {
    throw new \Exception("{$errstr} on line {$errline} in {$errfile}");
});
