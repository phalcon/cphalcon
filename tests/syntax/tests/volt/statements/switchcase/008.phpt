--TEST--
switch-case - Tests recognize empty case clause with empty default clause
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$template =<<<EOF
{% switch username %}
    {% case "Jim" %}
        Hello username
    {% case "Nik" %}
        {{ username }}!
        {% break %}
    {% default %}
        Who are you?
{% endswitch %}
EOF;
$intermediate = parse_string($template);
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
      string(8) "username"
      ["file"]=>
      string(9) "eval code"
      ["line"]=>
      int(1)
    }
    ["case_clauses"]=>
    array(11) {
      [0]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(5) "
    "
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(2)
      }
      [1]=>
      array(4) {
        ["type"]=>
        int(412)
        ["expr"]=>
        array(4) {
          ["type"]=>
          int(260)
          ["value"]=>
          string(3) "Jim"
          ["file"]=>
          string(9) "eval code"
          ["line"]=>
          int(2)
        }
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(4)
      }
      [2]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(28) "
        Hello username
    "
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(4)
      }
      [3]=>
      array(4) {
        ["type"]=>
        int(412)
        ["expr"]=>
        array(4) {
          ["type"]=>
          int(260)
          ["value"]=>
          string(3) "Nik"
          ["file"]=>
          string(9) "eval code"
          ["line"]=>
          int(4)
        }
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(5)
      }
      [4]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(9) "
        "
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(5)
      }
      [5]=>
      array(4) {
        ["type"]=>
        int(359)
        ["expr"]=>
        array(4) {
          ["type"]=>
          int(265)
          ["value"]=>
          string(8) "username"
          ["file"]=>
          string(9) "eval code"
          ["line"]=>
          int(5)
        }
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(6)
      }
      [6]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(10) "!
        "
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(6)
      }
      [7]=>
      array(3) {
        ["type"]=>
        int(320)
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(7)
      }
      [8]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(5) "
    "
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(7)
      }
      [9]=>
      array(3) {
        ["type"]=>
        int(413)
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(9)
      }
      [10]=>
      array(4) {
        ["type"]=>
        int(357)
        ["value"]=>
        string(22) "
        Who are you?
"
        ["file"]=>
        string(9) "eval code"
        ["line"]=>
        int(9)
      }
    }
    ["file"]=>
    string(9) "eval code"
    ["line"]=>
    int(9)
  }
}
