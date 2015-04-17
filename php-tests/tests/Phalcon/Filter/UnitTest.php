<?php
/**
 * UnitTest.php
 * Filter_UnitTest
 *
 * Tests the \Phalcon\Filter component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Filter;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;
use \Phalcon\Test\Filter\Helper\IPv4 as PhTestFilterIPv4;

use \Phalcon\Filter as PhFilter;

class UnitTest extends PhTestUnitTestCase
{
	/**
	 * Tests the filter with a string (US characters)
	 *
	 * @dataProvider providerSanitizeStringStringFilter
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStringStringFilter($source, $expected)
	{
		$filter = new \Phalcon\Filter();

		$reference = filter_var($source, FILTER_SANITIZE_STRING);
		$actual    = $filter->sanitize($source, 'string');

		$this->assertEquals($reference, $actual, 'Actual and reference values do not match');
		$this->assertEquals($expected, $actual, 'String filter with latin1 does not return correct data');
	}

	public function providerSanitizeStringStringFilter()
	{
		return array(
			array('abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>', 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+'),
			array('this is a string<{', 'this is a string'),
			array('{[<<whitin french quotes>>]}', '{[]}'),
		);
	}

	/**
	 * Tests the filter with a string (International characters)
	 *
	 * @dataProvider providerSanitizeStringUTF8StringFilter
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStringUTF8StringFilter($source, $expected)
	{
		$filter = new \Phalcon\Filter();

		$reference = filter_var($source, FILTER_SANITIZE_STRING);
		$actual    = $filter->sanitize($source, 'string');

		$this->assertEquals($reference, $actual, 'Actual and reference values do not match');
		$this->assertEquals($expected, $actual, 'String filter with UTF-8 does not return correct data');
	}

	public function providerSanitizeStringUTF8StringFilter()
	{
		return array(
			array('buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>', 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+'),
			array('buenos días 123 καλημέρα! 早安<', 'buenos días 123 καλημέρα! 早安'),
			array('{[<<buenos días 123 καλημέρα! 早安>>]}', '{[]}'),
		);
	}

	/**
	 * Tests the filter with an array filter (US characters)
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStringArrayFilter()
	{
		$filter = new PhFilter();

		$source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';

		$expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
		$actual   = $filter->sanitize($source, array('string'));

		$this->assertEquals(
			$expected,
			$actual,
			'String filter with latin does not return correct data'
		);
	}

	/**
	 * Tests the filter with an array filter (International characters)
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStringUTF8ArrayFilter()
	{
		$filter = new PhFilter();

		$source   = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';

		$expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
		$actual   = $filter->sanitize($source, array('string'));

		$this->assertEquals(
			$expected,
			$actual,
			'String filter with UTF8 does not return correct data'
		);
	}

	/**
	 * Tests the filter with a string (no filtering) (US characters)
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStringStringFilterValidString()
	{
		$filter = new PhFilter();

		$source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';

		$expected = $source;
		$actual   = $filter->sanitize($source, 'string');

		$this->assertEquals(
			$expected,
			$actual,
			'String filter with latin does not return correct data'
		);
	}

	/**
	 * Tests the filter with a string (no filtering) (International characters)
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStringUTF8StringFilterValidString()
	{
		$filter = new PhFilter();

		$source = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';

		$expected = $source;
		$actual   = $filter->sanitize($source, 'string');

		$this->assertEquals(
			$expected,
			$actual,
			'String filter with UTF8 does not return correct data'
		);
	}

	/**
	 * Tests the filter with an array filter (no filtering) (US characters)
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeArrayFilterValidString()
	{
		$filter = new PhFilter();

		$source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';

		$expected = $source;
		$actual   = $filter->sanitize($source, array('string'));

		$this->assertEquals(
			$expected,
			$actual,
			'String filter with latin does not return correct data'
		);
	}

	/**
	 * Tests the filter with an array filter (no filtering)
	 * (International characters)
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeUTF8ArrayFilterValidStringNoFilter()
	{
		$filter = new PhFilter();

		$source = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';

		$expected = $source;
		$actual   = $filter->sanitize($source, array('string'));

		$this->assertEquals(
			$expected,
			$actual,
			'String filter with UTF8 does not return correct data'
		);
	}

	/**
	 * Tests a custom filter IPv4
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeCustomIPv4FilterHex()
	{
		$filter = new PhFilter();

		$filter->add('ipv4', new PhTestFilterIPv4());

		$expected = null;
		$actual   = $filter->sanitize('00:1c:42:bf:71:22', 'ipv4');

		$this->assertEquals(
			$expected,
			$actual,
			'Hex Custom filter is not correct Hex'
		);
	}

	/**
	 * Tests a custom filter IPv4 IP
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeCustomIPv4FilterIP()
	{
		$filter = new PhFilter();

		$filter->add('ipv4', new PhTestFilterIPv4());

		$expected = '127.0.0.1';
		$actual   = $filter->sanitize('127.0.0.1', 'ipv4');

		$this->assertEquals(
			$expected,
			$actual,
			'Hex Custom filter is not correct IP'
		);
	}

	/**
	 * Tests a custom filter Lambda
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeCustomLambdaFalse()
	{
		$filter = new PhFilter();

		$filter->add(
			'md5',
			function ($value) {
				$filtered = preg_replace('/[^0-9a-f]/', '', $value);

				return (strlen($filtered) != 32) ? false : $value;
			}
		);

		$expected = false;
		$actual   = $filter->sanitize('Lladlad12', 'md5');

		$this->assertEquals(
			$expected,
			$actual,
			'Lambda Custom filter is not correct False'
		);
	}

	/**
	 * Tests a custom filter Lambda
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeCustomLambdaFalseTrue()
	{
		$filter = new PhFilter();

		$filter->add(
			'md5',
			function ($value) {
				$filtered = preg_replace('/[^0-9a-f]/', '', $value);

				return (strlen($filtered) != 32) ? false : $value;
			}
		);

		$expected = md5('why?');
		$actual   = $filter->sanitize(md5('why?'), 'md5');

		$this->assertEquals(
			$expected,
			$actual,
			'Lambda Custom filter is not correct True'
		);
	}

	/**
	 * Tests integers
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeIntegerInteger()
	{
		$filter = new PhFilter();

		$expected = '1000';
		$actual   = $filter->sanitize(1000, 'int');

		$this->assertEquals(
			$expected,
			$actual,
			'Integer filter integer is not correct'
		);
	}

	/**
	 * Tests integers
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeIntegerHex()
	{
		$filter = new PhFilter();

		$expected = '0xFFA';
		$actual   = $filter->sanitize(0xFFA, 'int');

		$this->assertEquals(
			$expected,
			$actual,
			'Integer filter hex is not correct'
		);
	}

	/**
	 * Tests integers
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeIntegerStringNumber()
	{
		$filter = new PhFilter();

		$expected = '1000';
		$actual   = $filter->sanitize('1000', 'int');

		$this->assertEquals(
			$expected,
			$actual,
			'Integer filter string number is not correct'
		);
	}

	/**
	 * Tests integers
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeIntegerString()
	{
		$filter = new PhFilter();

		$expected = '';
		$actual   = $filter->sanitize('lol', 'int');

		$this->assertEquals(
			$expected,
			$actual,
			'Integer filter string is not correct'
		);
	}

	/**
	 * Tests integers
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeIntegerStringCombined()
	{
		$filter = new PhFilter();

		$expected = '10001901';
		$actual   = $filter->sanitize('!100a019.01a', 'int');

		$this->assertEquals(
			$expected,
			$actual,
			'Integer filter string combined is not correct'
		);
	}

	/**
	 * Tests Floats
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeFloatFloat()
	{
		$filter = new PhFilter();

		$expected = '1000.01';
		$actual   = $filter->sanitize(1000.01, 'float');

		$this->assertEquals(
			$expected,
			$actual,
			'Float filter Float is not correct'
		);
	}

	/**
	 * Tests Floats
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeFloatHex()
	{
		$filter = new PhFilter();

		$expected = '0xFFA';
		$actual   = $filter->sanitize(0xFFA, 'float');

		$this->assertEquals(
			$expected,
			$actual,
			'Float filter hex is not correct'
		);
	}

	/**
	 * Tests Floats
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeFloatStringNumber()
	{
		$filter = new PhFilter();

		$expected = '1000.01';
		$actual   = $filter->sanitize('1000.01', 'float');

		$this->assertEquals(
			$expected,
			$actual,
			'Float filter string number is not correct'
		);
	}

	/**
	 * Tests Floats
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeFloatString()
	{
		$filter = new PhFilter();

		$expected = '';
		$actual   = $filter->sanitize('lol', 'float');

		$this->assertEquals(
			$expected,
			$actual,
			'Float filter string is not correct'
		);
	}

	/**
	 * Tests Floats
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeFloatStringCombined()
	{
		$filter = new PhFilter();

		$expected = '100019.01';
		$actual   = $filter->sanitize('!100a019.01a', 'float');

		$this->assertEquals(
			$expected,
			$actual,
			'Float filter string combined is not correct'
		);
	}

	/**
	 * Tests Email
	 *
	 * @dataProvider providerSanitizeEmail
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeEmail($source, $expected)
	{
		$filter = new \Phalcon\Filter();

		$reference = filter_var(str_replace("'", '', $source), FILTER_SANITIZE_EMAIL);
		$actual    = $filter->sanitize($source, 'email');

		$this->assertEquals($reference, $actual, 'Actual and reference values do not match');
		$this->assertEquals($expected, $actual, 'Email is not correct');
	}

	public function providerSanitizeEmail()
	{
		return array(
			array('some(one)@exa\\mple.com', 'someone@example.com'),
			array("'!(first.guy)\n\t@*my-domain**##.com.rx//", '!first.guy@*my-domain**##.com.rx'),
		);
	}

	/**
	 * Tests Trim
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeTrimLeft()
	{
		$filter = new PhFilter();

		$expected = 'Hello';
		$actual   = $filter->sanitize('  Hello', 'trim');

		$this->assertEquals(
			$expected,
			$actual,
			'Trim left is not correct'
		);
	}

	/**
	 * Tests Trim
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeTrimRight()
	{
		$filter = new PhFilter();

		$expected = 'Hello';
		$actual   = $filter->sanitize('Hello  ', 'trim');

		$this->assertEquals(
			$expected,
			$actual,
			'Trim right is not correct'
		);
	}

	/**
	 * Tests Trim
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeTrimBoth()
	{
		$filter = new PhFilter();

		$expected = 'Hello';
		$actual   = $filter->sanitize('  Hello  ', 'trim');

		$this->assertEquals(
			$expected,
			$actual,
			'Trim both is not correct'
		);
	}

	/**
	 * Tests Lower
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeLowerAll()
	{
		$filter = new PhFilter();

		$expected = 'hello';
		$actual   = $filter->sanitize('HELLO', 'lower');

		$this->assertEquals(
			$expected,
			$actual,
			'Lower all is not correct'
		);
	}

	/**
	 * Tests Lower
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeLowerMixed()
	{
		$filter = new PhFilter();

		$expected = 'hello';
		$actual   = $filter->sanitize('HeLlO', 'lower');

		$this->assertEquals(
			$expected,
			$actual,
			'Lower mixed is not correct'
		);
	}

	/**
	 * Tests Upper
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeUpperAll()
	{
		$filter = new PhFilter();

		$expected = 'HELLO';
		$actual   = $filter->sanitize('hello', 'upper');

		$this->assertEquals(
			$expected,
			$actual,
			'Upper all is not correct'
		);
	}

	/**
	 * Tests Upper
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeUpperMixed()
	{
		$filter = new PhFilter();

		$expected = 'HELLO';
		$actual   = $filter->sanitize('HeLlO', 'upper');

		$this->assertEquals(
			$expected,
			$actual,
			'Upper mixed is not correct'
		);
	}

	/**
	 * Tests Multiple filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeMultiple()
	{
		$filter = new PhFilter();

		$expected = 'lol';
		$actual   = $filter->sanitize('   lol<<   ', array('string', 'trim'));

		$this->assertEquals(
			$expected,
			$actual,
			'Multiple filter is not correct'
		);
	}

	/**
	 * Tests Alphanum filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeAlphanumInteger()
	{
		$filter = new PhFilter();

		$expected = '0';
		$actual   = $filter->sanitize(0, 'alphanum');

		$this->assertEquals(
			$expected,
			$actual,
			'Alphanum integer filter is not correct'
		);
	}

	/**
	 * Tests Alphanum filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeAlphanumNull()
	{
		$filter = new PhFilter();

		$expected = '';
		$actual   = $filter->sanitize(null, 'alphanum');

		$this->assertEquals(
			$expected,
			$actual,
			'Alphanum null filter is not correct'
		);
	}

	/**
	 * Tests Alphanum filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeAlphanumMixed()
	{
		$filter = new PhFilter();

		$expected = 'a5xkat1sXan';
		$actual   = $filter->sanitize('?a&5xka\tŧ?1-s.Xa[\n', 'alphanum');

		$this->assertEquals(
			$expected,
			$actual,
			'Alphanum mixed filter is not correct'
		);
	}

	/**
	 * Tests Striptags filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStriptagsHTML()
	{
		$filter = new PhFilter();

		$expected = 'Hello';
		$actual   = $filter->sanitize('<h1>Hello</h1>', 'striptags');

		$this->assertEquals(
			$expected,
			$actual,
			'Striptags HTML filter is not correct'
		);
	}

	/**
	 * Tests Striptags filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStriptagsBrokenHTML()
	{
		$filter = new PhFilter();

		$expected = 'Hello';
		$actual   = $filter->sanitize('<h1><p>Hello</h1>', 'striptags');

		$this->assertEquals(
			$expected,
			$actual,
			'Striptags broken HTML filter is not correct'
		);
	}

	/**
	 * Tests Striptags filters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-30
	 */
	public function testSanitizeStriptagsSingle()
	{
		$filter = new PhFilter();

		$expected = '';
		$actual   = $filter->sanitize('<', 'striptags');

		$this->assertEquals(
			$expected,
			$actual,
			'Striptags single HTML filter is not correct'
		);
	}

	public function testSanitizeArray()
	{
		$filter = new PhFilter();

		$expected = array('1', '2', '3');
		$actual   = $filter->sanitize(array(' 1 ', '  2', '3  '), 'trim');

		$this->assertEquals(
			$expected,
			$actual,
			'Filter an array is not correct'
		);
	}

	public function testSanitizeArrayMultipleFilters()
	{
		$filter = new PhFilter();

		$expected = array('1', '2', '3');
		$actual   = $filter->sanitize(array(' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>  '), array('trim', 'striptags'));

		$this->assertEquals(
			$expected,
			$actual,
			'Filter an array with multiples filters is not correct'
		);
	}
}
