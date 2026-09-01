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

use InvalidArgumentException;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionConstruct(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $this->assertInstanceOf(Connection::class, $connection);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMPdoConnectionConstructException(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage("Driver not supported [random]");

        (new Connection('random:some data'));
    }
}
