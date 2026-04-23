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

final class WhereLogicalTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectWhereAnd(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_status_flag = 1 AND inv_total > 0";
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
                'type'  => 62,
                'left'  => [
                    'type'  => 61,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
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
                    'type'  => 258,
                    'value' => '0',
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
    public function testMvcModelQueryPhqlSelectWhereOr(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_status_flag = 0 OR inv_status_flag = 1";
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
                    'type'  => 61,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'right' => [
                        'type'  => 267,
                        'left'  => [
                            'type'  => 258,
                            'value' => '0',
                        ],
                        'right' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
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
    public function testMvcModelQueryPhqlSelectWhereAndAnd(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_cst_id = 1 AND inv_status_flag = 1 AND inv_total > 0";
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
                'type'  => 62,
                'left'  => [
                    'type'  => 61,
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
                                'name' => 'inv_status_flag',
                            ],
                        ],
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
                    'type'  => 258,
                    'value' => '0',
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
    public function testMvcModelQueryPhqlSelectWhereNot(): void
    {
        $source   = "SELECT * FROM Invoices WHERE NOT inv_status_flag = 0";
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
                    'type'  => 33,
                    'right' => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectWhereParenthesesOrAnd(): void
    {
        $source   = "SELECT * FROM Invoices WHERE (inv_status_flag = 1 OR inv_status_flag = 2) AND inv_total > 0";
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
                'type'  => 62,
                'left'  => [
                    'type'  => 266,
                    'left'  => [
                        'type' => 356,
                        'left' => [
                            'type'  => 61,
                            'left'  => [
                                'type'  => 61,
                                'left'  => [
                                    'type' => 355,
                                    'name' => 'inv_status_flag',
                                ],
                                'right' => [
                                    'type'  => 267,
                                    'left'  => [
                                        'type'  => 258,
                                        'value' => '1',
                                    ],
                                    'right' => [
                                        'type' => 355,
                                        'name' => 'inv_status_flag',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type'  => 258,
                                'value' => '2',
                            ],
                        ],
                    ],
                    'right' => [
                        'type' => 355,
                        'name' => 'inv_total',
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
