--TEST--
phql_parse_phql - Select with betwen
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT column_name
FROM table_name
WHERE column_name BETWEEN value1 AND value2
PHQL
));
?>
--EXPECT--
array(4) {
  ["type"]=>
  int(309)
  ["select"]=>
  array(2) {
    ["columns"]=>
    array(1) {
      [0]=>
      array(2) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(2) {
          ["type"]=>
          int(355)
          ["name"]=>
          string(11) "column_name"
        }
      }
    }
    ["tables"]=>
    array(1) {
      ["qualifiedName"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(10) "table_name"
      }
    }
  }
  ["where"]=>
  array(3) {
    ["type"]=>
    int(331)
    ["left"]=>
    array(2) {
      ["type"]=>
      int(355)
      ["name"]=>
      string(11) "column_name"
    }
    ["right"]=>
    array(3) {
      ["type"]=>
      int(266)
      ["left"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(6) "value1"
      }
      ["right"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(6) "value2"
      }
    }
  }
  ["id"]=>
  int(3)
}
