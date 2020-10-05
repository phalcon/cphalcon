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

class ModifyColumnCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: modifyColumn()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-27
     * @since  2020-05-02 Changed default null and nullable column definition
     */
    public function dbAdapterPdoMysqlModifyColumn(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - modifyColumn()');

        $modifications = [
            [
                new Column(
                    'updated_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP",
                        'notNull' => true,
                        'after'   => 'created_at',
                    ]
                ),
                new Column(
                    'updated_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP",
                        'notNull' => true,
                        'after'   => 'created_at',
                    ]
                ),
                'ALTER TABLE `test` MODIFY `updated_at` TIMESTAMP NOT NULL ' .
                'DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP AFTER `created_at`',
            ],
            [
                new Column(
                    'deleted_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP",
                        'notNull' => false,
                        'after'   => 'updated_at',
                    ]
                ),
                new Column(
                    'deleted_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "NULL",
                        'notNull' => false,
                        'after'   => 'updated_at',
                    ]
                ),
                'ALTER TABLE `test` MODIFY `deleted_at` TIMESTAMP NULL DEFAULT NULL AFTER `updated_at`',
            ],
            [
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'notNull' => true,
                        'after'   => 'updated_at',
                    ]
                ),
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'default' => 21.42,
                        'notNull' => false,
                        'after'   => 'updated_at',
                    ]
                ),
                'ALTER TABLE `test` MODIFY `numeric_val` FLOAT NULL DEFAULT 21.42 AFTER `updated_at`',
            ],
            [
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'notNull' => true,
                        'after'   => 'updated_at',
                    ]
                ),
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'default' => 21.42,
                        'notNull' => false,
                        'after'   => 'updated_at',
                        'comment' => 'test'
                    ]
                ),
                'ALTER TABLE `test` MODIFY `numeric_val` FLOAT NULL DEFAULT 21.42 COMMENT \'test\' AFTER `updated_at`',
            ],
        ];

        $mysql = new Mysql();
        foreach ($modifications as [$currentColumn, $column, $expected]) {
            $sql = $mysql->modifyColumn('test', '', $column, $currentColumn);

            $I->assertSame($expected, $sql);
        }
    }
}
