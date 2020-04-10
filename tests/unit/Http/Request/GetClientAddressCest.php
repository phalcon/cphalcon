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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class GetClientAddressCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getClientAddress()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGetClientAddress(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getClientAddress()');

        $store = $_SERVER ?? [];

        $this->setNewFactoryDefault();
        $request = $this->container->get('request');

        $_SERVER = [
            'REMOTE_ADDR'          => '192.168.0.1',
            'HTTP_X_FORWARDED_FOR' => '192.168.7.21',
        ];

        $I->assertEquals(
            '192.168.0.1',
            $request->getClientAddress()
        );

        $I->assertEquals(
            '192.168.7.21',
            $request->getClientAddress(true)
        );

        $_SERVER = [
            'REMOTE_ADDR' => '86.45.89.47, 214.55.34.56',
        ];

        $I->assertEquals(
            '86.45.89.47',
            $request->getClientAddress()
        );

        $_SERVER = $store;
    }
}
