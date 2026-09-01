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

namespace Phalcon\Tests\Database\DataMapper\Pdo\ConnectionLocator;

use Phalcon\DataMapper\Pdo\ConnectionLocator;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

use function spl_object_hash;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSetMasterTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionLocatorGetSetMaster(): void
    {
        $connection1 = self::getDataMapperConnection();
        $connection2 = self::getDataMapperConnection();
        $locator     = new ConnectionLocator($connection1);

        $actual = $locator->getMaster();
        $this->assertEquals(spl_object_hash($connection1), spl_object_hash($actual));

        $locator->setMaster($connection2);
        $actual = $locator->getMaster();
        $this->assertEquals(spl_object_hash($connection2), spl_object_hash($actual));
    }
}
