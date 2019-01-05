<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class TableOptionsCest
 */
class TableOptionsCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: tableOptions()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlTableOptions(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - tableOptions()');
        $table    = 'dialect_table';
        $expected = [
            'auto_increment'  => '1',
            'engine'          => 'InnoDB',
            'table_collation' => 'utf8_general_ci',
            'table_type'      => 'BASE TABLE',
        ];

        $actual = $this->connection->tableOptions($table, $this->getDatabaseName());
        $I->assertEquals($expected, $actual);
    }
}
