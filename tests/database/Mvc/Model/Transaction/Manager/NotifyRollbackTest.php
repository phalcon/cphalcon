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

namespace Phalcon\Tests\Database\Mvc\Model\Transaction\Manager;

use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class NotifyRollbackTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * notifyRollback() detaches the rolled-back transaction from the manager.
     *
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: notifyRollback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelTransactionManagerNotifyRollback(): void
    {
        $manager = new Manager($this->container);
        $manager->setRollbackPendent(false);

        $transaction = $manager->get();
        $this->assertTrue($manager->has());

        $manager->notifyRollback($transaction);
        $this->assertFalse($manager->has());

        // Close the still-open connection-level transaction.
        $transaction->commit();
    }
}
