<?php

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Resource;
use Phalcon\Test\Proxy\Assets\Collection;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Assets\CollectionTest
 * Tests the \Phalcon\Assets\Collection component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Asset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CollectionTest extends UnitTest
{
    /**
     * Tests Collection
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCollection()
    {
        $this->specify(
            "The resource collection is not correct",
            function () {
                $collection = new Collection();

                $collection->add(new Resource('js', 'js/jquery.js'));
                $collection->add(new Resource('js', 'js/jquery-ui.js'));

                $number = 0;
                foreach ($collection as $resource) {
                    expect($resource->getType())->equals('js');
                    $number++;
                }

                expect($number)->equals(2);
            }
        );
    }
}
