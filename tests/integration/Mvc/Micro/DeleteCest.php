<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Mvc\Micro;

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

        // Micro echoes out its result as well
        ob_start();
        $result = $micro->handle('/test');
        ob_end_clean();

        $I->assertEquals(
            'this is delete',
            $result
        );
    }
}
