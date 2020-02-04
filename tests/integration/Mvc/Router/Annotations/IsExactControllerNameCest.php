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
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class IsExactControllerNameCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('request');
        $this->setDiService('annotations');
    }

    /**
     * Tests Phalcon\Mvc\Router\Annotations :: isExactControllerName()
     */
    public function mvcRouterAnnotationsIsExactControllerName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - isExactControllerName()');

        $router = new Annotations(false);

        $I->assertTrue(
            $router->isExactControllerName()
        );
    }
}
