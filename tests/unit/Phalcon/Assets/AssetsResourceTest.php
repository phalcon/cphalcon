<?php
/**
 * AssetsResourceTest.php
 * \Phalcon\Resource\AssetsTest
 *
 * Tests the Phalcon\Assets component
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

use \PhalconTest\Assets\Resource as PhTAssetsResource;
use \PhalconTest\Assets\Resource\Css as PhTAssetsResourceCss;
use \PhalconTest\Assets\Resource\Js as PhTAssetsResourceJs;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class AssetsTest extends TBase
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

                $resource = new PhTAssetsResource('js', 'js/jquery.js');
                $expected = 'js';
                $actual   = $resource->getType();

                expect($actual)->equals($expected);
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

                $resource = new PhTAssetsResource('js', 'js/jquery.js');
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

                $resource = new PhTAssetsResource('js', 'js/jquery.js');
                $actual   = $resource->getLocal();

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests Css getType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetType()
    {
        $this->specify(
            "The resource Css getType is not correct",
            function () {

                $resource = new PhTAssetsResourceCss('/css/style.css', false);
                $expected = 'css';
                $actual   = $resource->getType();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests Css getPath
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetPath()
    {
        $this->specify(
            "The resource Css getPath is not correct",
            function () {

                $resource = new PhTAssetsResourceCss('/css/style.css', false);
                $expected = '/css/style.css';
                $actual   = $resource->getPath();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests Css getLocal
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetLocal()
    {
        $this->specify(
            "The resource Css getLocal is not correct",
            function () {

                $resource = new PhTAssetsResourceCss('/css/style.css', false);
                $actual   = $resource->getLocal();

                expect($actual)->false();
            }
        );
    }

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

                $resource = new PhTAssetsResourceJs('/js/jquery.js', false);
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

                $resource = new PhTAssetsResourceJs('/js/jquery.js', false);
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

                $resource = new PhTAssetsResourceJs('/js/jquery.js', false);
                $actual   = $resource->getLocal();

                expect($actual)->false();
            }
        );
    }
}
