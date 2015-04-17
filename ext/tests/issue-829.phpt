--TEST--
Parsing of ini files - https://github.com/phalcon/cphalcon/pull/829
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$config = new \Phalcon\Config\Adapter\Ini(__DIR__ . '/config/829-no-sections.ini');
var_dump($config->toArray());

$config = new \Phalcon\Config\Adapter\Ini(__DIR__ . '/config/829-with-empty-section.ini');
var_dump($config->toArray());
?>
--EXPECT--
array(2) {
  ["hoge"]=>
  string(4) "test"
  ["foo"]=>
  string(3) "bar"
}
array(3) {
  ["section"]=>
  array(1) {
    ["hoge"]=>
    string(4) "test"
  }
  ["empty"]=>
  array(0) {
  }
  ["test"]=>
  array(1) {
    ["foo"]=>
    string(3) "bar"
  }
}
