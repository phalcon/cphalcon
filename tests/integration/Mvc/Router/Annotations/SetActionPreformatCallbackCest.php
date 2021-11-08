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

namespace Phalcon\Tests\Integration\Mvc\Router\Annotations;

use IntegrationTester;
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Support\Helper\Str\Uncamelize;
use Phalcon\Text;

/**
 * Class SetActionPreformatCallbackCest
 */
class SetActionPreformatCallbackCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: setActionPreformatCallback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-03
     */
    public function mvcRouterAnnotationsSetActionPreformatCallback(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - setDefaultAction()');

        $router     = new Annotations(false);
        $uncamelize = new Uncamelize();
        $callback   = [$uncamelize, '__invoke'];
        $router->setActionPreformatCallback($callback);
        $attachedCallback = $router->getActionPreformatCallback();

        $I->assertEquals(
            $callback,
            $attachedCallback
        );
    }
}
