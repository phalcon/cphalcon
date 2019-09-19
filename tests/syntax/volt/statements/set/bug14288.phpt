--TEST--
set - Tests for false-positive matching
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse("{{ cookie().set('key', 'value') }}"));
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
            string(6) "cookie"
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
          string(3) "set"
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
      array(2) {
        [0]=>
        array(3) {
          ["expr"]=>
          array(4) {
            ["type"]=>
            int(260)
            ["value"]=>
            string(3) "key"
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
        [1]=>
        array(3) {
          ["expr"]=>
          array(4) {
            ["type"]=>
            int(260)
            ["value"]=>
            string(5) "value"
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
