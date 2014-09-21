--TEST--
Segmentation fault in zim_Phalcon_Http_Request_getBasicAuth - https://github.com/phalcon/cphalcon/issues/2819
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$request = new \Phalcon\Http\Request();
$_SERVER['PHP_AUTH_USER'] = '123456';
var_dump($request->getBasicAuth());
?>
--EXPECT--
array(2) {
  ["username"]=>
  string(6) "123456"
  ["password"]=>
  string(0) ""
}
