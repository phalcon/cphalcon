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

class HandleCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: handle()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
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


        // Micro echoes out its result as well
        ob_start();
        $testResult = $micro->handle('/test');
        ob_end_clean();

        $I->assertEquals(
            'this is a test',
            $testResult
        );


        // Micro echoes out its result as well
        ob_start();
        $helloSidResult = $micro->handle('/hello/sid');
        ob_end_clean();

        $I->assertEquals(
            'Hi Sid!',
            $helloSidResult
        );
    }
}
