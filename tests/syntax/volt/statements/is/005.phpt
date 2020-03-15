--TEST--
is - Perform conditional echo II (#14476)
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
// https://github.com/phalcon/cphalcon/issues/14476#issuecomment-560290546
var_dump($compiler->parse("{{ title is empty ? siteName : title }}"));
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
        int(386)
        ["left"]=>
        array(4) {
          ["type"]=>
          int(265)
          ["value"]=>
          string(5) "title"
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
        int(265)
        ["value"]=>
        string(8) "siteName"
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
        string(5) "title"
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
