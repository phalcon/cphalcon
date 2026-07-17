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
final class SetStickyTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Mvc\Model\Manager :: setSticky()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17256
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcModelManagerSetSticky(): void
    {
        /** @var Manager $manager */
        $manager = $this->container->getShared('modelsManager');
        $model   = new InvoicesReadWrite();

        $readConnection  = $this->container->getShared('dbRead');
        $writeConnection = $this->container->getShared('dbWrite');

        /**
         * Sticky is off by default: a recorded write must not redirect reads
         * to the write connection.
         */
        $manager->registerWrite($model);

        $this->assertSame(
            $readConnection,
            $manager->getReadConnection($model)
        );

        /**
         * With sticky enabled, reads still use the read connection until a
         * write has actually been recorded during the request cycle.
         */
        $manager->setSticky(true);

        $this->assertSame(
            $readConnection,
            $manager->getReadConnection($model)
        );

        /**
         * After a write is recorded, reads for that write service are served
         * from the write connection.
         */
        $manager->registerWrite($model);

        $this->assertSame(
            $writeConnection,
            $manager->getReadConnection($model)
        );
    }
}
