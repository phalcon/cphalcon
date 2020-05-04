<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Db\Adapter\Pdo;

use DatabaseTester;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Migrations\ComplexDefaultMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;

final class DescribeColumnsCest
{
    use DiTrait;

    /**
     * @var ComplexDefaultMigration
     */
    private $migration;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);

        $this->migration = new ComplexDefaultMigration($I->getConnection());
    }

    /**
     * Executed after each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _after(DatabaseTester $I): void
    {
        if ($this->migration) {
            $this->migration->clear();
        }
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-02
     *
     * @group  mysql
     */
    public function dbAdapterPdoDescribeColumnsOnUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - describeColumns()');

        $db  = $this->container->get('db');
        $now = date('Y-m-d H:i:s');

        $this->migration->insert(1, $now, $now);

        $columns = $db->describeColumns($this->migration->getTable());

        $I->assertSame('CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP', $columns[2]->getDefault());
        $I->assertSame('NULL on update CURRENT_TIMESTAMP', $columns[3]->getDefault());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns()
     *
     * @param  DatabaseTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-03-09
     *
     * @group  pgsql
     */
    public function dbAdapterPdoDescribeColumnsDefaultPostgres(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - describeColumns() - CheckPostgres Default value');

        $db  = $this->container->get('db');
        $now = date('Y-m-d H:i:s');

        $this->migration->insert(1, $now, $now);

        $columns = $db->describeColumns($this->migration->getTable());

        $I->assertSame('CURRENT_TIMESTAMP', $columns[1]->getDefault());

        if ($I->getDriver() === 'mysql') {
            $I->assertSame('CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP', $columns[2]->getDefault());
        } else {
            $I->assertSame('CURRENT_TIMESTAMP', $columns[2]->getDefault());
        }
    }
}
