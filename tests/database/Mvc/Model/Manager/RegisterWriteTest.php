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
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesReadWrite;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class RegisterWriteTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Mvc\Model\Manager :: registerWrite() - no-op when sticky
     * is disabled
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17256
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcModelManagerRegisterWriteIsNoopWhenNotSticky(): void
    {
        /** @var Manager $manager */
        $manager = $this->container->getShared('modelsManager');
        $model   = new InvoicesReadWrite();

        $manager->registerWrite($model);

        $this->assertSame(
            $this->container->getShared('dbRead'),
            $manager->getReadConnection($model)
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: registerWrite() - only the model's
     * own write service becomes sticky
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17256
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcModelManagerRegisterWriteIsScopedToWriteService(): void
    {
        /** @var Manager $manager */
        $manager        = $this->container->getShared('modelsManager');
        $readWriteModel = new InvoicesReadWrite();
        $defaultModel   = new Invoices();

        $manager->setSticky(true);
        $manager->registerWrite($readWriteModel);

        /**
         * The read/write model reads from its own write connection ...
         */
        $this->assertSame(
            $this->container->getShared('dbWrite'),
            $manager->getReadConnection($readWriteModel)
        );

        /**
         * ... while a model on a different (default "db") write service is
         * unaffected and keeps reading from its own connection.
         */
        $this->assertSame(
            $this->container->getShared('db'),
            $manager->getReadConnection($defaultModel)
        );
    }
}
