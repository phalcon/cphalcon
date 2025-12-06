<?php

/**
 * This file is part of the Phalcon Framework.
 * (c) Phalcon Team <team@phalcon.io>
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Cache\Cache;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Events\Manager;
use Phalcon\Storage\SerializerFactory;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Cache :: getEventsManager()
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function cacheCacheGetEventsManagerNotSet(IntegrationTester $I): void
    {
        $I->wantToTest('Cache\Cache - getEventsManager() - not set');

        $serializer = new SerializerFactory();
        $factory = new AdapterFactory($serializer);
        $instance = $factory->newInstance('memory');

        $adapter = new Cache($instance);

        $I->assertNull($adapter->getEventsManager());
    }

    /**
     * Tests Phalcon\Cache :: getEventsManager()
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function cacheCacheGetEventsManagerSet(IntegrationTester $I): void
    {
        $I->wantToTest('Cache\Cache - getEventsManager() - set');

        $serializer = new SerializerFactory();
        $factory = new AdapterFactory($serializer);
        $instance = $factory->newInstance('memory');

        $adapter = new Cache($instance);

        $adapter->setEventsManager(new Manager());

        $I->assertInstanceOf(Manager::class, $adapter->getEventsManager());
    }

    /**
     * Tests Phalcon\Cache :: trigger cache events
     *
     * @dataProvider getEvents
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function cacheCacheEventTriggers(IntegrationTester $I, Example $example): void
    {
        $I->wantToTest('Cache\Cache - triggered ' . $example->offsetGet(0));

        $serializer = new SerializerFactory();
        $factory = new AdapterFactory($serializer);
        $instance = $factory->newInstance('memory');

        $counter = 0;
        $adapter = new Cache($instance);
        $manager = new Manager();

        $manager->attach(
            'cache:' . $example->offsetGet(0),
            static function () use (&$counter) {
                $counter++;
            }
        );

        $adapter->setEventsManager($manager);

        // Avoid unset warning.
        if ($example->offsetGet(1) !== 'set' && $example->offsetGet(1) !== 'setMultiple') {
            $adapter->set('test', 'test');
            $adapter->set('test2', 'test2');
        }

        $I->assertInstanceOf($manager::class, $adapter->getEventsManager());

        call_user_func_array([$adapter, $example->offsetGet(1)], $example->offsetGet(2));
        call_user_func_array([$adapter, $example->offsetGet(1)], $example->offsetGet(2));
        $I->assertEquals(2, $counter);
    }

    public function getEvents(): array
    {
        // Event, Method, Data
        return [
            ['beforeDelete', 'delete', ['test']],
            ['afterDelete', 'delete', ['test']],
            ['beforeDeleteMultiple', 'deleteMultiple', [['test', 'test2']]],
            ['afterDeleteMultiple', 'deleteMultiple', [['test', 'test2']]],
            ['beforeGet', 'get', ['test']],
            ['afterGet', 'get', ['test']],
            ['beforeGetMultiple', 'getMultiple', [['test', 'test2']]],
            ['afterGetMultiple', 'getMultiple', [['test', 'test2']]],
            ['beforeHas', 'has', ['test']],
            ['afterHas', 'has', ['test']],
            ['beforeSet', 'set', ['test', 'test']],
            ['afterSet', 'set', ['test', 'test']],
            ['beforeSetMultiple', 'setMultiple', [['test' => 'test', 'test2' => 'test2']]],
            ['afterSetMultiple', 'setMultiple', [['test', 'test', 'test2' => 'test2']]],
        ];
    }
}
