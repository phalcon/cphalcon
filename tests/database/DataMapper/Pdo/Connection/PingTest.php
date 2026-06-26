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

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class PingTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\DataMapper\Pdo\Connection :: ping()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDMPdoConnectionPing(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $connection->connect();
        $this->assertTrue($connection->ping());

        $connection->disconnect();
        $this->assertFalse($connection->ping());
    }
}
