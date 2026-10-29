<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Cache\Cache;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Events\Manager;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getEvents(): array
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
            ['afterSetMultiple', 'setMultiple', [['test' => 'test', 'test2' => 'test2']]],
        ];
    }

    /**
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    #[DataProvider('getEvents')]
    public function testCacheCacheEventTriggers(
        string $event,
        string $method,
        array $data
    ): void {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('memory');

        $counter = 0;
        $adapter = new Cache($instance);
        $manager = new Manager();

        $manager->attach(
            'cache:' . $event,
            static function () use (&$counter) {
                $counter++;
            }
        );

        $adapter->setEventsManager($manager);

        $this->assertInstanceOf($manager::class, $adapter->getEventsManager());

        // Seed keys so Memory adapter does not throw on get/getMultiple
        if ($method === 'get') {
            $adapter->set('test', 'value');
        } elseif ($method === 'getMultiple') {
            $adapter->setMultiple(['test' => 'value', 'test2' => 'value']);
        }

        call_user_func_array([$adapter, $method], $data);
        call_user_func_array([$adapter, $method], $data);

        $expected = 2;
        $this->assertEquals($expected, $counter);
    }

    /**
     * With an events manager, each operation calls fireManagerEvent().
     *
     * @issue https://github.com/phalcon/cphalcon/issues/17703
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-28
     */
    public function testCacheCacheFireManagerEventWithEventsManager(): void
    {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('memory');

        $cache = new class ($instance) extends Cache {
            public int $fireCalls = 0;

            protected function fireManagerEvent(
                string $eventName,
                mixed $data = null,
                bool $cancellable = true,
                bool $stopOnFalse = false
            ): mixed {
                $this->fireCalls++;

                return parent::fireManagerEvent(
                    $eventName,
                    $data,
                    $cancellable,
                    $stopOnFalse
                );
            }
        };

        $cache->setEventsManager(new Manager());

        $cache->set('a', 1);
        $cache->get('a');
        $cache->has('a');
        $cache->delete('a');
        $cache->setMultiple(['b' => 2]);
        $cache->getMultiple(['b']);
        $cache->deleteMultiple(['b']);

        $this->assertSame(18, $cache->fireCalls);
    }

    /**
     * With no events manager, the operations do not call fireManagerEvent().
     *
     * @issue https://github.com/phalcon/cphalcon/issues/17703
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-28
     */
    public function testCacheCacheFireManagerEventWithoutEventsManager(): void
    {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('memory');

        $cache = new class ($instance) extends Cache {
            public int $fireCalls = 0;

            protected function fireManagerEvent(
                string $eventName,
                mixed $data = null,
                bool $cancellable = true,
                bool $stopOnFalse = false
            ): mixed {
                $this->fireCalls++;

                return parent::fireManagerEvent(
                    $eventName,
                    $data,
                    $cancellable,
                    $stopOnFalse
                );
            }
        };

        $cache->set('a', 1);
        $cache->get('a');
        $cache->has('a');
        $cache->delete('a');
        $cache->setMultiple(['b' => 2]);
        $cache->getMultiple(['b']);
        $cache->deleteMultiple(['b']);

        $this->assertSame(0, $cache->fireCalls);
    }

    /**
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function testCacheCacheGetEventsManagerNotSet(): void
    {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('memory');

        $adapter = new Cache($instance);

        $this->assertNull($adapter->getEventsManager());
    }

    /**
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function testCacheCacheGetEventsManagerSet(): void
    {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('memory');

        $adapter = new Cache($instance);

        $adapter->setEventsManager(new Manager());

        $this->assertInstanceOf(Manager::class, $adapter->getEventsManager());
    }
}
