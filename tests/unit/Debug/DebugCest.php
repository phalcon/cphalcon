<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug;

use Phalcon\Debug;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Url;
use Phalcon\Version;
use UnitTester;

class DebugCest
{
    public function _before(UnitTester $I)
    {
        Di::reset();
        $container = new FactoryDefault();

        $container->setShared('url', function () {
            return new Url();
        });

        Di::setDefault($container);
    }

    public function _after(UnitTester $I)
    {
        Di::reset();
    }

    /**
     * Tests the Debug::getVersion
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12215
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-09-25
     */
    public function testShouldGetVersion(UnitTester $I)
    {
        $debug   = new Debug;
        $target  = '"_new"';
        $uri     = '"https://docs.phalconphp.com/en/' . Version::getPart(Version::VERSION_MAJOR) . '.0.0/"';
        $version = Version::get();

        $expected = "<div class='version'>Phalcon Framework <a href={$uri} target={$target}>{$version}</a></div>";
        $actual   = $debug->getVersion();
        $I->assertEquals($expected, $actual);
    }
}
