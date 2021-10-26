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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Codeception\Example;
use Phalcon\Support\Helper\Str\Random;
use UnitTester;

use function strlen;

/**
 * Class RandomCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class RandomCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: random() - constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrRandomConstants(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - random() - constants');

        $I->assertEquals(0, Random::RANDOM_ALNUM);
        $I->assertEquals(1, Random::RANDOM_ALPHA);
        $I->assertEquals(2, Random::RANDOM_HEXDEC);
        $I->assertEquals(3, Random::RANDOM_NUMERIC);
        $I->assertEquals(4, Random::RANDOM_NOZERO);
        $I->assertEquals(5, Random::RANDOM_DISTINCT);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: random() - alnum
     *
     * @dataProvider oneToTenProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrRandomAlnum(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - random() - alnum');

        $object = new Random();
        $i      = $example[0];
        $source = $object(Random::RANDOM_ALNUM, $i);

        $I->assertEquals(
            1,
            preg_match('/[a-zA-Z0-9]+/', $source, $matches)
        );

        $I->assertEquals($source, $matches[0]);
        $I->assertEquals($i, strlen($source));
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: random() - alpha
     *
     * @dataProvider oneToTenProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrRandomAlpha(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - random() - alpha');

        $object = new Random();
        $i      = $example[0];
        $source = $object(Random::RANDOM_ALPHA, $i);

        $I->assertEquals(
            1,
            preg_match('/[a-zA-Z]+/', $source, $matches)
        );

        $I->assertEquals($source, $matches[0]);
        $I->assertEquals($i, strlen($source));
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: random() - hexdec
     *
     * @dataProvider oneToTenProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrRandomHexDec(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - random() - hexdex');

        $object = new Random();
        $i      = $example[0];
        $source = $object(Random::RANDOM_HEXDEC, $i);

        $I->assertEquals(
            1,
            preg_match('/[a-f0-9]+/', $source, $matches)
        );

        $I->assertEquals($source, $matches[0]);
        $I->assertEquals($i, strlen($source));
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: random() - numeric
     *
     * @dataProvider oneToTenProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrRandomNumeric(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - random() - numeric');

        $object = new Random();
        $i      = $example[0];
        $source = $object(Random::RANDOM_NUMERIC, $i);

        $I->assertEquals(
            1,
            preg_match('/[0-9]+/', $source, $matches)
        );

        $I->assertEquals($source, $matches[0]);
        $I->assertEquals($i, strlen($source));
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: random() - non zero
     *
     * @dataProvider oneToTenProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrRandomNonZero(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - random() - non zero');

        $object = new Random();
        $i      = $example[0];
        $source = $object(Random::RANDOM_NOZERO, $i);

        $I->assertEquals(
            1,
            preg_match('/[1-9]+/', $source, $matches)
        );

        $I->assertEquals($source, $matches[0]);
        $I->assertEquals($i, strlen($source));
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: random() - distinct type
     *
     * @dataProvider supportStrRandomDistinctProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrRandomDistinct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - random() - distinct');

        $object = new Random();
        $i      = $example[0];
        $source = $object(Random::RANDOM_DISTINCT, $i);

        $I->assertRegExp(
            '#^[2345679ACDEFHJKLMNPRSTUVWXYZ]+$#',
            $source
        );

        $I->assertEquals($i, strlen($source));
    }

    /**
     * @return int[][]
     */
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
     * @return int[][]
     */
    private function supportStrRandomDistinctProvider(): array
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
