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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DescribeColumnsCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeColumns(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeColumns()");

        $table    = 'dialect_table';
        $expected = $this->getExpectedColumns();

        $I->assertEquals(
            $expected,
            $this->connection->describeColumns($table)
        );

        $I->assertEquals(
            $expected,
            $this->connection->describeColumns(
                $table,
                $this->getSchemaName()
            )
        );
    }
}
