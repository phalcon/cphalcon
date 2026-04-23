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

final class SubqueriesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectWhereInNestedSubquery(): void
    {
        $source   = "SELECT * FROM Invoices "
            . "WHERE inv_cst_id IN "
            . "(SELECT id FROM Customers "
            . "WHERE id IN (SELECT cst_id FROM Orders WHERE status = 1))";
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
            'where'  => [
                'type'  => 315,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                'right' => [
                    'type'   => 309,
                    'select' => [
                        'columns' => [
                            0 => [
                                'type'   => 354,
                                'column' => [
                                    'type' => 355,
                                    'name' => 'id',
                                ],
                            ],
                        ],
                        'tables'  => [
                            'qualifiedName' => [
                                'type' => 355,
                                'name' => 'Customers',
                            ],
                        ],
                    ],
                    'where'  => [
                        'type'  => 315,
                        'left'  => [
                            'type' => 355,
                            'name' => 'id',
                        ],
                        'right' => [
                            'type'   => 309,
                            'select' => [
                                'columns' => [
                                    0 => [
                                        'type'   => 354,
                                        'column' => [
                                            'type' => 355,
                                            'name' => 'cst_id',
                                        ],
                                    ],
                                ],
                                'tables'  => [
                                    'qualifiedName' => [
                                        'type' => 355,
                                        'name' => 'Orders',
                                    ],
                                ],
                            ],
                            'where'  => [
                                'type'  => 61,
                                'left'  => [
                                    'type' => 355,
                                    'name' => 'status',
                                ],
                                'right' => [
                                    'type'  => 258,
                                    'value' => '1',
                                ],
                            ],
                        ],
                    ],
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
    public function testMvcModelQueryPhqlSelectWhereInSubquery(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_cst_id IN "
            . "(SELECT id FROM Customers WHERE status = 1)";
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
            'where'  => [
                'type'  => 315,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                'right' => [
                    'type'   => 309,
                    'select' => [
                        'columns' => [
                            0 => [
                                'type'   => 354,
                                'column' => [
                                    'type' => 355,
                                    'name' => 'id',
                                ],
                            ],
                        ],
                        'tables'  => [
                            'qualifiedName' => [
                                'type' => 355,
                                'name' => 'Customers',
                            ],
                        ],
                    ],
                    'where'  => [
                        'type'  => 61,
                        'left'  => [
                            'type' => 355,
                            'name' => 'status',
                        ],
                        'right' => [
                            'type'  => 258,
                            'value' => '1',
                        ],
                    ],
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
    public function testMvcModelQueryPhqlSelectWhereNotInSubquery(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_cst_id NOT IN "
            . "(SELECT id FROM Customers WHERE status = 0)";
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
            'where'  => [
                'type'  => 323,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                'right' => [
                    'type'   => 309,
                    'select' => [
                        'columns' => [
                            0 => [
                                'type'   => 354,
                                'column' => [
                                    'type' => 355,
                                    'name' => 'id',
                                ],
                            ],
                        ],
                        'tables'  => [
                            'qualifiedName' => [
                                'type' => 355,
                                'name' => 'Customers',
                            ],
                        ],
                    ],
                    'where'  => [
                        'type'  => 61,
                        'left'  => [
                            'type' => 355,
                            'name' => 'status',
                        ],
                        'right' => [
                            'type'  => 258,
                            'value' => '0',
                        ],
                    ],
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
    public function testMvcModelQueryPhqlSelectWhereExistsSubquery(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE EXISTS "
            . "(SELECT id FROM Customers WHERE id = Invoices.inv_cst_id)";
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
            'where'  => [
                'type'  => 408,
                'right' => [
                    'type'   => 309,
                    'select' => [
                        'columns' => [
                            0 => [
                                'type'   => 354,
                                'column' => [
                                    'type' => 355,
                                    'name' => 'id',
                                ],
                            ],
                        ],
                        'tables'  => [
                            'qualifiedName' => [
                                'type' => 355,
                                'name' => 'Customers',
                            ],
                        ],
                    ],
                    'where'  => [
                        'type'  => 61,
                        'left'  => [
                            'type' => 355,
                            'name' => 'id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'Invoices',
                            'name'   => 'inv_cst_id',
                        ],
                    ],
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
    public function testMvcModelQueryPhqlSelectWhereEqualsSubquery(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_total = (SELECT MAX(inv_total) FROM Invoices)";
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
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
                'right' => [
                    'type' => 407,
                    'left' => [
                        'type'   => 309,
                        'select' => [
                            'columns' => [
                                0 => [
                                    'type'   => 354,
                                    'column' => [
                                        'type'      => 350,
                                        'name'      => 'MAX',
                                        'arguments' => [
                                            0 => [
                                                'type' => 355,
                                                'name' => 'inv_total',
                                            ],
                                        ],
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
                    ],
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
    public function testMvcModelQueryPhqlSelectFieldSubquery(): void
    {
        $source   = "SELECT i.inv_id, "
            . "(SELECT COUNT(*) "
            . "FROM Invoices "
            . "WHERE inv_cst_id = i.inv_cst_id) AS cst_count "
            . "FROM Invoices i";
        $expected = [
            'type'   => 309,
            'select' => [
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
                            'type' => 407,
                            'left' => [
                                'type'   => 309,
                                'select' => [
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
                                        ],
                                    ],
                                    'tables'  => [
                                        'qualifiedName' => [
                                            'type' => 355,
                                            'name' => 'Invoices',
                                        ],
                                    ],
                                ],
                                'where'  => [
                                    'type'  => 61,
                                    'left'  => [
                                        'type' => 355,
                                        'name' => 'inv_cst_id',
                                    ],
                                    'right' => [
                                        'type'   => 355,
                                        'domain' => 'i',
                                        'name'   => 'inv_cst_id',
                                    ],
                                ],
                            ],
                        ],
                        'alias'  => 'cst_count',
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
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
