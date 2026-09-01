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
final class RollbackTest extends AbstractDatabaseTestCase
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
     * rollback() rolls back and collects the active managed transactions.
     *
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: rollback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelTransactionManagerRollback(): void
    {
        $manager = new Manager($this->container);
        $manager->setRollbackPendent(false);

        $manager->get();
        $this->assertTrue($manager->has());

        $manager->rollback();
        $this->assertFalse($manager->has());
    }
}
