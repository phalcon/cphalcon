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

use Phalcon\Mvc\Model\Transaction;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetTest extends AbstractDatabaseTestCase
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-07
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelTransactionManagerGet(): void
    {
        $tm = $this->container->getShared('transactionManager');
        $db = $this->container->getShared('db');

        $transaction = $tm->get();

        $this->assertInstanceOf(
            Transaction::class,
            $transaction
        );

        $this->assertSame(
            $transaction,
            $tm->get(true)
        );

        $this->assertSame(
            $transaction,
            $tm->get(false)
        );

        $this->assertSame(
            $db->getConnectionId(),
            $transaction->getConnection()->getConnectionId()
        );
    }
}
