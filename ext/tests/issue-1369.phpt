--TEST--
Phalcon\Image\Adapter\Imagick::_pixelate: Conditional jump or move depends on uninitialised value(s) - https://github.com/phalcon/cphalcon/issues/1369 - run under Valgrind!
--SKIPIF--
<?php
include('skipif.inc');
if (!class_exists('imagick')) {
	die('skip imagick extension is required');
}
?>
--FILE--
<?php
$im = new \Phalcon\Image\Adapter\Imagick(__DIR__ . '/images/Neighborhood_watch_bw.png');
$im->getInternalImInstance()->setResourceLimit(6, 1);
$im->pixelate(10);
?>
--EXPECT--
