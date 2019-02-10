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

namespace Phalcon\Test\Unit\Mvc\Router\Route;

use UnitTester;

/**
 * Class SetHostnameCest
 */
class SetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: setHostname()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcRouterRouteSetHostname(UnitTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - setHostname()');
        $I->skipTest('Need implementation');
    }
}
