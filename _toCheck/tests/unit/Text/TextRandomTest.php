<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextRandomTest
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
class TextRandomTest extends UnitTest
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
                expect(Text::RANDOM_ALNUM)->equals(0);
                expect(Text::RANDOM_ALPHA)->equals(1);
                expect(Text::RANDOM_HEXDEC)->equals(2);
                expect(Text::RANDOM_NUMERIC)->equals(3);
                expect(Text::RANDOM_NOZERO)->equals(4);
                expect(Text::RANDOM_DISTINCT)->equals(5);
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
                    $source = Text::random(Text::RANDOM_ALNUM, $i);

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
                    $source = Text::random(Text::RANDOM_ALPHA, $i);

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
                    $source = Text::random(Text::RANDOM_HEXDEC, $i);

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
                    $source = Text::random(Text::RANDOM_NUMERIC, $i);

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
                    $source = Text::random(Text::RANDOM_NOZERO, $i);

                    expect(preg_match('/[1-9]+/', $source, $matches))->equals(1);
                    expect($matches[0])->equals($source);
                    expect(strlen($source))->equals($i);
                }
            }
        );
    }

    /**
     * Tests the random function with distinct type
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-09
     */
    public function testRandomDistinct()
    {
        $this->specify(
            "distinct random does not return correct results",
            function ($i) {
                $source  = Text::random(Text::RANDOM_DISTINCT, $i);
                $pattern = '#^[^2345679ACDEFHJKLMNPRSTUVWXYZ]+$#';

                expect(preg_match($pattern, $source))->equals(0);
                expect(strlen($source))->equals($i);
            },
            [
                'examples' => [
                    [1],
                    [10],
                    [100],
                    [200],
                    [500],
                    [1000],
                    [2000],
                    [3000],
                    [4000],
                    [5000],
                ],
            ]
        );
    }
}
