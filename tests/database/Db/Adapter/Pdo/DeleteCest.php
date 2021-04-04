<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
declare(strict_types = 1);
namespace Phalcon\Test\Database\Db\Adapter\Pdo;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DeleteCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since 2022-04-04
     *       
     * @group  pgsql
     * @group  mysql
     * @group  sqlite
     */
    public function dbAdapterPdoQuery(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - delete()');

        $connection = $I->getConnection();
        $db = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $db->delete('public.co_invoices', 'inv_id = :id', [
            'id' => 267
        ]);
    }
}

