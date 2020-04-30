--TEST--
in - “in” have higher precedence than “and”
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip extension not loaded"; ?>
--FILE--
<?php
use Phalcon\Mvc\View\Engine\Volt\Compiler;

$compiler = new Compiler();

$volt = <<<EOF
{% if categoryIds is defined AND category['id'] in categoryIds %}
    checked
{% endif %}
EOF;

$exprs = $compiler->parse($volt);
echo $compiler->compileIf($exprs[0], false);
?>
--EXPECT--
<?php if (isset($categoryIds) && $this->isIncluded($category['id'], $categoryIds)) { ?>
    checked
<?php } ?>
