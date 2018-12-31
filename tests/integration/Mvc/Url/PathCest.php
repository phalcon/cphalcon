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

namespace Phalcon\Test\Integration\Mvc\Url;

use Phalcon\Mvc\Url;
use IntegrationTester;

/**
 * Class PathCest
 */
class PathCest
{
    /**
     * Tests Phalcon\Mvc\Url :: path()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlPath(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Url - path()");
        $url = new Url();

        $url->setBasePath('/en');
        $path = '/en';

        $expected = '/en/team';
        $actual   = $url->path('/team');
        $I->assertEquals($expected, $actual);
    }
}
