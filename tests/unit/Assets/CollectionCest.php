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

use Phalcon\Assets\Collection;
use Phalcon\Assets\Resource;
use UnitTester;

class CollectionCest
{
    /**
     * Tests Collection
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCollection(UnitTester $I)
    {
        $collection = new Collection();

        $collection->add(new Resource('js', 'js/jquery.js'));
        $collection->add(new Resource('js', 'js/jquery-ui.js'));

        $number   = 0;
        $expected = 'js';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
            $number++;
        }

        $expected = 2;
        $actual   = $number;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Collection::has
     *
     * @test
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-02
     */
    public function hasReource(UnitTester $I)
    {
        $collection = new Collection();

        $resource1 = new Resource('js', 'js/jquery.js');
        $resource2 = new Resource('js', 'js/jquery-ui.js');

        $collection->add($resource1);

        $actual = $collection->has($resource1);
        $I->assertTrue($actual);
        $actual = $collection->has($resource2);
        $I->assertFalse($actual);
    }

    /**
     * Tests Collection::has
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-02
     */
    public function doNotAddTheSameRecources(UnitTester $I)
    {
        $collection = new Collection();

        for ($i = 0; $i < 10; $i++) {
            $collection->add(new Resource('css', 'css/style.css'));
            $collection->add(new Resource('js', 'js/script.js'));
        }

        $expected = 2;
        $actual   = count($collection->getResources());
        $I->assertEquals($expected, $actual);
    }
}
