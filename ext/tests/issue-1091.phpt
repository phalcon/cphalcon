--TEST--
Phalcon\Http\Request::getRawBody() empties the raw body content - https://github.com/phalcon/cphalcon/issues/1091
--SKIPIF--
<?php include('skipif.inc'); ?>
--POST--
{"query":[["george","alan", "thomas"]]}
--FILE--
<?php
$request = new \Phalcon\Http\Request();
var_dump($request->getRawBody(), $request->getRawBody());
?>
--EXPECT--
string(39) "{"query":[["george","alan", "thomas"]]}"
string(39) "{"query":[["george","alan", "thomas"]]}"
