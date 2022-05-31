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

use function uniqid;

class ReadWriteCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: write()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterLibmemcachedRead(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - read()');

        $adapter = $this->newService('sessionLibmemcached');

        $value = uniqid();

        $adapter->write('test1', $value);

        $actual = $adapter->read('test1');
        $I->assertEquals($value, $actual);

        $I->clearMemcache();

        $actual = $adapter->read('test1');
        $I->assertNotNull($actual);
    }
}
