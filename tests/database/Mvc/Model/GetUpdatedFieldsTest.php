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

use Phalcon\Mvc\Model\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\CustomersKeepSnapshotsRelationFail;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesValidationFails;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetUpdatedFieldsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        \Phalcon\Mvc\Model::setup(['updateSnapshotOnSave' => true]);
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelGetUpdatedFieldsNotPersisted(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Change checking cannot be performed because the object has not been persisted or is deleted"
        );

        (new Invoices())->getUpdatedFields();
    }

    /**
     * Tests that the model snapshot is restored to its pre-save state when a
     * postSaveRelatedRecords failure rolls back the transaction, so that
     * Dynamic Update can still detect and persist the changes on the next save.
     *
     * @see    https://github.com/phalcon/cphalcon/issues/16410
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-04-23
     *
     * @group mysql
     */
    public function testMvcModelSnapshotRestoredAfterRelatedRecordRollback(): void
    {
        $connection = self::getConnection();
        (new CustomersMigration($connection));
        (new InvoicesMigration($connection));

        $customer                  = new CustomersKeepSnapshotsRelationFail();
        $customer->cst_status_flag = 1;
        $customer->cst_name_first  = 'John';
        $customer->cst_name_last   = 'Doe';
        $this->assertTrue($customer->save());

        $snapshotAfterCreate = $customer->getSnapshotData();
        $this->assertEquals('John', $snapshotAfterCreate['cst_name_first']);

        // Modify the customer and attach a related record whose validation always fails
        $customer->cst_name_first = 'Jane';

        $failingInvoice                  = new InvoicesValidationFails();
        $failingInvoice->inv_cst_id      = $customer->cst_id;
        $failingInvoice->inv_status_flag = Invoices::STATUS_PAID;
        $failingInvoice->inv_title       = 'rollback-test';
        $failingInvoice->inv_total       = 100.00;
        $failingInvoice->inv_created_at  = date('Y-m-d H:i:s');
        $customer->invoices              = [$failingInvoice];

        // Save fails: customer UPDATE succeeds but postSaveRelatedRecords rolls back
        $this->assertFalse($customer->save());

        // Snapshot must be restored to the pre-save state ('John'), not the
        // stale post-UPDATE value ('Jane'), so the next save can detect the change
        $snapshotAfterRollback = $customer->getSnapshotData();
        $this->assertEquals('John', $snapshotAfterRollback['cst_name_first']);
    }
}
