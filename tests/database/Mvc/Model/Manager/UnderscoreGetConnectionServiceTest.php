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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function strtolower;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class UnderscoreGetConnectionServiceTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getConnectionService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerUnderscoreGetConnectionService(): void
    {
        $manager = $this->container->get('modelsManager');
        $model   = new Invoices();

        // Falls back to the default 'db' service when none is registered.
        $this->assertSame('db', $manager->getConnectionService($model, []));

        // Otherwise returns the service mapped to the model class.
        $services = [strtolower(Invoices::class) => 'dbCustom'];

        $this->assertSame('dbCustom', $manager->getConnectionService($model, $services));
    }
}
