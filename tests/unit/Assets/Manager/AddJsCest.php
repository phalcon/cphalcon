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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

use function dataDir;

class AddJsCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiUrl();
    }

    public function _after(UnitTester $I)
    {
        $this->resetDi();
    }

    /**
     * Tests Phalcon\Assets\Manager :: addJs()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerAddJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addJs()');

        $assets = new Manager();

        $assets->addJs('/js/jquery.js');
        $assets->addJs('/js/jquery-ui.js');

        $collection = $assets->get('js');

        foreach ($collection as $resource) {
            $I->assertEquals(
                'js',
                $resource->getType()
            );
        }

        $I->assertCount(2, $collection);
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

        $container = $this->getDI();

        $assets = new Manager();

        $assets->setDI($container);

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
            "%s".PHP_EOL."%s".PHP_EOL."%s".PHP_EOL,
            "<script src=\"{$pathData}assets/assets-version-1.js?ver=1.0.0\"></script>",
            "<script src=\"{$pathData}assets/assets-version-2.js?ver=2.0.0\"></script>",
            "<script src=\"{$pathData}assets/assets-version-3.js\"></script>"
        );

        $assets->useImplicitOutput(false);

        $I->assertEquals(
            $expected,
            $assets->outputJs()
        );
    }
}
