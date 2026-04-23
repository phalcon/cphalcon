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

use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class AssignTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     *
     * @group mysql
     */
    public function testMvcModelAssign(): void
    {
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

        $this->assertEquals(
            1,
            $invoice->readAttribute('inv_id')
        );
        $this->assertEquals(
            2,
            $invoice->readAttribute('inv_cst_id')
        );
        $this->assertEquals(
            3,
            $invoice->readAttribute('inv_status_flag')
        );
        $this->assertEquals(
            $title,
            $invoice->readAttribute('inv_title')
        );
        $this->assertEquals(
            100.12,
            $invoice->readAttribute('inv_total')
        );
        $this->assertEquals(
            $date,
            $invoice->readAttribute('inv_created_at')
        );

        $this->assertEquals(
            $data,
            $invoice->toArray()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-13
     *
     * @group mysql
     */
    public function testMvcModelAssignAutoPrimary(): void
    {
        $data = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => uniqid('inv-'),
            'inv_total'       => 100.12,
            'inv_created_at'  => date('Y-m-d H:i:s'),
        ];

        $invoice = new Invoices();
        $invoice->assign($data, array_keys($data));

        $this->assertArrayHasKey('inv_id', $invoice->toArray());
        $this->assertEmpty($invoice->toArray()['inv_id']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     *
     * @group mysql
     */
    public function testMvcModelAssignIncomplete(): void
    {
        $title   = uniqid('inv-');
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_id'    => 1,
                'inv_title' => $title,
            ]
        );

        $this->assertEquals(
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
     * @issue  https://github.com/phalcon/cphalcon/issues/15739
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelAssignWithTransaction(): void
    {
        $title       = uniqid('inv-');
        $manager     = new Manager();
        $transaction = $manager->get();
        $invoice     = new Invoices();
        $invoice->setTransaction($transaction);
        $invoice->assign(
            [
                'inv_id'    => 1,
                'inv_title' => $title,
            ]
        );

        $result = $invoice->create();
        $this->assertTrue($result);

        $result = $transaction->commit();
        $this->assertTrue($result);

        $result = $invoice->delete();
        $this->assertTrue($result);
    }
}
