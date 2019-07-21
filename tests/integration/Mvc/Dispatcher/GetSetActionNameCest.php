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
use Phalcon\Mvc\Dispatcher;

class GetSetActionNameCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getActionName() / setActionName()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcDispatcherGetActionName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getActionName() / setActionName()');
        
        $dispatcher = new Dispatcher();

        $dispatcher->setActionName('login');

        $I->assertEquals(
            'login',
            $dispatcher->getActionName()
        );
    }
}
