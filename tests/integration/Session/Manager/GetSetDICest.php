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

namespace Phalcon\Tests\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Session\Manager;

class GetSetDICest
{
    /**
     * Tests Phalcon\Session\Manager :: getDI()/setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getDI()/setDI()');

        $session   = new Manager();
        $container = new FactoryDefault();

        $session->setDI($container);

        $actual = $session->getDI();
        $I->assertEquals($container, $actual);
    }
}
