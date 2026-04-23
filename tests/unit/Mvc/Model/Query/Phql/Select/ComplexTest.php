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

final class ComplexTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectSumFieldWhereGroupByHavingOrderByLimit(): void
    {
        $source   = "SELECT i.inv_id, i.inv_title, SUM(i.inv_total) AS total "
            . "FROM Invoices AS i "
            . "WHERE i.inv_status_flag = 1 "
            . "GROUP BY i.inv_cst_id "
            . "HAVING SUM(i.inv_total) > 500 "
            . "ORDER BY total DESC "
            . "LIMIT 10";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_id',
                        ],
                    ],
                    1 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_title',
                        ],
                    ],
                    2 => [
                        'type'   => 354,
                        'column' => [
                            'type'      => 350,
                            'name'      => 'SUM',
                            'arguments' => [
                                0 => [
                                    'type'   => 355,
                                    'domain' => 'i',
                                    'name'   => 'inv_total',
                                ],
                            ],
                        ],
                        'alias'  => 'total',
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
            ],
            'where'   => [
                'type'  => 61,
                'left'  => [
                    'type'   => 355,
                    'domain' => 'i',
                    'name'   => 'inv_status_flag',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
                ],
            ],
            'orderBy' => [
                'column' => [
                    'type' => 355,
                    'name' => 'total',
                ],
                'sort'   => 328,
            ],
            'groupBy' => [
                'type'   => 355,
                'domain' => 'i',
                'name'   => 'inv_cst_id',
            ],
            'having'  => [
                'type'  => 62,
                'left'  => [
                    'type'      => 350,
                    'name'      => 'SUM',
                    'arguments' => [
                        0 => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_total',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '500',
                ],
            ],
            'limit'   => [
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
    public function testMvcModelQueryPhqlSelectCountFieldWhereGroupByOrderBy(): void
    {
        $source   = "SELECT COUNT(*) AS cnt, inv_status_flag "
            . "FROM Invoices "
            . "WHERE inv_created_at IS NOT NULL "
            . "GROUP BY inv_status_flag "
            . "ORDER BY cnt DESC";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'      => 350,
                            'name'      => 'COUNT',
                            'arguments' => [
                                0 => [
                                    'type' => 352,
                                ],
                            ],
                        ],
                        'alias'  => 'cnt',
                    ],
                    1 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
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
                'type' => 366,
                'left' => [
                    'type' => 355,
                    'name' => 'inv_created_at',
                ],
            ],
            'orderBy' => [
                'column' => [
                    'type' => 355,
                    'name' => 'cnt',
                ],
                'sort'   => 328,
            ],
            'groupBy' => [
                'type' => 355,
                'name' => 'inv_status_flag',
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
    public function testMvcModelQueryPhqlSelectAllWhereAndInAndBetweenOrderByLimitOffset(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_cst_id = :cstId: "
            . "AND inv_status_flag IN (0, 1) "
            . "AND inv_total BETWEEN :min: AND :max: "
            . "ORDER BY inv_created_at DESC "
            . "LIMIT :limit: "
            . "OFFSET :offset:";
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
                'type'  => 331,
                'left'  => [
                    'type'  => 61,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_cst_id',
                    ],
                    'right' => [
                        'type'  => 266,
                        'left'  => [
                            'type'  => 266,
                            'left'  => [
                                'type'  => 274,
                                'value' => 'cstId',
                            ],
                            'right' => [
                                'type'  => 315,
                                'left'  => [
                                    'type' => 355,
                                    'name' => 'inv_status_flag',
                                ],
                                'right' => [
                                    0 => [
                                        'type'  => 258,
                                        'value' => '0',
                                    ],
                                    1 => [
                                        'type'  => 258,
                                        'value' => '1',
                                    ],
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 355,
                            'name' => 'inv_total',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 266,
                    'left'  => [
                        'type'  => 274,
                        'value' => 'min',
                    ],
                    'right' => [
                        'type'  => 274,
                        'value' => 'max',
                    ],
                ],
            ],
            'orderBy' => [
                'column' => [
                    'type' => 355,
                    'name' => 'inv_created_at',
                ],
                'sort'   => 328,
            ],
            'limit'   => [
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
}
