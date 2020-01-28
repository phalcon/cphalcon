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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;

class GetServiceCest
{
    /**
     * Unit Tests Phalcon\Di :: getService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diGetService(UnitTester $I)
    {
        $I->wantToTest('Di - getService()');

        // setup
        $di = new Di();

        // set a service and get it to check
        $actual = $di->set('escaper', Escaper::class);

        $I->assertInstanceOf(Service::class, $actual);

        // get escaper service
        $actual = $di->getService('escaper');

        $I->assertInstanceOf(Service::class, $actual);
        $I->assertFalse($actual->isShared());

        // non exists service
        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' wasn't found in the dependency injection container"
            ),
            function () use ($di) {
                $di->getService('non-exists');
            }
        );
    }
}
