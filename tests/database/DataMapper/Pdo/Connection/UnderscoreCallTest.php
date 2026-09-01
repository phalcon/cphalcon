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

use BadMethodCallException;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\DataMapper\Fake\FakeConnection;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class UnderscoreCallTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionUnderscoreCall(): void
    {
        /** @var Connection $connection */
        $connection = new FakeConnection(
            self::getDatabaseDsn(),
            self::getDatabaseUsername(),
            self::getDatabasePassword()
        );

        $actual = $connection->callMe('blondie');
        $this->assertEquals('blondie', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionUnderscoreCallException(): void
    {
        $this->expectException(BadMethodCallException::class);
        $this->expectExceptionMessage(
            "Class 'Phalcon\DataMapper\Pdo\Connection' does not have a method 'unknown'"
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $connection->unknown();
    }
}
