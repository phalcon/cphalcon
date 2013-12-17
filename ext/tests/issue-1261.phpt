--TEST--
Ability to restrict the maximum password length for Phalcon\Security::checkHash() - https://github.com/phalcon/cphalcon/pull/1261
--SKIPIF--
<?php
	include('skipif.inc');
	if (!extension_loaded('openssl')) {
		die('skip openssl extension is not available');
	}
?>
--FILE--
<?php
$s = new \Phalcon\Security();
$hash = $s->hash('password', 10);
echo var_export((bool)$s->checkHash('password', $hash), 0), PHP_EOL;
echo var_export((bool)$s->checkHash('password', $hash, 0), 0), PHP_EOL;
echo var_export((bool)$s->checkHash('password', $hash, 8), 0), PHP_EOL;
echo var_export((bool)$s->checkHash('password', $hash, 7), 0), PHP_EOL;
?>
--EXPECT--
true
true
true
false
