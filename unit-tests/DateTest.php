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
	public function test()
	{
		$seconds_data = array(
			'00', '01', '02', '03', '04', '05', '06', '07', '08', '09',
			'10', '11', '12', '13', '14', '15', '16', '17', '18', '19',
			'20', '21', '22', '23', '24', '25', '26', '27', '28', '29',
			'30', '31', '32', '33', '34', '35', '36', '37', '38', '39',
			'40', '41', '42', '43', '44', '45', '46', '47', '48', '49', 
			'50', '51', '52', '53', '54', '55', '56', '57', '58', '59'
		);

		$minutes_data = array(
			0 => '00', 5 => '05', 10 => '10', 15 => '15', 20 => '20', 25 => '25', 30 => '30', 35 => '35', 40 => '40', 45 => '45', 50 => '50', 55 => '55'
		);

		$hours_data = array(
			1 => '01', 2 => '02', 3 => '03', 4 => '04', 5 => '05', 6 => '06', 7 => '07', 8 => '08', 9 => '09', 10 => '10', 11 => '11', 12 => '12'
		);
		
		$days_data = array(
			1 => '01', 2 => '02', 3 => '03', 4 => '04', 5 => '05', 6 => '06', 7 => '07', 8 => '08', 9 => '09', 10 => '10',
			11 => '11', 12 => '12', 13 => '13', 14 => '14', 15 => '15', 16 => '16', 17 => '17', 18 => '18', 19 => '19', 20 => '20',
			21 => '21', 22 => '22', 23 => '23', 24 => '24', 25 => '25', 26 => '26', 27 => '27', 28 => '28', 29 => '29', 30 => '30'
		);

		$months_data = array(
			1 => "January",
			2 => "February",
			3 => "March",
			4 => "April",
			5 => "May",
			6 => "June",
			7 => "July",
			8 => "August",
			9 => "September",
			10 => "October",
			11 => "November",
			12 => "December"
		);

		$ret = \Phalcon\Utils\Date::offset('America/Chicago', 'GMT');
		$this->assertEquals($ret, -18000);

		$ret = \Phalcon\Utils\Date::seconds();
		$this->assertEquals($ret, $seconds_data);

		$ret = \Phalcon\Utils\Date::minutes();
		$this->assertEquals($ret, $minutes_data);

		$ret = \Phalcon\Utils\Date::hours(NULL);
		$this->assertEquals($ret, $hours_data);

		$ret = \Phalcon\Utils\Date::ampm(12);
		$this->assertEquals($ret, 'PM');

		$ret = \Phalcon\Utils\Date::adjust(3, 'pm');
		$this->assertEquals($ret, '15');

		$ret = \Phalcon\Utils\Date::days(4, 2010);
		$this->assertEquals($ret, $days_data);

		$ret = \Phalcon\Utils\Date::months(\Phalcon\Utils\Date::MONTHS_LONG);
		$this->assertEquals($ret, $months_data);

		$ret = \Phalcon\Utils\Date::years(2010, 2013);
		$this->assertEquals($ret, array(2010 => '2010', 2011 => '2011', 2012 => '2012', 2013 => '2013'));

		$ret = \Phalcon\Utils\Date::span(60, 182, 'minutes');
		$this->assertEquals($ret, 2);

		$ret = \Phalcon\Utils\Date::fuzzy_span(time() - 160);
		$this->assertEquals($ret, 'a few minutes ago');

		$ret = \Phalcon\Utils\Date::unix2dos(1377306618);
		$this->assertEquals($ret, 1125665097);

		$ret = \Phalcon\Utils\Date::dos2unix(1125665097);
		$this->assertEquals($ret, 1377306618);

		$ret = \Phalcon\Utils\Date::formatted_time('@1377304305');
		$this->assertEquals($ret, '2013-08-24 00:31:45');
	}
}