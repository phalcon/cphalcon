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

final class WhereIn extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectWhereIn(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_status_flag IN (0, 1, 2)";
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
                    'name' => 'inv_status_flag',
                ],
                'right' => [
                    0 => [
                        'type'  => 258,
                        'value' => '0',
                    ],
                    1 => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                    2 => [
                        'type'  => 258,
                        'value' => '2',
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
    public function testMvcModelQueryPhqlSelectWhereNotIn(): void
    {
        $source   = "SELECT * FROM Invoices WHERE inv_status_flag NOT IN (0, 1)";
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
                    'name' => 'inv_status_flag',
                ],
                'right' => [
                    0 => [
                        'type'  => 258,
                        'value' => '0',
                    ],
                    1 => [
                        'type'  => 258,
                        'value' => '1',
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
