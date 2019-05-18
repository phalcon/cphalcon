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

namespace Phalcon\Test\Unit\Assets\Manager;

use function dataDir;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class AddJsCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Manager :: addJs()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerAddJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addJs()');
        $assets = new Manager();

        $assets->addJs('/js/jquery.js');
        $assets->addJs('/js/jquery-ui.js');

        $collection = $assets->get('js');

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
     * Tests Phalcon\Assets\Manager :: addJs() - versioning
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-02-01
     */
    public function assetsManagerAddJsVersioning(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addJs() - versioning');

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
            '2.0.0'
        );
        $assets->addJs(
            dataDir('assets/assets/assets-version-3.js'),
            true,
            false,
            []
        );

        $pathData = dataDir('assets/');

        $expected = sprintf(
            "%s\n%s\n%s\n",
            "<script src=\"{$pathData}assets/assets-version-1.js?ver=1.0.0\"></script>",
            "<script src=\"{$pathData}assets/assets-version-2.js?ver=2.0.0\"></script>",
            "<script src=\"{$pathData}assets/assets-version-3.js\"></script>"
        );

        $assets->useImplicitOutput(false);
        $I->assertEquals($expected, $assets->outputJs());
    }
}
