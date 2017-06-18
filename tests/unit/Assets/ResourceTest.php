<?php

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Resource;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Assets\ResourceTest
 * Tests the \Phalcon\Assets\Resource component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Asset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ResourceTest extends UnitTest
{
    /**
     * Tests getType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetType()
    {
        $this->specify(
            "The resource getType is not correct",
            function () {
                $resource = new Resource('js', 'js/jquery.js');
                $expected = 'js';
                $actual   = $resource->getType();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests getResourceKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-02
     */
    public function getResourceKey()
    {
        $this->specify(
            "Unable to get resource key or resorce key is incorrect",
            function () {
                $resource = new Resource('js', 'js/jquery.js');

                expect(md5('js:js/jquery.js'))->equals($resource->getResourceKey());
            }
        );
    }

    /**
     * Tests getPath
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetPath()
    {
        $this->specify(
            "The resource getPath is not correct",
            function () {
                $resource = new Resource('js', 'js/jquery.js');
                $expected = 'js/jquery.js';
                $actual   = $resource->getPath();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests getLocal
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetLocal()
    {
        $this->specify(
            "The resource getLocal is not correct",
            function () {
                $resource = new Resource('js', 'js/jquery.js');
                $actual   = $resource->getLocal();

                expect($actual)->true();
            }
        );
    }
}
