<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Support\Version;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class GetVersionCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug
 */
class GetVersionCest
{
    use DiTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Debug :: getVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugGetVersion(UnitTester $I)
    {
        $I->wantToTest('Debug - getVersion()');

        $debug   = new Debug();
        $version = new Version();

        $target  = '"_new"';
        $uri     = '"https://docs.phalcon.io/'
            . $version->getPart(Version::VERSION_MAJOR) . '.'
            . $version->getPart(Version::VERSION_MEDIUM) . '/en/"';
        $version = $version->get();

        $I->assertEquals(
            "<div class=\"version\">Phalcon Framework <a href={$uri} target={$target}>{$version}</a></div>",
            $debug->getVersion()
        );
    }
}
