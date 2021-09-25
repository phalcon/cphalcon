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

namespace Phalcon\Tests\Integration\Mvc\Router\Route;

use IntegrationTester;

/**
 * Class ViaCest
 */
class ViaCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: via()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterRouteVia(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - via()');
        $I->skipTest('Need implementation');
    }
}
