--TEST--
Make sure Phalcon\Exception inheritance chain is correct - https://github.com/phalcon/cphalcon/issues/1770
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$e = new \Phalcon\Loader\Exception();
assert(!($e instanceof \Phalcon\Di\Exception));
assert($e instanceof \Phalcon\Exception);

$e = new \Phalcon\Forms\Exception();
assert(!($e instanceof \Phalcon\Di\Exception));
assert($e instanceof \Phalcon\Exception);

$e = new \Phalcon\Http\Request\Exception();
assert(!($e instanceof \Phalcon\Di\Exception));
assert($e instanceof \Phalcon\Exception);
?>
--EXPECT--
