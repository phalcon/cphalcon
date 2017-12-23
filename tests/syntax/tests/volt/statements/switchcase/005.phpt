--TEST--
switch-case - Tests exception for lack of endswitch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
<?php if (!defined('PHP_MAJOR_VERSION') || PHP_MAJOR_VERSION == 5) print "skip PHP5 has different message format"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

parse_string('{% switch foo %}');
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Syntax error, unexpected EOF in eval code, there is a 'switch' block without 'endswitch' in %sbootstrap.inc:45
Stack trace:
#0 %sbootstrap.inc(45): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% switch foo %...')
#1 %s005.php(3): parse_string('{% switch foo %...')
#2 {main}
  thrown in %sbootstrap.inc on line 45
