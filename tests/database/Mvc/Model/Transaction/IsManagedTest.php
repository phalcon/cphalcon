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

final class IsManagedTest extends AbstractDatabaseTestCase
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
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelTransactionIsManaged(): void
    {
        $transaction = new Transaction(
            $this->container
        );

        $this->assertFalse(
            $transaction->isManaged()
        );

        $transactionManager = $this->container->getShared('transactionManager');

        $transaction->setTransactionManager($transactionManager);

        $this->assertTrue(
            $transaction->isManaged()
        );
    }
}
