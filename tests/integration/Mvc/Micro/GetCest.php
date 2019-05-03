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
 * Class GetCest
 */
class GetCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: get()
     *
     * @param IntegrationTester $I
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcMicroGet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - get()');

        $micro = new Micro();

        $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $micro->post(
            '/test',
            function () {
                return 'this is post';
            }
        );

        $micro->head(
            '/test',
            function () {
                return 'this is head';
            }
        );


        $_SERVER['REQUEST_METHOD'] = 'GET';

        $I->assertEquals(
            'this is get',
            $micro->handle('/test')
        );
    }
}
