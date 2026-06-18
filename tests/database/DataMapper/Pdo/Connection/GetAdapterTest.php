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

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetAdapterTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionGetAdapter(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $this->assertFalse($connection->isConnected());

        $connection->connect();

        $this->assertTrue($connection->isConnected());
        $this->assertNotEmpty($connection->getAdapter());

        $connection->disconnect();

        $this->assertNotEmpty(
            $connection->getAdapter(),
            'getPdo() will re-connect if disconnected'
        );
        $this->assertTrue($connection->isConnected());
    }
}
