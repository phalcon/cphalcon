--TEST--
switch-case - Tests recognize empty switch statements
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$intermediate = parse_string('{% switch foo %}{% endswitch %}');
var_dump($intermediate);
--EXPECT--
array(1) {
  [0]=>
  array(4) {
    ["type"]=>
    int(411)
    ["expr"]=>
    array(4) {
      ["type"]=>
      int(265)
      ["value"]=>
      string(3) "foo"
      ["file"]=>
      string(9) "eval code"
      ["line"]=>
      int(1)
    }
    ["file"]=>
    string(9) "eval code"
    ["line"]=>
    int(1)
  }
}
