--TEST--
switch-case - Tests false detecting recognizion default as switch-case part
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$intermediate = parse_string('{% default %}');
var_dump($intermediate);
--EXPECT--
array(1) {
  [0]=>
  array(3) {
    ["type"]=>
    int(358)
    ["file"]=>
    string(9) "eval code"
    ["line"]=>
    int(1)
  }
}
