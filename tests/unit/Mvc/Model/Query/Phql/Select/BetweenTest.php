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

final class BetweenTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectBetweenFloat(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_total BETWEEN 10.00 AND 500.00";
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
                'type'  => 331,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
                'right' => [
                    'type'  => 266,
                    'left'  => [
                        'type'  => 259,
                        'value' => '10.00',
                    ],
                    'right' => [
                        'type'  => 259,
                        'value' => '500.00',
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
    public function testMvcModelQueryPhqlSelectBetweenInt(): void
    {
        $source   = "SELECT * "
            . "FROM Invoices "
            . "WHERE inv_id BETWEEN 1 AND 100";
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
                'type'  => 331,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 266,
                    'left'  => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                    'right' => [
                        'type'  => 258,
                        'value' => '100',
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
    public function testMvcModelQueryPhqlSelectNotBetweenFloat(): void
    {
        $source   = "SELECT * " . "FROM Invoices " . "WHERE inv_total NOT BETWEEN 10.00 AND 500.00";
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
                'type'  => 332,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_total',
                ],
                'right' => [
                    'type'  => 266,
                    'left'  => [
                        'type'  => 259,
                        'value' => '10.00',
                    ],
                    'right' => [
                        'type'  => 259,
                        'value' => '500.00',
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
    public function testMvcModelQueryPhqlSelectNotBetweenInt(): void
    {
        $source   = "SELECT * " . "FROM Invoices " . "WHERE inv_id NOT BETWEEN 1 AND 100";
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
                'type'  => 332,
                'left'  => [
                    'type' => 355,
                    'name' => 'inv_id',
                ],
                'right' => [
                    'type'  => 266,
                    'left'  => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                    'right' => [
                        'type'  => 258,
                        'value' => '100',
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
