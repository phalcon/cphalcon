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

namespace Phalcon\Test\Database\Db\Adapter\Pdo;

use DatabaseTester;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Migrations\ComplexDefaultMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;

final class DescribeColumnsCest
{
    use DiTrait;

    /**
     * @param DatabaseTester $I
     * @throws Exception
     */
    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-02
     *
     * @group mysql
     */
    public function dbAdapterPdoDescribeColumnsOnUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - describeColumns()');

        $connection = $I->getConnection();
        $db = $this->container->get('db');

        $now = date('Y-m-d H:i:s');
        $migration = new ComplexDefaultMigration($connection);
        $migration->insert(1, $now, $now);

        $columns = $db->describeColumns($migration->getTable());

        $I->assertSame('CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP', $columns[2]->getDefault());
        $I->assertSame('NULL on update CURRENT_TIMESTAMP', $columns[3]->getDefault());
    }
}
