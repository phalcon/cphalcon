--TEST--
set - Setting a value
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
var_dump($compiler->parse("{%- set defaultClass = 'form-control ' -%}"));
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
          string(12) "defaultClass"
          ["file"]=>
          string(9) "eval code"
          ["line"]=>
          int(1)
        }
        ["op"]=>
        int(61)
        ["expr"]=>
        array(4) {
          ["type"]=>
          int(260)
          ["value"]=>
          string(13) "form-control "
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
