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
 * Class GetConvertersCest
 */
class GetConvertersCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getConverters()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterRouteGetConverters(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getConverters()');
        $I->skipTest('Need implementation');
    }
}
