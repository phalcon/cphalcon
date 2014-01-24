--TEST--
'Indirect modification of overloaded property' notice in Phalcon\Session\Bag - https://github.com/phalcon/cphalcon/issues/1895
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--GET--
dummy=1
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$di['session']->start();
$namespace = new \Phalcon\Session\Bag('test');
$namespace->{'prop1'}['prop2'] = 'my value';
var_dump($namespace->{'prop1'});
?>
--EXPECT--
array(1) {
  ["prop2"]=>
  string(8) "my value"
}
