<?php
/**
 * TextRandomTest.php
 * \Phalcon\Text\TextRandomTest
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

use \Phalcon\Text as PhText;
use \PhalconTest\Text as PhTText;

class TextRandomTest extends Helper\TextBase
{
    /**
     * Tests the constants for the random function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomConstants()
    {
        $this->specify(
            "random constants are not correct",
            function () {

                expect(PhText::RANDOM_ALNUM)->equals(0);
                expect(PhText::RANDOM_ALPHA)->equals(1);
                expect(PhText::RANDOM_HEXDEC)->equals(2);
                expect(PhText::RANDOM_NUMERIC)->equals(3);
                expect(PhText::RANDOM_NOZERO)->equals(4);
            }
        );
    }

    /**
     * Tests the random function with alnum
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomAlnum()
    {
        $this->specify(
            "random with alnum does not return correct results",
            function () {

                for ($i = 1; $i < 10; $i++) {

                    $source = PhTText::random(PhText::RANDOM_ALNUM, $i);

                    expect(preg_match('/[a-zA-Z0-9]+/', $source, $matches))->equals(1);
                    expect($matches[0])->equals($source);
                    expect(strlen($source))->equals($i);
                }
            }
        );
    }

    /**
     * Tests the random function with alpha
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomAlpha()
    {
        $this->specify(
            "random with alpha does not return correct results",
            function () {

                for ($i = 1; $i < 10; $i++) {

                    $source = PhTText::random(PhText::RANDOM_ALPHA, $i);

                    expect(preg_match('/[a-zA-Z]+/', $source, $matches))->equals(1);
                    expect($matches[0])->equals($source);
                    expect(strlen($source))->equals($i);
                }
            }
        );
    }

    /**
     * Tests the random function with hexdec
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomHexDec()
    {
        $this->specify(
            "random with hexdec does not return correct results",
            function () {

                for ($i = 1; $i < 10; $i++) {

                    $source = PhTText::random(PhText::RANDOM_HEXDEC, $i);

                    expect(preg_match('/[a-f0-9]+/', $source, $matches))->equals(1);
                    expect($matches[0])->equals($source);
                    expect(strlen($source))->equals($i);
                }
            }
        );
    }

    /**
     * Tests the random function with numeric
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomNumeric()
    {
        $this->specify(
            "random with numeric does not return correct results",
            function () {

                for ($i = 1; $i < 10; $i++) {

                    $source = PhTText::random(PhText::RANDOM_NUMERIC, $i);

                    expect(preg_match('/[0-9]+/', $source, $matches))->equals(1);
                    expect($matches[0])->equals($source);
                    expect(strlen($source))->equals($i);
                }
            }
        );
    }

    /**
     * Tests the random function with non zero
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomNonZero()
    {
        $this->specify(
            "random with nonzero does not return correct results",
            function () {

                for ($i = 1; $i < 10; $i++) {

                    $source = PhTText::random(PhText::RANDOM_NOZERO, $i);

                    expect(preg_match('/[1-9]+/', $source, $matches))->equals(1);
                    expect($matches[0])->equals($source);
                    expect(strlen($source))->equals($i);
                }
            }
        );
    }
}
