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
     */
    public function dbAdapterPdoMysqlModifyColumn(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - modifyColumn()');

        $currentColumn = new Column(
            'updated_at',
            [
                'type' => Column::TYPE_TIMESTAMP,
                'default' => "CURRENT_TIMESTAMP",
                'notNull' => false,
                'after' => 'created_at'
            ]
        );

        $column = new Column(
            'updated_at',
            [
                'type' => Column::TYPE_TIMESTAMP,
                'default' => "CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP",
                'notNull' => false,
                'after' => 'created_at'
            ]
        );

        $mysql = new Mysql();
        $sql = $mysql->modifyColumn('test', '', $column, $currentColumn);
        $expected = 'ALTER TABLE `test` MODIFY `updated_at` TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NULL AFTER `created_at`';

        $I->assertSame($expected, $sql);
    }
}
