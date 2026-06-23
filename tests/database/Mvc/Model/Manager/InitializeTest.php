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

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class InitializeTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: initialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerInitialize(): void
    {
        $manager = new Manager();
        $manager->setDI($this->container);

        $invoice = new Invoices();

        // First call initializes the model and returns true.
        $this->assertTrue($manager->initialize($invoice));

        // A model is only initialized once, so a second call returns false.
        $this->assertFalse($manager->initialize($invoice));
    }
}
