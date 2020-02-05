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
use Phalcon\Text;

/**
 * Class SetActionPreformatCallbackCest
 */
class SetActionPreformatCallbackCest
{
    public const TESTING_ACTION = 'somePrettyControllerAction';

    /**
     * Tests Phalcon\Mvc\Router\Annotations :: setActionPreformatCallback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-03
     */
    public function mvcRouterAnnotationsSetActionPreformatCallback(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - setDefaultAction()');

        $router = $this->getRouter(false);

        $callback = [Text::class, 'uncamelize'];
        $router->setActionPreformatCallback($callback);
        $attachedCallback = $router->getActionPreformatCallback();

        $I->assertEquals(
            $callback,
            $attachedCallback
        );
    }
}
