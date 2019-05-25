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

namespace Phalcon\Test\Unit\Cache\Adapter\Redis;

use UnitTester;

class GetDefaultSerializerCest
{
    /**
     * Unit Tests Phalcon\Cache\Adapter\Redis :: getDefaultSerializer()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function cacheAdapterRedisGetDefaultSerializer(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - getDefaultSerializer()');

        $I->skipTest('Need implementation');
    }
}
