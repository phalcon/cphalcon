--TEST--
Regression in /ext/tests/issue-680.phpt - https://github.com/phalcon/cphalcon/issues/1791
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$_PUT['string'] = 'hello';
$_PUT['array']  = array('string' => 'world');

$di = new \Phalcon\DI\FactoryDefault();

$request = new \Phalcon\Http\Request();
$request->setDI($di);

var_dump($request->getPut('string', 'string'));
var_dump($request->getPut('string', 'string', null, true, true));

var_dump($request->getPut('array', 'string'));
var_dump($request->getPut('array', 'string', null, true, true));
echo PHP_EOL;

var_dump($request->hasPut('string'));
var_dump($request->hasPut('array'));
var_dump($request->hasPut('object'));

?>
--EXPECT--
string(5) "hello"
string(5) "hello"
array(1) {
  ["string"]=>
  string(5) "world"
}
NULL

bool(true)
bool(true)
bool(false)
