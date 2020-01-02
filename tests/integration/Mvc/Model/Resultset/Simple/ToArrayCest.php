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

use Phalcon\Mvc\Model\Query\Builder;
use IntegrationTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

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
        (new InvoicesMigration())($db);
        $data = [
            [1, 0, 'Title 1', 10.51, date('Y-m-d H:i:s')],
            [123, 1, 'Title 2', 5.2, date('Y-m-d H:i:s')],
            [321, 1, 'Title 3', 0.25, null],
        ];

        foreach ($data as $row) {
            $db->insert(
                'co_invoices',
                $row,
                ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total', 'inv_created_at']
            );
        }

        /**
         * Prepare data to assert
         */
        $rows1 = (new Builder())
            ->from([
                'Invoices' => Invoices::class,
            ])
            ->orderBy('Invoices.inv_id DESC')
            ->columns([
                'Invoices.inv_cst_id',
                'Invoices.inv_status_flag',
                'invoice_title' => 'Invoices.inv_title',
            ])
            ->getQuery()
            ->execute();
        $rows2 = Invoices::find();

        $renamedArray1 = $rows1->toArray();
        $untouchedArray1 = $rows1->toArray(false);
        $renamedArray2 = $rows2->toArray();
        $untouchedArray2 = $rows2->toArray(false);

        /**
         * Assert
         */
        $I->assertInternalType('array', $untouchedArray1);
        $I->assertInternalType('array', $renamedArray1);
        $I->assertInternalType('array', $untouchedArray2);
        $I->assertInternalType('array', $renamedArray2);

        $I->assertArrayHasKey('invoice_title', $untouchedArray1[0]);
        $I->assertArrayHasKey('invoice_title', $renamedArray1[0]);
        $I->assertArrayHasKey('inv_title', $untouchedArray2[0]);
        $I->assertArrayHasKey('inv_title', $renamedArray2[0]);
    }
}
