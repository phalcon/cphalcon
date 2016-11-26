<?php

namespace Phalcon\Build;

require __DIR__ . '/_resource/Phalcon/bootstrap.php';

$rootDir  = Util::normalize(__DIR__ . DIRECTORY_SEPARATOR . '..');
$buildDir = Util::normalize(__DIR__ . DIRECTORY_SEPARATOR . 'php' . PHP_MAJOR_VERSION);

$generator = new Generator($rootDir, $buildDir);

$generator->run();
