--TEST--
Default values in Phalcon\Http\Request::getQuery() - https://github.com/phalcon/cphalcon/issues/1226
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--GET--
id=1&num=a1a&age=aa&phone=
--POST--
id=1&num=a1a&age=aa&phone=
--FILE--
<?php
$di = new Phalcon\DI\FactoryDefault();

$request = new \Phalcon\Http\Request();
$request->setDI($di);

var_dump($request->get('id', 'int', 100));
var_dump($request->get('num', 'int', 100));
$t = $request->get('age', 'int', 100);
var_dump(empty($t));
var_dump($request->get('age', 'int', 100, true));
$t = $request->get('phone', 'int', 100);
var_dump(empty($t));
var_dump($request->get('phone', 'int', 100, true));
echo PHP_EOL;

var_dump($request->getQuery('id', 'int', 100));
var_dump($request->getQuery('num', 'int', 100));
$t = $request->getQuery('age', 'int', 100);
var_dump(empty($t));
var_dump($request->getQuery('age', 'int', 100, true));
$t = $request->getQuery('phone', 'int', 100);
var_dump(empty($t));
var_dump($request->getQuery('phone', 'int', 100, true));
echo PHP_EOL;

var_dump($request->getPost('id', 'int', 100));
var_dump($request->getPost('num', 'int', 100));
$t = $request->getPost('age', 'int', 100);
var_dump(empty($t));
var_dump($request->getPost('age', 'int', 100, true));
$t = $request->getPost('phone', 'int', 100);
var_dump(empty($t));
var_dump($request->getPost('phone', 'int', 100, true));
?>
--EXPECT--
string(1) "1"
string(1) "1"
bool(true)
int(100)
bool(true)
int(100)

string(1) "1"
string(1) "1"
bool(true)
int(100)
bool(true)
int(100)

string(1) "1"
string(1) "1"
bool(true)
int(100)
bool(true)
int(100)
