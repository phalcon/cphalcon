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
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class IsKeepingSnapshotsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        // Otherwise the global dynamic-update toggle forces snapshots on.
        Settings::set('orm.dynamic_update', false);
    }

    public function tearDown(): void
    {
        Settings::reset();
        $this->tearDownDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: isKeepingSnapshots()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerIsKeepingSnapshots(): void
    {
        $manager = new Manager();
        $model   = new Invoices();

        $this->assertFalse($manager->isKeepingSnapshots($model));

        $manager->keepSnapshots($model, true);

        $this->assertTrue($manager->isKeepingSnapshots($model));
    }
}
