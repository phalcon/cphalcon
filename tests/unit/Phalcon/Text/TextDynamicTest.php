<?php
/**
 * TextDynamicTest.php
 * \Phalcon\Text\TextDynamicTest
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


class TextDynamicTest extends Helper\TextBase
{
	/**
	 * Tests the dynamic function
	 *
	 * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
	 * @since  2015-07-01
	 */
	public function testTextDynamicString()
	{
		$this->specify(
			"dynamic do not return the correct string",
			function () {

				$actual = PhTText::dynamic('{Hi|Hello}, my name is a Bob!');
				expect($actual)->notContains('{');
				expect($actual)->notContains('}');

				expect(preg_match('/^(Hi|Hello), my name is a Bob!$/', $actual))->equals(1);
			}
		);
	}

	/**
	 * Tests the dynamic function
	 *
	 * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
	 * @since  2015-07-01
	 */
	public function testTextDynamicStringCustomDelimeter()
	{
		$actual = PhTText::dynamic('(Hi|Hello), my name is a Bob!', '(', ')');
		expect($actual)->notContains('(');
		expect($actual)->notContains(')');

		expect(preg_match('/^(Hi|Hello), my name is a Bob!$/', $actual))->equals(1);
	}
}