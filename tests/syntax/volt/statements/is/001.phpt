--TEST--
is - Perform test for equals
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse("{% if a is b %}c{% endif %}"));
?>
--EXPECT--
array(1) {
  [0]=>
  array(5) {
    ["type"]=>
    int(300)
    ["expr"]=>
    array(5) {
      ["type"]=>
      int(311)
      ["left"]=>
      array(4) {
        ["type"]=>
        int(265)
        ["value"]=>
        string(1) "a"
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
        string(1) "b"
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
    ["true_statements"]=>
    array(1) {
      [0]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(1) "c"
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(1)
      }
    }
    ["file"]=>
    string(9) "eval code"
    ["line"]=>
    int(1)
  }
}
