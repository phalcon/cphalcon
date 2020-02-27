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
     */
    public function dbAdapterPdoMysqlCreateTable(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - createTable()');

        $definition = [
            'columns' => [
                new Column(
                    'id',
                    [
                        'type' => Column::TYPE_INTEGER,
                        'notNull' => true,
                        'autoIncrement' => true,
                        'size' => 11,
                        'first' => true
                    ]
                ),
                new Column(
                    'updated_at',
                    [
                        'type' => Column::TYPE_TIMESTAMP,
                        'default' => "CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP",
                        'notNull' => false,
                        'after' => 'created_at'
                    ]
                ),
            ],
            'indexes' => [
                new Index('PRIMARY', ['id'], 'PRIMARY'),
            ],
        ];

        $mysql = new Mysql();
        $sql = $mysql->createTable('test', '', $definition);
        $expected = <<<SQL
CREATE TABLE `test` (
	`id` INT(11) NOT NULL AUTO_INCREMENT,
	`updated_at` TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NULL,
	PRIMARY KEY (`id`)
)
SQL;

        $I->assertSame($expected, $sql);
    }
}
