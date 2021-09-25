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

namespace Phalcon\Tests\Unit\Text;

use Codeception\Example;
use Phalcon\Text;
use UnitTester;

class RandomCest
{
    /**
     * Tests Phalcon\Text :: random() - constants
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textRandomConstants(UnitTester $I)
    {
        $I->wantToTest('Text - random() - constants');

        $I->assertEquals(0, Text::RANDOM_ALNUM);
        $I->assertEquals(1, Text::RANDOM_ALPHA);
        $I->assertEquals(2, Text::RANDOM_HEXDEC);
        $I->assertEquals(3, Text::RANDOM_NUMERIC);
        $I->assertEquals(4, Text::RANDOM_NOZERO);
        $I->assertEquals(5, Text::RANDOM_DISTINCT);
    }

    /**
     * Tests Phalcon\Text :: random() - alnum
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider oneToTenProvider
     */
    public function textRandomAlnum(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - random() - alnum');

        $i = $example[0];

        $source = Text::random(
            Text::RANDOM_ALNUM,
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

    /**
     * Tests Phalcon\Text :: random() - alpha
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider oneToTenProvider
     */
    public function textRandomAlpha(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - random() - alpha');

        $i = $example[0];

        $source = Text::random(
            Text::RANDOM_ALPHA,
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
     * Tests Phalcon\Text :: random() - hexdec
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider oneToTenProvider
     */
    public function textRandomHexDec(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - random() - hexdex');

        $i = $example[0];

        $source = Text::random(
            Text::RANDOM_HEXDEC,
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
     * Tests Phalcon\Text :: random() - numeric
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider oneToTenProvider
     */
    public function textRandomNumeric(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - random() - numeric');

        $i = $example[0];

        $source = Text::random(
            Text::RANDOM_NUMERIC,
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
     * Tests Phalcon\Text :: random() - non zero
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider oneToTenProvider
     */
    public function textRandomNonZero(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - random() - non zero');

        $i = $example[0];

        $source = Text::random(
            Text::RANDOM_NOZERO,
            $i
        );


        $actual = preg_match('/[1-9]+/', $source, $matches);

        $I->assertEquals(1, $actual);


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
     * Tests Phalcon\Text :: random() - distinct type
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider textRandomDistinctProvider
     */
    public function textRandomDistinct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - random() - distinct');

        $source = Text::random(
            Text::RANDOM_DISTINCT,
            $example[0]
        );

        $pattern = '#^[^2345679ACDEFHJKLMNPRSTUVWXYZ]+$#';

        $I->assertNotRegExp(
            $pattern,
            $source
        );

        $I->assertEquals(
            $example[0],
            strlen($source)
        );
    }

    private function textRandomDistinctProvider(): array
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
