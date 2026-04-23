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

use Phalcon\Support\Helper\Str\Interpolate;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class InterpolateTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                '2020-09-09 is the date',
                '%date% is the date',
                [
                    'date' => '2020-09-09',
                ],
            ],
            [
                '2020-09-09 is the date CRITICAL is the level',
                '%date% is the date %level% is the level',
                [
                    'date'  => '2020-09-09',
                    'level' => 'CRITICAL',
                ],
            ],
            [
                'no format',
                'no format',
                [
                    'date' => '2020-09-09',
                ],
            ],
            [
                '2020-09-09 is the date',
                '%date% is the date',
                [
                    'date' => '2020-09-09',
                ],
            ],
            [
                '2020-09-09 is the date AAA is context',
                '%date% is the date %stub% is context',
                [
                    'date' => '2020-09-09',
                    'stub' => 'AAA',
                ],
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-04-28
     */
    #[DataProvider('getExamples')]
    public function testSupportHelperHelperStrInterpolateInvoke(
        string $expected,
        string $format,
        array $context,
    ): void {
        $actual = (new Interpolate())($format, $context);
        $this->assertSame($expected, $actual);
    }
}
