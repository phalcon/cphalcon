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
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class EventsManagerPropagationTest extends AbstractDatabaseTestCase
{
    public function testDMPdoLocatorPropagatesToAlreadyResolvedConnection(): void
    {
        $locator = new ConnectionLocator(
            self::getDataMapperConnection(),
            [
                'read-one' => function () {
                    return self::getDataMapperConnection();
                },
            ]
        );

        // resolve first, attach the manager afterwards
        $first   = $locator->getRead('read-one');
        $manager = new Manager();
        $locator->setEventsManager($manager);

        $second = $locator->getRead('read-one');

        $this->assertSame($first, $second);
        $this->assertSame($manager, $second->getEventsManager());
    }

    public function testDMPdoLocatorPropagatesToLazyReadConnection(): void
    {
        $locator = new ConnectionLocator(
            self::getDataMapperConnection(),
            [
                'read-one' => function () {
                    return self::getDataMapperConnection();
                },
            ]
        );

        $manager = new Manager();
        $locator->setEventsManager($manager);

        $this->assertSame(
            $manager,
            $locator->getRead('read-one')->getEventsManager()
        );
    }

    public function testDMPdoLocatorPropagatesToMaster(): void
    {
        $locator = new ConnectionLocator(self::getDataMapperConnection());
        $manager = new Manager();

        $locator->setEventsManager($manager);

        $this->assertSame($manager, $locator->getEventsManager());
        $this->assertSame($manager, $locator->getMaster()->getEventsManager());
    }

    public function testDMPdoLocatorWithoutManagerLeavesConnectionAlone(): void
    {
        $locator = new ConnectionLocator(self::getDataMapperConnection());

        $this->assertNull($locator->getEventsManager());
        $this->assertNull($locator->getMaster()->getEventsManager());
    }
}
