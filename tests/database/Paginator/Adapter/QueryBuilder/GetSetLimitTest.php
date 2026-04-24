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

namespace Phalcon\Tests\Database\Paginator\Adapter\QueryBuilder;

use PDO;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSetLimitTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getLimit() / setLimit()
     *
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterQuerybuilderGetSetLimit(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $this->assertEquals(5, $paginator->getLimit());
        $paginator->setLimit(12);
        $this->assertEquals(12, $paginator->getLimit());

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Limit must be greater than zero');

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 0,
                'page'    => 1,
            ]
        );

        $paginator->paginate();
    }
}
