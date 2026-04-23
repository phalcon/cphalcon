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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Get;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $sample = new stdClass();
        $sample->one = 'two';

        return [
            [
                'boolean',
                1,
                true,
            ],
            [
                'bool',
                1,
                true,
            ],
            [
                'integer',
                "123",
                123,
            ],
            [
                'int',
                "123",
                123,
            ],
            [
                'float',
                "123.45",
                123.45,
            ],
            [
                'double',
                "123.45",
                123.45,
            ],
            [
                'string',
                123,
                "123",
            ],
            [
                'array',
                $sample,
                ['one' => 'two'],
            ],
            [
                'object',
                ['one' => 'two'],
                $sample,
            ],
            [
                'null',
                1234,
                null,
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
    public function testSupportHelperArrGetCast(
        string $cast,
        mixed $value,
        mixed $expected,
    ): void {
        $object = new Get();
        $collection = [
            'value' => $value,
        ];

        $actual = $object($collection, 'value', null, $cast);
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrGetDefault(): void
    {
        $object = new Get();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Error';
        $actual = $object($collection, uniqid(), 'Error');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrGetNumeric(): void
    {
        $object = new Get();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Phalcon';
        $actual = $object($collection, 1, 'Error');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrGetString(): void
    {
        $object = new Get();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Framework';
        $actual = $object($collection, 'suffix', 'Error');
        $this->assertSame($expected, $actual);
    }
}
