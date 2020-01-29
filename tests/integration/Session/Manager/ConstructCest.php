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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Session\ManagerInterface;

class ConstructCest
{
    /**
     * Tests Phalcon\Session\Manager :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __construct()');

        $manager = new Manager();

        $I->assertInstanceOf(
            ManagerInterface::class,
            $manager
        );
    }
}
