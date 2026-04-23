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

namespace Phalcon\Tests\Database\Mvc\Model\Behavior;

use Phalcon\Events\Event;
use Phalcon\Events\Manager as EventManager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBehavior;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class SoftDeleteTest extends AbstractDatabaseTestCase
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
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-10-03
     *
     * @group mysql
     */
    public function testMvcModelBehaviorSoftDelete(): void
    {
        /** Add row to SoftDelete then */
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => Invoices::STATUS_PAID,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new InvoicesBehavior();
        $invoice->assign($data);

        /* delete invoice */
        $invoice->delete();

        $this->assertEquals(Invoices::STATUS_INACTIVE, $invoice->inv_status_flag);
    }

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-10-03
     *
     * @group mysql
     */
    public function testMvcModelBehaviorSoftDeleteWithBeforeDeleteEvent(): void
    {
        $this->markTestSkipped('See: https://github.com/phalcon/cphalcon/issues/14904');

        /** ADD BeforeDelete event */
        $eventsManager = new EventManager();
        $eventsManager->attach('model:beforeDelete', function (Event $event, $model) {
            return false;
        });

        /** Add row to SoftDelete then */
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => Invoices::STATUS_PAID,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new InvoicesBehavior();
        $invoice->assign($data);

        /** delete invoice */
        $invoice->setEventsManager($eventsManager);
        $invoice->delete();

        /** Check that SoftDelete wasn't working because beforeDelete event return false */
        $this->assertEquals(Invoices::STATUS_PAID, $invoice->inv_status_flag);
    }

    /**
     *
     * @group mysql
     */
    public function testMvcModelBehaviorRemoveBehavior(): void
    {
        $this->markTestSkipped('TODO: Phalcon\Mvc\Model\Manager::removeBehavior() not yet ported to cphalcon');
        /** Add row to SoftDelete then */
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => Invoices::STATUS_PAID,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new InvoicesBehavior();
        $invoice->assign($data);

        // Remove the SoftDelete behavior
        $modelsManager = $invoice->getModelsManager();
        $modelsManager->removeBehavior($invoice, \Phalcon\Mvc\Model\Behavior\SoftDelete::class);

        /* delete invoice */
        $invoice->delete();

        // Check that the SoftDelete behavior was removed and the invoice was actually deleted
        $this->assertFalse($invoice->hasSnapshotData());
    }
}
