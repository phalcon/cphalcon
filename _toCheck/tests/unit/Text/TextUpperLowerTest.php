<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextUpperLowerTest
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
class TextUpperLowerTest extends UnitTest
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
                expect(Text::upper('hello'))->equals('HELLO');
                expect(Text::upper('HELLO'))->equals('HELLO');
                expect(Text::upper('1234'))->equals('1234');
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
                expect(Text::upper('ПРИВЕТ МИР!'))->equals('ПРИВЕТ МИР!');
                expect(Text::upper('ПриВЕт Мир!'))->equals('ПРИВЕТ МИР!');
                expect(Text::upper('привет мир!'))->equals('ПРИВЕТ МИР!');

                expect(Text::upper('MÄNNER'))->equals('MÄNNER');
                expect(Text::upper('mÄnnER'))->equals('MÄNNER');
                expect(Text::upper('männer'))->equals('MÄNNER');
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
                expect(Text::lower('hello'))->equals('hello');
                expect(Text::lower('HELLO'))->equals('hello');
                expect(Text::lower('1234'))->equals('1234');
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
                expect(Text::lower('привет мир!'))->equals('привет мир!');
                expect(Text::lower('ПриВЕт Мир!'))->equals('привет мир!');
                expect(Text::lower('ПРИВЕТ МИР!'))->equals('привет мир!');

                expect(Text::lower('männer'))->equals('männer');
                expect(Text::lower('mÄnnER'))->equals('männer');
                expect(Text::lower('MÄNNER'))->equals('männer');
            }
        );
    }
}
