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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;

class AddColumnCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: addColumn()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-02
     */
    public function dbAdapterPdoMysqlAddColumn(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - addColumn()');

        $additions = [
            [
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'default' => 21.42,
                        'notNull' => true,
                    ]
                ),
                'ALTER TABLE `test` ADD `numeric_val` FLOAT NOT NULL DEFAULT 21.42',
            ],
            [
                new Column(
                    'null_int',
                    [
                        'type'    => Column::TYPE_INTEGER,
                        'notNull' => false,
                        'after'   => 'numeric_val',
                    ]
                ),
                'ALTER TABLE `test` ADD `null_int` INT(11) NULL AFTER `numeric_val`',
            ],
            [
                new Column(
                    'created_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP",
                        'notNull' => true,
                        'after'   => 'created_at',
                    ]
                ),
                'ALTER TABLE `test` ADD `created_at` TIMESTAMP NOT NULL' .
                'DEFAULT CURRENT_TIMESTAMP AFTER `null_int`',
            ],
            [
                new Column(
                    'updated_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP",
                        'notNull' => true,
                        'after'   => 'created_at',
                    ]
                ),
                'ALTER TABLE `test` ADD `updated_at` TIMESTAMP NOT NULL' .
                'DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP AFTER `created_at`',
            ],
            [
                new Column(
                    'deleted_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'notNull' => false,
                        'after'   => 'created_at',
                    ]
                ),
                'ALTER TABLE `test` ADD `deleted_at` TIMESTAMP NULL AFTER `updated_at`',
            ],
        ];

        $mysql = new Mysql();
        foreach ($additions as [$column, $expected]) {
            $sql = $mysql->addColumn('test', '', $column);

            $I->assertSame($expected, $sql);
        }
    }
}
