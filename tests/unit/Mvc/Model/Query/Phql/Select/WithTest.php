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

final class WithTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     */
    public function testMvcModelQueryPhqlSelectWithCommonTableExpression(): void
    {
        $source   = "WITH recent AS (SELECT inv_id FROM Invoices) "
            . "SELECT recent.inv_id FROM recent";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'recent',
                            'name'   => 'inv_id',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'recent',
                    ],
                ],
            ],
            'with'   => [
                0 => [
                    'name'   => 'recent',
                    'select' => [
                        'type'   => 309,
                        'select' => [
                            'columns' => [
                                0 => [
                                    'type'   => 354,
                                    'column' => [
                                        'type' => 355,
                                        'name' => 'inv_id',
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
     * @since  2026-06-10
     */
    public function testMvcModelQueryPhqlSelectWithCommonTableExpressionColumns(): void
    {
        $source   = "WITH recent (id) AS (SELECT inv_id FROM Invoices) "
            . "SELECT recent.id FROM recent";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'recent',
                            'name'   => 'id',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'recent',
                    ],
                ],
            ],
            'with'   => [
                0 => [
                    'name'    => 'recent',
                    'columns' => [
                        0 => [
                            'type' => 355,
                            'name' => 'id',
                        ],
                    ],
                    'select'  => [
                        'type'   => 309,
                        'select' => [
                            'columns' => [
                                0 => [
                                    'type'   => 354,
                                    'column' => [
                                        'type' => 355,
                                        'name' => 'inv_id',
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
     * @since  2026-06-12
     */
    public function testMvcModelQueryPhqlSelectWithCommonTableExpressionUnion(): void
    {
        $source   = "WITH recent AS ("
            . "SELECT inv_id FROM Invoices "
            . "UNION SELECT inv_cst_id FROM Invoices"
            . ") SELECT recent.inv_id FROM recent";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'recent',
                            'name'   => 'inv_id',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'recent',
                    ],
                ],
            ],
            'with'   => [
                0 => [
                    'name'   => 'recent',
                    'select' => [
                        'type'   => 309,
                        'select' => [
                            'columns' => [
                                0 => [
                                    'type'   => 354,
                                    'column' => [
                                        'type' => 355,
                                        'name' => 'inv_id',
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
                        'union'  => [
                            0 => [
                                'select' => [
                                    'type'   => 309,
                                    'select' => [
                                        'columns' => [
                                            0 => [
                                                'type'   => 354,
                                                'column' => [
                                                    'type' => 355,
                                                    'name' => 'inv_cst_id',
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
                                ],
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
     * @since  2026-06-12
     */
    public function testMvcModelQueryPhqlSelectWithEscapedKeywordCommonTableExpressionName(): void
    {
        foreach (['union', 'recursive'] as $name) {
            $source = "WITH [" . $name . "] AS (SELECT inv_id FROM Invoices) "
                . "SELECT [" . $name . "].inv_id FROM [" . $name . "]";

            $actual = Lang::parsePhql($source);
            unset($actual['id']);

            $this->assertSame($name, $actual['with'][0]['name']);
            $this->assertSame($name, $actual['select']['columns'][0]['column']['domain']);
            $this->assertSame($name, $actual['select']['tables']['qualifiedName']['name']);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-12
     */
    public function testMvcModelQueryPhqlSelectWithRecursiveCommonTableExpression(): void
    {
        $source   = "WITH RECURSIVE recent (id) AS ("
            . "SELECT inv_id FROM Invoices "
            . "UNION ALL SELECT recent.id FROM recent"
            . ") SELECT recent.id FROM recent";
        $expected = [
            'type'          => 309,
            'select'        => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'recent',
                            'name'   => 'id',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'recent',
                    ],
                ],
            ],
            'with'          => [
                0 => [
                    'name'    => 'recent',
                    'columns' => [
                        0 => [
                            'type' => 355,
                            'name' => 'id',
                        ],
                    ],
                    'select'  => [
                        'type'   => 309,
                        'select' => [
                            'columns' => [
                                0 => [
                                    'type'   => 354,
                                    'column' => [
                                        'type' => 355,
                                        'name' => 'inv_id',
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
                        'union'  => [
                            0 => [
                                'all'    => true,
                                'select' => [
                                    'type'   => 309,
                                    'select' => [
                                        'columns' => [
                                            0 => [
                                                'type'   => 354,
                                                'column' => [
                                                    'type'   => 355,
                                                    'domain' => 'recent',
                                                    'name'   => 'id',
                                                ],
                                            ],
                                        ],
                                        'tables'  => [
                                            'qualifiedName' => [
                                                'type' => 355,
                                                'name' => 'recent',
                                            ],
                                        ],
                                    ],
                                ],
                            ],
                        ],
                    ],
                ],
            ],
            'withRecursive' => true,
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectWithCache(): void
    {
        $source   = "SELECT * FROM Invoices AS i WITH cache";
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
                    'alias'         => 'i',
                    'with'          => [
                        'type' => 355,
                        'name' => 'cache',
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
    public function testMvcModelQueryPhqlSelectWithCacheShared(): void
    {
        $source   = "SELECT * FROM Invoices AS i WITH (cache, shared)";
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
                    'alias'         => 'i',
                    'with'          => [
                        0 => [
                            'type' => 355,
                            'name' => 'cache',
                        ],
                        1 => [
                            'type' => 355,
                            'name' => 'shared',
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
