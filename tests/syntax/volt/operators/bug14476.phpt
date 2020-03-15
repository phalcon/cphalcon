--TEST--
ternary - Use with {{ }}
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse("{{ someVar is defined ? 'yes' : 'no' }}"));
?>
--EXPECT--
array(1) {
  [0]=>
  array(4) {
    ["type"]=>
    int(359)
    ["expr"]=>
    array(6) {
      ["type"]=>
      int(366)
      ["ternary"]=>
      array(4) {
        ["type"]=>
        int(363)
        ["left"]=>
        array(4) {
          ["type"]=>
          int(265)
          ["value"]=>
          string(7) "someVar"
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
      ["left"]=>
      array(4) {
        ["type"]=>
        int(260)
        ["value"]=>
        string(3) "yes"
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(1)
      }
      ["right"]=>
      array(4) {
        ["type"]=>
        int(260)
        ["value"]=>
        string(2) "no"
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
