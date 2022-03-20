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

class CloseCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: close()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterLibmemcachedClose(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - close()');

        $adapter = $this->newService('sessionLibmemcached');
        $actual  = $adapter->close();
        $I->assertTrue($actual);
    }
}
