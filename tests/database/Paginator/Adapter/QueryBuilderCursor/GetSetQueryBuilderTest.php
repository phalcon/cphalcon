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

namespace Phalcon\Tests\Database\Paginator\Adapter\QueryBuilderCursor;

use PDO;
use Phalcon\Paginator\Adapter\QueryBuilderCursor;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

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
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor ::
     * getQueryBuilder() / setQueryBuilder()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorGetSetQueryBuilder(): void
    {
        $manager  = $this->getService('modelsManager');
        $builder1 = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder1,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $this->assertSame($builder1, $paginator->getQueryBuilder());

        $builder2 = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->where('inv_cst_id = :custId:', ['custId' => 1])
            ->orderBy('inv_id')
        ;

        $result = $paginator->setQueryBuilder($builder2);

        $this->assertSame($builder2, $paginator->getQueryBuilder());
        $this->assertSame($paginator, $result);
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor ::
     * getCursor() / setCursor()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorGetSetCursor(): void
    {
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $this->assertNull($paginator->getCursor());

        $result = $paginator->setCursor(42);
        $this->assertSame(42, $paginator->getCursor());
        $this->assertSame($paginator, $result);

        $paginator->setCursor(null);
        $this->assertNull($paginator->getCursor());
    }
}
