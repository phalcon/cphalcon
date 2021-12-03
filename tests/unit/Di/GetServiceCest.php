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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class GetServiceCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetServiceCest
{
    /**
     * Unit Tests Phalcon\Di\Di :: getService()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetService(UnitTester $I)
    {
        $I->wantToTest('Di - getService()');

        // setup
        $container = new Di();

        // set a service and get it to check
        $class  = Service::class;
        $actual = $container->set('escaper', Escaper::class);
        $I->assertInstanceOf($class, $actual);

        // get escaper service
        $escaper = $container->getService('escaper');
        $I->assertInstanceOf(Service::class, $escaper);

        $actual = $escaper->isShared();
        $I->assertFalse($actual);
    }

    /**
     * Unit Tests Phalcon\Di :: getService() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetServiceException(UnitTester $I)
    {
        $I->wantToTest('Di - getService() - exception');

        // setup
        $container = new Di();

        // non exists service
        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' was not found in the " .
                "dependency injection container"
            ),
            function () use ($container) {
                $container->getService('non-exists');
            }
        );
    }
}
