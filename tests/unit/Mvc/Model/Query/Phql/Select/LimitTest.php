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

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Phql\Select;

use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Tests\AbstractUnitTestCase;

final class LimitTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectLimitBracePlaceholder(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT {limit}";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 277,
                    'value' => 'limit',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectLimitBracePlaceholderOffset(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT {limit} OFFSET {offset}";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 277,
                    'value' => 'limit',
                ],
                'offset' => [
                    'type'  => 277,
                    'value' => 'offset',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectLimit(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT 10";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 258,
                    'value' => '10',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectLimitBoth(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT 20, 10";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 258,
                    'value' => '10',
                ],
                'offset' => [
                    'type'  => 258,
                    'value' => '20',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectLimitOffset(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT 10 OFFSET 20";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 258,
                    'value' => '10',
                ],
                'offset' => [
                    'type'  => 258,
                    'value' => '20',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectLimitOffsetPlaceholders(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT :limit: OFFSET :offset:";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 274,
                    'value' => 'limit',
                ],
                'offset' => [
                    'type'  => 274,
                    'value' => 'offset',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectLimitPlaceholderNum(): void
    {
        $source   = "SELECT * FROM Invoices LIMIT ?0";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 273,
                    'value' => '?0',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectWhereOrderLimit(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_status_flag = 1 "
            . "ORDER BY inv_id DESC "
            . "LIMIT 5";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type' => 352,
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'where'   => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
                ],
            ],
            'orderBy' => [
                'column' => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'sort'   => 328,
            ],
            'limit'   => [
                'number' => [
                    'type'  => 258,
                    'value' => '5',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
