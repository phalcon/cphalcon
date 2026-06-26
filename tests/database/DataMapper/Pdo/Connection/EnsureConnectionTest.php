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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use PDO;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class EnsureConnectionTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\DataMapper\Pdo\Connection :: ensureConnection()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDMPdoConnectionEnsureConnection(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $this->assertFalse($connection->isConnected());

        $connection->ensureConnection();

        $this->assertTrue($connection->isConnected());
        $this->assertInstanceOf(PDO::class, $connection->getAdapter());
    }
}
