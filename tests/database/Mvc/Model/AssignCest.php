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

use function uniqid;

class AssignCest
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
     * Tests Phalcon\Mvc\Model :: assign()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelAssign(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - assign()');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_id'          => 1,
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);

        $I->assertEquals(
            1,
            $invoice->readAttribute('inv_id')
        );
        $I->assertEquals(
            2,
            $invoice->readAttribute('inv_cst_id')
        );
        $I->assertEquals(
            3,
            $invoice->readAttribute('inv_status_flag')
        );
        $I->assertEquals(
            $title,
            $invoice->readAttribute('inv_title')
        );
        $I->assertEquals(
            100.12,
            $invoice->readAttribute('inv_total')
        );
        $I->assertEquals(
            $date,
            $invoice->readAttribute('inv_created_at')
        );

        $I->assertEquals(
            $data,
            $invoice->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: assign() - incomplete
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     */
    public function mvcModelAssignIncomplete(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - assign() - incomplete');

        $title   = uniqid('inv-');
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_id'    => 1,
                'inv_title' => $title,
            ]
        );

        $I->assertEquals(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => null,
                'inv_status_flag' => null,
                'inv_title'       => $title,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            $invoice->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: assign() - auto_increment primary
     *
     * Current test serves for example with PHP 7.4 and nullable model's
     * property.
     * > Uncaught Error: Typed property Model::$id must not be accessed before
     * initialization
     *
     * Example: public ?int $id = null;
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-13
     */
    public function mvcModelAssignAutoPrimary(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - assign() - auto_increment primary');

        $data = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => uniqid('inv-'),
            'inv_total'       => 100.12,
            'inv_created_at'  => date('Y-m-d H:i:s'),
        ];

        $invoice = new Invoices();
        $invoice->assign($data, array_keys($data));

        $I->assertArrayHasKey('inv_id', $invoice->toArray());
        $I->assertEmpty($invoice->toArray()['inv_id']);
    }
}
