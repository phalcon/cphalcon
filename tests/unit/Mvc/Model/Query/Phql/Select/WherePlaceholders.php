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

final class WherePlaceholders extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectWherePlaceholderNum(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_id = ?0";
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
                    'name' => 'inv_id',
                ],
                'right' => [
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
    public function testMvcModelQueryPhqlSelectWherePlaceholderNumAnd(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_id = ?1 AND inv_status_flag = ?2";
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
                        'name' => 'inv_id',
                    ],
                    'right' => [
                        'type'  => 266,
                        'left'  => [
                            'type'  => 273,
                            'value' => '?1',
                        ],
                        'right' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 273,
                    'value' => '?2',
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
    public function testMvcModelQueryPhqlSelectWherePlaceholderString(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_title = :title:";
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
                    'name' => 'inv_title',
                ],
                'right' => [
                    'type'  => 274,
                    'value' => 'title',
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
    public function testMvcModelQueryPhqlSelectWherePlaceholderStringAnd(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_cst_id = :custId: AND inv_status_flag = :status:";
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
                        'name' => 'inv_cst_id',
                    ],
                    'right' => [
                        'type'  => 266,
                        'left'  => [
                            'type'  => 274,
                            'value' => 'custId',
                        ],
                        'right' => [
                            'type' => 355,
                            'name' => 'inv_status_flag',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 274,
                    'value' => 'status',
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
    public function testMvcModelQueryPhqlSelectWherePlaceholderBrackets(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_id = {id}";
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
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 277,
                    'value' => 'id',
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
    public function testMvcModelQueryPhqlSelectWherePlaceholderBracketsAnd(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_cst_id = {custId} AND inv_total > {minTotal}";
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
                        'name' => 'inv_cst_id',
                    ],
                    'right' => [
                        'type'  => 266,
                        'left'  => [
                            'type'  => 277,
                            'value' => 'custId',
                        ],
                        'right' => [
                            'type' => 355,
                            'name' => 'inv_total',
                        ],
                    ],
                ],
                'right' => [
                    'type'  => 277,
                    'value' => 'minTotal',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
