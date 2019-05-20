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
 * Class PatchCest
 */
class PatchCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: patch()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcMicroPatch(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - patch()');

        $micro = new Micro();

        $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $micro->patch(
            '/test',
            function () {
                return 'this is patch';
            }
        );

        $micro->post(
            '/test',
            function () {
                return 'this is post';
            }
        );


        $_SERVER['REQUEST_METHOD'] = 'PATCH';

        $I->assertEquals(
            'this is patch',
            $micro->handle('/test')
        );
    }
}
