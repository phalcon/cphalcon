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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

use function dataDir;
use function filemtime;

class SetAutoVersionCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * Tests Phalcon\Assets\Manager :: addJs() - automatic versioning
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-02-01
     */
    public function assetsManagerAddJsAutomaticVersioning(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addJs() - automatic versioning');

        $assets = new Manager();

        $assets->addJs(
            dataDir('assets/assets/assets-version-1.js'),
            true,
            false,
            [],
            '1.0.0'
        );

        $assets->addJs(
            dataDir('assets/assets/assets-version-2.js'),
            true,
            false,
            [],
            null,
            true
        );

        $assets->addJs(
            dataDir('assets/assets/assets-version-3.js'),
            true,
            false,
            [],
            null,
            false
        );

        $pathData = dataDir('assets/');

        $modificationTime = filemtime(
            dataDir('assets/assets/assets-version-3.js')
        );

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL . "%s" . PHP_EOL,
            "<script src=\"{$pathData}assets/assets-version-1.js?ver=1.0.0\"></script>",
            "<script src=\"{$pathData}assets/assets-version-2.js?ver=$modificationTime\"></script>",
            "<script src=\"{$pathData}assets/assets-version-3.js\"></script>"
        );

        $assets->useImplicitOutput(false);

        $I->assertEquals(
            $expected,
            $assets->outputJs()
        );
    }
}
