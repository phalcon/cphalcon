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

final class CaseTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectCaseSimple(): void
    {
        $source   = "SELECT CASE inv_status_flag "
            . "WHEN 0 THEN 'pending' "
            . "WHEN 1 THEN 'paid' "
            . "ELSE 'unknown' END "
            . "FROM Invoices";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'  => 409,
                            'left'  => [
                                'type' => 355,
                                'name' => 'inv_status_flag',
                            ],
                            'right' => [
                                0 => [
                                    'type'  => 410,
                                    'left'  => [
                                        'type'  => 258,
                                        'value' => '0',
                                    ],
                                    'right' => [
                                        'type'  => 260,
                                        'value' => 'pending',
                                    ],
                                ],
                                1 => [
                                    'type'  => 410,
                                    'left'  => [
                                        'type'  => 258,
                                        'value' => '1',
                                    ],
                                    'right' => [
                                        'type'  => 260,
                                        'value' => 'paid',
                                    ],
                                ],
                                2 => [
                                    'type' => 411,
                                    'left' => [
                                        'type'  => 260,
                                        'value' => 'unknown',
                                    ],
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
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectCaseSimpleAlias(): void
    {
        $source   = "SELECT CASE inv_status_flag "
            . "WHEN 0 THEN 'pending' "
            . "WHEN 1 THEN 'paid' "
            . "ELSE 'unknown' END AS status "
            . "FROM Invoices";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'  => 409,
                            'left'  => [
                                'type' => 355,
                                'name' => 'inv_status_flag',
                            ],
                            'right' => [
                                0 => [
                                    'type'  => 410,
                                    'left'  => [
                                        'type'  => 258,
                                        'value' => '0',
                                    ],
                                    'right' => [
                                        'type'  => 260,
                                        'value' => 'pending',
                                    ],
                                ],
                                1 => [
                                    'type'  => 410,
                                    'left'  => [
                                        'type'  => 258,
                                        'value' => '1',
                                    ],
                                    'right' => [
                                        'type'  => 260,
                                        'value' => 'paid',
                                    ],
                                ],
                                2 => [
                                    'type' => 411,
                                    'left' => [
                                        'type'  => 260,
                                        'value' => 'unknown',
                                    ],
                                ],
                            ],
                        ],
                        'alias'  => 'status',
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
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectCaseSimpleInWhere(): void
    {
        $source   = "SELECT * FROM Invoices "
            . "WHERE CASE inv_status_flag WHEN 1 THEN 1 ELSE 0 END = 1";
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
                    'type'  => 409,
                    'left'  => [
                        'type' => 355,
                        'name' => 'inv_status_flag',
                    ],
                    'right' => [
                        0 => [
                            'type'  => 410,
                            'left'  => [
                                'type'  => 258,
                                'value' => '1',
                            ],
                            'right' => [
                                'type'  => 258,
                                'value' => '1',
                            ],
                        ],
                        1 => [
                            'type' => 411,
                            'left' => [
                                'type'  => 258,
                                'value' => '0',
                            ],
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
}
