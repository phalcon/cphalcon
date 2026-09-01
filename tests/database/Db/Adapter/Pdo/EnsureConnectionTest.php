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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class EnsureConnectionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: ensureConnection()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoEnsureConnection(): void
    {
        $db = $this->container->get('db');

        $db->close();
        $this->assertNull($db->getInternalHandler());

        $db->ensureConnection();

        $this->assertInstanceOf(PDO::class, $db->getInternalHandler());
        $this->assertTrue($db->ping());
    }
}
