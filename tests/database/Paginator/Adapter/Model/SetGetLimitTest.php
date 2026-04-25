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

namespace Phalcon\Tests\Database\Paginator\Adapter\Model;

use PDO;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class SetGetLimitTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Paginator\Adapter\Model :: getLimit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testPaginatorAdapterModelGetLimit(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        $invId = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 11, $invId, 3, 'aaa');
        $this->insertDataInvoices($migration, 31, $invId, 1, 'aaa');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $paginator = new Model(
            [
                'model' => Invoices::class,
                'limit' => 5,
                'page'  => 1,
            ]
        );

        $this->assertEquals(5, $paginator->getLimit());
        $paginator->setLimit(12);
        $this->assertEquals(12, $paginator->getLimit());
    }
}
