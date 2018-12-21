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

namespace Phalcon\Test\Integration\Session\Adapter\Libmemcached;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use function sleep;
use function uniqid;

/**
 * Class GcCest
 */
class GcCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: gc()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - gc()');
        $adapter = $this->getSessionLibmemcached();

        /**
         * Add two session keys
         */
        $I->haveInLibmemcached('gc_1', uniqid(), 1);
        $I->haveInLibmemcached('gc_2', uniqid(), 1);
        /**
         * Sleep to make sure that the time expired
         */
        sleep(2);
        $actual = $adapter->gc(1);
        $I->assertTrue($actual);
        $I->dontSeeInLibmemcached('gc_1');
        $I->dontSeeInLibmemcached('gc_2');
    }
}
