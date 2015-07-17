<?php
/**
 * UnitTest.php
 * \Phalcon\Translate\Adapter\NativeArray\UnitTest
 *
 * Tests the \Phalcon\Translate\Adapter\NativeArray component
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

namespace Phalcon\Test\Translate\Interpolator\IndexedArray;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Translate\Exception as PhTranslateException;

class UnitTest extends PhTestUnitTestCase
{
	/**
	 * Tests IndexedArray interpolator
	 *
	 * @author Paulius Petronis <paulius@petronis.eu>
	 * @since  2015-07-13
	 */
	public function testIndexedArrayReplace()
	{
		$interpolator = new \Phalcon\Translate\Interpolator\IndexedArray();

		$stringFrom = 'Hello, %s %s %s';
		$replacedString = $interpolator->replacePlaceholders($stringFrom, array('John', 'D.', 'Doe'));
		$expected = 'Hello, John D. Doe!';

		$this->assertEquals($replacedString, $expected);
	}

	/**
	 * Tests AssociativeArray interpolator
	 *
	 * @author Paulius Petronis <paulius@petronis.eu>
	 * @since  2015-07-13
	 */
	public function testAssociativeArrayReplace()
	{
		$interpolator = new \Phalcon\Translate\Interpolator\AssociativeArray();

		$stringFrom = 'Hello, %fname% %mname% %lname%!';
		$replacedString = $interpolator->replacePlaceholders($stringFrom, array('fname' => 'John', 'lname' => 'Doe', 'mname' => 'D.'));
		$expected = 'Hello, John D. Doe!';

		$this->assertEquals($replacedString, $expected);
	}
}
