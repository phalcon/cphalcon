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

namespace Phalcon\Tests\Integration\Mvc\Router\Group;

use IntegrationTester;

/**
 * Class GetHostnameCest
 */
class GetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: getHostname()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterGroupGetHostname(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - getHostname()');
        $I->skipTest('Need implementation');
    }
}
