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

/**
 * Class DestroyCest
 */
class DestroyCest
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
     * Tests Phalcon\Session\Adapter\Libmemcached :: destroy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - destroy()');
        $adapter = $this->getSessionLibmemcached();

        $value      = uniqid();
        $serialized = serialize($value);
        $I->haveInLibmemcached('test1', $serialized);
        $actual = $adapter->destroy('test1');
        $I->assertTrue($actual);
        $I->dontSeeInLibmemcached('test1');
    }
}
