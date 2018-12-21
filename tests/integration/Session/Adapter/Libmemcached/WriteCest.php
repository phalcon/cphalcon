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
use function serialize;
use function uniqid;

/**
 * Class WriteCest
 */
class WriteCest
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
     * Tests Phalcon\Session\Adapter\Libmemcached :: write()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedWrite(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - write()');
        $adapter = $this->getSessionLibmemcached();
        $value   = uniqid();
        $adapter->write('test1', $value);

        /**
         * Serialize the value because the adapter does not have a serializer
         */
        $value = serialize($value);
        $I->seeInLibmemcached('test1', $value);
        $I->removeFromLibmemcached('test1');
    }
}
