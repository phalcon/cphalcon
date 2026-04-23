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

namespace Phalcon\Tests\Unit\Filter\Filter;

use Phalcon\Filter\FilterFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function restore_error_handler;
use function set_error_handler;

use const E_USER_NOTICE;

final class SanitizeMultipleTest extends AbstractUnitTestCase
{
    /**
     * @return array<array-key, array<string, mixed>>
     */
    public static function getFilterSanitizeCustomFiltersExamples(): array
    {
        return [
            [
                [4, 2, 0],
                [
                    'sum'  => fn($input) => array_sum($input),
                    'half' => fn($input) => $input / 2,
                ],
                true,
                3,
            ],
            [
                [4, 2, 0],
                [
                    'double'  => fn($input) => $input * 2,
                    'inverse' => fn($input) => 0 - $input,
                ],
                false,
                [-8, -4, 0],
            ],
        ];
    }

    /**
     * @return array<array-key, array<string, mixed>>
     */
    public static function getFilterSanitizeExamples(): array
    {
        return [
            [
                null,
                [
                    'string',
                    'trim',
                ],
                false,
                null,
            ],
            [
                '    lol<<<   ',
                [
                    'string',
                    'trim',
                ],
                false,
                'lol&lt;&lt;&lt;',
            ],
            [
                [' 1 ', '  2', '3  '],
                'trim',
                false,
                ['1', '2', '3'],
            ],
            [
                [' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>'],
                ['striptags', 'trim'],
                false,
                ['1', '2', '3'],
            ],
            [
                '  mary had a little lamb ',
                [
                    'trim',
                    'replace' => [' ', '-'],
                    'remove'  => ['mary'],
                ],
                false,
                '-had-a-little-lamb',
            ],
        ];
    }

    /**
     * @dataProvider getFilterSanitizeExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-10-23
     */
    public function testFilterFilterSanitize(
        mixed $source,
        array | string $filters,
        bool $noRecursive,
        mixed $expected
    ): void {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $actual = $filter->sanitize($source, $filters, $noRecursive);

        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getFilterSanitizeCustomFiltersExamples
     *
     */
    public function testFilterFilterSanitizeCustomFilters(
        array $source,
        array | string $filters,
        bool $noRecursive,
        array | int $expected
    ): void {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        foreach ($filters as $name => $testFilter) {
            $filter->set($name, $testFilter);
        }

        $actual = $filter->sanitize($source, array_keys($filters), $noRecursive);

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterSanitizeWithMultipleFiltersNotExisting(): void
    {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $value   = '  mary had a little lamb ';
        $filters = [
            'trim',
            'something',
        ];

        $error = [];
        set_error_handler(
            function ($number, $message, $file, $line) use (&$error) {
                $error = [
                    'number'  => $number,
                    'message' => $message,
                    'file'    => $file,
                    'line'    => $line,
                ];
            }
        );

        $actual = $filter->sanitize($value, $filters);
        restore_error_handler();

        $this->assertSame(E_USER_NOTICE, $error['number']);
        $this->assertSame(
            "Sanitizer 'something' is not registered",
            $error['message']
        );
    }
}
