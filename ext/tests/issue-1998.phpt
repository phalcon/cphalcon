--TEST--
Volt: `if` generates a notice when the body is empty - https://github.com/phalcon/cphalcon/issues/1998
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
echo $volt->compileString('{% if true %}{% endif %}' . PHP_EOL);
?>
--EXPECT--
<?php if (true) { ?><?php } ?>
