<?php
/**
 * TextIncrementTest.php
 * \Phalcon\Text\TextIncrementTest
 *
 * Tests the Phalcon\Text component
 *
 * Phalcon Framework
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

namespace Phalcon\Tests\unit\Phalcon\Text;

use \PhalconTest\Text as PhTText;

class TextIncrementTest extends Helper\TextBase
{
    /**
     * Tests the increment function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementSimpleString()
    {
        $this->specify(
            "increment does not increment a simple string",
            function () {

                $source   = 'file';
                $expected = 'file_1';
                $actual   = PhTText::increment($source);
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the increment function with an already incremented string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementAlreadyIncremented()
    {
        $this->specify(
            "increment does not increment an incremented string",
            function () {

                $source   = 'file_1';
                $expected = 'file_2';
                $actual   = PhTText::increment($source);
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the increment function for an already incremented string twice
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementAlreadyIncrementedTwice()
    {
        $this->specify(
            "increment does not increment a second incremented string",
            function () {

                $source   = 'file_2';
                $expected = 'file_3';
                $actual   = PhTText::increment($source);
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the increment function for a string with underscore
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementStringWithUnderscore()
    {
        $this->specify(
            "increment does not increment a string with an underscore",
            function () {

                $source   = 'file_';
                $expected = 'file_1';
                $actual   = PhTText::increment($source);
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the increment function for a string with a space at the end
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementStringWithSpace()
    {
        $this->specify(
            "increment does not increment a string with a space at the end",
            function () {

                $source   = 'file ';
                $expected = 'file _1';
                $actual   = PhTText::increment($source);
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the increment function with a different separator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementStringWithDifferentSeparator()
    {
        $this->specify(
            "increment does not increment a string with a different separator",
            function () {

                $source   = 'file';
                $expected = 'file-1';
                $actual   = PhTText::increment($source, '-');
                expect($actual)->equals($expected);
            }
        );
    }
}
