--TEST--
Memory leaks due to PHALCON_SEPARATE_PARAM_NMO - https://github.com/phalcon/cphalcon/issues/1345
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$s = new \Phalcon\Security();
$f1 = "10";
$f2 = $f1;
$s->setWorkFactor($f2);
$hash = $s->hash('password', null);

$d = new \Phalcon\Debug();
$f1 = 1;
$f2 = $f1;
$d->setCharset($f2);

$f1 = "1";
$f2 = $f1;
$d->setLinesBeforeContext($f2);
$d->setLinesAfterContext($f2);

$b = new \Phalcon\Mvc\Model\Query\Builder();
$b->distinct($f2);

$l = new \Phalcon\Logger\Formatter\FirePhp();
$l->setShowBacktrace($f2);

echo "OK", PHP_EOL;
?>
--EXPECT--
OK
