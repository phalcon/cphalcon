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

final class BitwiseTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectBitwiseAnd(): void
    {
        $source   = "SELECT * " . "FROM Invoices " . "WHERE inv_status_flag & 1 = 1";
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
                    'type'  => 38,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'right' => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '1',
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
    public function testMvcModelQueryPhqlSelectBitwiseInField(): void
    {
        $source   = "SELECT inv_status_flag & 3 AS masked " . "FROM Invoices";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'  => 38,
                            'left'  => [
                                'type' => 355,
                                'name' => 'inv_status_flag',
                            ],
                            'right' => [
                                'type'  => 258,
                                'value' => '3',
                            ],
                        ],
                        'alias'  => 'masked',
                    ],
                ],
                'tables'  => [
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
    public function testMvcModelQueryPhqlSelectBitwiseNotField(): void
    {
        $source   = "SELECT ~inv_status_flag " . "FROM Invoices";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'  => 126,
                            'right' => [
                                'type' => 355,
                                'name' => 'inv_status_flag',
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
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectBitwiseOr(): void
    {
        $source   = "SELECT * " . "FROM Invoices " . "WHERE inv_status_flag | 2 = 3";
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
                    'type'  => 124,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'right' => [
                        'type'  => 258,
                        'value' => '2',
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '3',
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
    public function testMvcModelQueryPhqlSelectBitwiseXor(): void
    {
        $source   = "SELECT * " . "FROM Invoices " . "WHERE inv_status_flag ^ 1 = 0";
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
                    'type'  => 94,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'right' => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
                'right' => [
                    'type'  => 258,
                    'value' => '0',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
