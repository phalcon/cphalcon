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

class PutCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: put()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
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

        // Micro echoes out its result as well
        ob_start();
        $result = $micro->handle('/test');
        ob_end_clean();

        $I->assertEquals(
            'this is put',
            $result
        );
    }
}
