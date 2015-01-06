--TEST--
Uncaught exception causes memory corruption on shutdown - https://github.com/phalcon/cphalcon/issues/2829
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
throw new \Exception("Hi!");
?>
--EXPECTF--
Fatal error: Uncaught exception 'Exception' with message 'Hi!' in %s:%d
Stack trace:
#0 {main}
  thrown in %s on line %d
