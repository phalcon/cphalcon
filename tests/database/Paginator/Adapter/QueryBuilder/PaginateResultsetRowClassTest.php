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
use Phalcon\Paginator\Repository;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\CustomResultsetRow;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class PaginateResultsetRowClassTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: paginate() - custom
     * resultset row class set on the builder is honored by the paginated items
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-14
     * @issue  https://github.com/phalcon/cphalcon/pull/17340
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQueryBuilderPaginateResultsetRowClass(): void
    {
        $migration = new InvoicesMigration(self::getPdoConnection());
        $migration->insert(1, 1, 0, 'Title 1');
        $migration->insert(2, 1, 0, 'Title 2');

        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->columns('inv_id, inv_title')
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;
        $builder->setResultsetRowClass(CustomResultsetRow::class);

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $page  = $paginator->paginate();
        $items = $page->getItems();

        $this->assertInstanceOf(Repository::class, $page);
        $this->assertCount(2, $items);
        $this->assertEquals(2, $page->getTotalItems());

        foreach ($items as $item) {
            $this->assertInstanceOf(CustomResultsetRow::class, $item);
        }

        $this->assertSame('TITLE 1', $items->getFirst()->getUpperTitle());
    }
}
