<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

class TextRandomCest
{
    /**
     * Tests the constants for the random function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomConstants(UnitTester $I)
    {
        $I->assertEquals(0, Text::RANDOM_ALNUM);
        $I->assertEquals(1, Text::RANDOM_ALPHA);
        $I->assertEquals(2, Text::RANDOM_HEXDEC);
        $I->assertEquals(3, Text::RANDOM_NUMERIC);
        $I->assertEquals(4, Text::RANDOM_NOZERO);
        $I->assertEquals(5, Text::RANDOM_DISTINCT);
    }

    /**
     * Tests the random function with alnum
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomAlnum(UnitTester $I)
    {
        for ($i = 1; $i < 10; $i++) {
            $source = Text::random(Text::RANDOM_ALNUM, $i);

            $expected = 1;
            $actual   = preg_match('/[a-zA-Z0-9]+/', $source, $matches);
            $I->assertEquals($expected, $actual);

            $expected = $source;
            $actual   = $matches[0];
            $I->assertEquals($expected, $actual);

            $expected = $i;
            $actual   = strlen($source);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the random function with alpha
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomAlpha(UnitTester $I)
    {
        for ($i = 1; $i < 10; $i++) {
            $source = Text::random(Text::RANDOM_ALPHA, $i);

            $expected = 1;
            $actual   = preg_match('/[a-zA-Z]+/', $source, $matches);
            $I->assertEquals($expected, $actual);

            $expected = $source;
            $actual   = $matches[0];
            $I->assertEquals($expected, $actual);

            $expected = $i;
            $actual   = strlen($source);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the random function with hexdec
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomHexDec(UnitTester $I)
    {
        for ($i = 1; $i < 10; $i++) {
            $source = Text::random(Text::RANDOM_HEXDEC, $i);

            $expected = 1;
            $actual   = preg_match('/[a-f0-9]+/', $source, $matches);
            $I->assertEquals($expected, $actual);

            $expected = $source;
            $actual   = $matches[0];
            $I->assertEquals($expected, $actual);

            $expected = $i;
            $actual   = strlen($source);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the random function with numeric
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomNumeric(UnitTester $I)
    {
        for ($i = 1; $i < 10; $i++) {
            $source = Text::random(Text::RANDOM_NUMERIC, $i);

            $expected = 1;
            $actual   = preg_match('/[0-9]+/', $source, $matches);
            $I->assertEquals($expected, $actual);

            $expected = $source;
            $actual   = $matches[0];
            $I->assertEquals($expected, $actual);

            $expected = $i;
            $actual   = strlen($source);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the random function with non zero
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testRandomNonZero(UnitTester $I)
    {
        for ($i = 1; $i < 10; $i++) {
            $source = Text::random(Text::RANDOM_NOZERO, $i);

            $expected = 1;
            $actual   = preg_match('/[1-9]+/', $source, $matches);
            $I->assertEquals($expected, $actual);

            $expected = $source;
            $actual   = $matches[0];
            $I->assertEquals($expected, $actual);

            $expected = $i;
            $actual   = strlen($source);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the random function with distinct type
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-09
     */
    public function testRandomDistinct(UnitTester $I)
    {
        $examples = [1, 10, 100, 200, 500, 1000, 2000, 3000, 4000, 5000];
        foreach ($examples as $i) {
            $source  = Text::random(Text::RANDOM_DISTINCT, $i);
            $pattern = '#^[^2345679ACDEFHJKLMNPRSTUVWXYZ]+$#';

            $expected = 0;
            $actual   = preg_match($pattern, $source);
            $I->assertEquals($expected, $actual);

            $expected = $i;
            $actual   = strlen($source);
            $I->assertEquals($expected, $actual);
        }
    }
}
