--TEST--
Phalcon 1.3.0 segfault - https://github.com/phalcon/cphalcon/issues/1567
--SKIPIF--
<?php
include('skipif.inc');
if (defined('PHP_ZTS') && PHP_ZTS) {
	die('skip ZTS is not affected');
}
?>
--FILE--
<?php
die("OK" . PHP_EOL);
?>
--EXPECT--
OK
