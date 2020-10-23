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

namespace Phalcon\Test\Integration\Session\Adapter\Libmemcached;

use IntegrationTester;
use Phalcon\Session\Adapter\Libmemcached;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use SessionHandlerInterface;

class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - __construct()');

        $adapter = $this->newService('sessionLibmemcached');

        $I->assertInstanceOf(
            SessionHandlerInterface::class,
            $adapter
        );
    }

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: __construct() - with custom prefix
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-23
     */
    public function sessionAdapterLibmemcachedConstructWithPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - __construct() - with custom prefix');

        $options           = getOptionsLibmemcached();
        $options['prefix'] = 'my-custom-prefix-';

        $serializerFactory = new SerializerFactory();
        $factory           = new AdapterFactory($serializerFactory);

        $memcachedSession = new Libmemcached($factory, $options);

        $I->assertTrue(
            $memcachedSession->write(
                'my-session-prefixed-key',
                'test-data'
            )
        );

        $memcachedStorage = $factory->newInstance('libmemcached', $options);

        $I->assertEquals(
            'my-custom-prefix-',
            $memcachedStorage->getPrefix()
        );

        $I->assertEquals(
            'test-data',
            $memcachedStorage->get('my-session-prefixed-key')
        );
    }
}
