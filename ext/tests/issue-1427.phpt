--TEST--
Phalcon\Http\Cookie::toString() throws exceptions - https://github.com/phalcon/cphalcon/pull/1427
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$_COOKIE['name'] = 'value';
$c = new \Phalcon\Http\Cookie('name');
$c->useEncryption(true);
echo $c, PHP_EOL;
?>
--EXPECTF--
Fatal error: A dependency injection object is required to access the '%s' service in %s on line %d
