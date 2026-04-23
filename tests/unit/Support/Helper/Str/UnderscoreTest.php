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

use Phalcon\Support\Helper\Str\Underscore;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class UnderscoreTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        return [
            [
                'start a horse',
                'start_a_horse',
            ],
            [
                "five\tcats",
                'five_cats',
            ],
            [
                ' look behind ',
                'look_behind',
            ],
            [
                " \t Awesome \t  \t Phalcon ",
                'Awesome_Phalcon',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getExamples')]
    public function testSupportHelperStrUnderscore(
        string $text,
        string $expected,
    ): void {
        $object = new Underscore();
        $actual = $object($text);
        $this->assertSame($expected, $actual);
    }
}
