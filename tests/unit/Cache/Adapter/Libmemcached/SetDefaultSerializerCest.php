<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Adapter\Libmemcached;

use UnitTester;

class SetDefaultSerializerCest
{
    /**
     * Unit Tests Phalcon\Cache\Adapter\Libmemcached :: setDefaultSerializer()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function cacheAdapterLibmemcachedSetDefaultSerializer(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - setDefaultSerializer()');

        $I->skipTest('Need implementation');
    }
}
