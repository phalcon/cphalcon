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

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetReadConnectionServiceTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: setReadConnectionService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerSetReadConnectionService(): void
    {
        $manager = $this->container->get('modelsManager');
        $model   = new Invoices();

        $manager->setReadConnectionService($model, 'dbRead');

        $this->assertSame('dbRead', $manager->getReadConnectionService($model));
    }
}
