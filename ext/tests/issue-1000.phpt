--TEST--
Phalcon + PHP-FPM = segfault - https://github.com/phalcon/cphalcon/issues/1000
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class Issue1000 extends \Phalcon\Config
{
	private $_section;

	public function __construct($file, $section = null)
	{
		$this->_section = $section;
	}
}

$t1 = new Issue1000('test');
$t2 = new Issue1000('test', 'test');
?>
--EXPECT--
