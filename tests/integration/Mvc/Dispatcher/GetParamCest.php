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

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;

/**
 * Class GetParamCest
 */
class GetParamCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getParam()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcDispatcherGetParam(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getParam()');
        $I->skipTest('Need implementation');
    }
}
