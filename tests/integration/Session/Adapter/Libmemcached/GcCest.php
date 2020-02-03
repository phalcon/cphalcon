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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

use function sleep;
use function uniqid;

class GcCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: gc()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - gc()');
        $adapter = $this->newService('sessionLibmemcached');

        /**
         * Add two session keys
         */
        $I->haveInLibmemcached('sess-memc-gc_1', uniqid(), 1);
        $I->haveInLibmemcached('sess-memc-gc_2', uniqid(), 1);
        /**
         * Sleep to make sure that the time expired
         */
        sleep(2);
        $actual = $adapter->gc(1);
        $I->assertTrue($actual);
        $I->dontSeeInLibmemcached('sess-memc-gc_1');
        $I->dontSeeInLibmemcached('sess-memc-gc_2');
    }
}
