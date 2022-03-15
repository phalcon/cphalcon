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

namespace Phalcon\Tests\Integration\Session\Adapter\Libmemcached;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function sleep;
use function uniqid;

class GcCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: gc()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterLibmemcachedGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - gc()');
        $adapter = $this->newService('sessionLibmemcached');

        /**
         * Add two session keys
         */
        $I->haveInMemcached('sess-memc-gc_1', uniqid(), 1);
        $I->haveInMemcached('sess-memc-gc_2', uniqid(), 1);
        /**
         * Sleep to make sure that the time expired
         */
        sleep(2);
        $actual = $adapter->gc(1);
        $I->assertTrue($actual);
        $I->dontSeeInMemcached('sess-memc-gc_1');
        $I->dontSeeInMemcached('sess-memc-gc_2');
    }
}
