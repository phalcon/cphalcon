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
use DateTime;

use function uniqid;

final class TimestampableCest
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
     * Tests Phalcon\Mvc\Model\Behavior :: Timestampable()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-10-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelBehaviorTimestampable(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Behavior - Timestampable()');

        /** Add row to Timestampable then */
        $title = uniqid('inv-');

        $invoice = new InvoicesBehavior();
        $invoice->inv_cst_id = 2;
        $invoice->inv_status_flag = Invoices::STATUS_PAID;
        $invoice->inv_title = $title;
        $invoice->inv_total = 100.12;

        $date    = date('Y-m-d');
        $invoice->save();

        $I->assertNotEmpty($invoice->inv_created_at);

        $secondThreshold = 60;
        $dateFromAssign  = new Datetime($invoice->inv_created_at);
        $dateAfterAssign = new Datetime($date);
        $nInterval       = $dateFromAssign->diff($dateAfterAssign)->format('%s');

        $I->assertLessThan($secondThreshold, $nInterval);
    }

    /**
     * Tests Phalcon\Mvc\Model\Behavior :: Timestampable() - with before create event
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-10-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelBehaviorTimestampableWithBeforeCreateEvent(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Behavior - Timestampable() - with before create event');
        $I->skipTest('See: https://github.com/phalcon/cphalcon/issues/14904');

        /** ADD BeforeDelete event */
        $eventsManager = new EventManager();
        $eventsManager->attach('model:beforeCreate', function (Event $event, $model) {
            return false;
        });

        /** Add row to Timestampable then */
        $title = uniqid('inv-');

        $invoice = new InvoicesBehavior();
        $invoice->setEventsManager($eventsManager);
        $invoice->inv_cst_id = 2;
        $invoice->inv_status_flag = Invoices::STATUS_PAID;
        $invoice->inv_title = $title;
        $invoice->inv_total = 100.12;

        $invoice->save();

        $I->assertEmpty($invoice->inv_created_at);
    }
}
