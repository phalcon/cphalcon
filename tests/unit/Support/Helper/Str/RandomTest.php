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

use Phalcon\Support\Helper\Str\Random;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function strlen;

final class RandomTest extends AbstractUnitTestCase
{
    /**
     * @return int[][]
     */
    public static function oneToTenProvider(): array
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
    public static function randomDistinctProvider(): array
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

    /**
     * @dataProvider oneToTenProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('oneToTenProvider')]
    public function testSupportHelperStrRandomAlnum(
        int $i,
    ): void {
        $object = new Random();
        $source = $object(Random::RANDOM_ALNUM, $i);

        $this->assertSame(
            1,
            preg_match('/[a-zA-Z0-9]+/', $source, $matches),
        );

        $this->assertSame($source, $matches[0]);
        $this->assertSame($i, strlen($source));
    }

    /**
     * @dataProvider oneToTenProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('oneToTenProvider')]
    public function testSupportHelperStrRandomAlpha(
        int $i,
    ): void {
        $object = new Random();
        $source = $object(Random::RANDOM_ALPHA, $i);

        $this->assertSame(
            1,
            preg_match('/[a-zA-Z]+/', $source, $matches),
        );

        $this->assertSame($source, $matches[0]);
        $this->assertSame($i, strlen($source));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrRandomConstants(): void
    {
        $this->assertSame(0, Random::RANDOM_ALNUM);
        $this->assertSame(1, Random::RANDOM_ALPHA);
        $this->assertSame(2, Random::RANDOM_HEXDEC);
        $this->assertSame(3, Random::RANDOM_NUMERIC);
        $this->assertSame(4, Random::RANDOM_NOZERO);
        $this->assertSame(5, Random::RANDOM_DISTINCT);
    }

    /**
     * @dataProvider randomDistinctProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('randomDistinctProvider')]
    public function testSupportHelperStrRandomDistinct(
        int $i,
    ): void {
        $object = new Random();
        $source = $object(Random::RANDOM_DISTINCT, $i);

        $this->assertMatchesRegularExpression(
            '#^[2345679ACDEFHJKLMNPRSTUVWXYZ]+$#',
            $source,
        );

        $this->assertSame($i, strlen($source));
    }

    /**
     * @dataProvider oneToTenProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('oneToTenProvider')]
    public function testSupportHelperStrRandomHexDec(
        int $i,
    ): void {
        $object = new Random();
        $source = $object(Random::RANDOM_HEXDEC, $i);

        $this->assertSame(
            1,
            preg_match('/[a-f0-9]+/', $source, $matches),
        );

        $this->assertSame($source, $matches[0]);
        $this->assertSame($i, strlen($source));
    }

    /**
     * @dataProvider oneToTenProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('oneToTenProvider')]
    public function testSupportHelperStrRandomNonZero(
        int $i,
    ): void {
        $object = new Random();
        $source = $object(Random::RANDOM_NOZERO, $i);

        $this->assertSame(
            1,
            preg_match('/[1-9]+/', $source, $matches),
        );

        $this->assertSame($source, $matches[0]);
        $this->assertSame($i, strlen($source));
    }

    /**
     * @dataProvider oneToTenProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('oneToTenProvider')]
    public function testSupportHelperStrRandomNumeric(
        int $i,
    ): void {
        $object = new Random();
        $source = $object(Random::RANDOM_NUMERIC, $i);

        $this->assertSame(
            1,
            preg_match('/[0-9]+/', $source, $matches),
        );

        $this->assertSame($source, $matches[0]);
        $this->assertSame($i, strlen($source));
    }
}
