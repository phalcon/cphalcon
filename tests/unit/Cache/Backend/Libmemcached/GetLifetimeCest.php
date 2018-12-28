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

namespace Phalcon\Test\Unit\Cache\Backend\Libmemcached;

use UnitTester;

/**
 * Class GetLifetimeCest
 */
class GetLifetimeCest
{
    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: getLifetime()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedGetLifetime(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - getLifetime()');
        $I->skipTest('Need implementation');
    }
}
