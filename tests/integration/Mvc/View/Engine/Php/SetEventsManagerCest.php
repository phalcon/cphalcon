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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Php;

use IntegrationTester;

/**
 * Class SetEventsManagerCest
 */
class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Php :: setEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEnginePhpSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Php - setEventsManager()');
        $I->skipTest('Need implementation');
    }
}
