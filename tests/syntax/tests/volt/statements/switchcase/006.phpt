--TEST--
switch-case - Tests exception for lack of switch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
<?php if (!defined('PHP_MAJOR_VERSION') || PHP_MAJOR_VERSION == 5) print "skip PHP5 has different message format"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

parse_string('{% case foo %}');
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Unexpected CASE in eval code on line 1 in %sbootstrap.inc:45
Stack trace:
#0 %sbootstrap.inc(45): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% case foo %}')
#1 %s006.php(3): parse_string('{% case foo %}')
#2 {main}
  thrown in %sbootstrap.inc on line 45
