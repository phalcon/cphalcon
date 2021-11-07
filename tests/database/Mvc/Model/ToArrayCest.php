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

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use PDO;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\InvoicesMap;

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
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @issue https://github.com/phalcon/cphalcon/issues/1701
     *
     * @group  mysql
     * @group  sqlite
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

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - find - castOnHydrate/forceCasting
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @issue https://github.com/phalcon/cphalcon/issues/15361
     *
     * @group  mysql
     */
    public function mvcModelToArrayFindCastOnHydrateForceCasting(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - find - castOnHydrate/forceCasting');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);
        $migration->insert(5, 2, 1, $title, 222.19, $date);

        Invoices::setup(
            [
                'forceCasting'  => true,
                'castOnHydrate' => true,
            ]
        );

        $invoices = Invoices::findFirst();

        $expected = [
            'inv_id'          => 4,
            'inv_cst_id'      => 1,
            'inv_status_flag' => 0,
            'inv_title'       => $title,
            'inv_total'       => 111.26,
            'inv_created_at'  => $date,
        ];
        $actual   = $invoices->toArray();
        $I->assertEquals($expected, $actual);

        $invoices = Invoices::find();

        $expected = [
            [
                'inv_id'          => 4,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 0,
                'inv_title'       => $title,
                'inv_total'       => 111.26,
                'inv_created_at'  => $date,
            ],
            [
                'inv_id'          => 5,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 1,
                'inv_title'       => $title,
                'inv_total'       => 222.19,
                'inv_created_at'  => $date,
            ]
        ];
        $actual   = $invoices->toArray();
        $I->assertSame($expected, $actual);

        Invoices::setup(
            [
                'forceCasting'  => false,
                'castOnHydrate' => false,
            ]
        );
    }
}
