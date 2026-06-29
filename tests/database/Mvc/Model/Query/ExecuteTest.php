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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Row;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ExecuteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private InvoicesMigration $invoiceMigration;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->invoiceMigration = new InvoicesMigration(self::getConnection());
        $this->invoiceMigration->insert(1, 1, 0, 'Title 1');
        $this->invoiceMigration->insert(2, 2, 1, 'Title 2');
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: execute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryExecute(): void
    {
        $manager = $this->container->get('modelsManager');

        $query  = $manager->createQuery('SELECT * FROM ' . Invoices::class);
        $result = $query->execute();

        $this->assertInstanceOf(ResultsetInterface::class, $result);
        $this->assertSame(2, $result->count());
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     */
    public function testMvcModelQueryExecuteWithCommonTableExpressionWildcard(): void
    {
        $phql = sprintf(
            'WITH recent (id, title) AS ('
            . 'SELECT i.inv_id, i.inv_title FROM [%s] AS i '
            . 'WHERE i.inv_id = 1'
            . ') SELECT * FROM recent',
            Invoices::class
        );

        (new Query($phql, $this->container))->getSql();

        $result = (new Query($phql, $this->container))->execute();

        $this->assertSame(1, $result->count());

        $row = $result->getFirst();

        $this->assertInstanceOf(Row::class, $row);
        $this->assertSame(1, $row->id);
        $this->assertSame('Title 1', $row->title);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     */
    public function testMvcModelQueryExecuteWithInferredCommonTableExpressionColumns(): void
    {
        $phql = sprintf(
            'WITH recent AS ('
            . 'SELECT i.* FROM [%s] AS i WHERE i.inv_id = 1'
            . ') '
            . 'SELECT recent.* FROM recent',
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->execute();

        $this->assertSame(1, $result->count());

        $row = $result->getFirst();

        $this->assertInstanceOf(Row::class, $row);
        $this->assertSame(1, $row->inv_id);
        $this->assertSame('Title 1', $row->inv_title);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     */
    public function testMvcModelQueryExecuteWithUnnamedCommonTableExpressionColumn(): void
    {
        $phql = sprintf(
            'WITH totals AS (SELECT COUNT(*) FROM [%s]) '
            . 'SELECT * FROM totals',
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->execute();

        $this->assertSame(1, $result->count());
        $this->assertEquals(2, $result->getFirst()->column_0);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     */
    public function testMvcModelQueryExecuteWithOverlappingCommonTableExpressionColumns(): void
    {
        $phql = sprintf(
            'WITH first_rows (id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i WHERE i.inv_id = 1'
            . '), second_rows (id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i WHERE i.inv_id = 2'
            . ') SELECT first_rows.*, second_rows.* '
            . 'FROM first_rows, second_rows',
            Invoices::class,
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->execute();

        $this->assertSame(1, $result->count());

        $row = $result->getFirst();

        $this->assertInstanceOf(Row::class, $row);
        $this->assertSame(1, $row->id);
        $this->assertSame(2, $row->second_rows_id);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     */
    public function testMvcModelQueryExecuteWithCommonTableExpressionColumnBeforeOverlappingModelColumn(): void
    {
        $phql = sprintf(
            'WITH recent (inv_id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i WHERE i.inv_id = 1'
            . ') SELECT recent.*, i.inv_id '
            . 'FROM recent, [%s] AS i WHERE i.inv_id = 2',
            Invoices::class,
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->execute();

        $this->assertSame(1, $result->count());

        $row = $result->getFirst();

        $this->assertInstanceOf(Row::class, $row);
        $this->assertSame(1, $row->recent_inv_id);
        $this->assertSame(2, $row->inv_id);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     */
    public function testMvcModelQueryExecuteWithCommonTableExpressionBindings(): void
    {
        for ($id = 3; $id <= 4; $id++) {
            $this->invoiceMigration->insert($id, 10, 1, 'invoice-' . $id);
        }

        $subBuilder = new Builder(null, $this->container);
        $subBuilder
            ->columns('i.inv_id')
            ->from(['i' => Invoices::class])
            ->where('i.inv_status_flag = :status:', ['status' => 1])
            ->orderBy('i.inv_id')
            ->limit(3, 1);

        $builder = new Builder(null, $this->container);
        $builder
            ->addWith('recent', $subBuilder, ['id'])
            ->columns('recent.id')
            ->from('recent')
            ->where('recent.id > :id:', ['id' => 0])
            ->orderBy('recent.id')
            ->limit(1, 1);

        $result = $builder->getQuery()->execute();

        $this->assertSame(1, $result->count());
        $this->assertSame(4, $result->getFirst()->id);
    }
}
