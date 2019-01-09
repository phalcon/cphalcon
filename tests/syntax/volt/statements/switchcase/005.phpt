--TEST--
switch-case - Tests exception for lack of endswitch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();
$compiler->parse('{% switch foo %}');
?>
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Syntax error, unexpected EOF in eval code, there is a 'switch' block without 'endswitch' in %s005.php:5
Stack trace:
#0 %s005.php(5): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% switch foo %...')
#1 {main}
  thrown in %s005.php on line 5
