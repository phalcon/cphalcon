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
 * Class SetHostnameCest
 */
class SetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: setHostname()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterGroupSetHostname(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - setHostname()');
        $I->skipTest('Need implementation');
    }
}
