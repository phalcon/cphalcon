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

namespace Phalcon\Test\Unit\Storage\Adapter\Redis;

use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageAdapterRedisGet(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()');

        $I->skipTest('Need implementation');
    }
}
