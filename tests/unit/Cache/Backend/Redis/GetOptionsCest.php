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

class GetOptionsCest
{
    /**
     * Tests Phalcon\Cache\Backend\Redis :: getOptions()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendRedisGetOptions(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Redis - getOptions()');

        $I->skipTest('Need implementation');
    }
}
