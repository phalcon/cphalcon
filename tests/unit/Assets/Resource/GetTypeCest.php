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

class GetTypeCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Resource :: getType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceGetType(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource - getType()");
        $resource = new Resource('js', 'js/jquery.js');
        $this->resourceGetType($I, $resource, 'js');

        $resource = new Resource('css', 'css/docs.css');
        $this->resourceGetType($I, $resource, 'css');
    }
}
