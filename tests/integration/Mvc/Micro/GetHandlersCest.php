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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Mvc\Micro;

class GetHandlersCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: getHandlers()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcMicroGetHandlers(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - getHandlers()');

        $micro = new Micro();

        $getRoute = $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $postRoute = $micro->post(
            '/test',
            function () {
                return 'this is post';
            }
        );

        $headRoute = $micro->head(
            '/test',
            function () {
                return 'this is head';
            }
        );

        $handlers = $micro->getHandlers();

        $I->assertCount(
            3,
            $handlers
        );

        $I->assertEquals(
            'this is get',
            $handlers[$getRoute->getId()]()
        );

        $I->assertEquals(
            'this is post',
            $handlers[$postRoute->getId()]()
        );

        $I->assertEquals(
            'this is head',
            $handlers[$headRoute->getId()]()
        );
    }
}
