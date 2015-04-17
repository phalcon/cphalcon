--TEST--
flashSession->getMessages(type, BOOLEAN remove) removed all messages - https://github.com/phalcon/cphalcon/issues/1575
--GET--
dummy=1
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$s  = new \Phalcon\Session\Adapter\Files(array('uniqueId' => 'issue-1575'));
var_dump($s->start());
$fs = $di->getShared('flashSession');
$fs->success('Success');
$fs->warning('Warning');
var_dump($fs->getMessages(null, false));
$fs->getMessages('success', true);
var_dump($fs->getMessages(null, false));
$fs->getMessages(null, true);
var_dump($fs->getMessages(null, false));
?>
--EXPECT--
bool(true)
array(2) {
  ["success"]=>
  array(1) {
    [0]=>
    string(7) "Success"
  }
  ["warning"]=>
  array(1) {
    [0]=>
    string(7) "Warning"
  }
}
array(1) {
  ["warning"]=>
  array(1) {
    [0]=>
    string(7) "Warning"
  }
}
array(0) {
}
