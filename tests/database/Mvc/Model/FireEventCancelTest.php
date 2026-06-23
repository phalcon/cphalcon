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

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class FireEventCancelTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelFireEventCancel(): void
    {
        $invoice = new Invoices();

        $eventsManager = new EventsManager();
        $eventsManager->attach(
            'model:customCancelEvent',
            function () {
                return false;
            }
        );

        $invoice->getModelsManager()->setEventsManager($eventsManager);

        // A listener returning false cancels the event
        $this->assertFalse($invoice->fireEventCancel('customCancelEvent'));

        // An event with no cancelling listener is not cancelled
        $this->assertNotFalse($invoice->fireEventCancel('someOtherEvent'));
    }
}
