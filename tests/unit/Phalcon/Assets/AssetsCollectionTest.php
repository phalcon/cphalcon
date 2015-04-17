<?php
/**
 * AssetsCollectionTest.php
 * \Phalcon\Resource\AssetsCollectionTest
 *
 * Tests the Phalcon\Assets\Collection component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Assets;

use \Phalcon\Assets\Resource as PhAssetsResource;

use \PhalconTest\Assets\Collection as PhTAssetsCollection;
use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class AssetsCollectionTest extends TBase
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

                $collection = new PhTAssetsCollection();

                $collection->add(new PhAssetsResource('js', 'js/jquery.js'));
                $collection->add(new PhAssetsResource('js', 'js/jquery-ui.js'));

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
