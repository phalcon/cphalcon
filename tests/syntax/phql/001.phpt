--TEST--
phql_parse_phql - Select with limit
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT r.* FROM Robots r LIMIT 10
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
        int(353)
        ["column"]=>
        string(1) "r"
      }
    }
    ["tables"]=>
    array(2) {
      ["qualifiedName"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(6) "Robots"
      }
      ["alias"]=>
      string(1) "r"
    }
  }
  ["limit"]=>
  array(1) {
    ["number"]=>
    array(2) {
      ["type"]=>
      int(258)
      ["value"]=>
      string(2) "10"
    }
  }
  ["id"]=>
  int(3)
}
