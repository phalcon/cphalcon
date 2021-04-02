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

namespace Phalcon\Test\Database\Mvc\Model\Behavior;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesBehavior;
use Phalcon\Events\Event;
use Phalcon\Events\Manager as EventManager;

use function uniqid;

final class SoftDeleteCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        $connection = $I->getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model\Behavior :: SoftDelete()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-10-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelBehaviorSoftDelete(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Behavior - SoftDelete()');

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

        $I->assertEquals(Invoices::STATUS_INACTIVE, $invoice->inv_status_flag);
    }

    /**
     * Tests Phalcon\Mvc\Model\Behavior :: SoftDelete() - with before delete event
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-10-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelBehaviorSoftDeleteWithBeforeDeleteEvent(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Behavior - SoftDelete() - with before delete event');
        $I->skipTest('See: https://github.com/phalcon/cphalcon/issues/14904');

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
        $I->assertEquals(Invoices::STATUS_PAID, $invoice->inv_status_flag);
    }
}
