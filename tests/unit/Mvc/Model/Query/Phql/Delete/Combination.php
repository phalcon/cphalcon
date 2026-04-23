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

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Phql\Delete;

use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Tests\AbstractUnitTestCase;

final class Combination extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlDelete(): void
    {
        $source   = "DELETE FROM Invoices";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
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
    public function testMvcModelQueryPhqlDeleteAliasWhereEqZero(): void
    {
        $source   = "DELETE FROM Invoices AS i WHERE i.inv_status_flag = 0";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type'   => 355,
                    'domain' => 'i',
                    'name'   => 'inv_status_flag',
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
    public function testMvcModelQueryPhqlDeleteLimit(): void
    {
        $source   = "DELETE FROM Invoices LIMIT 10";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlDeleteWhereEqNum(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_id = 1";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
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
    public function testMvcModelQueryPhqlDeleteWhereEqPlaceholder(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_id = :id:";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
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
    public function testMvcModelQueryPhqlDeleteWhereEqPlaceholderNumeric(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_id = ?0";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
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
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 273,
                    'value' => '?0',
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
    public function testMvcModelQueryPhqlDeleteWhereEqZero(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_status_flag = 0";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
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
    public function testMvcModelQueryPhqlDeleteWhereIn(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_cst_id IN (1, 2, 3)";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
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
    public function testMvcModelQueryPhqlDeleteWhereIsNull(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_created_at IS NULL";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'where'  => [
                'type' => 365,
                'left' => [
                    'type' => 355,
                    'name' => 'inv_created_at',
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
    public function testMvcModelQueryPhqlDeleteWhereLtNumLimit(): void
    {
        $source   = "DELETE FROM Invoices WHERE inv_total < 0 LIMIT 3";
        $expected = [
            'type'   => 303,
            'delete' => [
                'tables' => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 60,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '0',
                ],
            ],
            'limit'  => [
                'number' => [
                    'type'  => 258,
                    'value' => '3',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        $this->assertSame($expected, $actual);
    }
}
