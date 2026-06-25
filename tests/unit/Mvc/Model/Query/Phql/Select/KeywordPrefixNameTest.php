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

final class KeywordPrefixNameTest extends AbstractUnitTestCase
{

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16831
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     */
    public function testMvcModelQueryPhqlSelectJoinPrefixNotColumn(): void
    {
        $source   = "SELECT * FROM Robots r "
            . "LEFT JOIN RobotsParts rp ON r.notes_id = rp.robots_id";
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
                        'name' => 'Robots',
                    ],
                    'alias'         => 'r',
                ],
                'joins'   => [
                    'type'       => 361,
                    'qualified'  => [
                        'type' => 355,
                        'name' => 'RobotsParts',
                    ],
                    'alias'      => [
                        'type' => 355,
                        'name' => 'rp',
                    ],
                    'conditions' => [
                        'type'  => 61,
                        'left'  => [
                            'type'   => 355,
                            'domain' => 'r',
                            'name'   => 'notes_id',
                        ],
                        'right' => [
                            'type'   => 355,
                            'domain' => 'rp',
                            'name'   => 'robots_id',
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
    public function testMvcModelQueryPhqlSelectPrefixGroups(): void
    {
        $source   = "SELECT Groups FROM Settings";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Groups',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Settings',
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
    public function testMvcModelQueryPhqlSelectPrefixGroupsBrackets(): void
    {
        $source   = "SELECT [Groups] FROM Settings";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Groups',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Settings',
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
    public function testMvcModelQueryPhqlSelectPrefixNotes(): void
    {
        $source   = "SELECT Notes FROM Contacts";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Notes',
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
    public function testMvcModelQueryPhqlSelectPrefixNotesBrackets(): void
    {
        $source   = "SELECT [Notes] FROM Contacts";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Notes',
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
    public function testMvcModelQueryPhqlSelectPrefixOrders(): void
    {
        $source   = "SELECT Orders FROM Customers";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Orders',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Customers',
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
    public function testMvcModelQueryPhqlSelectPrefixOrdersBrackets(): void
    {
        $source   = "SELECT [Orders] FROM Customers";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type' => 355,
                            'name' => 'Orders',
                        ],
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Customers',
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
    public function testMvcModelQueryPhqlSelectPrefixWhereNotesIsNotNull(): void
    {
        $source   = "SELECT * FROM Contacts WHERE [Notes] IS NOT NULL";
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
                        'name' => 'Contacts',
                    ],
                ],
            ],
            'where'  => [
                'type' => 366,
                'left' => [
                    'type' => 355,
                    'name' => 'Notes',
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
    public function testMvcModelQueryPhqlSelectPrefixWhereNotesLike(): void
    {
        $source   = "SELECT * FROM Contacts WHERE [Notes] LIKE '%important%'";
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
                        'name' => 'Contacts',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 268,
                'left'  => [
                    'type' => 355,
                    'name' => 'Notes',
                ],
                'right' => [
                    'type'  => 260,
                    'value' => '%important%',
                ],
            ],
        ];
        $actual   = Lang::parsePhql($source);
        unset($actual['id']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17087
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testMvcModelQueryPhqlSelectPrefixWhereNotificationSentEquals(): void
    {
        $source   = "SELECT COUNT(*) AS rowcount FROM Travel "
            . "WHERE notification_sent=1";
        $expected = [
            'type'   => 309,
            'select' => [
                'columns' => [
                    0 => [
                        'type'   => 354,
                        'column' => [
                            'type'      => 350,
                            'name'      => 'COUNT',
                            'arguments' => [
                                0 => [
                                    'type' => 352,
                                ],
                            ],
                        ],
                        'alias'  => 'rowcount',
                    ],
                ],
                'tables'  => [
                    'qualifiedName' => [
                        'type' => 355,
                        'name' => 'Travel',
                    ],
                ],
            ],
            'where'  => [
                'type'  => 61,
                'left'  => [
                    'type' => 355,
                    'name' => 'notification_sent',
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
