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
use function uniqid;

class DestroyCest
{
    use DiTrait;
    use SessionTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: destroy()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - destroy()');

        $adapter = $this->getSessionLibmemcached();

        $value = uniqid();

        $I->haveInLibmemcached(
            'sess-memc-test1',
            serialize($value)
        );

        $I->assertTrue(
            $adapter->destroy('test1')
        );

        $I->dontSeeInLibmemcached('sess-memc-test1');
    }
}
