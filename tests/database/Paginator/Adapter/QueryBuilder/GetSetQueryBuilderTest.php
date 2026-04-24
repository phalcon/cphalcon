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
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSetQueryBuilderTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getQueryBuilder() /
     * setQueryBuilder()
     *
     * @group mysql
     * @group sqlite
     */
    public function testPaginatorAdapterQuerybuilderGetSetQueryBuilder(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 17, $invId, 2, 'ccc');
        $this->insertDataInvoices($migration, 15, $invId, 2, 'bbb');

        $manager  = $this->getService('modelsManager');
        $builder1 = $manager
            ->createBuilder()
            ->from(Invoices::class)
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder1,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $this->assertEquals($builder1, $paginator->getQueryBuilder());

        $builder2 = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->where('inv_cst_id = :custId:', ['custId' => 2])
        ;

        $result = $paginator->setQueryBuilder($builder2);

        $this->assertEquals($builder2, $paginator->getQueryBuilder());
        $this->assertEquals($paginator, $result);
    }
}
