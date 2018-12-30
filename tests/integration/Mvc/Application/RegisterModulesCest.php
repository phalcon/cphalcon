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

namespace Phalcon\Test\Integration\Mvc\Application;

use IntegrationTester;

/**
 * Class RegisterModulesCest
 */
class RegisterModulesCest
{
    /**
     * Tests Phalcon\Mvc\Application :: registerModules()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcApplicationRegisterModules(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Application - registerModules()');
        $I->skipTest('Need implementation');
    }
}
