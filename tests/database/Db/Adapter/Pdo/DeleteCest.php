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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use DatabaseTester;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

final class DeleteCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Db\Adapter\AbstractAdapter :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since 2021-05-10
     *
     * @group  pgsql
     * @group  mysql
     * @group  sqlite
     */
    public function dbAdapterPdoQuery(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - delete()');

        $connection = $I->getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);
        $migration->insert(2, 1, 1, 'title 2', 102);
        $migration->insert(3, 1, 1, 'title 3', 103);

        $I->assertSame(3, Invoices::count());

        $db->delete($migration->getTable(), 'inv_id > :id', [
            'id' => 1,
        ]);

        $I->assertSame(1, Invoices::count());
    }
}
