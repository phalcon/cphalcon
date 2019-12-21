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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;

/**
 * Class RegisterEnginesCest
 */
class RegisterEnginesCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: registerEngines()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleRegisterEngines(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - registerEngines()');
        $I->skipTest('Need implementation');
    }
}
