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

namespace Phalcon\Test\Unit\Cache\Backend\Redis;

use UnitTester;

/**
 * Class GetLastKeyCest
 */
class GetLastKeyCest
{
    /**
     * Tests Phalcon\Cache\Backend\Redis :: getLastKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cacheBackendRedisGetLastKey(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Redis - getLastKey()');
        $I->skipTest('Need implementation');
    }
}
