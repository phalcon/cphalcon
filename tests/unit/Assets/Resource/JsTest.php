<?php

namespace Phalcon\Test\Unit\Assets\Resource;

use Phalcon\Assets\Resource\Js;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Assets\Resource\JsTest
 * Tests the \Phalcon\Assets\Resource\Js component
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
class JsTest extends UnitTest
{
    /**
     * Tests Js getType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceJsGetType()
    {
        $this->specify(
            "The resource Js getType is not correct",
            function () {
                $resource = new Js('/js/jquery.js', false);
                $expected = 'js';
                $actual   = $resource->getType();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests Js getPath
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceJsGetPath()
    {
        $this->specify(
            "The resource Js getPath is not correct",
            function () {
                $resource = new Js('/js/jquery.js', false);
                $expected = '/js/jquery.js';
                $actual   = $resource->getPath();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests Js getLocal
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceJsGetLocal()
    {
        $this->specify(
            "The resource Js getLocal is not correct",
            function () {
                $resource = new Js('/js/jquery.js', false);
                $actual   = $resource->getLocal();

                expect($actual)->false();
            }
        );
    }
}
