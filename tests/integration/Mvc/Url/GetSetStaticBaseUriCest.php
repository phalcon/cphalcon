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

namespace Phalcon\Tests\Integration\Mvc\Url;

use IntegrationTester;
use Phalcon\Mvc\Url;

class GetSetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getStaticBaseUri()/setStaticBaseUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetStaticBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - getStaticBaseUri()/setStaticBaseUri()');

        $url = new Url();

        $path = 'https://phalcon.io';

        $url->setStaticBaseUri($path);

        $I->assertEquals(
            $path,
            $url->getStaticBaseUri()
        );
    }

    /**
     * Tests Phalcon\Mvc\Url :: getStaticBaseUri()/setStaticBaseUri() -
     * getBaseUrl()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetStaticBaseUriGetBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - getStaticBaseUri()/setStaticBaseUri() - getBaseUri()');

        $url = new Url();

        $expected = 'https://phalcon.io';

        $url->setBaseUri($expected);

        $actual = $url->getStaticBaseUri();

        $I->assertEquals($expected, $actual);
    }
}
