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

namespace Phalcon\Test\Unit\Debug;

use Phalcon\Debug\Debug;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Version;
use UnitTester;

class GetVersionCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Debug :: getVersion()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugGetVersion(UnitTester $I)
    {
        $I->wantToTest('Debug - getVersion()');

        $debug = new Debug();

        $target  = '"_new"';
        $uri     = '"https://docs.phalconphp.com/'
            . Version::getPart(Version::VERSION_MAJOR) . '.'
            . Version::getPart(Version::VERSION_MEDIUM) . '/en/"';
        $version = Version::get();

        $I->assertEquals(
            "<div class='version'>Phalcon Framework <a href={$uri} target={$target}>{$version}</a></div>",
            $debug->getVersion()
        );
    }
}
