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

/**
 * Class GetNamespaceNameCest
 */
class GetNamespaceNameCest
{
    /**
     * Tests Phalcon\Mvc\Router :: getNamespaceName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterGetNamespaceName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - getNamespaceName()');
        $I->skipTest('Need implementation');
    }
}
