<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Resource;

use Phalcon\Assets\Resource;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class GetResourceKeyCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Resource :: getResourceKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceGetResourceKey(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource - getResourceKey()");
        $resource = new Resource('css', 'css/docs.css');
        $expected = md5('css:css/docs.css');
        $this->resourceGetResourceKey($I, $resource, $expected);


        $resource = new Resource('js', 'js/jquery.js');
        $expected = md5('js:js/jquery.js');
        $this->resourceGetResourceKey($I, $resource, $expected);
    }
}
