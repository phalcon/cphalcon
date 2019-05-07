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

namespace Phalcon\Test\Unit\Mvc\Router\Group;

use UnitTester;

class SetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: setHostname()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcRouterGroupSetHostname(UnitTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - setHostname()');

        $I->skipTest('Need implementation');
    }
}
