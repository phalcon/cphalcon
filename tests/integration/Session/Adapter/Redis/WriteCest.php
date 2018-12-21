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

namespace Phalcon\Test\Integration\Session\Adapter\Redis;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
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
     * Tests Phalcon\Session\Adapter\Redis :: write()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisWrite(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - write()');
        $adapter = $this->getSessionRedis();
        $value   = uniqid();
        $adapter->write('test1', $value);

        /**
         * Serialize the value because the adapter does not have a serializer
         */
        $expected = $value;
        $actual   = $I->grabFromRedis('test1');
        $I->assertEquals($expected, $actual);
        $I->sendCommandToRedis('del', 'test1');
    }
}
