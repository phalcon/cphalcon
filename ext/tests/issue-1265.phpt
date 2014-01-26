--TEST--
MongoDB Request Injection Attacks (getQuery/getPost) - https://github.com/phalcon/cphalcon/issues/1265
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--GET--
string=hello&array[string]=world
--POST--
string=hello&array[string]=world
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();

$request = new \Phalcon\Http\Request();
$request->setDI($di);

var_dump($request->get('string', 'string'));
var_dump($request->get('string', 'string', null, true, true));

var_dump($request->get('array', 'string'));
var_dump($request->get('array', 'string', null, true, true));
echo PHP_EOL;

var_dump($request->getQuery('string', 'string'));
var_dump($request->getQuery('string', 'string', null, true, true));

var_dump($request->getQuery('array', 'string'));
var_dump($request->getQuery('array', 'string', null, true, true));
echo PHP_EOL;


var_dump($request->getPost('string', 'string'));
var_dump($request->getPost('string', 'string', null, true, true));

var_dump($request->getPost('array', 'string'));
var_dump($request->getPost('array', 'string', null, true, true));
?>
--EXPECT--
string(5) "hello"
string(5) "hello"
array(1) {
  ["string"]=>
  string(5) "world"
}
NULL

string(5) "hello"
string(5) "hello"
array(1) {
  ["string"]=>
  string(5) "world"
}
NULL

string(5) "hello"
string(5) "hello"
array(1) {
  ["string"]=>
  string(5) "world"
}
NULL
