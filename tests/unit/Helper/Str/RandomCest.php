<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Helper\Str;

use Codeception\Example;
use Phalcon\Helper\Str;
use UnitTester;

class RandomCest
{
    /**
     * Tests Phalcon\Helper\Str :: random() - constants
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider oneToTenProvider
     */
    public function helperStrRandomAlnum(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - random() - alnum');

        $i = $example[0];

        $source = Str::random(
            Str::RANDOM_ALNUM,
            $i
        );

        $I->assertEquals(
            1,
            preg_match('/[a-zA-Z0-9]+/', $source, $matches)
        );

        $I->assertEquals(
            $source,
            $matches[0]
        );

        $I->assertEquals(
            $i,
            strlen($source)
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: random() - alpha
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider oneToTenProvider
     */
    public function helperStrRandomAlpha(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - random() - alpha');

        $i = $example[0];

        $source = Str::random(
            Str::RANDOM_ALPHA,
            $i
        );

        $I->assertEquals(
            1,
            preg_match('/[a-zA-Z]+/', $source, $matches)
        );

        $I->assertEquals(
            $source,
            $matches[0]
        );

        $I->assertEquals(
            $i,
            strlen($source)
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: random() - hexdec
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider oneToTenProvider
     */
    public function helperStrRandomHexDec(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - random() - hexdex');

        $i = $example[0];

        $source = Str::random(
            Str::RANDOM_HEXDEC,
            $i
        );

        $I->assertEquals(
            1,
            preg_match('/[a-f0-9]+/', $source, $matches)
        );

        $I->assertEquals(
            $source,
            $matches[0]
        );

        $I->assertEquals(
            $i,
            strlen($source)
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: random() - numeric
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider oneToTenProvider
     */
    public function helperStrRandomNumeric(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - random() - numeric');

        $i = $example[0];

        $source = Str::random(
            Str::RANDOM_NUMERIC,
            $i
        );

        $I->assertEquals(
            1,
            preg_match('/[0-9]+/', $source, $matches)
        );

        $I->assertEquals(
            $source,
            $matches[0]
        );

        $I->assertEquals(
            $i,
            strlen($source)
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: random() - non zero
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider oneToTenProvider
     */
    public function helperStrRandomNonZero(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - random() - non zero');

        $i = $example[0];

        $source = Str::random(
            Str::RANDOM_NOZERO,
            $i
        );

        $I->assertEquals(
            1,
            preg_match('/[1-9]+/', $source, $matches)
        );

        $I->assertEquals(
            $source,
            $matches[0]
        );

        $I->assertEquals(
            $i,
            strlen($source)
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: random() - distinct type
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider helperStrRandomDistinctProvider
     */
    public function helperStrRandomDistinct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - random() - distinct');

        $source = Str::random(
            Str::RANDOM_DISTINCT,
            $example[0]
        );

        $I->assertRegExp(
            '#^[2345679ACDEFHJKLMNPRSTUVWXYZ]+$#',
            $source
        );

        $I->assertEquals(
            $example[0],
            strlen($source)
        );
    }

    private function oneToTenProvider(): array
    {
        return [
            [1],
            [2],
            [3],
            [4],
            [5],
            [6],
            [7],
            [8],
            [9],
            [10],
        ];
    }

    private function helperStrRandomDistinctProvider(): array
    {
        return [
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
        ];
    }
}
