--TEST--
Phalcon\Config::merge - https://github.com/phalcon/cphalcon/issues/2046
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$cfg1 = new \Phalcon\Config\adapter\Ini(__DIR__ . '/config/2046a.ini');
$cfg2 = new \Phalcon\Config\adapter\Ini(__DIR__ . '/config/2046b.ini');
var_dump($cfg1->toArray());
var_dump($cfg2->toArray());
$cfg1->merge($cfg2);
var_dump($cfg1->toArray());
?>
--EXPECT--
array(1) {
  ["server"]=>
  array(3) {
    ["fileName"]=>
    string(16) "volny@head01.pem"
    ["type"]=>
    string(3) "PEM"
    ["keyPassword"]=>
    string(0) ""
  }
}
array(1) {
  ["server"]=>
  array(1) {
    ["keyPassword"]=>
    string(8) "PASSWORD"
  }
}
array(1) {
  ["server"]=>
  array(3) {
    ["fileName"]=>
    string(16) "volny@head01.pem"
    ["type"]=>
    string(3) "PEM"
    ["keyPassword"]=>
    string(8) "PASSWORD"
  }
}
