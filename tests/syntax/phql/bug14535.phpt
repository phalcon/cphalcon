--TEST--
phql_parse_phql - Using spaces in column alias
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\Model\Query\Lang;

var_dump(Lang::parsePHQL(<<<PHQL
SELECT
  People.firstName AS [First Name]
  People.lastName  AS [Last Name]
FROM
  People
PHQL
));
?>
--EXPECT--
