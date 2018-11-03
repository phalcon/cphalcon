--TEST--
switch-case - Tests false detecting recognizion default as switch-case part
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
<?php if (PHP_MAJOR_VERSION == 5) print "skip PHP5 has different message format"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

parse_string('{% default %}');
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Syntax error, unexpected token DEFAULT(default) in eval code on line 1 in %sbootstrap.inc:45
Stack trace:
#0 %sbootstrap.inc(45): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% default %}')
#1 %s007.php(3): parse_string('{% default %}')
#2 {main}
  thrown in %sbootstrap.inc on line 45
