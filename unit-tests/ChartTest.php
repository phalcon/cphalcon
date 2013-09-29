<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
	+------------------------------------------------------------------------+
	| This source file is subject to the New BSD License that is bundled     |
	| with this package in the file docs/LICENSE.txt.                        |
	|                                                                        |
	| If you did not receive a copy of the license and are unable to         |
	| obtain it through the world-wide-web, please send an email             |
	| to license@phalconphp.com so we can send you a copy immediately.       |
	+------------------------------------------------------------------------+
	| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
	|          Eduar Carvajal <eduar@phalconphp.com>                         |
	+------------------------------------------------------------------------+
*/

class ChartTest extends PHPUnit_Framework_TestCase
{

	public function testQRencode()
	{
		@unlink('unit-tests/assets/qr.png');

		$str = 'Phalcon is web framework';

		try {
			$qr = new \Phalcon\Chart\QRcode();
			$ret = $qr->generate($str);
			$this->assertTrue($ret);

			if ($ret) {
				$data = $qr->render();
				$this->assertTrue(strlen($ret) > 0);

				$ret = $qr->save('unit-tests/assets/qr.png');
				$this->assertTrue($ret);

				$ret = $qr->scan('unit-tests/assets/qr.png');
				$this->assertEquals($ret, $str);

				$data = $qr->render(NULL, NULL, 'FFCC00', '000000');
				$this->assertTrue(strlen($ret) > 0);

				$ret = $qr->save('unit-tests/assets/qr.png', NULL, NULL, 'FFCC00', '000000');
				$this->assertTrue($ret);
			}
		} catch (Exception $e) {
		}
	}
}