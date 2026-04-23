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

final class BracketsWithSpaceNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-09
     */
    public function testMvcModelQueryPhqlSelectBracketsFieldSpaces(): void
    {
        $source   = "SELECT [First Name], [Last Name] FROM Contacts";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'First Name',
                        ],
                    ],
                    1 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Last Name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Contacts',
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
    public function testMvcModelQueryPhqlSelectBracketsFieldSpacesAlias(): void
    {
        $source   = "SELECT c.[First Name], c.[Last Name] " . "FROM Contacts AS c";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'First Name',
                        ],
                    ],
                    1 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'Last Name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Contacts',
                    ],
                    'alias'         => 'c',
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
    public function testMvcModelQueryPhqlSelectBracketsFieldSpacesAliasWhereString(): void
    {
        $source   = "SELECT c.[First Name] " . "FROM Contacts AS c " . "WHERE c.[Last Name] = 'Smith'";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'   => 355,
                            'domain' => 'c',
                            'name'   => 'First Name',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Contacts',
                    ],
                    'alias'         => 'c',
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type'   => 355,
                    'domain' => 'c',
                    'name'   => 'Last Name',
                ],
                'right' => [
                    'type'  => 260,
                    'value' => 'Smith',
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
    public function testMvcModelQueryPhqlSelectBracketsFieldSpacesOrderBy(): void
    {
        $source   = "SELECT [First Name] AS firstName, [Last Name] AS lastName "
                    . "FROM Contacts "
                    . "ORDER BY [Last Name] ASC";
        $expected = [
            'type'    => 309,
            'select'  => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'First Name',
                        ],
                        'alias'  => 'firstName',
                    ],
                    1 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Last Name',
                        ],
                        'alias'  => 'lastName',
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Contacts',
                    ],
                ],
            ],
            'orderBy' => [
                'column' => [
                    'type' => 355,
                    'name' => 'Last Name',
                ],
                'sort'   => 327,
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
    public function testMvcModelQueryPhqlSelectBracketsTableSpaces(): void
    {
        $source   = "SELECT * FROM [My Table]";
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
                        'name' => 'My Table',
                    ],
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }
}
