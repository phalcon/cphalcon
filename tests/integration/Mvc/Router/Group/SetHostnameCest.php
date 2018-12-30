<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;

/**
 * Class SetHostnameCest
 */
class SetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: setHostname()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGroupSetHostname(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - setHostname()');
        $I->skipTest('Need implementation');
    }
}
