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

use Phalcon\Test\Fixtures\Traits\Cache\LibmemcachedTrait;
use UnitTester;

/**
 * Class FlushCest
 */
class FlushCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: flush()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedFlush(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - flush()');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache    = $this->getDataCache($statsKey);

        $I->haveInLibmemcached('data-flush-1', 1);
        $I->haveInLibmemcached('data-flush-2', 2);
        $I->haveInLibmemcached('data-flush-3', 3);

        $I->haveInLibmemcached(
            $statsKey,
            ['data-flush-1' => $lifetime, 'data-flush-2' => $lifetime, 'data-flush-3' => $lifetime]
        );

        $I->assertTrue($cache->flush());

        $I->dontSeeInLibmemcached('data-flush-1');
        $I->dontSeeInLibmemcached('data-flush-2');
        $I->dontSeeInLibmemcached('data-flush-3');

        $I->dontSeeInLibmemcached($statsKey);
    }
}
