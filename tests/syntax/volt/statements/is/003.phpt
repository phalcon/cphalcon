--TEST--
is - Using as an object property and {{ }}
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse("{{ object.is }}"));
?>
--EXPECT--
array(1) {
  [0]=>
  array(4) {
    ["type"]=>
    int(359)
    ["expr"]=>
    array(5) {
      ["type"]=>
      int(46)
      ["left"]=>
      array(4) {
        ["type"]=>
        int(265)
        ["value"]=>
        string(6) "object"
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(1)
      }
      ["right"]=>
      array(4) {
        ["type"]=>
        int(265)
        ["value"]=>
        string(2) "is"
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
    ["file"]=>
    string(9) "eval code"
    ["line"]=>
    int(1)
  }
}
