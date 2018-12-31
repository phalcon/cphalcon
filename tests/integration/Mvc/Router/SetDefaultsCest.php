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

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;

/**
 * Class SetDefaultsCest
 */
class SetDefaultsCest
{
    /**
     * Tests Phalcon\Mvc\Router :: setDefaults()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterSetDefaults(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - setDefaults()');
        $I->skipTest('Need implementation');
    }
}
