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

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;

/**
 * Class SetDefaultActionCest
 */
class SetDefaultActionCest
{
    /**
     * Tests Phalcon\Mvc\Router :: setDefaultAction()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterSetDefaultAction(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - setDefaultAction()');
        $I->skipTest('Need implementation');
    }
}
