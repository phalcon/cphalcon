<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class RandomCest
 */
class RandomCest
{
    /**
     * Tests Phalcon\Helper\Str :: random() - constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomConstants(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - constants');
        $I->assertEquals(0, Str::RANDOM_ALNUM);
        $I->assertEquals(1, Str::RANDOM_ALPHA);
        $I->assertEquals(2, Str::RANDOM_HEXDEC);
        $I->assertEquals(3, Str::RANDOM_NUMERIC);
        $I->assertEquals(4, Str::RANDOM_NOZERO);
        $I->assertEquals(5, Str::RANDOM_DISTINCT);
    }

    /**
     * Tests Phalcon\Helper\Str :: random() - alnum
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomAlnum(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - alnum');
        for ($i = 1; $i < 10; $i++) {
            $source = Str::random(Str::RANDOM_ALNUM, $i);

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
     * Tests Phalcon\Helper\Str :: random() - alpha
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomAlpha(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - alpha');
        for ($i = 1; $i < 10; $i++) {
            $source = Str::random(Str::RANDOM_ALPHA, $i);

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
     * Tests Phalcon\Helper\Str :: random() - hexdec
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomHexDec(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - hexdex');
        for ($i = 1; $i < 10; $i++) {
            $source = Str::random(Str::RANDOM_HEXDEC, $i);

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
     * Tests Phalcon\Helper\Str :: random() - numeric
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomNumeric(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - numeric');
        for ($i = 1; $i < 10; $i++) {
            $source = Str::random(Str::RANDOM_NUMERIC, $i);

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
     * Tests Phalcon\Helper\Str :: random() - non zero
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomNonZero(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - non zero');
        for ($i = 1; $i < 10; $i++) {
            $source = Str::random(Str::RANDOM_NOZERO, $i);

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
     * Tests Phalcon\Helper\Str :: random() - distinct type
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrRandomDistinct(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - random() - distinct');
        $examples = [1, 10, 100, 200, 500, 1000, 2000, 3000, 4000, 5000];
        foreach ($examples as $i) {
            $source  = Str::random(Str::RANDOM_DISTINCT, $i);
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
