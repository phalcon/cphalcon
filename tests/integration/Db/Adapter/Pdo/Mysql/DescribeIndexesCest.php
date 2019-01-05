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
 * Class DescribeIndexesCest
 */
class DescribeIndexesCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeIndexes()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeIndexes(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeIndexes()");
        $table    = 'dialect_table';
        $expected = $this->getExpectedIndexes();
        $I->assertEquals($expected, $this->connection->describeIndexes($table));
        $I->assertEquals($expected, $this->connection->describeIndexes($table, $this->getSchemaName()));
    }
}
