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

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesMap;

use function uniqid;

class ToArrayCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray()
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelToArray(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray()');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $data = [
            'inv_id'          => 1,
            'inv_cst_id'      => 5,
            'inv_status_flag' => 2,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);

        $expected = $data;
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);

        $expected = [];
        $actual   = $invoice->toArray(['unknown']);
        $I->assertEquals($expected, $actual);

        $expected = $data;
        unset($expected['inv_created_at']);
        unset($expected['inv_total']);
        $actual = $invoice->toArray(
            [
                'inv_id',
                'inv_cst_id',
                'inv_status_flag',
                'inv_title',
            ]
        );
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - column map
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelToArrayColumnMap(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - column map');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $data = [
            'id'          => 4,
            'cst_id'      => 5,
            'status_flag' => 2,
            'title'       => $title,
            'total'       => 100.12,
            'created_at'  => $date,
        ];

        $invoice = new InvoicesMap();
        $invoice->assign($data);

        $expected = [];
        $actual   = $invoice->toArray(['unknown']);
        $I->assertEquals($expected, $actual);

        $expected = $data;
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);

        $expected = $data;
        unset($expected['created_at']);
        unset($expected['total']);
        $actual = $invoice->toArray(
            [
                'id',
                'cst_id',
                'status_flag',
                'title',
            ]
        );
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - find first columns
     *
     * @issue 1701
     *
     * @group mysql
     * @group sqlite
     */
    public function mvcModelToArrayFindFirstColumns(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - find first columns');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $data = [
            'inv_id'          => 4,
            'inv_cst_id'      => 5,
            'inv_status_flag' => 2,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);
        $result = $invoice->save();
        $I->assertNotFalse($result);

        $invoice = Invoices::findFirst(
            [
                'columns' => 'inv_id, inv_cst_id, inv_title',
                'inv_title = "' . $title . '"',
            ]
        );

        $expected = [
            'inv_id'     => 4,
            'inv_cst_id' => 5,
            'inv_title'  => $title,
        ];
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);
    }
}
