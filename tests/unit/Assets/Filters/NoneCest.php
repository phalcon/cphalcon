<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Filters;

use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Test\Unit\Assets\Helper\TrimFilter;
use Phalcon\Test\Unit\Assets\Helper\UppercaseFilter;
use UnitTester;

class NoneCest
{
    /**
     * Tests none filter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterNone(UnitTester $I)
    {
        $cssmin   = new None();
        $expected = ' ';
        $actual   = $cssmin->filter(' ');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests custom filters
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/1198
     * @author  Volodymyr Kolesnykov <volodymyr@wildwolf.name>
     * @since   2013-09-15
     */
    public function testAssetsFilterChainCustomFilterWithCssmin(UnitTester $I, $scenario)
    {
        $scenario->skip('TODO: Check DI');
        $fileName = $I->getNewFileName('assets_', 'css');

        $assets = new Manager();
        $assets->useImplicitOutput(false);
        $css = $assets->collection('css');

        $css->setTargetPath(PATH_CACHE . $fileName);
        $css->addCss(PATH_DATA . 'assets/assets/1198.css');
        $css->addFilter(new UppercaseFilter());
        $css->addFilter(new TrimFilter());
        $css->join(true);
        $assets->outputCss('css');

        $expected = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
        $actual   = file_get_contents(PATH_CACHE . $fileName);

        $I->cleanFile(PATH_CACHE, $fileName);

        $I->assertEquals($expected, $actual);
    }
}
