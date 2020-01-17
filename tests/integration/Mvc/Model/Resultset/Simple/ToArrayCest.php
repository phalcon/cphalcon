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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesWithColumnMap;

/**
 * Class ToArrayCest
 */
class ToArrayCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-01
     */
    public function mvcModelResultsetSimpleToArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - toArray()');

        /**
         * Init Di with services
         */
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiMysql();

        /**
         * Re-create DB table with data
         */
        $db = $this->getService('db');
        $migration = new InvoicesMigration($db);
        $migration->create();
        $data = [
            [1, 0, 'Title 1', 10.51, date('Y-m-d H:i:s')],
            [123, 1, 'Title 2', 5.2, date('Y-m-d H:i:s')],
            [321, 1, 'Title 3', 0.25, null],
        ];

        foreach ($data as $row) {
            $migration->insert(
                null,
                $row[1],
                $row[2],
                $row[3],
                $row[4]
            );
        }

        /**
         * Prepare data to assert
         */
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

        /**
         * Assert
         */
        $I->assertInternalType('array', $renamedArray1);
        $I->assertInternalType('array', $renamedArray2);
        $I->assertInternalType('array', $renamedArray3);
        $I->assertInternalType('array', $renamedArray4);
        $I->assertInternalType('array', $renamedArray5);
        $I->assertInternalType('array', $renamedArray6);

        $I->assertInternalType('array', $untouchedArray1);
        $I->assertInternalType('array', $untouchedArray2);
        $I->assertInternalType('array', $untouchedArray3);
        $I->assertInternalType('array', $untouchedArray4);
        $I->assertInternalType('array', $untouchedArray5);
        $I->assertInternalType('array', $untouchedArray6);

        $I->assertArrayHasKey('invoice_title', $untouchedArray1[0]);
        $I->assertArrayHasKey('invoice_title', $renamedArray1[0]);

        $I->assertArrayHasKey('invoice_title', $untouchedArray2[0]);
        $I->assertArrayHasKey('invoice_title', $renamedArray2[0]);

        $I->assertArrayHasKey('inv_title', $untouchedArray3[0]);
        $I->assertArrayHasKey('inv_title', $renamedArray3[0]);

        $I->assertArrayHasKey('inv_title', $untouchedArray4);
        $I->assertArrayHasKey('inv_title', $renamedArray4);

        $I->assertArrayHasKey('inv_title', $untouchedArray5[0]);
        $I->assertArrayHasKey('title', $renamedArray5[0]);
        $I->assertArrayNotHasKey('title', $untouchedArray5[0]);
        $I->assertArrayNotHasKey('inv_title', $renamedArray5[0]);

        $I->assertArrayHasKey('title', $untouchedArray6);
        $I->assertArrayHasKey('title', $renamedArray6);
        $I->assertArrayNotHasKey('inv_title', $untouchedArray6);
        $I->assertArrayNotHasKey('inv_title', $renamedArray6);

        $migration->drop();
    }
}
