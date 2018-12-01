--TEST--
switch-case - Tests recognize empty case clause with empty default clause
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$intermediate = parse_string('{% switch foo%} {% case foo %} {% default %} {% endswitch%}');
var_dump($intermediate);
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
    array(5) {
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
      [3]=>
      array(3) {
        ["type"]=>
        int(413)
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(1)
      }
      [4]=>
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
