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

namespace Phalcon\Tests\Integration\Session\Adapter\Redis;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function uniqid;

class DestroyCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Redis :: destroy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterRedisDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - destroy()');

        $adapter = $this->newService('sessionRedis');

        $value = uniqid();

        $I->haveInRedis(
            'string',
            'sess-reds-test1',
            serialize($value)
        );

        $actual = $adapter->destroy('test1');
        $I->assertTrue($actual);

        $I->dontSeeInRedis('sess-reds-test1');
    }
}
