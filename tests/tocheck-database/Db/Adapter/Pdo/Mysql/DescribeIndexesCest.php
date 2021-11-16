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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DescribeIndexesCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeIndexes(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeIndexes()");

        $table    = 'dialect_table';
        $expected = $this->getExpectedIndexes();

        $I->assertEquals(
            $expected,
            $this->connection->describeIndexes($table)
        );

        $I->assertEquals(
            $expected,
            $this->connection->describeIndexes(
                $table,
                $this->getSchemaName()
            )
        );
    }
}
