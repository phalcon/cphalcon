--TEST--
phql_parse_phql - Using spaces in column alias
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT
  People.firstName AS [First Name],
  People.lastName  AS [Last Name]
FROM
  People
PHQL
));
?>
--EXPECT--
array(3) {
  ["type"]=>
  int(309)
  ["select"]=>
  array(2) {
    ["columns"]=>
    array(2) {
      [0]=>
      array(3) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(3) {
          ["type"]=>
          int(355)
          ["domain"]=>
          string(6) "People"
          ["name"]=>
          string(9) "firstName"
        }
        ["alias"]=>
        string(10) "First Name"
      }
      [1]=>
      array(3) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(3) {
          ["type"]=>
          int(355)
          ["domain"]=>
          string(6) "People"
          ["name"]=>
          string(8) "lastName"
        }
        ["alias"]=>
        string(9) "Last Name"
      }
    }
    ["tables"]=>
    array(1) {
      ["qualifiedName"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(6) "People"
      }
    }
  }
  ["id"]=>
  int(3)
}
