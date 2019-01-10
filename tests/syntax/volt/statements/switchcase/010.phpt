--TEST--
switch-case - Tests exception for empty switch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$template =<<<'EOF'
{% switch %}
  {% case foo %}
  {% break %}
{% endswitch %}
EOF;

$compiler = new Compiler();
$compiler->parse($template);
?>
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Syntax error, unexpected token %} in eval code on line 1 in %s010.php:12
Stack trace:
#0 %s010.php(12): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% switch %}\n  ...')
#1 {main}
  thrown in %s010.php on line 12
