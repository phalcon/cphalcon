<?php

/**
 * This file is part of the Phalcon Framework.
 * (c) Phalcon Team <team@phalcon.io>
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Storage\Adapter;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;
use function sprintf;

class EventsCest
{
    /**
     * Tests Phalcon\Storage\Adapter\* :: events - beforeGet
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsBeforeGet(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'beforeGet'
            )
        );

        $manager->attach(
            'storage:beforeGet',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'get'], ['test']);
        call_user_func_array([$adapter, 'get'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - afterGet
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsAfterGet(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'afterGet'
            )
        );

        $manager->attach(
            'storage:afterGet',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'get'], ['test']);
        call_user_func_array([$adapter, 'get'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - beforeHas
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsBeforeHas(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'beforeHas'
            )
        );

        $manager->attach(
            'storage:beforeHas',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'has'], ['test']);
        call_user_func_array([$adapter, 'has'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - afterHas
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsAfterHas(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'afterHas'
            )
        );

        $manager->attach(
            'storage:afterHas',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'has'], ['test']);
        call_user_func_array([$adapter, 'has'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - beforeDelete
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsBeforeDelete(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'beforeDelete'
            )
        );

        $manager->attach(
            'storage:beforeDelete',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'delete'], ['test']);
        call_user_func_array([$adapter, 'delete'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - afterDelete
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsAfterDelete(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'afterDelete'
            )
        );

        $manager->attach(
            'storage:afterDelete',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'delete'], ['test']);
        call_user_func_array([$adapter, 'delete'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - beforeIncrement
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsBeforeIncrement(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'beforeIncrement'
            )
        );

        $manager->attach(
            'storage:beforeIncrement',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'increment'], ['test']);
        call_user_func_array([$adapter, 'increment'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - afterIncrement
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsAfterIncrement(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'afterIncrement'
            )
        );

        $manager->attach(
            'storage:afterIncrement',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'increment'], ['test']);
        call_user_func_array([$adapter, 'increment'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - beforeDecrement
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsBeforeDecrement(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'beforeDecrement'
            )
        );

        $manager->attach(
            'storage:beforeDecrement',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'decrement'], ['test']);
        call_user_func_array([$adapter, 'decrement'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - afterDecrement
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsAfterDecrement(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'afterDecrement'
            )
        );

        $manager->attach(
            'storage:afterDecrement',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'decrement'], ['test']);
        call_user_func_array([$adapter, 'decrement'], ['test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - beforeSet
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsBeforeSet(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'beforeSet'
            )
        );

        $manager->attach(
            'storage:beforeSet',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'set'], ['test', 'test']);
        call_user_func_array([$adapter, 'set'], ['test', 'test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: events - afterSet
     *
     * @dataProvider getExamples
     * @author       n[oO]ne <lominum@protonmail.com>
     * @since        2024-06-07
     */
    public function storageAdapterEventsAfterSet(IntegrationTester $I, Example $example): void
    {
        $className = $example[0];
        $extension = $example[1];
        $class = $example[2];
        $options = $example[3];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $counter = 0;
        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);
        $manager = new Manager();

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - triggered event - %s',
                $className,
                'afterSet'
            )
        );

        $manager->attach(
            'storage:afterSet',
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        call_user_func_array([$adapter, 'set'], ['test', 'test']);
        call_user_func_array([$adapter, 'set'], ['test', 'test']);

        $I->assertEquals(2, $counter);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'Apcu',
                'apcu',
                Apcu::class,
                [],
            ],
            [
                'Libmemcached',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
            ],
            [
                'Memory',
                '',
                Memory::class,
                [],
            ],
            [
                'Redis',
                'redis',
                Redis::class,
                getOptionsRedis(),
            ],
            [
                'Stream',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
            ],
            [
                'Weak',
                '',
                Weak::class,
                [],
            ],
        ];
    }
}
