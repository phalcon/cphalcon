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

namespace Phalcon\Tests\Unit\Application;

use Phalcon\Application\AbstractApplication;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Tests\Fixtures\Application\ApplicationFixture;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Application
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Application\* :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationConstruct(UnitTester $I)
    {
        $I->wantToTest('Application - __construct()');

        $application = new ApplicationFixture();

        $I->assertInstanceOf(EventsAwareInterface::class, $application);
        $I->assertInstanceOf(InjectionAwareInterface::class, $application);
        $I->assertInstanceOf(AbstractApplication::class, $application);
    }
}
