--TEST--
is - Perform conditional echo (#14476)
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
// https://github.com/phalcon/cphalcon/issues/14476#issuecomment-557857901
var_dump($compiler->parse("{{ uploadedPhoto is user.avatar ? 'checked=\"checked\"' : '' }}"));
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
      array(5) {
        ["type"]=>
        int(311)
        ["left"]=>
        array(4) {
          ["type"]=>
          int(265)
          ["value"]=>
          string(13) "uploadedPhoto"
          ["file"]=>
          string(9) "eval code"
          ["line"]=>
          int(1)
        }
        ["right"]=>
        array(5) {
          ["type"]=>
          int(46)
          ["left"]=>
          array(4) {
            ["type"]=>
            int(265)
            ["value"]=>
            string(4) "user"
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
            string(6) "avatar"
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
      ["left"]=>
      array(4) {
        ["type"]=>
        int(260)
        ["value"]=>
        string(17) "checked="checked""
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
        string(0) ""
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
