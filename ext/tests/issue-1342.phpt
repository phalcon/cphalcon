--TEST--
Implement Phalcon\Flash\Session::isset() - https://github.com/phalcon/cphalcon/issues/1342
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--GET--
dummy
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$f  = $di->getShared('flashSession');
$s  = new \Phalcon\Session\Adapter\Files(array('uniqueId' => 'issue-1342'));
var_dump($s->start());
var_dump($f->has('type'));
$f->message('type', 'message');
var_dump($f->has('type'));
?>
--EXPECT--
bool(true)
bool(false)
bool(true)
