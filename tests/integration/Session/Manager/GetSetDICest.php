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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Session\Manager;

/**
 * Class GetDICest
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Session\Manager :: getDI()/setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getDI()/setDI()');
        $session   = new Manager();
        $container = new FactoryDefault();
        $session->setDI($container);
        $I->assertEquals($container, $session->getDI());
    }
}
