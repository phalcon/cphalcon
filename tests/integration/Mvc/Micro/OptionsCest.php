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
 * Class OptionsCest
 */
class OptionsCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: options()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcMicroOptions(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - options()');

        $micro = new Micro();

        $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $micro->options(
            '/test',
            function () {
                return 'this is options';
            }
        );

        $micro->head(
            '/test',
            function () {
                return 'this is head';
            }
        );


        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';

        $I->assertEquals(
            'this is options',
            $micro->handle('/test')
        );
    }
}
