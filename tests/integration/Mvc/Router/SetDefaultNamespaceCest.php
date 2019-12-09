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

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router;

class SetDefaultNamespaceCest
{
    /**
     * Tests Phalcon\Mvc\Router :: setDefaultNamespace()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcRouterSetDefaultNamespace(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - setDefaultNamespace()');

        $router = new Router();

        $router->setDefaultNamespace('Phalcon');

        $I->assertEquals(
            'Phalcon',
            $router->getDefaults()['namespace']
        );
    }
}
