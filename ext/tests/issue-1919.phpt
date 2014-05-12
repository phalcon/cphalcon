--TEST--
Phalcon\Crypt\decryptBase64() modifies its argument - https://github.com/phalcon/cphalcon/issues/1919
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (!extension_loaded('mcrypt')) die('skip mcrypt extension is required'); ?>
--FILE--
<?php
$crypt   = new \Phalcon\Crypt();
$source  = 'Life is much too short to be intoxicated';
$key     = 'very secret key ';

do {
	$dest = $crypt->encryptBase64($source, $key, true);
} while (false === strpos($dest, '-'));
$copy = (string)$dest;
$crypt->decryptBase64($dest, $key, true);

var_dump($dest === $copy);
?>
--EXPECT--
bool(true)
