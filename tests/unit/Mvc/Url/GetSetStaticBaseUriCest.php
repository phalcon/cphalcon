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

namespace Phalcon\Test\Unit\Mvc\Url;

use Phalcon\Mvc\Url;
use UnitTester;

/**
 * Class GetStaticBaseUriCest
 *
 * @package Phalcon\Test\Unit\Mvc\Url
 */
class GetSetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getStaticBaseUri()/setStaticBaseUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetStaticBaseUri(UnitTester $I)
    {
        $I->wantToTest("Mvc\Url - getStaticBaseUri()/setStaticBaseUri()");
        $url = new Url();

        $path = 'https://phalconphp.com';
        $url->setStaticBaseUri($path);

        $expected = $path;
        $actual   = $url->getStaticBaseUri();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Url :: getStaticBaseUri()/setStaticBaseUri() -
     * getBaseUrl()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetStaticBaseUriGetBaseUri(UnitTester $I)
    {
        $I->wantToTest("Mvc\Url - getStaticBaseUri()/setStaticBaseUri() - getBaseUri()");
        $url = new Url();

        $expected = 'https://phalconphp.com';
        $url->setBaseUri($expected);
        $actual = $url->getStaticBaseUri();
        $I->assertEquals($expected, $actual);
    }
}
