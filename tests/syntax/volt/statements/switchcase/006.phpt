--TEST--
switch-case - Tests exception for lack of switch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
$compiler->parse('{% case foo %}');
?>
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Unexpected CASE in eval code on line 1 in %s006.php:5
Stack trace:
#0 %s006.php(5): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% case foo %}')
#1 {main}
  thrown in %s006.php on line 5
