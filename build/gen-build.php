<?php

namespace Phalcon\Build;

require __DIR__ . '/_resource/Phalcon/bootstrap.php';

$rootDir = Util::normalize(__DIR__ . '/..');

$buildDir = Util::normalize(__DIR__);

if (version_compare(phpversion(), '7.0.0', '<')) {
    $buildDir .= '/php5';
} else {
    $buildDir .= '/php7';
}

$generator = new Generator($rootDir, $buildDir);
$generator->run();
