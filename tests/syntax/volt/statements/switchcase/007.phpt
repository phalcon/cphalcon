--TEST--
switch-case - Tests false detecting recognizion default as switch-case part
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
$compiler->parse('{% default %}');
?>
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Syntax error, unexpected token DEFAULT(default) in eval code on line 1 in %s007.php:5
Stack trace:
#0 %s007.php(5): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% default %}')
#1 {main}
  thrown in %s007.php on line 5
