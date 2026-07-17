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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\InvoicesReadWrite;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ResetConnectionStateTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->container->setShared('dbRead', $this->newDbService());
        $this->container->setShared('dbWrite', $this->newDbService());
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: resetConnectionState()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17256
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcModelManagerResetConnectionState(): void
    {
        /** @var Manager $manager */
        $manager = $this->container->getShared('modelsManager');
        $model   = new InvoicesReadWrite();

        $manager->setSticky(true);
        $manager->registerWrite($model);

        /**
         * Sticky routing is active after a recorded write.
         */
        $this->assertSame(
            $this->container->getShared('dbWrite'),
            $manager->getReadConnection($model)
        );

        /**
         * Resetting the per-request state clears the tracking, so reads revert
         * to the read connection.
         */
        $manager->resetConnectionState();

        $this->assertSame(
            $this->container->getShared('dbRead'),
            $manager->getReadConnection($model)
        );
    }
}
