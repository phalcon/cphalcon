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

class DateTest extends PHPUnit_Framework_TestCase
{

	public function testGD()
	{
		$ret = \Phalcon\Utils\Date::offset('America/Chicago', 'GMT');

		$ret = \Phalcon\Utils\Date::seconds();

		$ret = \Phalcon\Utils\Date::minutes();

		$ret = \Phalcon\Utils\Date::hours(NULL);

		$ret = \Phalcon\Utils\Date::ampm(12);

		$ret = \Phalcon\Utils\Date::adjust(3, 'pm');

		$ret = \Phalcon\Utils\Date::days(4, 2010);

		$ret = \Phalcon\Utils\Date::months(\Phalcon\Utils\Date::MONTHS_LONG);
	}
}