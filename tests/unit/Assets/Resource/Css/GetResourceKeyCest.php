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

namespace Phalcon\Test\Unit\Assets\Resource\Css;

use Phalcon\Assets\Resource\Css;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class GetResourceKeyCest
 *
 * @package Phalcon\Test\Unit\Assets\Resource\Css
 */
class GetResourceKeyCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Resource\Css :: getResourceKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceCssGetResourceKey(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource\Css - getResourceKey()");
        $resource = new Css('css/docs.css');
        $expected = md5('css:css/docs.css');

        $this->resourceGetResourceKey($I, $resource, $expected);
    }
}
