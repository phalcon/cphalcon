<?php
/**
 * TextConcatTest.php
 * \Phalcon\Text\TextCamelizeTest
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


class TextConcatTest extends Helper\TextBase
{
	/**
	 * Tests the concat function
	 *
	 * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
	 * @since  2015-05-06
	 */
	public function testTextConcatString()
	{
		$this->specify(
			"concat do not return the correct string",
			function () {

				// Test 1
				$actual   = PhTText::concat('/', '/tmp/', '/folder_1/', '/folder_2', 'folder_3/');
				$expected = '/tmp/folder_1/folder_2/folder_3/';
				expect($actual)->equals($expected);

				// Test 2
				$actual   = PhTText::concat('.', '@test.', '.test2.', '.test', '.34');
				$expected = '@test.test2.test.34';
				expect($actual)->equals($expected);
			}
		);
	}
}