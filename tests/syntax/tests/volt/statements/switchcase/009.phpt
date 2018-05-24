--TEST--
switch-case - Tests exception for nested switch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
<?php if (!defined('PHP_MAJOR_VERSION') || PHP_MAJOR_VERSION == 5) print "skip PHP5 has different message format"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$template =<<<EOF
{% switch foo %}
  {% switch %}
  {% endswitch %}
{% endswitch %}
EOF;
parse_string($template);
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: A nested switch detected. There is no nested switch-case statements support in eval code on line 2 in %sbootstrap.inc:45
Stack trace:
#0 %sbootstrap.inc(45): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% switch foo %...')
#1 %s009.php(9): parse_string('{% switch foo %...')
#2 {main}
  thrown in %sbootstrap.inc on line 45
