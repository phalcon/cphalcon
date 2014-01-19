<?php
namespace Phalcon\Build;

require __DIR__ . '/_resource/Phalcon/bootstrap.php';

$rootDir = Util::normalize(__DIR__ . '/..');
$buildDir = Util::normalize(__DIR__);
$generator = new Generator($rootDir, $buildDir);
$generator->run();
