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
use Phalcon\Mvc\Micro;

/**
 * Class HandleCest
 */
class HandleCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: handle()
     *
     * @param IntegrationTester $I
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcMicroHandle(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - handle()');

        $micro = new Micro();

        $micro->map(
            '/test',
            function () {
                return 'this is a test';
            }
        );

        $micro->map(
            '/hello/{name}',
            function ($name) {
                return 'Hi ' . ucfirst($name) . '!';
            }
        );



        $I->assertEquals(
            'this is a test',
            $micro->handle('/test')
        );

        $I->assertEquals(
            'Hi Sid!',
            $micro->handle('/hello/sid')
        );
    }
}
