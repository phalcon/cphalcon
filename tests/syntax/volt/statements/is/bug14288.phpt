--TEST--
is - Tests for false-positive matching
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse("{{ foo().is('bar') }}"));
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
      int(350)
      ["name"]=>
      array(5) {
        ["type"]=>
        int(46)
        ["left"]=>
        array(4) {
          ["type"]=>
          int(350)
          ["name"]=>
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
      ["arguments"]=>
      array(1) {
        [0]=>
        array(3) {
          ["expr"]=>
          array(4) {
            ["type"]=>
            int(260)
            ["value"]=>
            string(3) "bar"
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
