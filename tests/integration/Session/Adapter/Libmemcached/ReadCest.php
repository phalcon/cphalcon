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
use Phalcon\Tests\Fixtures\Traits\SessionTrait;

use function uniqid;

class ReadCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: write()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedRead(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - read()');

        $adapter = $this->newService('sessionLibmemcached');

        $value = uniqid();

        $I->haveInLibmemcached('sess-memc-test1', $value);

        $I->assertEquals(
            $value,
            $adapter->read('test1')
        );

        $I->removeFromLibmemcached('sess-memc-test1');

        $I->assertNotNull(
            $adapter->read('test1')
        );
    }
}
