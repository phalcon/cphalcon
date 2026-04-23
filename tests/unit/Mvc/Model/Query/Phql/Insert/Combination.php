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

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Phql\Insert;

use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Tests\AbstractUnitTestCase;

final class Combination extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlInsert(): void
    {
        $source   = "INSERT INTO Invoices " . "VALUES (1, 1, 1, 'Test Invoice', 100.00, '2025-01-01 00:00:00')";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'values'        => [
                0 => [
                    'type'  => 258,
                    'value' => '1',
                ],
                1 => [
                    'type'  => 258,
                    'value' => '1',
                ],
                2 => [
                    'type'  => 258,
                    'value' => '1',
                ],
                3 => [
                    'type'  => 260,
                    'value' => 'Test Invoice',
                ],
                4 => [
                    'type'  => 259,
                    'value' => '100.00',
                ],
                5 => [
                    'type'  => 260,
                    'value' => '2025-01-01 00:00:00',
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
    public function testMvcModelQueryPhqInsertFields(): void
    {
        $source   = "INSERT INTO Invoices " . "(inv_cst_id, inv_status_flag, inv_title, inv_total, inv_created_at) " .
                    "VALUES (1, 0, 'Test Invoice', 150.50, '2025-01-01 00:00:00')";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
                2 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                3 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
                4 => [
                    'type' => 355,
                    'name' => 'inv_created_at',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 258,
                    'value' => '1',
                ],
                1 => [
                    'type'  => 258,
                    'value' => '0',
                ],
                2 => [
                    'type'  => 260,
                    'value' => 'Test Invoice',
                ],
                3 => [
                    'type'  => 259,
                    'value' => '150.50',
                ],
                4 => [
                    'type'  => 260,
                    'value' => '2025-01-01 00:00:00',
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
    public function testMvcModelQueryPhqlInsertFieldsNull(): void
    {
        $source   = "INSERT INTO Invoices " . "(inv_title, inv_total) " . "VALUES ('Null Test', NULL)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 260,
                    'value' => 'Null Test',
                ],
                1 => [
                    'type' => 322,
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
    public function testMvcModelQueryPhqlInsertFieldsPartial(): void
    {
        $source   = "INSERT INTO Invoices (inv_title, inv_total) " . "VALUES ('Invoice A', 200.00)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 260,
                    'value' => 'Invoice A',
                ],
                1 => [
                    'type'  => 259,
                    'value' => '200.00',
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
    public function testMvcModelQueryPhqlInsertFieldsPlaceholders(): void
    {
        $source   = "INSERT INTO Invoices " . "(inv_cst_id, inv_status_flag, inv_title, inv_total) " .
                    "VALUES (:cstId:, :status:, :title:, :total:)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
                2 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                3 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 274,
                    'value' => 'cstId',
                ],
                1 => [
                    'type'  => 274,
                    'value' => 'status',
                ],
                2 => [
                    'type'  => 274,
                    'value' => 'title',
                ],
                3 => [
                    'type'  => 274,
                    'value' => 'total',
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
    public function testMvcModelQueryPhqlInsertFieldsPlaceholdersNum(): void
    {
        $source   = "INSERT INTO Invoices " . "(inv_cst_id, inv_title, inv_total) " . "VALUES (?0, ?1, ?2)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                2 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 273,
                    'value' => '?0',
                ],
                1 => [
                    'type'  => 273,
                    'value' => '?1',
                ],
                2 => [
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
    public function testMvcModelQueryPhqlInsertFieldsPlaceholdersBrackets(): void
    {
        $source   = "INSERT INTO Invoices " . "(inv_id, inv_cst_id, inv_status_flag, inv_title, inv_total) " .
                    "VALUES ({id}, {cstId}, {status}, {title}, {total})";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_cst_id',
                ],
                2 => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
                3 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                4 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 277,
                    'value' => 'id',
                ],
                1 => [
                    'type'  => 277,
                    'value' => 'cstId',
                ],
                2 => [
                    'type'  => 277,
                    'value' => 'status',
                ],
                3 => [
                    'type'  => 277,
                    'value' => 'title',
                ],
                4 => [
                    'type'  => 277,
                    'value' => 'total',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlInsertArithmeticInValues(): void
    {
        $source   = "INSERT INTO Invoices (inv_total) VALUES (100 + 50)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 43,
                    'left'  => [
                        'type'  => 258,
                        'value' => '100',
                    ],
                    'right' => [
                        'type'  => 258,
                        'value' => '50',
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlInsertFuncInValues(): void
    {
        $source   = "INSERT INTO Invoices (inv_title, inv_total) "
            . "VALUES (UPPER('test invoice'), 100.00)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
            ],
            'values'        => [
                0 => [
                    'type'      => 350,
                    'name'      => 'UPPER',
                    'arguments' => [
                        0 => [
                            'type'  => 260,
                            'value' => 'test invoice',
                        ],
                    ],
                ],
                1 => [
                    'type'  => 259,
                    'value' => '100.00',
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
    public function testMvcModelQueryPhqlInsertFieldsTrue(): void
    {
        $source   = "INSERT INTO Invoices (inv_title, inv_status_flag) VALUES ('New Invoice', TRUE)";
        $expected = [
            'type'          => 306,
            'qualifiedName' => [
                'type' => 355,
                'name' => 'Invoices',
            ],
            'fields'        => [
                0 => [
                    'type' => 355,
                    'name' => 'inv_title',
                ],
                1 => [
                    'type' => 355,
                    'name' => 'inv_status_flag',
                ],
            ],
            'values'        => [
                0 => [
                    'type'  => 260,
                    'value' => 'New Invoice',
                ],
                1 => [
                    'type' => 334,
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }
}
