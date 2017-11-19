--TEST--
switch-case - Tests exception for empty switch
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
<?php if (!defined('PHP_MAJOR_VERSION') || PHP_MAJOR_VERSION == 5) print "skip PHP5 has different message format"; ?>
--FILE--
<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$template =<<<EOF
{% switch %}
  {% case foo %}
  {% break %}
{% endswitch %}
EOF;
$intermediate = parse_string($template);
var_dump($intermediate);
--EXPECTF--
Fatal error: Uncaught Phalcon\Mvc\View\Exception: Syntax error, unexpected token %} in eval code on line 1 in %sbootstrap.inc:45
Stack trace:
#0 %sbootstrap.inc(45): Phalcon\Mvc\View\Engine\Volt\Compiler->parse('{% switch %}\n  ...')
#1 %s010.php(9): parse_string('{% switch %}\n  ...')
#2 {main}
  thrown in %sbootstrap.inc on line 45
