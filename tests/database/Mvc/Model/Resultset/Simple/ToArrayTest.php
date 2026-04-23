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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Simple;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesWithColumnMap;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;

/**
 *
 * @group phql
 */
final class ToArrayTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'Title 1', 10.51, date('Y-m-d H:i:s'));
        $migration->insert(2, 123, 1, 'Title 2', 5.2, date('Y-m-d H:i:s'));
        $migration->insert(3, 321, 1, 'Title 3', 0.25);
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelResultsetSimpleToArray(): void
    {
        $rows1 = (new Builder())
            ->from([
                'Inv1' => Invoices::class,
            ])
            ->orderBy('Inv1.inv_id DESC')
            ->columns([
                'Inv1.inv_cst_id',
                'Inv1.inv_status_flag',
                'invoice_title' => 'Inv1.inv_title',
            ])
            ->getQuery()
            ->execute();

        $rows2 = (new Builder())
            ->from([
                'Inv2' => InvoicesWithColumnMap::class,
            ])
            ->orderBy('Inv2.id DESC')
            ->columns([
                'Inv2.id',
                'Inv2.status',
                'invoice_title' => 'Inv2.title',
            ])
            ->getQuery()
            ->execute();

        $rows3 = Invoices::find();
        $rows4 = Invoices::findFirst();
        $rows5 = InvoicesWithColumnMap::find();
        $rows6 = InvoicesWithColumnMap::findFirst();

        $renamedArray1   = $rows1->toArray();
        $renamedArray2   = $rows2->toArray();
        $renamedArray3   = $rows3->toArray();
        $renamedArray4   = $rows4->toArray();
        $renamedArray5   = $rows5->toArray();
        $renamedArray6   = $rows6->toArray();
        $untouchedArray1 = $rows1->toArray(false);
        $untouchedArray2 = $rows2->toArray(false);
        $untouchedArray3 = $rows3->toArray(false);
        $untouchedArray4 = $rows4->toArray(false);
        $untouchedArray5 = $rows5->toArray(false);
        $untouchedArray6 = $rows6->toArray(false);

        $this->assertIsArray($renamedArray1);
        $this->assertIsArray($renamedArray2);
        $this->assertIsArray($renamedArray3);
        $this->assertIsArray($renamedArray4);
        $this->assertIsArray($renamedArray5);
        $this->assertIsArray($renamedArray6);

        $this->assertIsArray($untouchedArray1);
        $this->assertIsArray($untouchedArray2);
        $this->assertIsArray($untouchedArray3);
        $this->assertIsArray($untouchedArray4);
        $this->assertIsArray($untouchedArray5);
        $this->assertIsArray($untouchedArray6);

        $this->assertArrayHasKey('invoice_title', $untouchedArray1[0]);
        $this->assertArrayHasKey('invoice_title', $renamedArray1[0]);

        $this->assertArrayHasKey('invoice_title', $untouchedArray2[0]);
        $this->assertArrayHasKey('invoice_title', $renamedArray2[0]);

        $this->assertArrayHasKey('inv_title', $untouchedArray3[0]);
        $this->assertArrayHasKey('inv_title', $renamedArray3[0]);

        $this->assertArrayHasKey('inv_title', $untouchedArray4);
        $this->assertArrayHasKey('inv_title', $renamedArray4);

        $this->assertArrayHasKey('inv_title', $untouchedArray5[0]);
        $this->assertArrayHasKey('title', $renamedArray5[0]);
        $this->assertArrayNotHasKey('title', $untouchedArray5[0]);
        $this->assertArrayNotHasKey('inv_title', $renamedArray5[0]);

        $this->assertArrayHasKey('title', $untouchedArray6);
        $this->assertArrayHasKey('title', $renamedArray6);
        $this->assertArrayNotHasKey('inv_title', $untouchedArray6);
        $this->assertArrayNotHasKey('inv_title', $renamedArray6);
    }
}
