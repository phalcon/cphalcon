<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextConcatTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextConcatTest extends UnitTest
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
                $actual   = Text::concat('/', '/tmp/', '/folder_1/', '/folder_2', 'folder_3/');
                $expected = '/tmp/folder_1/folder_2/folder_3/';
                expect($actual)->equals($expected);

                // Test 2
                $actual   = Text::concat('.', '@test.', '.test2.', '.test', '.34');
                $expected = '@test.test2.test.34';
                expect($actual)->equals($expected);
            }
        );
    }
}
