--TEST--
phql_parse_phql - Using FQCN for source model
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT
  AVG(inv_total) AS average
FROM
  [Phalcon\Test\Models\Invoices]
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
    array(1) {
      [0]=>
      array(3) {
        ["type"]=>
        int(354)
        ["column"]=>
        array(3) {
          ["type"]=>
          int(350)
          ["name"]=>
          string(3) "AVG"
          ["arguments"]=>
          array(1) {
            [0]=>
            array(2) {
              ["type"]=>
              int(355)
              ["name"]=>
              string(9) "inv_total"
            }
          }
        }
        ["alias"]=>
        string(7) "average"
      }
    }
    ["tables"]=>
    array(1) {
      ["qualifiedName"]=>
      array(2) {
        ["type"]=>
        int(355)
        ["name"]=>
        string(28) "Phalcon\Test\Models\Invoices"
      }
    }
  }
  ["id"]=>
  int(3)
}
