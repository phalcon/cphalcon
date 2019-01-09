--TEST--
switch-case - Tests exception for nested switch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$template =<<<'EOF'
{% switch foo %}
  {% switch %}
  {% endswitch %}
{% endswitch %}
EOF;

$compiler = new Compiler();
$compiler->parse($template);
?>
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: A nested switch detected. There is no nested switch-case statements support in eval code on line 2 in %s009.php:12
Stack trace:
#0 %s009.php(12): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% switch foo %...')
#1 {main}
  thrown in %s009.php on line 12
