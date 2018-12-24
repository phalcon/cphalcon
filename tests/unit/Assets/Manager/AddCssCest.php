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

use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class AddCssCest
 */
class AddCssCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addCss()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerAddCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addCss()');
        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');

        $collection = $assets->get('css');

        $number   = 0;
        $expected = 'css';
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
     * Tests Phalcon\Assets\Manager :: addCss() - duplicate
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-02
     */
    public function assetsManagerAddCssDuplicate(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addCss() - duplicate');
        $assets = new Manager();

        for ($i = 0; $i < 10; $i++) {
            $assets
                ->addCss('css/style.css')
                ->addJs('script.js')
            ;
        }

        $expected = 1;
        $actual   = count($assets->getCss());
        $I->assertEquals($expected, $actual);
        $expected = 1;
        $actual   = count($assets->getJs());
        $I->assertEquals($expected, $actual);

        for ($i = 0; $i < 2; $i++) {
            $assets
                ->addCss('style_' . $i . '.css')
                ->addJs('script_' . $i . '.js')
            ;
        }

        $expected = 3;
        $actual   = count($assets->getCss());
        $I->assertEquals($expected, $actual);
        $expected = 3;
        $actual   = count($assets->getJs());
        $I->assertEquals($expected, $actual);
    }
}
