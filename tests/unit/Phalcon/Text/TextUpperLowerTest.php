<?php
/**
 * TextUpperLowerTest.php
 * \Phalcon\Text\TextUpperLowerTest
 *
 * Tests the Phalcon\Text component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
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

namespace Phalcon\Tests\unit\Phalcon\Text;

use \PhalconTest\Text as PhTText;

class TextUpperLowerTest extends Helper\TextBase
{
	/**
	 * Tests the upper function
	 *
	 * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
	 * @since  2014-09-29
	 */
	public function testUpper()
	{
		$this->specify(
			"upper returns incorrect results",
			function () {

				expect(PhTText::upper('hello'))->equals('HELLO');
				expect(PhTText::upper('HELLO'))->equals('HELLO');
				expect(PhTText::upper('1234'))->equals('1234');
			}
		);
	}

	/**
	 * Tests the upper function for multi-bytes encoding
	 *
	 * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
	 * @since  2015-05-06
	 */
	public function testUpperMultiBytesEncoding()
	{
		$this->specify(
			"upper returns incorrect results",
			function () {

				expect(PhTText::upper('ПРИВЕТ МИР!'))->equals('ПРИВЕТ МИР!');
				expect(PhTText::upper('ПриВЕт Мир!'))->equals('ПРИВЕТ МИР!');
				expect(PhTText::upper('привет мир!'))->equals('ПРИВЕТ МИР!');

				expect(PhTText::upper('MÄNNER'))->equals('MÄNNER');
				expect(PhTText::upper('mÄnnER'))->equals('MÄNNER');
				expect(PhTText::upper('männer'))->equals('MÄNNER');
			}
		);
	}

	/**
	 * Tests the lower function
	 *
	 * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
	 * @since  2014-09-29
	 */
	public function testLower()
	{
		$this->specify(
			"lower returns incorrect results",
			function () {

				expect(PhTText::lower('hello'))->equals('hello');
				expect(PhTText::lower('HELLO'))->equals('hello');
				expect(PhTText::lower('1234'))->equals('1234');
			}
		);
	}

	/**
	 * Tests the lower function for multi-bytes encoding
	 *
	 * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
	 * @since  2015-05-06
	 */
	public function testLowerMultiBytesEncoding()
	{
		$this->specify(
			"lower returns incorrect results",
			function () {
				expect(PhTText::lower('привет мир!'))->equals('привет мир!');
				expect(PhTText::lower('ПриВЕт Мир!'))->equals('привет мир!');
				expect(PhTText::lower('ПРИВЕТ МИР!'))->equals('привет мир!');

				expect(PhTText::lower('männer'))->equals('männer');
				expect(PhTText::lower('mÄnnER'))->equals('männer');
				expect(PhTText::lower('MÄNNER'))->equals('männer');
			}
		);
	}
}
