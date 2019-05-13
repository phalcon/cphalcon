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

namespace Phalcon\Test\Integration\Url;

use IntegrationTester;
use Phalcon\Url;

/**
 * Class GetSetBaseUriCest
 *
 * @package Phalcon\Test\Integration\Url
 */
class GetSetBaseUriCest
{
    /**
     * Tests Phalcon\Url :: getBaseUri()/setBaseUri()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function urlGetSetBaseUri(IntegrationTester $I)
    {
        $I->wantToTest("Url - getBaseUri()/setBaseUri()");
        $url = new Url();

        $path = 'https://phalconphp.com';
        $url->setBaseUri($path);

        $expected = $path;
        $actual   = $url->getBaseUri();
        $I->assertEquals($expected, $actual);
    }
}
