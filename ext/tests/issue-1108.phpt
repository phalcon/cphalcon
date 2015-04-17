--TEST--
Phalcon\Session\AdapterInterface should be compatible with SessionHandlerInterface - https://github.com/phalcon/cphalcon/issues/1108
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_VERSION_ID < 50400) die('skip SessionHandlerInterface is available on PHP 5.4+'); ?>
--FILE--
<?php
abstract class X extends Phalcon\Session\Adapter implements \SessionHandlerInterface
{
}
?>
--EXPECT--
