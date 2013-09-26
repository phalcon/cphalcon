--TEST--
Assets Manager doesn't use result of preceding css filter as the source for the next one - https://github.com/phalcon/cphalcon/issues/1198
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class TrimFilter implements Phalcon\Assets\FilterInterface
{
	public function filter($s)
	{
		return str_replace(array("\n", "\r", " ", "\t"), '', $s);
	}
}

class UppercaseFilter implements Phalcon\Assets\FilterInterface
{
	public function filter($s)
	{
		return strtoupper($s);
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$assets = new \Phalcon\Assets\Manager();
$assets->useImplicitOutput(false);
$css = $assets->collection('css');
$css->setTargetPath(__DIR__ . '/1198.css');
$css->setTargetUri('/1198.css');
$css->addCss(__DIR__ . '/assets/1198.css');
$css->addFilter(new UppercaseFilter());
$css->addFilter(new TrimFilter());
$css->join(true);
$assets->outputCss('css');
echo file_get_contents(__DIR__ . '/1198.css');
?>
--EXPECT--
A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}
--CLEAN--
<?php unlink(__DIR__ . '/1198.css'); ?>
