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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection\Decorated;

use PDO;
use Phalcon\DataMapper\Pdo\Connection\Decorated;
use Phalcon\DataMapper\Pdo\Exception\CannotDisconnect;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class DisconnectTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionDecoratedDisconnect(): void
    {
        $this->expectException(CannotDisconnect::class);
        $this->expectExceptionMessage("Cannot disconnect a Decorated connection instance");

        $connection = new PDO(
            self::getDatabaseDsn(),
            self::getDatabaseUsername(),
            self::getDatabasePassword()
        );

        $decorated = new Decorated($connection);
        $decorated->disconnect();
    }
}
