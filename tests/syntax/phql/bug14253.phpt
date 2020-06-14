--TEST--
phql_parse_phql - Select with betwen
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT Id, ProductName, UnitPrice
FROM Product
WHERE UnitPrice NOT BETWEEN 5 AND 100
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
    array(3) {
      [0]=>
      array(2) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(2) {
          ["type"]=>
          int(355)
          ["name"]=>
          string(2) "Id"
        }
      }
      [1]=>
      array(2) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(2) {
          ["type"]=>
          int(355)
          ["name"]=>
          string(11) "ProductName"
        }
      }
      [2]=>
      array(2) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(2) {
          ["type"]=>
          int(355)
          ["name"]=>
          string(9) "UnitPrice"
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
        string(7) "Product"
      }
    }
  }
  ["where"]=>
  array(3) {
    ["type"]=>
    int(332)
    ["left"]=>
    array(2) {
      ["type"]=>
      int(355)
      ["name"]=>
      string(9) "UnitPrice"
    }
    ["right"]=>
    array(3) {
      ["type"]=>
      int(266)
      ["left"]=>
      array(2) {
        ["type"]=>
        int(258)
        ["value"]=>
        string(1) "5"
      }
      ["right"]=>
      array(2) {
        ["type"]=>
        int(258)
        ["value"]=>
        string(3) "100"
      }
    }
  }
  ["id"]=>
  int(3)
}
