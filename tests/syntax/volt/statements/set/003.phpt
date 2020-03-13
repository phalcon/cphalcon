--TEST--
set - Using “is” and ternary operator (#14476)
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
// https://github.com/phalcon/cphalcon/issues/14476#issuecomment-543138840
var_dump($compiler->parse("{% set myVar = someVar is defined ? 'yes' : 'no' %}"));
?>
--EXPECT--
array(1) {
  [0]=>
  array(2) {
    ["type"]=>
    int(306)
    ["assignments"]=>
    array(1) {
      [0]=>
      array(5) {
        ["variable"]=>
        array(4) {
          ["type"]=>
          int(265)
          ["value"]=>
          string(5) "myVar"
          ["file"]=>
          string(9) "eval code"
          ["line"]=>
          int(1)
        }
        ["op"]=>
        int(61)
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
  }
}
