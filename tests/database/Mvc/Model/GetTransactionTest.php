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
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetTransactionTest extends AbstractDatabaseTestCase
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
    public function testMvcModelGetTransaction(): void
    {
        $invoice = new Invoices();

        // No transaction by default
        $this->assertNull($invoice->getTransaction());

        $manager = new Manager();
        $manager->setDI($this->container);

        $transaction = $manager->get();

        $returned = $invoice->setTransaction($transaction);

        $this->assertInstanceOf(Invoices::class, $returned);
        $this->assertSame($transaction, $invoice->getTransaction());

        // Resolve the transaction so the manager has nothing left pending
        $transaction->commit();
    }
}
