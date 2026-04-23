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

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Phql\Update;

use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Tests\AbstractUnitTestCase;

final class Combination extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlUpdateWhereMultipleAndConditions(): void
    {
        $source   = "UPDATE Invoices SET inv_status_flag = 1 "
            . "WHERE inv_cst_id = 1 AND inv_total > 100 AND inv_status_flag = 0";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type'  => 62,
                    'left'  => [
                        'type'  => 61,
                        'left'  => [
                            'type' => 355,
                            'name' => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'  => 266,
                            'left'  => [
                                'type'  => 258,
                                'value' => '1',
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
                            'type'  => 258,
                            'value' => '100',
                        ],
                        'right' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '0',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdate(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_status_flag = 1";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateAliasNumWhereNum(): void
    {
        $source   = "UPDATE Invoices AS i " . "SET i.inv_status_flag = 1 " . "WHERE i.inv_cst_id = 1";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'values' => [
                    'column' => [
                        'type'   => 355,
                        'domain' => 'i',
                        'name'   => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type'   => 355,
                    'domain' => 'i',
                    'name'   => 'inv_cst_id',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateCalculatedWhereNumZero(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_total = inv_total * 1.1 " . "WHERE inv_status_flag = 0";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_total',
                    ],
                    'expr'   => [
                        'type'  => 42,
                        'left'  => [
                            'type' => 355,
                            'name' => 'inv_total',
                        ],
                        'right' => [
                            'type'  => 259,
                            'value' => '1.1',
                        ],
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '0',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateTrueWhereNum(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_status_flag = TRUE " . "WHERE inv_id = 1";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type' => 334,
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateNullWhereNum(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_total = NULL " . "WHERE inv_status_flag = 0";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_total',
                    ],
                    'expr'   => [
                        'type' => 322,
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '0',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateNumLimit(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_status_flag = 0 " . "LIMIT 10";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type'  => 258,
                        'value' => '0',
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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateNumPlaceholderWhereNumPlaceholder(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_status_flag = ?0, inv_total = ?1 " . "WHERE inv_id = ?2";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    0 => [
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
                        'expr'   => [
                            'type'  => 273,
                            'value' => '?0',
                        ],
                    ],
                    1 => [
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_total',
                        ],
                        'expr'   => [
                            'type'  => 273,
                            'value' => '?1',
                        ],
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 273,
                    'value' => '?2',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateNumStringWhereEqNum(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_status_flag = 1, inv_title = 'Updated' " . "WHERE inv_id = 1";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    0 => [
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
                        'expr'   => [
                            'type'  => 258,
                            'value' => '1',
                        ],
                    ],
                    1 => [
                        'column' => [
                            'type' => 355,
                            'name' => 'inv_title',
                        ],
                        'expr'   => [
                            'type'  => 260,
                            'value' => 'Updated',
                        ],
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateNumWhereEqNum(): void
    {
        $source   = "UPDATE Invoices SET inv_status_flag = 1 WHERE inv_id = 1";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateNumWhereIn(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_status_flag = 1 " . "WHERE inv_id IN (1, 2, 3)";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'expr'   => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 315,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    0 => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                    1 => [
                        'type'  => 258,
                        'value' => '2',
                    ],
                    2 => [
                        'type'  => 258,
                        'value' => '3',
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdatePlaceholderWherePlaceholder(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_title = :title: " . "WHERE inv_id = :id:";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_title',
                    ],
                    'expr'   => [
                        'type'  => 274,
                        'value' => 'title',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 274,
                    'value' => 'id',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlUpdateUpperWhereNum(): void
    {
        $source   = "UPDATE Invoices " . "SET inv_title = UPPER(inv_title) " . "WHERE inv_status_flag = 1";
        $expected = [
            'type'   => 300,
            'update' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
                'values' => [
                    'column' => [
                        'type' => 355,
                        'name' => 'inv_title',
                    ],
                    'expr'   => [
                        'type'      => 350,
                        'name'      => 'UPPER',
                        'arguments' => [
                            0 => [
                                'type' => 355,
                                'name' => 'inv_title',
                            ],
                        ],
                    ],
                ],
            ],
            'where'  => [
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
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }
}
