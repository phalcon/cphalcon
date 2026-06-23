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

namespace Phalcon\Tests\Database\Mvc\Model\Transaction;

use Phalcon\Mvc\Model\Transaction;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class IsValidTest extends AbstractDatabaseTestCase
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
     * isValid() reflects whether the connection is under an active transaction.
     *
     * Tests Phalcon\Mvc\Model\Transaction :: isValid()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelTransactionIsValid(): void
    {
        $transaction = new Transaction($this->container);
        $transaction->begin();

        $this->assertTrue($transaction->isValid());

        $transaction->commit();
    }
}
