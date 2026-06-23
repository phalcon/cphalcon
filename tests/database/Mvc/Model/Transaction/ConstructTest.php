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

use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ConstructTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Mvc\Model\Transaction :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelTransactionConstruct(): void
    {
        $transaction = new Transaction($this->container);

        $this->assertInstanceOf(Transaction::class, $transaction);
        $this->assertInstanceOf(AdapterInterface::class, $transaction->getConnection());
    }
}
