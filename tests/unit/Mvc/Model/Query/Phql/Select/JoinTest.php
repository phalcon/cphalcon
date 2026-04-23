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

final class JoinTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcModelQueryPhqlSelectInnerJoinOnComplexCondition(): void
    {
        $source   = "SELECT i.inv_id, c.name FROM Invoices AS i "
            . "INNER JOIN Customers AS c "
            . "ON (i.inv_cst_id = c.id AND i.inv_status_flag = 1)";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 360,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type' => 356,
                        'left' => [
                            'type'  => 61,
                            'left'  => [
                                'type'  => 61,
                                'left'  => [
                                    'type'   => 355,
                                    'domain' => 'i',
                                    'name'   => 'inv_cst_id',
                                ],
                                'right' => [
                                    'type'  => 266,
                                    'left'  => [
                                        'type'   => 355,
                                        'domain' => 'c',
                                        'name'   => 'id',
                                    ],
                                    'right' => [
                                        'type'   => 355,
                                        'domain' => 'i',
                                        'name'   => 'inv_status_flag',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type'  => 258,
                                'value' => '1',
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
    public function testMvcModelQueryPhqlSelectCrossJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name " . "FROM Invoices AS i " . "CROSS JOIN Customers AS c";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'      => 363,
                    'qualified' => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'     => [
                        'type' => 355,
                        'name' => 'c',
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
    public function testMvcModelQueryPhqlSelectFullJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "FULL JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 364,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectFullOuterJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "FULL OUTER JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 364,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectInnerJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "INNER JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 360,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectInnerLeftJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name, p.description "
            . "FROM Invoices AS i "
            . "INNER JOIN Customers AS c ON i.inv_cst_id = c.id "
            . "LEFT JOIN Products AS p ON i.inv_id = p.inv_id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                    2 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'p',
                            'name'   => 'description',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    0 => [
                        'type'       => 360,
                        'qualified'  => [
                            'type' => 355,
                            'name' => 'Customers',
                        ],
                        'alias'      => [
                            'type' => 355,
                            'name' => 'c',
                        ],
                        'conditions' => [
                            'type'  => 61,
                            'left'  => [
                                'type'   => 355,
                                'domain' => 'i',
                                'name'   => 'inv_cst_id',
                            ],
                            'right' => [
                                'type'   => 355,
                                'domain' => 'c',
                                'name'   => 'id',
                            ],
                        ],
                    ],
                    1 => [
                        'type'       => 361,
                        'qualified'  => [
                            'type' => 355,
                            'name' => 'Products',
                        ],
                        'alias'      => [
                            'type' => 355,
                            'name' => 'p',
                        ],
                        'conditions' => [
                            'type'  => 61,
                            'left'  => [
                                'type'   => 355,
                                'domain' => 'i',
                                'name'   => 'inv_id',
                            ],
                            'right' => [
                                'type'   => 355,
                                'domain' => 'p',
                                'name'   => 'inv_id',
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
    public function testMvcModelQueryPhqlSelectJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 360,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectLeftJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
            . "FROM Invoices AS i "
            . "LEFT JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 361,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectLeftOuterJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "LEFT OUTER JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 361,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectRightJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "RIGHT JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 362,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
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
    public function testMvcModelQueryPhqlSelectRightOuterJoin(): void
    {
        $source   = "SELECT i.inv_id, c.name "
                    . "FROM Invoices AS i "
                    . "RIGHT OUTER JOIN Customers AS c ON i.inv_cst_id = c.id";
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
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Invoices',
                    ],
                    'alias'         => 'i',
                ],
                'joins'   => [
                    'type'       => 362,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'Customers',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'c',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'i',
                            'name'   => 'inv_cst_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'id',
                        ],
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
