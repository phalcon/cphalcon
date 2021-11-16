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

namespace Phalcon\Tests\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router;

class SetDefaultActionCest
{
    /**
     * Tests Phalcon\Mvc\Router :: setDefaultAction()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcRouterSetDefaultAction(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - setDefaultAction()');

        $router = new Router();

        $router->setDefaultAction('default');

        $I->assertEquals(
            'default',
            $router->getDefaults()['action']
        );
    }
}
