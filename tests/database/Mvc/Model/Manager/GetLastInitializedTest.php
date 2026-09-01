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
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class GetLastInitializedTest extends AbstractDatabaseTestCase
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
     * Tests that getLastInitialized() returns null after initialization
     * completes so that the manager does not permanently retain the model
     * instance (which would create a reference cycle in long-running
     * processes).
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16566
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-30
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelManagerGetLastInitializedIsNullAfterInitialization(): void
    {
        /** @var Manager $manager */
        $manager = $this->container->getShared('modelsManager');

        new Invoices();

        $this->assertNull($manager->getLastInitialized());
    }
}
