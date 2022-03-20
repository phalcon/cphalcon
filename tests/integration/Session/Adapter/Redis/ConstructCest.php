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

namespace Phalcon\Tests\Integration\Session\Adapter\Redis;

use IntegrationTester;
use Phalcon\Session\Adapter\Redis;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use SessionHandlerInterface;

class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Redis :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterRedisConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - __construct()');

        $adapter = $this->newService('sessionRedis');

        $class = SessionHandlerInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }

    /**
     * Tests Phalcon\Session\Adapter\Redis :: __construct() - with custom prefix
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-23
     */
    public function sessionAdapterRedisConstructWithPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - __construct() - with custom prefix');

        $options           = getOptionsRedis();
        $options['prefix'] = 'my-custom-prefix-';

        $serializerFactory = new SerializerFactory();
        $factory           = new AdapterFactory($serializerFactory);

        $redisSession = new Redis($factory, $options);

        $actual = $redisSession->write(
            'my-session-prefixed-key',
            'test-data'
        );

        $I->assertTrue($actual);

        $redisStorage = $factory->newInstance('redis', $options);

        $expected = 'my-custom-prefix-';
        $actual   = $redisStorage->getPrefix();
        $I->assertEquals($expected, $actual);

        $expected = 'test-data';
        $actual   = $redisStorage->get('my-session-prefixed-key');
        $I->assertEquals($expected, $actual);
    }
}
