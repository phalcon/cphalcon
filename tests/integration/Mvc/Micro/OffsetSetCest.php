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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;

class OffsetSetCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: offsetSet()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcMicroOffsetSet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - offsetSet()');

        $micro = new Micro();

        $di = new Di();

        $micro->setDi($di);



        $dispatcher = new Dispatcher();

        $micro['dispatcher'] = $dispatcher;

        $I->assertSame(
            $dispatcher,
            $micro['dispatcher']
        );
    }
}
