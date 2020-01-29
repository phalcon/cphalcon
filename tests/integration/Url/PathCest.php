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

namespace Phalcon\Test\Integration\Url;

use IntegrationTester;
use Phalcon\Url;

class PathCest
{
    /**
     * Tests Phalcon\Url :: path()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function urlPath(IntegrationTester $I)
    {
        $I->wantToTest('Url - path()');
        $url = new Url();

        $url->setBasePath('/en');
        $path = '/en';

        $expected = '/en/team';
        $actual   = $url->path('/team');
        $I->assertEquals($expected, $actual);
    }
}
