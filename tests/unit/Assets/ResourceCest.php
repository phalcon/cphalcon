<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Resource;
use UnitTester;

class ResourceCest
{
    /**
     * Tests getPath
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetPath(UnitTester $I)
    {
        $resource = new Resource('js', 'js/jquery.js');
        $expected = 'js/jquery.js';
        $actual   = $resource->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getLocal
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetLocal(UnitTester $I)
    {
        $resource = new Resource('js', 'js/jquery.js');
        $actual   = $resource->getLocal();
        $I->assertTrue($actual);
    }
}
