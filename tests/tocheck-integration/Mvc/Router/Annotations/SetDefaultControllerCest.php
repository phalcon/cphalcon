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

namespace Phalcon\Test\Integration\Mvc\Router\Annotations;

use IntegrationTester;

/**
 * Class SetDefaultControllerCest
 */
class SetDefaultControllerCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: setDefaultController()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsSetDefaultController(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - setDefaultController()');
        $I->skipTest('Need implementation');
    }
}
