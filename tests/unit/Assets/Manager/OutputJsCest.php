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

use Phalcon\Assets\Asset\Js;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Assets\CustomTag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class OutputJsCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    public function _after(UnitTester $I)
    {
        $this->resetDi();
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs() - implicit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputJs() - implicit');

        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');

        $assets->addAsset(
            new Js('/js/script3.js', false)
        );

        $assets->useImplicitOutput(false);

        $expected = '<script src="/js/script1.js"></script>' . PHP_EOL
            . '<script src="/js/script2.js"></script>' . PHP_EOL
            . '<script src="/js/script3.js"></script>' . PHP_EOL;

        $I->assertEquals(
            $expected,
            $actual = $assets->outputJs()
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs() - not implicit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsNotImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputJs() - not implicit');

        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');

        $assets->addAsset(
            new Js(
                '/js/script3.js',
                false
            )
        );

        $expected = '<script src="/js/script1.js"></script>' . PHP_EOL .
            '<script src="/js/script2.js"></script>' . PHP_EOL .
            '<script src="/js/script3.js"></script>' . PHP_EOL;

        ob_start();
        $assets->outputJs();
        $actual = ob_get_clean();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - custom tag component
     */
    public function assetsManagerOutputJsCustomTag(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - custom tag component');

        $di = $this->getDi();

        $di->setShared(
            'tag',
            CustomTag::class
        );

        $assets = new Manager();

        $assets->setDI($di);

        $assets->addJs('js/script1.js');
        $assets->addJs('/js/script2.js');

        $assets->addAsset(
            new Js('/js/script3.js')
        );

        $expected = '<script src="js/script1.js" type="application/javascript"></script>' . PHP_EOL
            . '<script src="/js/script2.js" type="application/javascript"></script>' . PHP_EOL
            . '<script src="/js/script3.js" type="application/javascript"></script>' . PHP_EOL;

        ob_start();
        $assets->outputJs();
        $actual = ob_get_clean();

        $I->assertEquals($expected, $actual);
    }
}
