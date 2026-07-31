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

namespace Phalcon\Tests\Unit\Mvc\Model\Eager;

use Phalcon\Mvc\Model\Eager\PathTree;
use Phalcon\Mvc\Model\Exceptions\InvalidEagerPath;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerOption;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\TestCase;

final class PathTreeTest extends TestCase
{
    /**
     * @return array<string, array{0: array, 1: array}>
     */
    public static function getExamples(): array
    {
        $leaf = ['options' => [], 'children' => []];

        return [
            'single'   => [
                ['customer'],
                ['customer' => $leaf],
            ],
            'nested'   => [
                ['customer.country'],
                [
                    'customer' => [
                        'options'  => [],
                        'children' => ['country' => $leaf],
                    ],
                ],
            ],
            'prefix'   => [
                ['customer', 'customer.country'],
                [
                    'customer' => [
                        'options'  => [],
                        'children' => ['country' => $leaf],
                    ],
                ],
            ],
            'branches' => [
                ['customer.country', 'customer.address'],
                [
                    'customer' => [
                        'options'  => [],
                        'children' => [
                            'country' => $leaf,
                            'address' => $leaf,
                        ],
                    ],
                ],
            ],
            'siblings' => [
                ['customer', 'items'],
                ['customer' => $leaf, 'items' => $leaf],
            ],
            'trimmed'  => [
                [' customer . country '],
                [
                    'customer' => [
                        'options'  => [],
                        'children' => ['country' => $leaf],
                    ],
                ],
            ],
            'empty'    => [
                [],
                [],
            ],
        ];
    }

    /**
     * @return array<string, array{0: array}>
     */
    public static function getInvalidExamples(): array
    {
        return [
            'empty string' => [['']],
            'blank'        => [['   ']],
            'double dot'   => [['customer..country']],
            'trailing dot' => [['customer.']],
            'leading dot'  => [['.customer']],
            'non string'   => [[123]],
            'too deep'     => [['a.b.c.d.e.f']],
        ];
    }

    /**
     * Dotted paths become a tree in which a path implies its prefixes and
     * prefixes dedupe, so query count follows distinct nodes rather than the
     * number of strings supplied.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[DataProvider('getExamples')]
    public function testMvcModelEagerPathTreeParse(
        array $spec,
        array $expected
    ): void {
        $this->assertSame($expected, PathTree::parse($spec));
    }

    /**
     * Malformed paths are rejected up front rather than silently loading
     * nothing, which would be indistinguishable from the feature not working.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[DataProvider('getInvalidExamples')]
    public function testMvcModelEagerPathTreeParseInvalid(array $spec): void
    {
        $this->expectException(InvalidEagerPath::class);

        PathTree::parse($spec);
    }

    /**
     * Options attach to the last segment of the path they were written on, and
     * merge when the same node is reached twice.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testMvcModelEagerPathTreeParseOptions(): void
    {
        $result = PathTree::parse(
            [
                'customer.country' => ['columns' => 'cnt_id, cnt_name'],
                'items'            => ['conditions' => 'itm_active = 1'],
            ]
        );

        $this->assertSame(
            ['columns' => 'cnt_id, cnt_name'],
            $result['customer']['children']['country']['options']
        );
        $this->assertSame([], $result['customer']['options']);
        $this->assertSame(
            ['conditions' => 'itm_active = 1'],
            $result['items']['options']
        );
    }

    /**
     * A per-parent limit needs a window function PHQL cannot express, so it is
     * refused at parse time rather than silently applied to the whole batch -
     * which would return N children in total instead of N per parent.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testMvcModelEagerPathTreeParseRejectsLimit(): void
    {
        $this->expectException(UnsupportedEagerOption::class);
        $this->expectExceptionMessage("'limit'");

        PathTree::parse(['items' => ['limit' => 5]]);
    }
}
