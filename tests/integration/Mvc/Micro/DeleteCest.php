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
 * Class DeleteCest
 */
class DeleteCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: delete()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcMicroDelete(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - delete()');

        $micro = new Micro();

        $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $micro->delete(
            '/test',
            function () {
                return 'this is delete';
            }
        );

        $micro->head(
            '/test',
            function () {
                return 'this is head';
            }
        );


        $_SERVER['REQUEST_METHOD'] = 'DELETE';

        $I->assertEquals(
            'this is delete',
            $micro->handle('/test')
        );
    }
}
