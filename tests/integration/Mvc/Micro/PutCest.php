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
 * Class PutCest
 */
class PutCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: put()
     *
     * @param IntegrationTester $I
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcMicroPut(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - put()');

        $micro = new Micro();

        $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $micro->put(
            '/test',
            function () {
                return 'this is put';
            }
        );

        $micro->post(
            '/test',
            function () {
                return 'this is post';
            }
        );


        $_SERVER['REQUEST_METHOD'] = 'PUT';

        $I->assertEquals(
            'this is put',
            $micro->handle('/test')
        );
    }
}
