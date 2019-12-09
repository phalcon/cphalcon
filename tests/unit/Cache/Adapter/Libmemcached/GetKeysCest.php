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

namespace Phalcon\Test\Unit\Cache\Adapter\Libmemcached;

use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;

use function getOptionsLibmemcached;

class GetKeysCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-13
     */
    public function cacheAdapterLibmemcachedGetKeys(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - getKeys()');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $memcachedServerVersions   = $adapter->getAdapter()->getVersion();
        $memcachedExtensionVersion = phpversion('memcached');

        foreach ($memcachedServerVersions as $server => $memcachedServerVersion) {
            // https://www.php.net/manual/en/memcached.getallkeys.php#123793
            // https://bugs.launchpad.net/libmemcached/+bug/1534062
            if (
                version_compare($memcachedServerVersion, '1.4.23', '>=') &&
                version_compare($memcachedExtensionVersion, '3.0.1', '<')
            ) {
                $I->skipTest(
                    'getAllKeys() does not work in certain Memcached versions'
                );
            }

            // https://github.com/php-memcached-dev/php-memcached/issues/367
            if (version_compare($memcachedServerVersion, '1.5.0', '>=')) {
                $I->skipTest(
                    'getAllKeys() does not work in certain Memcached versions'
                );
            }
        }

        $adapter->clear();

        $adapter->set('key-1', 'test');
        $adapter->set('key-2', 'test');

        $actual = $adapter->getKeys();
        sort($actual);
        $I->assertEquals(
            [
                'ph-memc-key-1',
                'ph-memc-key-2',
            ],
            $actual
        );
    }
}
