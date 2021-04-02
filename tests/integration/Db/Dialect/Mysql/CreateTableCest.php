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
use Phalcon\Db\Index;

class CreateTableCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: createTable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-27
     * @since  2020-05-02 Changed default null and nullable column definition
     */
    public function dbAdapterPdoMysqlCreateTable(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - createTable()');

        $definition = [
            'columns' => [
                new Column(
                    'id',
                    [
                        'type'          => Column::TYPE_INTEGER,
                        'notNull'       => true,
                        'autoIncrement' => true,
                        'size'          => 11,
                        'first'         => true,
                    ]
                ),
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'default' => 21.42,
                        'notNull' => true,
                    ]
                ),
                new Column(
                    'null_int',
                    [
                        'type'    => Column::TYPE_INTEGER,
                        'size'    => 11,
                        'notNull' => false,
                        'after'   => 'numeric_val',
                    ]
                ),
                new Column(
                    'created_at',
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
                new Column(
                    'deleted_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'notNull' => false,
                        'after'   => 'created_at',
                    ]
                ),
            ],
            'indexes' => [
                new Index('PRIMARY', ['id'], 'PRIMARY'),
            ],
        ];

        $mysql    = new Mysql();
        $sql      = $mysql->createTable('test', '', $definition);
        $expected = <<<SQL
CREATE TABLE `test` (
	`id` INT(11) NOT NULL AUTO_INCREMENT,
	`numeric_val` FLOAT NOT NULL DEFAULT 21.42,
	`null_int` INT(11) NULL,
	`created_at` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
	`updated_at` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	`deleted_at` TIMESTAMP NULL,
	PRIMARY KEY (`id`)
)
SQL;

        $I->assertSame($expected, $sql);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: createTable()
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function dbAdapterPdoMysqlCreateTableForComment(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - createTable()');

        $definition = [
            'columns' => [
                new Column(
                    'id',
                    [
                        'type'          => Column::TYPE_INTEGER,
                        'notNull'       => true,
                        'autoIncrement' => true,
                        'size'          => 11,
                        'first'         => true,
                        'comment'       => 'id',
                    ]
                ),
                new Column(
                    'numeric_val',
                    [
                        'type'    => Column::TYPE_FLOAT,
                        'default' => 21.42,
                        'notNull' => true,
                        'comment' => 'numeric_val',
                    ]
                ),
                new Column(
                    'null_int',
                    [
                        'type'    => Column::TYPE_INTEGER,
                        'size'    => 11,
                        'notNull' => false,
                        'after'   => 'numeric_val',
                        'comment' => 'null_int',
                    ]
                ),
                new Column(
                    'created_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP",
                        'notNull' => true,
                        'after'   => 'created_at',
                        'comment' => 'created_at',
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
                new Column(
                    'deleted_at',
                    [
                        'type'    => Column::TYPE_TIMESTAMP,
                        'notNull' => false,
                        'after'   => 'created_at',
                    ]
                ),
            ],
            'indexes' => [
                new Index('PRIMARY', ['id'], 'PRIMARY'),
            ],
        ];

        $mysql    = new Mysql();
        $sql      = $mysql->createTable('test', '', $definition);
        $expected = <<<SQL
CREATE TABLE `test` (
	`id` INT(11) NOT NULL AUTO_INCREMENT COMMENT 'id',
	`numeric_val` FLOAT NOT NULL DEFAULT 21.42 COMMENT 'numeric_val',
	`null_int` INT(11) NULL COMMENT 'null_int',
	`created_at` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'created_at',
	`updated_at` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	`deleted_at` TIMESTAMP NULL,
	PRIMARY KEY (`id`)
)
SQL;

        $I->assertSame($expected, $sql);
    }
}
