--TEST--
phql_parse_phql - [#16831] JOIN ON a column whose name starts with a keyword (NOT)
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT * FROM Robots r LEFT JOIN RobotsParts rp ON r.notes_id = rp.robots_id
PHQL
));
?>
--EXPECT--
array(3) {
  ["type"]=>
  int(309)
  ["select"]=>
  array(3) {
    ["columns"]=>
    array(1) {
      [0]=>
      array(1) {
        ["type"]=>
        int(352)
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
    ["joins"]=>
    array(4) {
      ["type"]=>
      int(361)
      ["qualified"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(11) "RobotsParts"
      }
      ["alias"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(2) "rp"
      }
      ["conditions"]=>
      array(3) {
        ["type"]=>
        int(61)
        ["left"]=>
        array(3) {
          ["type"]=>
          int(355)
          ["domain"]=>
          string(1) "r"
          ["name"]=>
          string(8) "notes_id"
        }
        ["right"]=>
        array(3) {
          ["type"]=>
          int(355)
          ["domain"]=>
          string(2) "rp"
          ["name"]=>
          string(9) "robots_id"
        }
      }
    }
  }
  ["id"]=>
  int(3)
}
