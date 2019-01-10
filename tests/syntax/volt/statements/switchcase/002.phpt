--TEST--
switch-case - Tests recognize empty case clause
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse('{% switch foo%} {% case foo %} {% endswitch%}'));
?>
--EXPECT--
array(1) {
  [0]=>
  array(5) {
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
    ["case_clauses"]=>
    array(3) {
      [0]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(1) " "
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(1)
      }
      [1]=>
      array(4) {
        ["type"]=>
        int(412)
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
      [2]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(1) " "
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
