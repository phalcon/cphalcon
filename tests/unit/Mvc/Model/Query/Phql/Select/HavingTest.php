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

final class HavingTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectHavingCountAll(): void
    {
        $source   = "SELECT inv_status_flag, COUNT(*) AS cnt " . "FROM Invoices " . "GROUP BY inv_status_flag " .
                    "HAVING COUNT(*) > 5";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
                    ],
                    1 => [
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
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'groupBy' => [
                'type' => 355,
                'name' => 'inv_status_flag',
            ],
            'having'  => [
                'type'  => 62,
                'left'  => [
                    'type'      => 350,
                    'name'      => 'COUNT',
                    'arguments' => [
                        0 => [
                            'type' => 352,
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '5',
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
    public function testMvcModelQueryPhqlSelectHavingCountField(): void
    {
        $source   = "SELECT inv_cst_id, COUNT(*) AS cnt " . "FROM Invoices " . "GROUP BY inv_cst_id " .
                    "HAVING cnt > 10";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_cst_id',
                        ],
                    ],
                    1 => [
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
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'groupBy' => [
                'type' => 355,
                'name' => 'inv_cst_id',
            ],
            'having'  => [
                'type'  => 62,
                'left'  => [
                    'type' => 355,
                    'name' => 'cnt',
                ],
                'right' => [
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
    public function testMvcModelQueryPhqlSelectHavingSum(): void
    {
        $source   = "SELECT inv_cst_id, SUM(inv_total) AS total " . "FROM Invoices " . "GROUP BY inv_cst_id " .
                    "HAVING SUM(inv_total) > 1000";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_cst_id',
                        ],
                    ],
                    1 => [
                        'type'   => 354,
                        'column' => [
                            'type'      => 350,
                            'name'      => 'SUM',
                            'arguments' => [
                                0 => [
                                    'type' => 355,
                                    'name' => 'inv_total',
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
                ],
            ],
            'groupBy' => [
                'type' => 355,
                'name' => 'inv_cst_id',
            ],
            'having'  => [
                'type'  => 62,
                'left'  => [
                    'type'      => 350,
                    'name'      => 'SUM',
                    'arguments' => [
                        0 => [
                            'type' => 355,
                            'name' => 'inv_total',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1000',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
