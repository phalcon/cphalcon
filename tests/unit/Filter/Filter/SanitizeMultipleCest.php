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

use Codeception\Example;
use Phalcon\Filter\FilterFactory;
use UnitTester;

use function restore_error_handler;
use function set_error_handler;

use const E_USER_NOTICE;

class SanitizeMultipleCest
{
    /**
     * Tests sanitizing values
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-23
     */
    public function filterFilterSanitize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Filter - sanitize() - ' . $example['label']);

        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $source   = $example['source'];
        $expected = $example['expected'];
        $filters  = $example['filters'];
        $actual   = $filter->sanitize($source, $filters);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests sanitizing array with multiple filters and one not existing
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function filterFilterSanitizeWithMultipleFiltersNotExisting(UnitTester $I)
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

        $I->assertEquals(E_USER_NOTICE, $error['number']);
        $I->assertEquals(
            "Sanitizer 'something' is not registered",
            $error['message']
        );
    }

    /**
     * @return array<array-key, array<string, mixed>>
     */
    private function getExamples(): array
    {
        return [
            [
                'label' => 'null value',
                'source' => null,
                'filters' => [
                    'string',
                    'trim',
                ],
                'expected' => null,
            ],
            [
                'label' => 'string with filters',
                'source' => '    lol<<<   ',
                'filters' => [
                    'string',
                    'trim',
                ],
                'expected' => 'lol',
            ],
            [
                'label' => 'array with filters',
                'source' => [' 1 ', '  2', '3  '],
                'filters' => 'trim',
                'expected' => ['1', '2', '3'],
            ],
            [
                'label' => 'array with multiple filters',
                'source' => [' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>'],
                'filters' => ['striptags', 'trim'],
                'expected' => ['1', '2', '3'],
            ],
            [
                'label' => 'multiple filters and more parameters',
                'source' => '  mary had a little lamb ',
                'filters' => [
                    'trim',
                    'replace' => [' ', '-'],
                    'remove'  => ['mary'],
                ],
                'expected' => '-had-a-little-lamb',
            ],
        ];
    }
}
