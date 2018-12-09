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

namespace Phalcon\Test\Unit\Assets\Resource\Js;

use Phalcon\Assets\Resource\Js;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class GetResourceKeyCest
 *
 * @package Phalcon\Test\Unit\Assets\Resource\Js
 */
class GetResourceKeyCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Resource\Js :: getResourceKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceJsGetResourceKey(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource\Js - getResourceKey()");
        $resource = new Js('js/jquery.js');
        $expected = md5('js:js/jquery.js');

        $this->resourceGetResourceKey($I, $resource, $expected);
    }
}
